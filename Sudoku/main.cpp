#include <iostream>
#include "sudokusolver.h"
using namespace std;

//#define WITH_SAVE

int main(){
    SudokuSolver sudokuSolver;
    EntryBoard entryBoard = {8,0,0,0,3,0,0,4,0,
							 0,0,0,0,0,9,0,0,5,
							 0,5,1,0,0,6,0,3,0,
							 0,0,5,0,4,0,0,0,9,
							 0,0,0,1,0,2,0,0,0,
							 0,0,0,0,0,0,3,0,0,
							 0,3,0,7,0,0,6,8,0,
							 0,0,0,0,0,0,0,0,0,
							 0,0,0,0,0,0,0,0,0};
    if(sudokuSolver.setBoardToSolve(entryBoard)){
        #ifdef WITH_SAVE
        sudokuSolver.setSavingResultToFile(true);
        sudokuSolver.setPathAndOpenFile("result.txt");
        sudokuSolver.solve();
        sudokuSolver.closeResultFile();
        #endif
        #ifndef WITH_SAVE
        sudokuSolver.setSavingResultToFile(false);
        sudokuSolver.solve();
        #endif
        cout<<"Number of results: "<<sudokuSolver.getNumberOfResults()<<"\n";
        cout<<"Time of solving in miliseconds: "<<sudokuSolver.getTimeOfSolvingInMs()<<"\n";
    }else{
        cout<<"Wrong board\n";
    }
    return 0;
}

