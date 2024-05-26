#include <SFML/Graphics.hpp>

int main()
{
    int screenWidth = 800;
    int screenHeight = 450;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "02_Array_Loop_Condition");
    sf::RectangleShape rect;

    const int numRect = 30;
    // sf::RectangleShape rects[numRect];
    float xPos[numRect];
    float yPos[numRect];
    sf::Color color[numRect];
    float speed[numRect];

    float rectWidth[numRect]; // = 20.0f;
    float rectHeight[numRect];// = 20.0f;

    for (int i = 0; i < numRect; i++)
    {
        float randomX = rand() % screenWidth;
        float randomY = rand() % screenHeight;
        unsigned int randomR = rand() % 255;
        unsigned int randomG = rand() % 255;
        unsigned int randomB = rand() % 255;
        xPos[i] = randomX;
        yPos[i] = randomY;
        rectWidth[i] = rand() % 40 + 10;
        rectHeight[i] = rand() % 40 + 10;
        speed[i] = (rand() % 10) * 0.005f;
        color[i] = sf::Color(randomR, randomG, randomB);
        //rects[i] = sf::RectangleShape(sf::Vector2f{ rectWidth, rectHeight });
        //rects[i].setFillColor(randomColor);
        //rects[i].setPosition(sf::Vector2f{ randomX, randomY });
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int i = 0; i < numRect; i++)
        {
            xPos[i] += speed[i];
            if (xPos[i] == screenWidth)

            //sf::Vector2f pos = rects[i].getPosition();
            //pos.x += 0.005f;
            //rects[i].setPosition(pos);
        }

        window.clear();

        for (int i = 0; i < numRect; i++)
        {
            rect.setPosition(sf::Vector2f(xPos[i], yPos[i]));
            rect.setFillColor(color[i]);
            rect.setSize(sf::Vector2f(rectWidth[i], rectHeight[i]));
            window.draw(rect);
            //window.draw(rects[i]);
        }

        window.display();
    }

    return 0;
}

//--- Practice

// 1. 각 사각형의 크기도 랜덤하게 생성되도록 코드를 수정해 보세요.
// 2. 모든 사각형의 이동속도가 동일합니다. 각 사각형이 서로 다른 이동속도를 가지도록 수정해 보세요.
// 3. 사각형이 오른쪽 끝에 부딪히면 반대 방향으로 움직이도록 수정해 보세요.