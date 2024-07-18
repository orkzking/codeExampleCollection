#pragma once

#ifndef DECK_HPP
#define DECK_HPP

#include <algorithm>
#include <random>
#include <vector>

class deck
{
private:
    /* data */
    int nmbLands;
    int nmbTargets;
    int nmbRelevantNonLands;
    int nmbOtherNonLands;
    std::mt19937 rng;
    double probLand();
    double probTarget();
    double probRelevantNonLand();
    double probOtherNonLand();
    int cutLands();
    int cutTargets();
    int cutRelevantNonLands();
    int cutOtherNonLands();
public:
    deck(int pnmbLands, int pnmbTargets, int pnmbRelevantNonLands, int pnmbOtherNonLands);
    //~deck();
    int nmbOfCards();
    int DrawCard();
    int Dredge(int pCntDredge);
    int Ripple(int pCntRipple);
};

#endif // DECK_HPP