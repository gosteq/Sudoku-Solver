#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H
#include "Structures.h"
#include "Stack.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <string.h>

class SudokuSolver{
private:
    Stack stack;
    BoardInfo board;

    std::string result;
    int arrayOfIllusions[81];
    int arrayOfIllusionsSize;
    std::fstream file;
    bool saveToFile;
    PlaceInfo heapOfPlaceInfo[81];
    bool savingResultToFile;

    clock_t timeOfSolving;

    long numberOfFindedResults;

    void pits();
    void heap(int i, int n);
    Move findMove();
    bool checkEntryBoard();
    bool checkIfIsGoodFilled();
    bool saveResult();
    bool prepareForSolving();
    void updatePossible(int value, int j, int i);
    bool isSolved();

public:
    SudokuSolver();
    bool setBoardToSolve(EntryBoard entryBoard);
    void setSavingResultToFile(bool ifSaving);
    bool setPathAndOpenFile(char* path);
    bool closeResultFile();
    void solve();
    long getTimeOfSolvingInMs();
    long getNumberOfResults();
};

#endif // SUDOKUSOLVER_H
