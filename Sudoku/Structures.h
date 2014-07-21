#ifndef STRUCTURES_H
#define STRUCTURES_H

struct PlaceInfo{
    int index;
    int howMany;
};

struct Move{
    PlaceInfo choosedPlace;
    bool experiment;
};

struct BoardInfo{
    int tabTmp[9][9];
    bool possibleTmp[81][10];
    PlaceInfo howMuchTmp[81];
    int indexPlaceExperiment;
    int valueChoosedExperiment;
    int numberOfFilled;
    int numberOfEmpty;
};

struct EntryBoard{
    int board[9][9];
};

#endif // STRUCTURES_H
