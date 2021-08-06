#ifndef STATION_H
#define STATION_H

#include <vector>
#include "SDL.h"

// Define a generic stationary object (assume single point)
class Object {
 public:
 
  Object(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height) {}

  virtual SDL_Point GetLocation() {return objectLocation;} // getter function
  virtual void SetLocation(int x, int y); // setter function
  
  virtual bool Occupied(int x, int y);

 protected:
  SDL_Point objectLocation;
  int grid_width;
  int grid_height;
};

// Define Wall object
// extend definition for vector of points
class Wall: public Object {
  public:
      Wall(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height), {
          SetLocation(grid_width, grid_height); 
          }
    
    std::vector<SDL_Point> wallLocation;
    std::vector<SDL_Point> GetLocation() { return wallLocation; }
    void SetLocation(int x, int y); // setter function

  private:
    int wallBottomX{0};
    int wallTopX;
    int wallBottomY{0};
    int wallTopY;
}

// class Food: public Object {
  
// }

// class Obstacle: public Object {
//   public:

// }
#endif