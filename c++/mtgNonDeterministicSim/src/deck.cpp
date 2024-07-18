#include "deck.hpp"

double deck::probLand()
{
    return (double)nmbLands / nmbOfCards();
}

double deck::probTarget()
{
    return (double)nmbTargets / nmbOfCards();
}

double deck::probRelevantNonLand()
{
    return (double)nmbRelevantNonLands / nmbOfCards();
}

double deck::probOtherNonLand()
{
    return (double)nmbOtherNonLands / nmbOfCards();
}

int deck::cutLands()
{
    return nmbLands;
}

int deck::cutTargets()
{
    return cutLands() + nmbTargets;
}

int deck::cutRelevantNonLands()
{
    return cutTargets() + nmbRelevantNonLands;
}

int deck::cutOtherNonLands()
{
    return cutRelevantNonLands() + nmbOtherNonLands;
}

deck::deck(int pnmbLands, int pnmbTargets, int pnmbRelevantNonLands, int pnmbOtherNonLands)
{
    nmbLands = pnmbLands;
    nmbTargets = pnmbTargets;
    nmbRelevantNonLands = pnmbRelevantNonLands;
    nmbOtherNonLands = pnmbOtherNonLands;
    std::random_device rd;
    rng = std::mt19937(rd());
}

int deck::nmbOfCards()
{
    return nmbLands+nmbRelevantNonLands+nmbOtherNonLands+nmbTargets;
}

int deck::DrawCard()
{
    int lResult = 0;
    if (nmbOfCards()>0)
    {
        std::uniform_int_distribution<> distr(1,nmbOfCards());
        int rngnmb = distr(rng);
        if (rngnmb <= cutLands())
        {
            lResult = 1; // Land
            nmbLands--;
        }
        else if (rngnmb > cutLands() && rngnmb <= cutTargets())
        {
            lResult = 2; // Target
            nmbTargets--;
        }
        else if (rngnmb > cutTargets() && rngnmb <= cutRelevantNonLands())
        {
            lResult = 3; // RelevantNonLand
            nmbRelevantNonLands--;
        }
        else if (rngnmb > cutRelevantNonLands() && rngnmb <= cutOtherNonLands())
        {
            lResult = 4; // OtherNonLand
            nmbOtherNonLands--;
        }
        else
        {
            lResult = -1; // ERROR
        }
    }  

    return lResult;
}

int deck::Dredge(int pCntDredge)
{
    int lResult = 0;

    std::vector<int> lCards;// = std::vector<int>();
    for (int i = 0; i < pCntDredge; i++)
    {
        lCards.emplace_back(DrawCard());
    }
    if(std::find(lCards.begin(),lCards.end(),1) != lCards.end())
    {
        lResult += 1; //hit a land
    }
    if(std::find(lCards.begin(),lCards.end(),2) != lCards.end())
    {
        lResult += 100; //hit a Target
    }
    if(std::find(lCards.begin(),lCards.end(),3) != lCards.end())
    {
        lResult += 10; //hit RelevantNonLand
    }

    return lResult;    
}

int deck::Ripple(int pCntRipple)
{
    int lResult = 0;

    std::vector<int> lCards;// = std::vector<int>();
    for (int i = 0; i < pCntRipple; i++)
    {
        lCards.emplace_back(DrawCard());
    }
    for (auto card : lCards)
    {
        if (card == 2)
        {
            lResult += 1 + Ripple(pCntRipple);
        }        
    }
    
    return lResult;
}