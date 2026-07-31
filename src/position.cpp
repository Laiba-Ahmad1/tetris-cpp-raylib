#include "position.h"

//to rpresent positon on grid with a single object
Position::Position(int row, int column){

    this->row=row; //this is used when name conflicts between obj name and parameter
    this->column=column;
}