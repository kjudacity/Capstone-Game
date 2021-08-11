#include "game.h"
#include <iostream>
#include "SDL.h"

// Initialize game parameters
Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      wall(grid_width, grid_height), // initialize wall object
      food(), // initialize food object
      obstacles(), //initialize obstacle objects
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1))  {
        PlaceFood();
      }

// Run the game (no changes)
void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, wall, obstacles);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

// Updated place food to use new find clear location function
void Game::PlaceFood() {
  food.SetPoint(Game::FindClearLocation());
}

// new function that checks to ensure a space doesn't contain the snake, food, the wall, or obstacles
SDL_Point Game::FindClearLocation() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake or wall item before placing
    // food or obstacle.
    if (!snake.SnakeCell(x, y) && !wall.Occupied(x, y) && !obstacles.Occupied(x,y) && !food.Occupied(x,y)) {
      SDL_Point freepoint{ static_cast<int>(x), static_cast<int>(y)};
      return freepoint;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
    if (food.GetLocation().at(0).x == new_x && food.GetLocation().at(0).y == new_y) {
    score++;
    PlaceFood();

    //Add an obstacle every third level
    if (score % 3 == 0 && score > 1) {
      obstacles.SetPoint(Game::FindClearLocation());
    }

    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
  // Check if snake contected wall or obstacles
  if (wall.Occupied(new_x, new_y) || obstacles.Occupied(new_x, new_y)) {
    snake.alive = false;  //snake dies if it did
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }