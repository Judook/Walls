#include <iostream>
#include <cmath> 
using namespace std;

struct Vec2 {
    float x, y;
};

float degToRad(float degAngle) {
    const double pi = 3.14159265358979323846264338327950288419716939937510;
    float radAngle;
    radAngle = (pi/18.0) * degAngle;
    return radAngle;
}

Vec2 march(Vec2 pos, float angle, char world[20][30]) {
    float marchVector;
    Vec2 hitPos;
    int checkX, checkY;
    // The actual marching of the ray
    for(marchVector = 0; marchVector <= 30; marchVector++) {
        checkX = (int)round((float)pos.x + marchVector*sin(degToRad(angle)));
        checkY = (int)round((float)pos.y + marchVector*cos(degToRad(angle)));
        // Checking if the world has that specific spot as a '#'(Wall)
        if(world[checkY][checkX] == '#') {
            hitPos = {(float)checkX, (float)checkY};
            break;
        }
    }
    return hitPos;
}

int main() {
    char world[20][30] = {
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        ".............................", 
        "#############################"
    };
    Vec2 playerPos = {10.0f, 20.0f};
    float playerAngle = 0.0f;
    float playerFOV = 60.0f;

    
    return 0;
}