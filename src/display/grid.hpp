#ifndef ECOSYSTEMSIMULATION_GRID_HPP
#define ECOSYSTEMSIMULATION_GRID_HPP

#include "config.hpp"


enum class Element {
    VOID,  PLANT, PREY, PREDATOR
};


class Grid {

public:
    Grid();

    void updateSimulation();

    void display(sf::RenderWindow& window);

    void changePause();

    void displayStats() const;

private:
    static bool _isInBounds(const Vector2& position);

    void _updateElements();

    bool _isRunning { false };

    sf::Texture _texture;
    std::vector<sf::Uint8> _pixels;
    sf::Sprite _sprite;

    const int RADIUS { 10 };

    bool _isMouseClicking { false };

    std::vector<std::vector<float>> _densityField;

    std::vector<std::vector<Element>> _oldMap;
    std::vector<std::vector<Element>> _map;
};


#endif //ECOSYSTEMSIMULATION_GRID_HPP
