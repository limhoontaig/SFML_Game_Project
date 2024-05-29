#define _CRTDBG_MAP_ALLOC
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "player.h"
#include "enemy.h"
#include "bullet.h"
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

int screenWidth = 800;
int screenHeight = 450;
float gameFactor = 50.0f;


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");
    window.setFramerateLimit(60);
    

    // enemies create

    std::vector<Enemy*> enemies;
    float enemyFirePeriod = 10.0f;
    float enemyFireTimer = enemyFirePeriod;
    
    
    
   
    sf::Clock deltaTimeClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        
        
        
        //sf::sleep(sf::seconds(0.1f));
    }
   
    return 0;
}