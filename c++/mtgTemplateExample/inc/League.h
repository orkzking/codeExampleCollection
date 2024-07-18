#ifndef LEAGUE_H
#define LEAGUE_H

#include <vector>
#include <string>
#include <variant>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

// put here all own coded header
#include "utilStructs.h"

class League
{
private:
    int zPointsPerWin;
    int zPointsPerParticipation;
    int zPointsPerDraw;
    int zNmbTournaments;
    std::vector<Player> zPlayers;
public:
    League(int pPointsPerWin, int pPointsPerParticipation, int pPointsPerDraw, int pNmbTournaments);
    League();
    ~League();
    void loadLeagueFromCSV(std::string pPath2Data);
    void recalcPointsOfPlayers();
    void saveLeagueAsCSV(std::string pExportPath);
};

#endif