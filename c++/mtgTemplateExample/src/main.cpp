#include "std_header.h"

int main(int argc, char **argv)
{
    std::filesystem::path lPath2Data("");
    int lReplacemode = 0, lPpW = 2, lPpP = 1, lPpD = 0; //default
    std::cout<<"Hello World\n";

    if(argc > 1)
    {
        lPath2Data = argv[1];
    }
    else
    {
        lPath2Data = "../../../../data/Tabelle_Archonliga_Q3-23.csv";
    }
    if (argc > 4)
    {
        lPpW = std::stoi(argv[2]);
        lPpP = std::stoi(argv[3]);
        lPpD = std::stoi(argv[4]);
        lReplacemode = -42;
    }
    else if(argc > 2)
    {
        lReplacemode = std::stoi(argv[2]);
    }

    std::stringstream ss;

    switch (lReplacemode)
    {
    case -42:
        std::cout<<"Using parameters from command line arguments\n";
        break;

    case 1:
        lPpW = 3;
        lPpP = 15;
        lPpD = 1;
        break;

    case 2:
        lPpW = 3;
        lPpP = 12;
        lPpD = 1;
        break;

    case 3:
        lPpW = 3;
        lPpP = 10;
        lPpD = 1;
        break;

    case 4:
        lPpW = 3;
        lPpP = 8;
        lPpD = 1;
        break;
    
    default:
        std::cout<<"using standart points\n";
        break;
    }

    ss<<"_w"<<lPpW<<"_p"<<lPpP<<"_d"<<lPpD;
    ss.flush();
    std::string lCasename = ss.str();

    League lTest = League(lPpW,lPpP,lPpD,12);

    lTest.loadLeagueFromCSV(lPath2Data.make_preferred().string());

    lTest.recalcPointsOfPlayers();

    lPath2Data.replace_filename(lPath2Data.filename().replace_extension().string()+lCasename+".csv");

    lTest.saveLeagueAsCSV(lPath2Data.make_preferred().string());  

    return EXIT_SUCCESS;
}