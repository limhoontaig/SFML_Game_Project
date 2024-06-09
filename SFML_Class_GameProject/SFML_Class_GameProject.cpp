/*
#include <SFML/Graphics.hpp>
#include <iostream>

enum TextType
{
    STARTUP, INPROCESS, PLAYERFALSE, RESTART, ENDOFGAME,
};

class GameText
{
public:
    GameText(sf::Text, sf::String, sf::Font, int, TextType, sf::Color, sf::Color, float, sf::Vector2f);
    void SetTextType(TextType type) { this->type = type; }
    void Update(std::vector<GameText> gameTexts);
    void draw(sf::RenderWindow& window);
    
private:
    sf::Text text;
    sf::Font font;
    int size;
    TextType type;
    sf::Color color;
    sf::Color outColor;
    float outlineThickness;
    sf::Vector2f pos;
    sf::String string;
    std::vector<GameText> gameTexts;
};

GameText::GameText(sf::Text text, sf::String string, sf::Font font, int size, TextType type , 
    sf::Color color, sf::Color outColor, float outlineThickness, sf::Vector2f pos)
    : text{ text }, string{ string }, font{ font }, size{size}, type{type}, color{color},
    outColor{outColor}, outlineThickness{outlineThickness}, pos{pos}
{
    text.setString(string);
    text.setFont(font);
    text.setFillColor(color);
    text.setCharacterSize(size);
    this->SetTextType(type);
}

void GameText::Update(GameText::gameTexts)
{
    for (int i = 0; i < gameTexts.size(); i++)
    {

    }
}


int main()
{
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
    std::vector<GameText> gameTexts;
    sf::Text text;
    sf::String string;
    string = "Welcome to GameWorld!!!";
    std::vector<GameText> gameText;
    GameText gameText = GameText(text, string, font, 50, STARTUP, sf::Color::Blue, sf::Color::Yellow, 3.0f, sf::Vector2f{100.0f, 150.0f});
    gameTexts.push_back( gameText& );







    sf::Text text;
    text.setFont(font);
    text.setString("Hello SFML!");
    text.setCharacterSize(124);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Blue);
    text.setOutlineThickness(3.0f);
    text.setPosition(sf::Vector2f(150.0f, 350.0f));

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

        //--- 화면을 그리는 세 단계

        // 1) 이미 그려져 있는 모든 것을 지운다.
        window.clear();

        // 2) 그리고 싶은 것들을 draw 함수를 사용해 그린다.
        window.draw(shape);
        window.draw(text);

        // 3) 화면에 표시한다.
        window.display();
    }

    return 0;
}

//--- Practice

// 1. 화면의 크기를 더 크게, 또는 더 작게 만들어 보세요.
// 2. 원을 화면의 다른 위치에, 다른 크기로 만들어 보세요.
// 3. 원 개신 사각형을 화면에 그려 보세요. (https://www.sfml-dev.org/documentation/2.6.0/classsf_1_1RectangleShape.php)
*/