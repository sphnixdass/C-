//https://www.youtube.com/watch?v=XqJRm9uxKjo
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    std::cout << "Hi \x4dO\115!\n";
    std::cout<<"Who goes with F\145rgus?\012"<<std::endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}