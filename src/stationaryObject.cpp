#include "stationaryObject.h"
#include <cmath>
#include <iostream>

#include <vector>
#include "SDL.h"


// Check location is occupied by Object

void Wall::SetLocation(int x, int y) { //can used if we want the box to be different than the window
    wallTopX = x;
    wallTopY = y;

    SDL_Point point;

    // loop through the top/bottom note: subtract one or you end up offscreen
    for (size_t k = 0; k < wallTopX-1; k++)
    {
        point.x = k;
        point.y = 0;
        wallLocation.push_back(point);
        point.x = k;
        point.y = wallTopY-1; 
        wallLocation.push_back(point);
    }

    // loop through the sides note: subtract one or you end up offscreen
    for (size_t k = 1; k < wallTopY-1; k++)
    {
        point.x = 0;
        point.y = k;
        wallLocation.push_back(point);
        point.x = wallTopX-1;
        point.y = k;
        wallLocation.push_back(point);
    }
}


bool Wall::Occupied(int x, int y) {
  if (x == 0 || x == wallTopX-1|| y == 0 || y == wallTopY-1) {
    return true;
  }
  return false;
}

