#define _CRTDBG_MAP_ALLOC
#include <SFML/Graphics.hpp>
#include <iostream>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

int screenWidth = 800;
int screenHeight = 450;
const int numberOfEnemy = 10;
float gameSpeed = 0.005f;
float rectWidth = 20.0f;
float rectHeight = 20.0f;

void UpdatePlayerPosition(float &currentxPosition, float &currentyPosition)
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

void UpdateEnemyPosition(int numberOfEnemy, float* enemyXPosition, float* enemyYPosition,float playerXPosition, float playerYPosition )
{
    for (int i = 0; i < numberOfEnemy; i++)
    {
        float enemyToPlayerX = playerXPosition - enemyXPosition[i];
        float enemyToPlayerY = playerYPosition - enemyYPosition[i];

        float length = sqrt(enemyToPlayerX * enemyToPlayerX + enemyToPlayerY * enemyToPlayerY);
        
        enemyToPlayerX /= length;
        enemyToPlayerY /= length;

        enemyXPosition[i] += enemyToPlayerX * gameSpeed;
        enemyYPosition[i] += enemyToPlayerY * gameSpeed;
 
    }
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");
    
    sf::RectangleShape player;
    float* enemyXPosition = new float [numberOfEnemy];
    float* enemyYPosition = new float [numberOfEnemy];
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


    float playerXPosition = 50.0f;
    float playerYPosition = 50.0f;

    player.setSize(sf::Vector2f(rectWidth, rectHeight));
    player.setPosition(sf::Vector2f(playerXPosition, playerYPosition));
    player.setFillColor(sf::Color::Red);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        UpdatePlayerPosition(playerXPosition, playerYPosition);
        player.setPosition(sf::Vector2f(playerXPosition, playerYPosition));
        
        UpdateEnemyPosition(numberOfEnemy, enemyXPosition, enemyYPosition, playerXPosition, playerYPosition);
        
        window.clear();
        window.draw(player);
        for (int i = 0; i < numberOfEnemy; i++)
        {
            enemies[i].setPosition(sf::Vector2f(enemyXPosition[i], enemyYPosition[i]));
            window.draw(enemies[i]);
        }
        window.display();
    }
    delete[] enemyXPosition;
    delete[] enemyYPosition;    
    return 0;
}
