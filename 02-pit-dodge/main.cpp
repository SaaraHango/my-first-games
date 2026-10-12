#include "raylib.h"


    struct Pit{int x,z; bool triggered;};
    Pit pits[5]; // 5 hidden holes

int main(){

    InitWindow(800, 600, "My First Game");// the page size
    SetTargetFPS(60);
     
        for(int i=0; i<5; i++){
        pits[i].x =GetRandomValue(-4, 4) * 2; //same grid as the cube
        pits[i].z =GetRandomValue(-4, 4) * 2; //same grid as the cube
        pits[i].triggered = false; //makes sure no pit spawns exact on 0,0 where you strt
        if(pits[i].x == 0 && pits[i].z == 0)pits[i].x =8;
    }
    for(auto & p:pits){
        if(cubeX === p.x && cubeZ == p.z){
            p.triggered = true;// GAME OVER LOGIC
            gameOver=true;

        }
    }
    
    
    float x=0; //remember x first before we start //aslo left and right keys
    float y=0;//up and down keys

    // for 3D
    float z=0;// forward/backward motion
    //for three 3D movements we use z
    Camera3D camera = { 0 };
    camera.position=(Vector3){ 10, 10, 10}; //wherw my camera stands 
    camera.target =(Vector3){ 0, 0, 0}; //what it looks at
    camera.up= (Vector3){ 0, 1, 0}; //which way is up
    camera.fovy = 45;
    camera.projection = CAMERA_PERSPECTIVE;
    while (!WindowShouldClose()){
        if (IsKeyDown(KEY_RIGHT)){
            x=x+0.1f;
        }
        if(IsKeyDown(KEY_LEFT)){
            x=x-0.1f;
        }
        if(IsKeyDown(KEY_UP)){
            z=z-0.1f;
        }
        if(IsKeyDown(KEY_DOWN)){
            z=z+0.1f;
        }
        //if (text  is off thr right side){put it back to  start}
        //loops forever
        BeginDrawing();//start at the edge
                ClearBackground(BLUE);
                BeginMode3D(camera);
                   //Draw ground
                   DrawPlane ((Vector3){0, 0, 0}, (Vector2){20,20} LIGHTGRAY);
                   DrawCube((Vector3){ x, 1, z}, 2, 2, 2, YELLOW); //THE CUBE AT X, Z
                   DrawGrid(20, 1.0f); //floor so I see the depth
                   EndMode3D();
                   DrawText("Use your arrows now - NOW IN 3D!", 10, 10, 20, WHITE);
                   EndDrawing();
    }
    CloseWindow();
    return 0;
    } 