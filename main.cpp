#include <iostream>
#include <raylib.h>
using namespace std;





int main(){
    const int screen_width = 800;
    const int screen_height = 600;
    const string name = "Dodge the obstacles!";

    // initialize the window
    InitWindow(screen_width,screen_height,name.c_str());



    // game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);


        EndDrawing();
    }

    // close window
    CloseWindow();




    return 0;
}