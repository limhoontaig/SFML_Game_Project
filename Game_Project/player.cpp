#include "player.h"

Player::Player(sf::Vector2f pos, float size, sf::Color color, float speed)
    : position(pos), size(size), color(color), speed(speed)
{
    sf::RectangleShape player;
 

    player.setSize(sf::Vector2f(size, size));
    player.setPosition(sf::Vector2f(pos.x, pos.y));
    player.setFillColor(color);
}
void Player::Update()
{

}

void Player::Draw(sf::RenderWindow& window)
{

}

sf::Vector2f Player::GetPosition()
{

}

void Player::ProcessInput()
{
    bool pressedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool pressedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    bool pressedUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool pressedDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    if (pressedLeft)
    {
        position.x -= speed * gameFactor;
        if (position.x <= 0)
            position.x = 0.0;
    }
    if (pressedRight)
    {
        position.x += speed * gameFactor;
        if (position.x >= screenWidth - size)
            position.x = screenWidth - size;
    }
    if (pressedUp)
    {
        currentyPosition -= gameSpeed * gameFactor;
        if (currentyPosition <= 0)
            currentyPosition = 0.0;
    }
    if (pressedDown)
    {
        currentyPosition += gameSpeed * gameFactor;
        if (currentyPosition >= screenHeight - rectHeight)
            currentyPosition = screenHeight - rectHeight;
    }
}
