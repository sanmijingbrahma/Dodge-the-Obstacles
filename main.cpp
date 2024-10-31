#include <iostream>
#include <raylib.h>
using namespace std;


class Player{
    public:
        int height;
        int width;
        int x, y;
        int speed;
    void Darw(){
        DrawRectangle(x,y,width,height,WHITE);
    }

    void Update(){
        if(IsKeyDown(KEY_LEFT)){
            x-=speed;
        }
        if(IsKeyDown(KEY_RIGHT)){
            x+=speed;
        }
        if(x+width>=GetScreenWidth()-60){
            x=(GetScreenWidth()-60)-width;
        }
        if(x<=60){
            x=60;
        }
    }
};

Player p1;


int main(){
    const int screen_width = 800;
    const int screen_height = 600;
    const string name = "Dodge the obstacles!";

    // initialize the window
    InitWindow(screen_width,screen_height,name.c_str());
    SetTargetFPS(60);


    // Player Properties
    p1.speed = 6;
    p1.width = 25;
    p1.height = 25;
    p1.x= 66;
    p1.y = GetScreenHeight()-25;


    // game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawLine(60,0,60,600,WHITE);
        DrawLine(740,0,740,600,WHITE);
        DrawLine(0,screen_height-250,screen_width,screen_height-250,WHITE);
        p1.Update();


        p1.Darw();


        EndDrawing();
    }

    // close window
    CloseWindow();




    return 0;
}