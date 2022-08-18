#include "display/grid.hpp"


Grid::Grid() {
    const int WIDTH { static_cast<int>(GRID_SIZE.getX()) },
              HEIGHT { static_cast<int>(GRID_SIZE.getY()) };

    _texture.create(WIDTH, HEIGHT);
    for (int i { 0 }; i < WIDTH * HEIGHT * 4; ++i) _pixels.push_back(255);
    _texture.update(_pixels.data());

    _sprite.setTexture(_texture);
    _sprite.setScale(CELL_SIZE, CELL_SIZE);

    for (int i { 0 }; i < WIDTH; ++i) {
        _map.emplace_back();
        for (int j { 0 }; j < HEIGHT; ++j) {
            float randomNumber { static_cast<float>(rand() % 100) / 100.f };
            if (randomNumber < PLANT_RATE) _map[i].emplace_back(Element::PLANT);
            else if (PLANT_RATE <= randomNumber && randomNumber < PLANT_RATE + PREY_RATE) _map[i].emplace_back(Element::PREY);
            else if (PREY_RATE <= randomNumber && randomNumber < PLANT_RATE + PREY_RATE + PREDATOR_RATE) _map[i].emplace_back(Element::PREDATOR);
            else _map[i].emplace_back(Element::VOID);
        }
    }
}

void Grid::updateSimulation() {
    if (_isRunning) _updateElements();

    sf::Uint8* ptr { _pixels.data() };
    for (int j { 0 }; j < static_cast<int>(GRID_SIZE.getY()); ++j) {
        for (int i { 0 }; i < static_cast<int>(GRID_SIZE.getX()); ++i) {
            Element element { _map[i][j] };

            sf::Color color;
            if (element == Element::PLANT) color = PLANT_COLOR;
            else if (element == Element::PREY) color = PREY_COLOR;
            else if (element == Element::PREDATOR) color = PREDATOR_COLOR;
            else color = WINDOW_COLOR;

            if (color != sf::Color(*ptr, *(ptr+1), *(ptr+2))) {
                *ptr++ = color.r;
                *ptr++ = color.g;
                *ptr++ = color.b;
                ++ptr;
            }
            else {
                ptr += 4;
            }
        }
    }

    _texture.update(_pixels.data());
    _sprite.setTexture(_texture);
}

void Grid::display(sf::RenderWindow& window) {
    window.draw(_sprite);
}

bool Grid::_isInBounds(const Vector2& position) {
    return position.getX() >= 0 && position.getX() < GRID_SIZE.getX() &&
           position.getY() >= 0 && position.getY() < GRID_SIZE.getY();
}

void Grid::changePause() {
    _isRunning = !_isRunning;
}

void Grid::_updateElements() {
    _oldMap = _map;

    for (int x { 0 }; x < GRID_SIZE.getX(); ++x) {
        for (int y { 0 }; y < GRID_SIZE.getY(); ++y) {
            Element element { _oldMap[x][y] };

            for (int i { -1 }; i <= 1; ++i) {
                for (int j { -1 }; j <= 1; ++j) {
                    if ((i != 0 || j != 0) && _isInBounds(Vector2(x + i, y + j))) {
                        Element newElement { _oldMap[x + i][y + j] };

                        // Propagation des plantes
                        if (element == Element::PLANT && newElement == Element::VOID && !(rand() % 100)) {
                            _map[x + i][y + j] = element;
                        }

                        if (element == Element::PREY) {
                            // Les proies mangent les plantes
                            if (newElement == Element::PLANT) {
                                if (!(rand() % 10)) {
                                    _map[x + i][y + j] = element;
                                    // Les proies qui mangent beaucoup se reproduisent
                                    if (rand() % 5) _map[x][y] = Element::VOID;
                                }
                            }

                            // Les proies qui ne mangent pas pendant trop longtemps meurent
                            else if (!(rand() % 200)) {
                                _map[x][y] = Element::VOID;
                            }
                        }

                        if (element == Element::PREDATOR) {
                            // Les prédateurs mangent les proies
                            if (newElement == Element::PREY) {
                                if (!(rand() % 5)) {
                                    _map[x + i][y + j] = element;
                                    // Les prédateurs qui mangent beaucoup se reproduisent
                                    if (rand() % 2) _map[x][y] = Element::VOID;
                                }
                            }

                            // Les prédateurs qui ne mangent pas pendant trop longtemps meurent
                            else if (!(rand() % 1000)) {
                                _map[x][y] = Element::VOID;
                            }
                        }

                    }
                }
            }
        }
    }
}

void Grid::displayStats() const {
    float totalElements { GRID_SIZE.getX() * GRID_SIZE.getY() };

    int plantsNumber { 0 };
    int preysNumber { 0 };
    int predatorsNumber { 0 };

    for (auto& line: _map) {
        for (auto& element: line) {
            if (element == Element::PLANT) ++plantsNumber;
            else if (element == Element::PREY) ++preysNumber;
            else if (element == Element::PREDATOR) ++predatorsNumber;
        }
    }

    std::cout << "Plants Rate : " << static_cast<float>(plantsNumber * 100) / totalElements << "%" << std::endl;
    std::cout << "Preys Rate : " << static_cast<float>(preysNumber * 100) / totalElements << "%" << std::endl;
    std::cout << "Predators Rate : " << static_cast<float>(predatorsNumber * 100) / totalElements << "%" << std::endl;
    std::cout << std::endl;
}
