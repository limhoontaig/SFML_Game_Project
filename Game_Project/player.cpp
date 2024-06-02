#include "player.h"
#include "game.h"
#include "textDisplay.h"

Player::Player(Game* game, ActorType type,  sf::Vector2f pos, float size, float speed)
    : Actor {game, type, pos, speed, size}
{
    shape.setTexture(game->GetShipTexture());
    shape.setTextureRect(sf::IntRect{ 8,0,8,8 }); // x, y, width, height

    shape.setScale(sf::Vector2f{ size, size });
    sf::FloatRect bounds = shape.getLocalBounds();
    shape.setOrigin(std::floor(bounds.left + bounds.width / 2.f),
        std::floorf(bounds.top + bounds.height / 2.f));
}

Player::~Player()
{
}

void Player::Update(float dt)
{
    if (isActive)
    {
        ProcessInput(dt);
        shape.setPosition(position);
    }
    else
    {
    }
}

void Player::ProcessInput(float dt)
{
    sf::Vector2i screenSize = game->GetScreenSize();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        position.x -= speed * dt;
        if (position.x < size / 2.0f) { position.x = size / 2.0f; }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        position.x += speed * dt;
        if (position.x > (float) (screenSize.x - size)) 
        { 
            position.x = (float)(screenSize.x - size); 
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        position.y -= speed * dt;
        if (position.y < 0.0f) { position.y = 0.0f; }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        position.y += speed * dt;
        if (position.y > screenSize.y - size)
        {
            position.y = (float)(screenSize.y - size);
        }
    }
}
