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

class Obstacles{
    public:
        float x, y;
        float radius;
        int speed_y;
    void Draw(){
        DrawCircle(x,y,radius,WHITE);
    }

    void Update(){
       
        y+=speed_y;
    }    
    
};

Player p1;
Obstacles O1;


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

    // Obstacles Properties
    O1.speed_y = 7;
    O1.radius = 25 + rand()% (40-25)+1;

    int xMin = 60+O1.radius;
    int xMax = ((780-O1.radius) - xMin) +1;

    int yMin = O1.radius;
    int yMax = ((screen_height-250)-yMin)+1;

    O1.x = xMin + rand()% ((xMax-xMin)+1);
    O1.y = yMin + rand()% ((yMax-yMin)+1);



    // game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawLine(60,0,60,600,WHITE);
        DrawLine(740,0,740,600,WHITE);
        DrawLine(0,screen_height-250,screen_width,screen_height-250,WHITE);
        if(O1.y+O1.radius>=GetScreenHeight()-250){
            O1.x = xMin + rand()% ((xMax-xMin)+1);
            O1.y = yMin + rand()% ((yMax-yMin)+1);
        }


        p1.Update();
        O1.Update();

        O1.Draw();
        p1.Darw();


        EndDrawing();
    }

    // close window
    CloseWindow();




    return 0;
}