#include "display/grid.hpp"


int main() {
    sf::VideoMode videoMode { (unsigned int)WINDOW_SIZE.getX(), (unsigned int)WINDOW_SIZE.getY() };
    sf::RenderWindow window(videoMode, WINDOW_TITLE, sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(WINDOW_FPS);

    sf::Image icon;
    icon.loadFromFile("res/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Grid grid;

    while (window.isOpen()) {
        sf::Event event {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            else if (event.type == sf::Event::MouseButtonPressed &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left))
                grid.changePause();
            else if (event.type == sf::Event::MouseButtonPressed &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Right))
                grid.displayStats();
        }

        grid.updateSimulation();

        window.clear();
        grid.display(window);
        window.display();
    }

    return EXIT_SUCCESS;
}