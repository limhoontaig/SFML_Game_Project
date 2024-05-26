#include <SFML/Graphics.hpp>
#include <iostream>

int screenWidth = 800;
int screenHeight = 450;
const int numberOfEnemy = 10;
float gameSpeed = 0.115f;
float rectWidth = 20.0f;
float rectHeight = 20.0f;

void UpdatePosition(float &currentxPosition, float &currentyPosition)
{
    bool pressedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool pressedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    bool pressedUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool pressedDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    if (pressedLeft)
    {
        currentxPosition -= gameSpeed;
        if (currentxPosition <= 0)
            currentxPosition = 0.0;
    }
    if (pressedRight)
    {
        currentxPosition += gameSpeed;
        if (currentxPosition >= screenWidth - rectWidth)
            currentxPosition = screenWidth - rectWidth;
    }
    if (pressedUp)
    {
        currentyPosition -= gameSpeed;
        if (currentyPosition <= 0)
            currentyPosition = 0.0;
    }
    if (pressedDown)
    {
        currentyPosition += gameSpeed;
        if (currentyPosition >= screenHeight - rectHeight)
            currentyPosition = screenHeight - rectHeight;
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");
    
    sf::RectangleShape player;
    float enemyXPosition[numberOfEnemy];
    float enemyYPosition[numberOfEnemy];
    const float enemySize = 10.0f;
    const sf::Color enemyColor = { 155, 100, 155 };
    sf::CircleShape enemies[numberOfEnemy];
    for (int i = 0; i < numberOfEnemy; i++)
    {
        enemyXPosition[i] = screenWidth - 100;
        enemyYPosition[i] = rand() % screenHeight;
        enemies[i] = sf::CircleShape(enemySize);
        enemies[i].setPosition(sf::Vector2f(enemyXPosition[i], enemyYPosition[i]));
        enemies[i].setRadius(enemySize);
        enemies[i].setFillColor(enemyColor);
        enemies[i].setOutlineColor(sf::Color::Red);
        enemies[i].setOutlineThickness(3.0f);
    }


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
        UpdatePosition(rectXPosition, rectYPosition);

        player.setPosition(sf::Vector2f(rectXPosition, rectYPosition));

        window.clear();
        window.draw(player);
        for (int i = 0; i < numberOfEnemy; i++)
        {
            window.draw(enemies[i]);
        }
        window.display();
    }

    return 0;
}
