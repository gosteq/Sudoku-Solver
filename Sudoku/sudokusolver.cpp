#include "sudokusolver.h"

SudokuSolver::SudokuSolver(){
    numberOfFindedResults = 0;
    timeOfSolving = 0;
    board.numberOfEmpty = 81;
    board.numberOfFilled = 0;
    arrayOfIllusionsSize = 0;
    for(int j=0 ; j<81 ; ++j){
        arrayOfIllusions[j] = j;
        for(int i=0 ; i<10 ; ++i){
            board.possibleTmp[j][i] = true;
        }
        board.howMuchTmp[j].index = j;
        board.howMuchTmp[j].howMany = 9;
    }
}

void SudokuSolver::pits(){
    for(int i=81/2 ; i>=0 ; --i){
        heap(i, 81);
    }
}

void SudokuSolver::heap(int i,int n){
    int l,r,maxi;
    int t;
    l = 2*i+1;
    r = 2*i+2;
    if((l<n)&&(board.howMuchTmp[arrayOfIllusions[l]].howMany < board.howMuchTmp[arrayOfIllusions[i]].howMany)){
        maxi = l;
    }else{
        maxi = i;
    }
    if((r<n) && (board.howMuchTmp[arrayOfIllusions[r]].howMany < board.howMuchTmp[arrayOfIllusions[maxi]].howMany)){
        maxi = r;
    }
    if(maxi != i){
        t = arrayOfIllusions[i];
        arrayOfIllusions[i] = arrayOfIllusions[maxi];
        arrayOfIllusions[maxi] = t;
        heap(maxi, n);
    }
}

Move SudokuSolver::findMove(){
    Move move;
    pits();
    move.choosedPlace = board.howMuchTmp[arrayOfIllusions[0]];
    if(board.howMuchTmp[arrayOfIllusions[0]].howMany == 1){
        move.experiment = false;
    }else{
        move.experiment = true;
    }
    return move;
}

bool SudokuSolver::checkEntryBoard(){
    for(int j=0 ; j<9 ; ++j){
        for(int i=0 ; i<9 ; ++i){
            if(board.tabTmp[j][i] != 0){
                for(int x=0 ; x<9 ; ++x){
                    if((board.tabTmp[j][i] == board.tabTmp[j][x]) && (x != i)){
                        return false;
                    }
                }
                for(int y=0 ; y<9 ; ++y){
                    if((board.tabTmp[j][i] == board.tabTmp[y][i]) && (y != j)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool SudokuSolver::checkIfIsGoodFilled(){
    return (board.numberOfEmpty + board.numberOfFilled == 81) ? true : false;
}

bool SudokuSolver::saveResult(){
    if(saveToFile){
        result = "";
        for(int y=0 ; y<9 ; ++y){
            for(int x=0 ; x<9 ; ++x){
                result += (char)board.tabTmp[y][x] + 48;
            }
        }
        result += "\n";
        file << result;
    }
    return true;
}

bool SudokuSolver::prepareForSolving(){
    for(int j=0 ; j<9 ; ++j){
        for(int i=0 ; i<9 ; ++i){
            if(board.tabTmp[j][i] != 0){
                board.numberOfFilled += 1;
                board.numberOfEmpty -= 1;
                updatePossible(board.tabTmp[j][i],  j, i);
                int tmp = (j*9)+i;
                for(int x=0 ; x<10 ; ++x) {
                    board.possibleTmp[tmp][x] = false;
                }
                board.howMuchTmp[tmp].howMany = 80;
            }
        }
    }
    return checkIfIsGoodFilled();
}

void SudokuSolver::updatePossible(int value, int j, int i){
    int Y,X;
    Y = (j/3)*3;
    X = (i/3)*3;
    for(int y=Y ; y<=Y+2 ; ++y){
        for(int x=X ; x<=X+2 ; ++x){
            if(board.tabTmp[y][x] == 0){
                int tmp = (y*9)+x;
                if(board.possibleTmp[tmp][value]){
                    board.possibleTmp[tmp][value] = false;
                    --board.howMuchTmp[tmp].howMany;
                    if(board.howMuchTmp[tmp].howMany == 0){
                        --board.numberOfEmpty;
                    }
                }
            }
        }
    }
    for(int xx=0 ; xx<9 ; ++xx){
        if(board.tabTmp[j][xx] == 0){
            int tmp = (j*9)+xx;
            if(board.possibleTmp[tmp][value]){
                board.possibleTmp[tmp][value] = false;
                --board.howMuchTmp[tmp].howMany;
                if(board.howMuchTmp[tmp].howMany == 0){
                    --board.numberOfEmpty;
                }
            }
        }
    }
    for(int yy=0 ; yy<9 ; ++yy){
        if(board.tabTmp[yy][i] == 0){
            int tmp = (yy*9)+i;
            if(board.possibleTmp[tmp][value]){
                board.possibleTmp[tmp][value] = false;
                --board.howMuchTmp[tmp].howMany;
                if(board.howMuchTmp[tmp].howMany == 0){
                    --board.numberOfEmpty;
                }
            }
        }
    }
}

bool SudokuSolver::setBoardToSolve(EntryBoard entryBoard){
    for(int j=0 ; j<9 ; ++j){
        for(int i=0 ; i<9 ; ++i){
            board.tabTmp[j][i] = entryBoard.board[j][i];
            if((entryBoard.board[j][i] < 0) || (entryBoard.board[j][i] > 9)){
                return false;
            }
        }
    }
    return checkEntryBoard() && prepareForSolving();
}

void SudokuSolver::setSavingResultToFile(bool ifSaving){
    saveToFile = ifSaving;
}

bool SudokuSolver::setPathAndOpenFile(char* path){
    if(saveToFile == false){
        return false;
    }
    file.open(path,std::ios::out);
    return file.good();
}

bool SudokuSolver::closeResultFile(){
    if(saveToFile == false){
        return false;
    }
    file.close();
    return true;
}

bool SudokuSolver::isSolved(){
    if((board.numberOfFilled == 81) && (board.numberOfEmpty == 0)){
        return true;
    }else{
        return false;
    }
}

void SudokuSolver::solve(){
    Move move;
    bool find;
    PlaceInfo placeInfo;
    int number = 0;
    bool error;
    clock_t start = clock();
    do{
        error = false;
        while(!isSolved() && !error){
            if(checkIfIsGoodFilled()){
                number = 0;
                move = findMove();
                placeInfo = move.choosedPlace;
                if(!move.experiment){
                    for(int i=1 ; i<10 ; ++i){
                        if(board.possibleTmp[placeInfo.index][i]){
                            number = i;
                        }
                    }
                    --board.numberOfEmpty;
                    ++board.numberOfFilled;
                    board.tabTmp[placeInfo.index/9][placeInfo.index%9] = number;
                    updatePossible(number, placeInfo.index/9, placeInfo.index%9);
                    board.howMuchTmp[placeInfo.index].howMany = 80;
                    board.possibleTmp[placeInfo.index][number] = false;
                }else{
                    bool find = false;
                    for(int i=1 ; i<10 ; ++i){
                        if(board.possibleTmp[placeInfo.index][i] && !find) {
                            number = i;
                            find = true;
                        }
                    }
                    board.indexPlaceExperiment = placeInfo.index;
                    board.valueChoosedExperiment = number;
                    stack.push(&board);
                    --board.numberOfEmpty;
                    ++board.numberOfFilled;
                    board.tabTmp[placeInfo.index/9][placeInfo.index%9] = number;
                    updatePossible(number, placeInfo.index/9, placeInfo.index%9);
                    board.howMuchTmp[placeInfo.index].howMany = 80;
                    for(int i=0 ; i<10 ; ++i){
                        board.possibleTmp[placeInfo.index][i] = false;
                    }
                }
            }else{
                error = true;
            }
        }
        if(!error){
            saveResult();
            ++numberOfFindedResults;
        }
        if(!stack.empty() || error){
            find = false;
            while(!find && !stack.empty()){
                stack.pop(&board);
                for(int i=board.valueChoosedExperiment+1 ; i<10 ; ++i){
                    if(!find && board.possibleTmp[board.indexPlaceExperiment][i]){
                        find = true;
                        number = i;
                    }
                }
                if(find){
                    board.valueChoosedExperiment = number;
                    stack.push(&board);
                    --board.numberOfEmpty;
                    ++board.numberOfFilled;
                    board.tabTmp[board.indexPlaceExperiment/9][board.indexPlaceExperiment%9] = number;
                    updatePossible(number, board.indexPlaceExperiment/9, board.indexPlaceExperiment%9);
                    board.howMuchTmp[board.indexPlaceExperiment].howMany = 80;
                    for(int i=0 ; i<10 ; ++i){
                        board.possibleTmp[board.indexPlaceExperiment][i] = false;
                    }
                }else{
                    error = false;
                }
            }
        }
    }while(!stack.empty() || error);
    clock_t stop = clock();
    timeOfSolving = stop - start;
}

long SudokuSolver::getTimeOfSolvingInMs(){
    return (long)timeOfSolving;
}

long SudokuSolver::getNumberOfResults(){
    return numberOfFindedResults;
}
