#include "game.h"
#include <random>


Game::Game()
{

    grid = Grid(); //grid obj
    blocks = GetAllBlocks(); //blocks is vector vector
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
}

Block Game::GetRandomBlock(){

    if(blocks.empty()){
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin()+ randomIndex); //makes sure previous blok doesnt appear again, and eahc block appears atleast 1time before cycle repeats
    return block;
}

vector<Block> Game::GetAllBlocks(){

    return {IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
}


void Game::Draw(){

    grid.Draw();
    currentBlock.Draw(11,11);
    switch(nextBlock.id){
        case 3: nextBlock.Draw(255,290); break; //i block
        case 4: nextBlock.Draw(255,280); break; //o block
        default: nextBlock.Draw(270,270);
    }
    
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if(gameOver && keyPressed != 0){
        gameOver=false;
        Reset();
    }
    switch(keyPressed){

        case KEY_LEFT:
        MoveBlockLeft();
        break;
        case KEY_RIGHT:
        MoveBlockRight();
        break;
        case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0,1);
        break;
        case KEY_R:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft(){
    // if(isBlockOutside()){
    //     return;
    // }
    // else  currentBlock.Move(0,-1); y ni kia kiu k pehle block ik cell bahar jaye ga phir use pta lge ga or wo return hoga
    if(!gameOver){
    currentBlock.Move(0,-1);
    if(isBlockOutside() || BlockFits()==false){
        currentBlock.Move(0,1);
    }
    }
    
}
void Game::MoveBlockRight(){
    if(!gameOver){
    currentBlock.Move(0,1);
        if(isBlockOutside() || BlockFits()==false){
         currentBlock.Move(0,-1);
        }
    }
}
void Game::MoveBlockDown(){
    if(!gameOver){
    currentBlock.Move(1,0);
    if(isBlockOutside() || BlockFits()==false){
        currentBlock.Move(-1,0);
        lockBlock();
    }
}
}


bool Game::isBlockOutside()
{
    vector<Position> tiles = currentBlock.GetCellPositions();
    for( Position item: tiles){
        if(grid.isCellOutside(item.row, item.column)){
            return true;
        }
    }
    return false;
}


// void Game::Update(){
//     currentBlock.Move(1,0);
// } similar to moveBlockDown fucntion so we used that.

void Game::RotateBlock()
{
    if(!gameOver){
    currentBlock.Rotate();
    if(isBlockOutside()){
        currentBlock.UndoRotate();
    }
}
}

//jb ik block floor hit krega to kia hoga:
void Game::lockBlock()
{
    vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){

        grid.grid[item.row][item.column] = currentBlock.id; //hr block ki id grid cell m store krali (to  know color)
    }
    currentBlock = nextBlock; //new block a jaye ga
    if(BlockFits()==false) //new block fit na ho mtlb container full h.
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock(); //next block m nae block ki value store hojaye gi for next block
    // grid.clearFullRows(); score add krne s pehle bs y tha
    int rowsCleared = grid.clearFullRows();
    UpdateScore(rowsCleared, 0);
}

//to see if our block can fir or one or more cell already occupies another block cell
bool Game::BlockFits()
{
    vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        
        if(grid.isCellEmpty(item.row, item.column) == false)
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks(); //Jo constructor m kia wo isme krenge to reset
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int LinesCleared, int MoveDownPoints)
{
    switch (LinesCleared)
    {
    case 1:
        score+=100;
        break;
    case 2:
        score+=300;
        break;
    case 3:
        score+=500;
        break;
    default:
        break;
    }
    score = score + MoveDownPoints;
}
