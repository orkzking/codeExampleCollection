#include <omp.h>

#include <iostream>
#include <filesystem>
#include <sstream>
#include <vector>
#include <compare>
#include <chrono>
#include <deck.hpp>

struct ComboRun
{
    int nmbDredges;
    int result;
    std::chrono::milliseconds durationS;

    bool operator==(ComboRun const& rhs) {return result == rhs.result;};
    std::partial_ordering operator<=>(ComboRun const& rhs) const{
        if(auto c = result <=> rhs.result; c != 0) return c;
        return nmbDredges <=> rhs.nmbDredges;
    }
};

int main(int argc, char **argv)
{
    std::filesystem::path lPath2Results("");
    const int nmbIter = 1000000;
    // standard parameter
    int lNmbLands = 40, lNmbTargets = 1, lNmbRelevantNonLands = 2, lNmbOtherNonLands = 45, lCntDredge = 6, lRestartCnt = 1;

    if (argc > 6)
    {
        /* override standard parameters */
        lNmbLands = std::stoi(argv[1]);
        lNmbTargets = std::stoi(argv[2]);
        lNmbRelevantNonLands = std::stoi(argv[3]);
        lNmbOtherNonLands = std::stoi(argv[4]);
        lCntDredge = std::stoi(argv[5]);
        lRestartCnt = std::stoi(argv[6]);
    }

    std::vector<ComboRun> resRuns = std::vector<ComboRun>();
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
    std::vector<ComboRun> resRunsPrivate;
    #pragma omp for schedule(dynamic) nowait
    for (int iter = 0; iter < nmbIter; iter++)
    {
        // set deck state at combo start
        deck lDeck(lNmbLands,lNmbTargets,lNmbRelevantNonLands,lNmbOtherNonLands);
        int lResult = 0, lNmbDredges = 0, lRestart = lRestartCnt;
        auto startI = std::chrono::high_resolution_clock::now();
        do
        {
            if (lDeck.nmbOfCards() >= lCntDredge)
            {
                lResult = lDeck.Dredge(lCntDredge);
                lNmbDredges++;
                //std::cout<<"Res: "<<lResult;
                if (lResult % 100 % 12 > 1) // shuffle trigger
                {
                    //std::cout<<" -> Shuffle Trigger";
                    lDeck = deck(lNmbLands,lNmbTargets,lNmbRelevantNonLands,lNmbOtherNonLands);
                }
                if (lResult % 2 == 0 && lRestart > 0) //restart with land from hand
                {
                    lResult = 1;
                    //std::cout<<" -> used Restart";
                    lRestart--;
                }
                
            }
            else
            {
                //std::cout<<"libary to small -> wifed";
                lResult = -1;
            }
            //std::cout<<"\n";
            
        } while (lResult>0 && lResult <100 && lResult != 10);
        auto stopI = std::chrono::high_resolution_clock::now();
        resRunsPrivate.emplace_back(lNmbDredges,lResult,std::chrono::duration_cast<std::chrono::seconds>(stopI - startI));
        /*
        switch (lResult)
        {
        case -1:
            std::cout<<"Wifed with remaining libary to small\n";
            break;
        case 0:
            std::cout<<"Wifed with non-lands\n";
            break;
        
        case 10:
            std::cout<<"Wifed on shuffle trigger\n";
            break;

        default:
            std::cout<<"Hit the target Dakmor Salvage\n";
            break;
        }
        */
    }
    #pragma omp critical
    resRuns.insert(resRuns.end(),resRunsPrivate.begin(),resRunsPrivate.end());
}
    auto stop = std::chrono::high_resolution_clock::now();
    ComboRun lcmpRun;
    int lCnt = 0;
    lcmpRun.result = -1;
    lCnt = std::count(resRuns.begin(),resRuns.end(),lcmpRun);
    std::cout<<"nmb wifed libary to small "<<lCnt<<"  Probability:" <<(double)lCnt / nmbIter<<"\n";
    lcmpRun.result = 0;
    lCnt = std::count(resRuns.begin(),resRuns.end(),lcmpRun);
    std::cout<<"nmb wifed non-lands "<<lCnt<<"  Probability:" <<(double)lCnt / nmbIter<<"\n";
    lcmpRun.result = 10;
    lCnt = std::count(resRuns.begin(),resRuns.end(),lcmpRun);
    std::cout<<"nmb wifed on shuffle trigger "<<lCnt<<"  Probability:" <<(double)lCnt / nmbIter<<"\n";
    lcmpRun.result = 100;
    lCnt = std::count(resRuns.begin(),resRuns.end(),lcmpRun);
    std::cout<<"nmb hit only Dakmor Salvage "<<lCnt<<"  Probability:" <<(double)lCnt / nmbIter<<"\n";
    lcmpRun.result = 101;
    lCnt = std::count(resRuns.begin(),resRuns.end(),lcmpRun);
    std::cout<<"nmb hit Dakmor Salvage and land(s) "<<lCnt<<"  Probability:" <<(double)lCnt / nmbIter<<"\n";
    lcmpRun.result = 110;
    lCnt = std::count(resRuns.begin(),resRuns.end(),lcmpRun);
    std::cout<<"nmb hit Dakmor Salvage with shuffe trigger "<<lCnt<<"  Probability:" <<(double)lCnt / nmbIter<<"\n";
    lcmpRun.result = 111;
    lCnt = std::count(resRuns.begin(),resRuns.end(),lcmpRun);
    std::cout<<"nmb hit Dakmor Salvage and land(s) with shuffe trigger "<<lCnt<<"  Probability:" <<(double)lCnt / nmbIter<<"\n";

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    std::cout<<"Duration of the sim "<<duration.count()<<" [s]\n";
    std::cout<<"Used "<<nthreads<<" Threads\n";

    std::ranges::sort(resRuns,{},&ComboRun::result);
    
    return 0;
}
