#ifndef ECOSYSTEMSIMULATION_CONFIG_HPP
#define ECOSYSTEMSIMULATION_CONFIG_HPP

#include "vector/vector2.hpp"


// The dimensions of the window (in pixels)
extern const Vector2 WINDOW_SIZE;
// The name of the simulation window
extern const std::string WINDOW_TITLE;
// The number of images displayed per second
extern const int WINDOW_FPS;
// The background color of the window
extern const sf::Color WINDOW_COLOR;

// The length of the side of a cell (in pixels)
extern const float CELL_SIZE;
// The dimensions of the grid (in pixels)
extern const Vector2 GRID_SIZE;

// The rate of plants at the beginning in the grid
extern const float PLANT_RATE;
// The color of the plant type cells
extern const sf::Color PLANT_COLOR;

// The rate of preys at the beginning in the grid
extern const float PREY_RATE;
// The color of the prey type cells
extern const sf::Color PREY_COLOR;

// The rate of predators at the beginning in the grid
extern const float PREDATOR_RATE;
// The color of the predator type cells
extern const sf::Color PREDATOR_COLOR;


#endif //ECOSYSTEMSIMULATION_CONFIG_HPP