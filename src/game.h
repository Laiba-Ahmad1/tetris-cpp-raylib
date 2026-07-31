#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game{
    
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    bool isBlockOutside();
    bool BlockFits(); //to see if every cell of a block is on top of empty cell grid or not
    void Reset();
    void UpdateScore(int LinesCleared, int MoveDownPoints);
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    vector<Block> GetAllBlocks();
    void RotateBlock();
    void lockBlock();
    Grid grid;
    
    public:
    Game();
    void HandleInput();
    void MoveBlockDown();
    // void Update();
    void Draw();
    bool gameOver;
    int score;

};