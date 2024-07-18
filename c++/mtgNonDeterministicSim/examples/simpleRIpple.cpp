#include <omp.h>

#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>
#include <compare>
#include <chrono>
#include <deck.hpp>

struct rippleRun
{
    int nmbRipples;
    int remainingDeck;
    std::chrono::milliseconds durationS;

    bool operator==(rippleRun const& rhs) {return nmbRipples == rhs.nmbRipples;};
    std::partial_ordering operator<=>(rippleRun const& rhs) const{
        if(auto c = nmbRipples <=> rhs.nmbRipples; c != 0) return c;
        return remainingDeck <=> rhs.remainingDeck;
    }
};


int main(int argc, char **argv)
{
    std::filesystem::path lPath2Results("");
    const int nmbIter = 1000000;
    // standard parameter
    int lNmbLands = 34, lNmbTargets = 31, lNmbRelevantNonLands = 0, lNmbOtherNonLands = 23, lCntRipple = 4, lRestartCnt = 0;

    if (argc > 6)
    {
        /* override standard parameters */
        lNmbLands = std::stoi(argv[1]);
        lNmbTargets = std::stoi(argv[2]);
        lNmbRelevantNonLands = std::stoi(argv[3]);
        lNmbOtherNonLands = std::stoi(argv[4]);
        lCntRipple = std::stoi(argv[5]);
        lRestartCnt = std::stoi(argv[6]);
    }

    std::vector<rippleRun> resRuns = std::vector<rippleRun>();
    int nthreads;
    auto start = std::chrono::high_resolution_clock::now();
#pragma omp parallel
{
#pragma omp single nowait
{
#ifdef _OPENMP
    nthreads = omp_get_num_threads();
#else
    nthreads = 1;
#endif
}
    std::vector<rippleRun> resRunsPrivate;
    #pragma omp for schedule(dynamic) nowait
    for (int iter = 0; iter < nmbIter; iter++)
    {
        deck lDeck(lNmbLands,lNmbTargets,lNmbRelevantNonLands,lNmbOtherNonLands);
        int lResult = 0, lRestart = lRestartCnt;
        auto startI = std::chrono::high_resolution_clock::now();
        lResult = lDeck.Ripple(lCntRipple);
        auto stopI = std::chrono::high_resolution_clock::now();
        resRunsPrivate.emplace_back(lResult,lDeck.nmbOfCards(),std::chrono::duration_cast<std::chrono::seconds>(stopI - startI));
    }
#pragma omp critical
    resRuns.insert(resRuns.end(),resRunsPrivate.begin(),resRunsPrivate.end());
}

    auto stop = std::chrono::high_resolution_clock::now();

    rippleRun lComp;
    int lCnt = 0;

    lComp.nmbRipples = 0;
    lCnt = std::count(resRuns.begin(),resRuns.end(),lComp);
    std::cout<<"nmb no Ripple "<<lCnt<<"  Probability:" <<(double)lCnt / nmbIter<<"\n";

    lComp.nmbRipples = lNmbTargets;
    lCnt = std::count(resRuns.begin(),resRuns.end(),lComp);
    std::cout<<"nmb all Ripple "<<lCnt<<"  Probability:" <<(double)lCnt / nmbIter<<"\n";

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    std::cout<<"Duration of the sim "<<duration.count()<<" [s]\n";
    std::cout<<"Used "<<nthreads<<" Threads\n";

    std::ranges::sort(resRuns,{},&rippleRun::nmbRipples);

    if (!lPath2Results.has_filename())
    {
        lPath2Results.append("rippleSimRes.csv");
    }
    std::ofstream ofs = std::ofstream(lPath2Results.make_preferred(),std::ofstream::out);
    ofs<<"nmbRipple;remainingDeck;time [ms]\n";
    for(auto res : resRuns)
    {
        ofs<<res.nmbRipples<<";"<<res.remainingDeck<<";"<<res.durationS<<"\n";
    }
    ofs.close();

    return 0;
}