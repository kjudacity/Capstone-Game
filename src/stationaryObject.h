#ifndef STATION_H
#define STATION_H

#include <vector>
#include "SDL.h"

// Define a generic stationary object (assume single point)
class StationaryObject{
 public:
  StationaryObject(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height) {}

  ~StationaryObject() {};
  StationaryObject() {};

  virtual std::vector<SDL_Point> GetLocation() { return objectLocation; } // getter function

  virtual void SetLocation(int x, int y) {
    SDL_Point objectLocation{ static_cast<int>(x), static_cast<int>(y) }; 
  }; // setter function
  
  virtual bool Occupied(int x, int y) {
    for (auto const &item : objectLocation) {
      if (x == item.x && y == item.y) {
        return true;
      }
    }
    return false;
  }

 protected:
  std::vector<SDL_Point> objectLocation;
  int grid_width;
  int grid_height;
};

// Define Wall object
// extend definition for vector of points
class Wall: public StationaryObject {
  public:
    Wall(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height) {}
    Wall() {};
    ~Wall() {};
    std::vector<SDL_Point> wallLocation;
    std::vector<SDL_Point> GetLocation() { return wallLocation; }
    void SetLocation(int x, int y); // setter function
    bool Occupied(int x, int y);

  private:
    int wallBottomX{0};
    int wallTopX;
    int wallBottomY{0};
    int wallTopY;
    int grid_width;
    int grid_height;
};

// class Food: public Object {
  
// }

// class Obstacle: public Object {
//   public:

// }
#endif