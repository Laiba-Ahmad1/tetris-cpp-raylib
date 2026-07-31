#include "grid.h"
#include <iostream>
using namespace std;

Grid::Grid()
{

    numRows=20;
    numCols=10;
    cellSize=30;
    Initialize();
    colors = GetCellColors();
};

void Grid::Initialize(){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            grid[i][j]=0; //giving initial value of 0 to each grid
        }
    }
}

void Grid::Print(){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            cout<<grid[i][j]<<" "; 
        }
        cout<<endl;
    }
}

vector<Color> Grid::GetCellColors(){
    Color darkGrey = {26,31,40,255};
    Color green = {47,230,23,255};
    Color red = {232,18,18,255};
    Color orange = {226,116,17,255};
    Color yellow = {237,234,4,255};
    Color purple = {166,0,247,255};
    Color cyan ={21,204,209,255};
    Color blue ={13,64,216,255};

    return {darkGrey,green,red,orange,yellow,purple,cyan,blue};
}

void Grid::Draw(){
     for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            int cellValue =  grid[i][j];
            DrawRectangle(j*cellSize+11, i*cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int column)
{
    if(row >=0 && row< numRows && column>=0 && column< numCols){
        return false;
    }
    return true;
}

//checks if grid cell has a block or not, so that we can stack block on top of other
bool Grid::isCellEmpty(int row, int column)
{
    if(grid[row][column]==0){
        return true;
    }
    return false;
}

// to clear a row on full
bool Grid::isRowFull(int row)
{
    for(int column=0; column<numCols; column++){

        if(grid[row][column] == 0){  //jb bhi koi ik 0 hoga to retur hojaye ga to indicate its not full rn
             return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for(int column =0; column<numCols; column++){
        grid[row][column] =0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int column =0; column<numCols; column++){
        grid[row+ numRows][column] = grid[row][column]; //moves a row in grid down by number of rows rows
        grid[row][column] = 0; //clears the orignal row and gives its vaalue to the upper row so it appears to  go down
    }  
}

int Grid::clearFullRows()
{
    int completed = 0;
    for(int row = numRows-1; row>=0; row--){ //reverse, starting from 19 to 0
        if(isRowFull(row)){ //agr to full h to erase
            ClearRow(row);
            completed++;
        }
        else if(completed>0){ //agr full ni h but neche wali full thi to move down
            MoveRowDown(row, completed);
        }
    }
    return completed;
}
