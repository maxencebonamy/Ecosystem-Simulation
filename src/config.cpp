#include "config.hpp"


// The dimensions of the window (in pixels)
const Vector2 WINDOW_SIZE { 1280, 720 };
// The name of the simulation window
const std::string WINDOW_TITLE { "Ecosystem Simulation" };
// The number of images displayed per second
const int WINDOW_FPS { 60 };
// The background color of the window
const sf::Color WINDOW_COLOR { 4, 8, 41 };

// The length of the side of a cell (in pixels)
const float CELL_SIZE { 5 };
// The dimensions of the grid (in pixels)
const Vector2 GRID_SIZE { WINDOW_SIZE / CELL_SIZE };

// The rate of plants at the beginning in the grid
const float PLANT_RATE { 0.01 };
// The color of the plant type cells
const sf::Color PLANT_COLOR { 3, 206, 14 };

// The rate of preys at the beginning in the grid
const float PREY_RATE { 0.02 };
// The color of the prey type cells
const sf::Color PREY_COLOR { 254, 255, 255 };

// The rate of predators at the beginning in the grid
const float PREDATOR_RATE { 0.02 };
// The color of the predator type cells
const sf::Color PREDATOR_COLOR { 246, 30, 11 };