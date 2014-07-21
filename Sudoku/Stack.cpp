#include "Stack.h"

Stack::Stack(){
    actualFreePlaceForBoard = 0;
}

Stack::~Stack(){

}

bool Stack::empty(){
    return actualFreePlaceForBoard == 0 ? true : false;
}

void Stack::pop(BoardInfo *boardInfo){
    actualFreePlaceForBoard--;
    boardInfo->indexPlaceExperiment =
            boards[actualFreePlaceForBoard].indexPlaceExperiment;
    boardInfo->numberOfEmpty =
            boards[actualFreePlaceForBoard].numberOfEmpty;
    boardInfo->numberOfFilled =
            boards[actualFreePlaceForBoard].numberOfFilled;
    boardInfo->valueChoosedExperiment =
            boards[actualFreePlaceForBoard].valueChoosedExperiment;
    for(int j=0 ; j<81 ; ++j){
        boardInfo->howMuchTmp[j] =
                boards[actualFreePlaceForBoard].howMuchTmp[j];
        for(int i=0 ; i<10 ; ++i){
            boardInfo->possibleTmp[j][i] =
                    boards[actualFreePlaceForBoard].possibleTmp[j][i];
        }
        boardInfo->tabTmp[j/9][j%9] =
                boards[actualFreePlaceForBoard].tabTmp[j/9][j%9];
    }
}

void Stack::push(BoardInfo *boardInfo){
    boards[actualFreePlaceForBoard].indexPlaceExperiment =
            boardInfo->indexPlaceExperiment;
    boards[actualFreePlaceForBoard].numberOfEmpty =
            boardInfo->numberOfEmpty;
    boards[actualFreePlaceForBoard].numberOfFilled =
            boardInfo->numberOfFilled;
    boards[actualFreePlaceForBoard].valueChoosedExperiment =
            boardInfo->valueChoosedExperiment;
    for(int j=0 ; j<81 ; ++j){
        boards[actualFreePlaceForBoard].howMuchTmp[j] =
                boardInfo->howMuchTmp[j];
        for(int i=0 ; i<10 ; ++i){
            boards[actualFreePlaceForBoard].possibleTmp[j][i] =
                    boardInfo->possibleTmp[j][i];
        }
        boards[actualFreePlaceForBoard].tabTmp[j/9][j%9] =
                boardInfo->tabTmp[j/9][j%9];
    }
    actualFreePlaceForBoard++;
}
