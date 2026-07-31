#include "block.h"


//to initialize some values
Block::Block(){

    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    // to move the block, we make an axis that we can mmove wo that whole block move with it
    rowOffset = 0;
    columnOffset = 0;
}


//doing the same thing we did in grid to define color. now we define color of blocks
vector<Color> Block::GetCellColors(){
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

//Drawing blocks

void Block::Draw(int offsetX, int offsetY){

    // vector<Position> tiles = cells[rotationState]; pehle y tha movement s pehle
    vector<Position> tiles = GetCellPositions();  
    for(Position item: tiles){ //position k item ki hr tiles tk loop

        DrawRectangle(item.column*cellSize + offsetX, item.row*cellSize + offsetY,cellSize-1,cellSize-1,colors[id]); //x,y,w,h,color , offset ki value 11 di h cuz grd ko bhi 11 s offset kia tha
    } 
}

//movement, riw offset ko jo hi value pass krenge(move) wo orignal wo and column m plus(getcellpos), or phir updated value ko draw upr
void Block::Move(int rows, int columns){

    rowOffset+=rows;
    columnOffset+=columns;
}

vector<Position> Block::GetCellPositions(){

    vector<Position> tiles = cells[rotationState]; //cell pos for current rot state
    vector<Position> movedTiles; //empty vector
    for(Position item: tiles){ //all tils will be iterated
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset); //add the offset to tiles position
        movedTiles.push_back(newPos);
    }
    return movedTiles;
 }

 void Block::Rotate()
 {
    rotationState++;
    if(rotationState == (int)cells.size()){
        rotationState = 0;
    }
 }

 void Block::UndoRotate()
 {
    rotationState--;
    if(rotationState==  -1){
        rotationState= cells.size()-1; //max value 
    }
 }
