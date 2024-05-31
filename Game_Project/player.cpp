#include "player.h"
#include "game.h"

Player::Player(Game* game, sf::Vector2f pos, float size,  
    float speed, int screenWidth, int screenHeight)
    : Actor {game, pos, speed, size},
    screenWidth(screenWidth), screenHeight(screenHeight)
{
    
    shape.setTexture(game->GetShipTexture());
    shape.setTextureRect(sf::IntRect{ 8,0,8,8 }); // x, y, width, height

    shape.setScale(sf::Vector2f{ size, size });

}

void Player::Update(float dt)
{
    shape.setPosition(position);
    ProcessInput(dt);
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
