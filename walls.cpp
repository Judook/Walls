#include <iostream>
#include <cmath> 
#include <array>
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

int march(Vec2 pos, float angle, char world[20][30]) {
    int marchVector;
    int checkX, checkY;
    // The actual marching of the ray
    for(marchVector = 0; marchVector <= 30; marchVector++) {
        checkX = (int)round((float)pos.x + marchVector*sin(degToRad(angle)));
        checkY = (int)round((float)pos.y + marchVector*cos(degToRad(angle)));
        // Checking if the world has that specific spot as a '#'(Wall)
        if(world[checkY][checkX] == '#') {
            break;
        }
    }
    return marchVector;
}

array<int, 100> scan (float playerAngle, float fov, Vec2 pos, char world[20][30]) {
    float piece = fov/100;
    int i;
    array<int, 100> out = {};
    float scanAngle;
    for(scanAngle = playerAngle - fov/2, i=0; scanAngle <= playerAngle + fov/2; scanAngle += piece, i++) {
        out[i] = march(pos, scanAngle, world);
    }
    return out;
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
    
    array<int, 100> a = scan(180.0f, 90.0f, playerPos, world);
    for(int i=0; i<100; i++) cout<<a[i]<<" ";

    return 0;
}
