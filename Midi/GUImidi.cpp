// g++ -c GUImidi.cpp
// g++ GUImidi.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string> 
#include <unistd.h>

sf::Mutex mutex;
sf::Sprite spritea;
sf::Sprite sprite;
sf::Sprite sprite2;
sf::Sprite sprite3;

sf::Sprite spriteb;
sf::Sprite spriteb1;
sf::Sprite spriteb2;
sf::Sprite spriteb3;

sf::Texture texture;
sf::Text text;
sf::Text textb;
sf::Font font;

int leftIni = 372;
int leftRepeat = 16;
int rectTop = 460;
int rectWidth = 18;
int rectHeight = 60;

int leftInib = 132;

int rand1 = 1;
int rand2 = 2;
int rand3 = 3;

int rand1b = 1;
int rand2b = 2;
int rand3b = 3;

std::string textFunc(int randt)
{
    std::string tempstr = " ";

    if (randt == 1){
        tempstr = "C";
    } else if (randt == 2)
    {
        tempstr = "D";
    }else if (randt == 3)
    {
        tempstr = "E";
    }else if (randt == 4)
    {
        tempstr = "F";
    }else if (randt == 5)
    {
        tempstr = "G";
    }else if (randt == 6)
    {
        tempstr = "A";
    }else if (randt == 7)
    {
        tempstr = "B";
    }else if (randt == 8)
    {
        tempstr = "C";
    }else if (randt == 9)
    {
        tempstr = "D";
    }else if (randt == 10)
    {
        tempstr = "E";
    }else if (randt == 11)
    {
        tempstr = "F";
    }else if (randt == 12)
    {
        tempstr = "G";
    }else if (randt == 13)
    {
        tempstr = "A";
    }else if (randt == 14)
    {
        tempstr = "B";
    }
    else {
        tempstr = " ";
    }

    return tempstr;
}

std::string textFuncb(int randt)
{
    std::string tempstr = " ";

    if (randt == 1){
        tempstr = "C";
    } else if (randt == 2)
    {
        tempstr = "D";
    }else if (randt == 3)
    {
        tempstr = "E";
    }else if (randt == 4)
    {
        tempstr = "F";
    }else if (randt == 5)
    {
        tempstr = "G";
    }else if (randt == 6)
    {
        tempstr = "A";
    }else if (randt == 7)
    {
        tempstr = "B";
    }else if (randt == 8)
    {
        tempstr = "C";
    }else if (randt == 9)
    {
        tempstr = "D";
    }else if (randt == 10)
    {
        tempstr = "E";
    }else if (randt == 11)
    {
        tempstr = "F";
    }else if (randt == 12)
    {
        tempstr = "G";
    }else if (randt == 13)
    {
        tempstr = "A";
    }else if (randt == 14)
    {
        tempstr = "B";
    }
    else {
        tempstr = " ";
    }

    return tempstr;
}


// void makeWindowOnTop(sf::RenderWindow& window)
// {
//         HWND hwnd = window.getSystemHandle();
//         SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
// }

void ranFunc()
{
    // mutex.lock();
    // this function is started when thread.launch() is called

    // srand(time(0));
    rand1 = rand2;
    rand2 = rand3;
    rand3 = (rand() % 14 + 1);

    rand1b = rand2b;
    rand2b = rand3b;
    rand3b = (rand() % 14 + 1);

    // std::cout << "Random function called" + std::to_string(rand1) + std::to_string(rand2) + std::to_string(rand3) <<std::endl; 
    // mutex.unlock();
    spritea.setTexture(texture);    
    spritea.setTextureRect(sf::IntRect(366, 464, 30, 60));
    spritea.setPosition(0,0);

    sprite.setTexture(texture);    
    sprite.setTextureRect(sf::IntRect(leftIni + (leftRepeat * rand1), rectTop, rectWidth, rectHeight));
    sprite.setPosition(32,0);
    

    sprite2.setTexture(texture);    
    sprite2.setTextureRect(sf::IntRect(leftIni + (leftRepeat * rand2) , rectTop, rectWidth, rectHeight));
    sprite2.setPosition(48,0);

    sprite3.setTexture(texture);    
    sprite3.setTextureRect(sf::IntRect(leftIni + (leftRepeat * rand3), rectTop, rectWidth, rectHeight));
    sprite3.setPosition(64,0);
    sprite3.setColor(sf::Color(0, 255, 0));


    spriteb.setTexture(texture);    
    spriteb.setTextureRect(sf::IntRect(3, 464, 30, 60));
    spriteb.setPosition(0,100);

    spriteb1.setTexture(texture);    
    spriteb1.setTextureRect(sf::IntRect(leftInib + (leftRepeat * rand1b), rectTop, rectWidth, rectHeight));
    spriteb1.setPosition(32,100);
    

    spriteb2.setTexture(texture);    
    spriteb2.setTextureRect(sf::IntRect(leftInib + (leftRepeat * rand2b) , rectTop, rectWidth, rectHeight));
    spriteb2.setPosition(48,100);

    spriteb3.setTexture(texture);    
    spriteb3.setTextureRect(sf::IntRect(leftInib + (leftRepeat * rand3b), rectTop, rectWidth, rectHeight));
    spriteb3.setPosition(64,100);
    spriteb3.setColor(sf::Color(0, 255, 0));

    text.setString(textFunc(rand1) + textFunc(rand2) + textFunc(rand3));
    textb.setString(textFunc(rand1b) + textFunc(rand2b) + textFunc(rand3b));


}

int main()
{






    sf::RenderWindow window(sf::VideoMode(100, 200), "Piano");
   
    sf::Thread thread(&ranFunc);

    // run it
    // thread.launch();
    // mutex.lock();


    if (!font.loadFromFile("/hdd/Backup/Coding/C++/Midi/arial_narrow_7.ttf"))
    {
        std::cout << "Cannot load font";
    }


    text.setFont(font); // font is a sf::Font
    
    text.setCharacterSize(33); // in pixels, not points!
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    text.setPosition(32, 60);

    textb.setFont(font); // font is a sf::Font
    
    textb.setCharacterSize(33); // in pixels, not points!
    textb.setFillColor(sf::Color::Green);
    textb.setStyle(sf::Text::Bold);
    textb.setPosition(32, 160);



    sf::Image image;
    if (!(image.loadFromFile("/hdd/Backup/Coding/C++/Midi/Piano2.png")))
            std::cout << "Cannot load image";   //Load Image
    
   
    texture.loadFromImage(image);  //Load Texture from image
    texture.setSmooth(true);

  

    while (window.isOpen())
    {
        thread.launch();
        sf::sleep(sf::milliseconds(3000));

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


   
        window.clear();
        window.draw(spritea);
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(text);

        window.draw(spriteb);
        window.draw(spriteb1);
        window.draw(spriteb2);
        window.draw(spriteb3);
        window.draw(textb);
        // window.draw(shape);
        window.display();

        // std::cout<<"hi"<<std::endl;
    }

    // mutex.unlock();
    return 0;
}
