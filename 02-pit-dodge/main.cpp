#include "raylib.h"


    struct Pit{int x;
        int z; 
        bool triggered;
    };


int main(){

    InitWindow(800, 600, "My First Game");// the page size
    SetTargetFPS(60);

        Pit pits[5]; // 5 hidden holes
        for(int i=0; i<5; i++){
        pits[i].x =GetRandomValue(-4, 4) * 2; //same grid as the cube
        pits[i].z =GetRandomValue(-4, 4) * 2; //same grid as the cube
        pits[i].triggered = false; //makes sure no pit spawns exact on 0,0 where you strt
        if(pits[i].x == 0 && pits[i].z == 0)pits[i].x =8;
    }

        float x=0; //remember x first before we start //aslo left and right keys
        float y=1;//up and down keys
        float z=0;
        bool gameOver = false;

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

    for(auto & p:pits){
        if(cubeX === p.x && cubeZ == p.z){
            p.triggered = true;// GAME OVER LOGIC
            gameOver=true;

            }
        }
     }

     //I'll update camera to follow cube 
        camera.target ={x, 0, z};

        BeginDrawing();//start at the edge
                ClearBackground(SKYLUE);
                BeginMode3D(camera);
                   //Draw ground
                   DrawPlane ((Vector3){0, 0, 0}, (Vector2){20,20} LIGHTGRAY);

                   for( auto &p:pits){
                    if(triggered){
                        DrawCube({(float)p.x, -0.5f, (float)p.z}2, 1, 2, BLACK);// deep hole 
                    }
                    //else draw nothing -player can't see anything
                   }
                   //if cube falls down game over
                   if(gameOver) DrawCube({x, -0.5f, z}, 1, 1, 1, RED);
                   else DrawCube ({x,y,z}, 1, 1, 1, YELLOW);
                   DrawCube((Vector3){ x, 1, z}, 2, 2, 2, YELLOW); //THE CUBE AT X, Z
                   DrawGrid(20, 1.0f); //floor so I see the depth
                   
                   EndMode3D();

                   if( gameOver )DrawText("YOU FELL!", 320, 20, 30), RED};
                        else DrawText("Dodge the invisible pits", 10, 10, 20, DARKGRAY);

                        EndDrawing();
                }
    CloseWindow();
    return 0;
    } 