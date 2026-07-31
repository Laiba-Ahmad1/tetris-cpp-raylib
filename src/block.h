#pragma once
#include<vector>
#include<map>
#include"position.h"
#include <raylib.h>
using namespace std;

//inheritance, parent class. (where each blocks has same code)
class Block{

    public:
    Block();
    void Draw(int offsetX, int offsetY); //offset to display next block away from game.
    void Move(int rows, int columns);
    vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotate();
    int id;                            // to distinguish between 7 types of blocks
    map <int, vector<Position>> cells; //map gives a key to each position value

    //now we define what each block needs, cellSize, rotationState, colors
    private:
    int cellSize;
    int rotationState;
    vector<Color> GetCellColors();
    vector<Color> colors;
    int rowOffset;
    int columnOffset;
};

