#include <raylib.h>
#include<iostream>
#include "game.h"
using namespace std;

double lastUpdateTime = 0;
bool eventTriggered(double interval) {  
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) { 
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main(){
    Color darkBlue = {44,44,127,255};
    InitWindow(500,620, "raylib tetris");
    SetTargetFPS(60);

    // Grid grid = Grid();
    // grid.grid[0][0]=1;

    // IBlock block = IBlock();
    // block.Move(4,3); 

    Game game = Game();

    while(!(WindowShouldClose())){
         if (eventTriggered(0.3)) {
                // game.Update();
                game.MoveBlockDown();
            }
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);
        // grid.Draw();
        // block.Draw();
        
        DrawText("Score",355,15,38,WHITE);
        DrawText("Next",365,175,38,WHITE);
        if(game.gameOver){
            DrawText("Game Over",320,450,32,WHITE);
        }
        DrawRectangleRounded({320,55,170,60}, 0.3,6,{59,85,162,255}); //last {} is defining light blue color //to display score in it
       //-----------------To keep the score text centered even if tis 1 or 10000-------
        char scoreText[10];
        sprintf(scoreText, "%d", game.score); //score text holds score value
        int textSize = MeasureText(scoreText,38); //returns width
        DrawText(scoreText, 320+(170-textSize)/2 , 65 , 38, WHITE);
       
        DrawRectangleRounded({320,215,170,180}, 0.3,6,{59,85,162,255});
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}




//hmne block floor hit hone p uski id grid cells mm store krali or new block generate rkdia, phr next block n dekha k grid cell 0 h
//ya kuch or, agr kuch or to neche na ja paye wohin lock hojaye. iske lie block fits or is cell empty use kia







//---------------------------SNAKE GAME----------------------------------------
// #include<iostream>
// #include <raylib.h> 
// #include <deque> //double-ended queue where elements can be inserted or removed easily
// #include<raymath.h> // to perform vector sum
// using namespace std;

// Color green ={173, 204, 96, 255};
// Color darkGreen ={43, 51, 24, 255};


//     int cellSize = 30; //grid
//     int cellCount = 25;

    
//     enum GameState {
//         MENU,
//         PLAYING,
//         GAME_OVER,
// };
// GameState currentState = PLAYING;

// //----to slow down snake.
//     double lastUpdatetime = 0;    
//     bool eventTriggered(double interval){              //we passed 0.2 to interval.

//         double currentTime = GetTime();
//         if(currentTime-lastUpdatetime >= interval)     //to check if specific time has passed
//         {
//             lastUpdatetime=currentTime;
//             return true;
//         }
//         return false;
//     }

// //----to spawn food in other cells than snake
//     bool ElementInDeque(Vector2 element, deque<Vector2> snakeBody){ //element in deque is userdefined fucntion provided by user in github,it checks for the presence of certain element in deque of snake game
//         for( unsigned int i=0; i<snakeBody.size(); i++){
//             if(Vector2Equals(snakeBody[i],element)){
//                 return true;
//             }
//         }
//         return false;
//     }

// class Snake{

//     public:
//     deque<Vector2> body = {Vector2{6,9},Vector2{5,9},Vector2{4,9}};       //deque is like array but we can add and remove things from its start and end efficiently, deque<Vector2> tells us that deque will store Vector2.
//     Vector2 direction  = {1,0};                                          
//     bool addSegment = false;

//     void Draw(){
//         for(unsigned int i=0; i < body.size(); i++){                      //deque gives a predefined size method which returns the number of elements it contains.
//             float x = body[i].x;                                          //to get the x and y coordinates of each segment i
//             float y = body[i].y;
//             Rectangle segment = Rectangle{x*cellSize, y*cellSize, (float)cellSize, (float)cellSize}; //dont need to turn into float but compiler shows warning so..
//             DrawRectangleRounded(segment, 0.5, 6, darkGreen);             //(Rectangke rec(type), float roundness , int segments, Color color)
//         }
//     }

//     void Update(){                                                        //to change position
//         if(addSegment == true){                                           //snake gets bigger when eat
//             body.push_front(Vector2Add(body[0],direction));
//             addSegment = false;

//         }else{
//             body.pop_back();                                                  //removes one element from end
//             body.push_front(Vector2Add(body[0], direction));                  //adds a new value at the start of snake
    
//         }
        
//     }
//     void Reset(){
//         body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
//         direction = {1,0};
//     }
// };

// class Food{

//     public:
//         Vector2 position; //fixes positon in x y coordinates
//         Texture2D texture; //texture class to give texture

//         Food(deque<Vector2> snakeBody){             //constructor so that image loads when food is created
//             Image image = LoadImage("Graphics/apple2.png");
//             ImageResize(&image, cellSize, cellSize); // FORCE size
//             texture = LoadTextureFromImage(image);
//             UnloadImage(image);
//             position = GenerateRandomPos(snakeBody);  //snake body given to genrandompos function 
//         }
//         ~Food(){ //destructor, to  save memory
//             UnloadTexture(texture);
//         }

//         void Draw(){
//             //Apple
//             DrawTexture(texture,position.x*cellSize, position.y*cellSize, WHITE);
//         }

// //----to generate random position of apple
//         Vector2 GenerateRandomCell(){
//             float x = GetRandomValue(0, cellCount-1); //cel; 25 hn to -1 take bounf=dry k andr andr
//             float y = GetRandomValue(0, cellCount-1);
//             return Vector2{x,y};
//         }

//         Vector2 GenerateRandomPos(deque<Vector2> SnakeBody){
//             Vector2 position = GenerateRandomCell();

//             while (ElementInDeque(position,SnakeBody)){     //take snake of food ki position same na a jaye to position vector or snake vector ko function m bheja, agr position same hojaye to generate another random pos
//                 position = GenerateRandomCell();
//             }
//             return position;
//         }

// };

// class Game{

//     public:
//         Snake snake = Snake();
//         Food food = Food(snake.body);
//         bool running = true;            //if gameover, it gets false and then when user press a key it gets true so snake moves when userpress key.

//     void Draw(){
//         food.Draw();
//         snake.Draw();
//     }
//     void Update(){
//         if(running){
//         snake.Update();
//         CheckCollisionWithFood();
//         CheckCollisionWithEdges();
//         CheckCollisionWithTail();
//         }
//     }
//     void CheckCollisionWithFood(){
//         if(Vector2Equals(snake.body[0], food.position)){        //if snake's head and food have same position
//             food.position = food.GenerateRandomPos(snake.body);
//             snake.addSegment = true;       //snake gets bgger when eat
//         }   
//     }
//     void CheckCollisionWithEdges(){
//         if(snake.body[0].x == cellCount || snake.body[0].x == -1){ //agr snake ka head right side boundry ko touch ya left side boundary (-1 left boundary cuz plane waha s start hota h)
//             GameOver();
//         }
//         if(snake.body[0].y == cellCount || snake.body[0].y == -1){
//             GameOver();
//         }
//     }
//     void CheckCollisionWithTail(){
//         deque<Vector2> headlessBody = snake.body;
//         headlessBody.pop_front(); //removes head from snake's body
//         if(ElementInDeque(snake.body[0],headlessBody)){
//             GameOver();
//         }
//     }
//     void GameOver(){
//         currentState = GAME_OVER;
//         running = false;
//     }
// };

// int main() 
// {
//     InitWindow(cellSize*cellCount, cellSize*cellCount , "Retro Snake"); //to set size of window
//     SetTargetFPS(60); //refresh rate, smooth

//     Game game = Game(); 

//     while(WindowShouldClose()==false){
//         if(currentState==PLAYING){

//         if(eventTriggered(0.2)){        //agr event ko trigger hue we 0.2 sec ho gye hn to snake move ho
//             game.Update();             //too fast movement bcz of 60fps so we slow it down.
//         }
        

//         //snake controls
//         if(IsKeyPressed(KEY_UP) && game.snake.direction.y!=1){  //and condition take backwards move na kre snake
//             game.snake.direction={0,-1};   //-1 cuz our plane starts from up. so to go up we minus the y coordinate.
//             game.running = true;
//         }
//         if(IsKeyPressed(KEY_DOWN) && game.snake.direction.y!=-1){
//             game.snake.direction={0,1};     //1 down in y axis
//              game.running = true;
//         }
//         if(IsKeyPressed(KEY_LEFT) && game.snake.direction.x!=1){
//             game.snake.direction={-1,0};
//              game.running = true;
//         }
//         if(IsKeyPressed(KEY_RIGHT) && game.snake.direction.x!=-1){
//             game.snake.direction={1,0};
//             game.running = true;
//         }
//         }
//         else if (currentState == GAME_OVER) {
//             if (IsKeyPressed(KEY_ENTER)) {
//                 game.snake.Reset();
//                 game.food.position = game.food.GenerateRandomPos(game.snake.body);
//                 currentState = PLAYING;
//             }
//         }
        
//         //Drawing
//         BeginDrawing();
//         ClearBackground(green);
//         if(currentState==PLAYING){
//         game.Draw();
//     }
//          else if (currentState == GAME_OVER) {
//             DrawText("GAME OVER", 250, 200, 40, RED);
//             DrawText("Press ENTER To Play again", 235, 320, 20, GRAY);
//         }
//         EndDrawing();
//     }

//     CloseWindow();
//     return 0;
// }







