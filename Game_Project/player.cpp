#include "player.h"

Player::Player(sf::Vector2f pos, float size, sf::Color color, 
    float speed, int screenWidth, int screenHeight)
    : position(pos), size(size), color(color), speed(speed), 
    screenWidth(screenWidth), screenHeight(screenHeight)
{
    shape.setSize(sf::Vector2f{ size, size });
    shape.setFillColor(color);
}

void Player::Update(float dt)
{
    shape.setPosition(position);
    ProcessInput(dt);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::Vector2f Player::GetPosition() const
{
    return position;
}

void Player::ProcessInput(float dt)
{
    bool pressedLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool pressedRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    bool pressedUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool pressedDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    if (pressedLeft)
    {
        position.x -= speed * dt;// *gameFactor;
        if (position.x <= 0)
            position.x = 0.0;
    }
    if (pressedRight)
    {
        position.x += speed * dt;// * gameFactor;
        if (position.x >= screenWidth - size)
            position.x = screenWidth - size;
    }
    if (pressedUp)
    {
        position.y -= speed * dt;// * gameFactor;
        if (position.y <= 0)
            position.y = 0.0;
    }
    if (pressedDown)
    {
        position.y += speed * dt;// * gameFactor;
        if (position.y >= screenHeight - size)
            position.y = screenHeight - size;
    }
}
