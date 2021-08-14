#include "header.h"


void findHandValue(Player* player)
{
    resetArray(player->scoringOptions, 9);

    populateScoringArray(player);

    findBestOptions(player);
}

void populateScoringArray(Player* player)
{
    findRepeatingFaceValues(player);

    testForStraight(player);

    findRepeatingSuits(player);
}


void resetArray(int inputArray[], int size)
{
    for (int increment = 0; increment < size; increment++)
    {
        inputArray[increment] = 0;
    }
}

void findRepeatingFaceValues(Player* player)
{
    int heldValue;
    for (int comparisonCard_1 = 0; comparisonCard_1 < player->playerHandSize; comparisonCard_1++)
    {
        int similarCardsCount = 0;
        for (int comparisonCard_2 = 0; comparisonCard_2 < player->playerHandSize; comparisonCard_2++)
        {
            if (player->playerHand[comparisonCard_1].faceValue == player->playerHand[comparisonCard_2].faceValue && comparisonCard_1 != comparisonCard_2)
            {
                similarCardsCount++;
                
                player->playerHand[comparisonCard_1].keepFlag = 1;
                player->playerHand[comparisonCard_2].keepFlag = 1;
                
                heldValue = player->playerHand[comparisonCard_1].faceValue;
            }
        }
        evalutateRepeatedFaceValues(player, similarCardsCount);
    }
    checkFor2Pair(player, heldValue);  
}

void checkFor2Pair(Player* player, int foundPairValue)
{
    if (player->scoringOptions[1] == 1)
    {
        for (int comparisonCard_1 = 0; comparisonCard_1 < player->playerHandSize; comparisonCard_1++)
        {
            for (int comparisonCard_2 = 0; comparisonCard_2 < player->playerHandSize; comparisonCard_2++)
            {
                if (player->playerHand[comparisonCard_1].faceValue == player->playerHand[comparisonCard_2].faceValue && (comparisonCard_1 != comparisonCard_2 && player->playerHand[comparisonCard_1].faceValue != foundPairValue))
                {
                    player->scoringOptions[2] = 1;
                    
                    player->playerHand[comparisonCard_1].keepFlag = 1;
                    player->playerHand[comparisonCard_2].keepFlag = 1;                    
                }
            }
        }
    }
}


void evalutateRepeatedFaceValues(Player* player, int similarCards)
{
    switch(similarCards)
    {
        case 3:
            player->scoringOptions[7] = 1;
            break;
        case 2:
            player->scoringOptions[3] = 1;
            if (player->scoringOptions[1] == 1)
            {
                player->scoringOptions[6] = 1;
            }
            break;
        case 1:
            player->scoringOptions[1] = 1;
            if (player->scoringOptions[3] == 1)
            {
                player->scoringOptions[6] = 1;
            }
    }
}


void testForStraight(Player* player)
{
    int sequentialCardCount = 0;

    for (int cardIncrement = 1; cardIncrement < player->playerHandSize; cardIncrement++)
    {
        if (player->playerHand[cardIncrement - 1].faceValue == player->playerHand[cardIncrement].faceValue - 1)
        {
            sequentialCardCount++;
        }
    }
    if (sequentialCardCount == 4)
    {
        applyStraightOutcome(player);
    }
}

void applyStraightOutcome(Player* player)
{
    player->scoringOptions[4] = 1;
    printf("Straight found\n");

    for (int cardIncrement = 0; cardIncrement < player->playerHandSize; cardIncrement++)
    {
        player->playerHand[cardIncrement].keepFlag = 1;
    }
}

void findRepeatingSuits(Player* player)   
{
    int similarCardsCount = 0;
    for (int comparisonCard = 1; comparisonCard < player->playerHandSize; comparisonCard++)
    {
        if (player->playerHand[comparisonCard].suit == player->playerHand[0].suit)
        {
            similarCardsCount++;
        }
    }
    if (similarCardsCount == 4)
    {
        applyFlushOutcome(player);
    }
}

void applyFlushOutcome(Player* player)
{
    player->scoringOptions[5] = 1;

    for (int cardIncrement = 0; cardIncrement < player->playerHandSize; cardIncrement++)
    {
        player->playerHand[cardIncrement].keepFlag = 1;
    }

    if (player->scoringOptions[4] == 1)
    {
        player->scoringOptions[8] = 1;
    }
}

void findBestOptions(Player* player)
{
    player->handValue = findHighestOption(player->scoringOptions, 9);
}


int findHighestOption(int scoringArray[], int size)
{
    int bestOption = 0;
    for (int scoringIncrement = 0; scoringIncrement < size; scoringIncrement++)
    {
        if (scoringArray[scoringIncrement] == 1)
        {
            bestOption = scoringIncrement;
        }
    }
    return bestOption;
}

void displayBestOption(int handValue)
{
    switch(handValue)
    {
        case 8:
            printf("Straight Flush!!!\n");
            break;
        case 7:
            printf("4 of a kind!!\n");
            break;
        case 6:
            printf("Full House!\n");
            break;
        case 5:
            printf("Flush!\n");
            break;
        case 4:
            printf("Straight!\n");
            break;
        case 3:
            printf("3 of a kind!\n");
            break;
        case 2:
            printf("2 Pair\n");
            break;
        case 1:
            printf("1 Pair\n");
            break;
        case 0:
            printf("High card\n");
            break;
    }
}