#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <iostream>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Text.hpp>
#include "game.h"

int TextPrint(sf::Text& textMsg, sf::Font& font, int size, float x, 
    float y, const sf::Color& color, sf::Color outColor, sf::String p)
{
    textMsg.setFont(font); //폰트 
    textMsg.setCharacterSize(size); //크기
    textMsg.setPosition(x, y);   //x, y 위치
    textMsg.setFillColor(color); //색    
    textMsg.setOutlineColor(outColor); //글자 테두리 색
    textMsg.setOutlineThickness(1.f); //글자 테두리 굵기
    textMsg.setString(p); //출력할 문자열
    return 0;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 화면을 그릴 윈도우 생성
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");

    // 글을 표시하고 싶을 경우 폰트 로딩 필요
    sf::Font font;
    if (!font.loadFromFile("../resources/font/arial.ttf"))
    {
        std::cout << "Font Loading Error!" << std::endl;
    }

    // 화면에 그릴 원 객체 생성
    sf::CircleShape shape(100.f);
    shape.setPosition(sf::Vector2f{ 150.f,100.f });
    shape.setFillColor(sf::Color::Green);

    // 화면에 그릴 텍스트 객체 생성
    sf::Text text1, text2, text3;
    
    float interval = 0.0f;

    TextPrint(text2, font, 30.0f, 200.0f, 100.0f,
        sf::Color::Red, sf::Color::Cyan, "This is a Galaxy Shooter Game.");
    TextPrint(text1, font, 56.0f, 200.0f, 150.0f,
        sf::Color::Magenta, sf::Color::White, "Enjoy Your Spare Time!");
    TextPrint(text3, font, 100.0f, 200.0f, 250.0f,
        sf::Color::Yellow, sf::Color::Blue, "GAME START!!!");

    // 윈도우가 열려 있을 동안 반복
    while (window.isOpen())
    {
        // 종료 조건
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Clock clock;
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        interval += time;

        //--- 화면을 그리는 세 단계

        // 1) 이미 그려져 있는 모든 것을 지운다.
        window.clear();

        // 2) 그리고 싶은 것들을 draw 함수를 사용해 그린다.
        //window.draw(shape);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);

        // 3) 화면에 표시한다.
        window.display();
    }
    
    
    
    /*
    {
        Game game;
        bool success = game.Initialize();
        if (success)
        {
            game.RunLoop();
        }
        game.Shutdown();
    }
    */
   
    return 0;
}