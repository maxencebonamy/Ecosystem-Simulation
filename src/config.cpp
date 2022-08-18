#include "config.hpp"


const Vector2 WINDOW_SIZE { 1280, 720 };
const std::string WINDOW_TITLE { "Ecosystem Simulation" };
const int WINDOW_FPS { 60 };
const sf::Color WINDOW_COLOR { 4, 8, 41 };

const float CELL_SIZE { 5 };
const Vector2 GRID_SIZE { WINDOW_SIZE / CELL_SIZE };


const float PLANT_RATE { 0.01 };
const sf::Color PLANT_COLOR { 3, 206, 14 };

const float PREY_RATE { 0.02 };
const sf::Color PREY_COLOR { 254, 255, 255 };

const float PREDATOR_RATE { 0.02 };
const sf::Color PREDATOR_COLOR { 246, 30, 11 };