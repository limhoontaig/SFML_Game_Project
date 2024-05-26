#include <SFML/Graphics.hpp>
#include <iostream>

int screenWidth = 800;
int screenHeight = 450;
float gameSpeed = 0.115f;
float rectWidth = 20.0f;
float rectHeight = 20.0f;

void UpdatePosition(float* currentxPosition, float* currentyPosition)
{
    bool pressedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool pressedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    bool pressedUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool pressedDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    if (pressedLeft)
    {
        *currentxPosition -= gameSpeed;
        if (*currentxPosition <= 0)
            *currentxPosition = 0.0;
    }
    if (pressedRight)
    {
        *currentxPosition += gameSpeed;
        if (*currentxPosition >= screenWidth - rectWidth)
            *currentxPosition = screenWidth - rectWidth;
    }
    if (pressedUp)
    {
        *currentyPosition -= gameSpeed;
        if (*currentyPosition <= 0)
            *currentyPosition = 0.0;
    }
    if (pressedDown)
    {
        *currentyPosition += gameSpeed;
        if (*currentyPosition >= screenHeight - rectHeight)
            *currentyPosition = screenHeight - rectHeight;
    }
    //return currentxPosition;
}
/*
float UpdateYPosition(float currentyPosition)
{
    return currentyPosition;
}
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");
    
    sf::RectangleShape player;
    sf::CircleShape circle[5];
    
    float rectXPosition = 50.0f;
    float rectYPosition = 50.0f;

    player.setSize(sf::Vector2f(rectWidth, rectHeight));
    player.setPosition(sf::Vector2f(rectXPosition, rectYPosition));
    player.setFillColor(sf::Color::Red);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        UpdatePosition(&rectXPosition, &rectYPosition);

        player.setPosition(sf::Vector2f(rectXPosition, rectYPosition));

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}

//--- Practice

// 1. 각 사각형의 크기도 랜덤하게 생성되도록 코드를 수정해 보세요.
// 2. 모든 사각형의 이동속도가 동일합니다. 각 사각형이 서로 다른 이동속도를 가지도록 수정해 보세요.
// 3. 사각형이 오른쪽 끝에 부딪히면 반대 방향으로 움직이도록 수정해 보세요.