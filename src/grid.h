#pragma once
#include <vector>
#include <raylib.h>
using namespace std;

class Grid{
    
    vector<Color> GetCellColors();
    int numRows;
    int numCols;
    int cellSize;
    vector<Color> colors;
    bool isRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);

    public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    int grid[20][10];
    bool isCellOutside(int row,int column);
    bool isCellEmpty(int row,int column); //to stack blocks on top of eachother. 
    int clearFullRows();
};