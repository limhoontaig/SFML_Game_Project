#include "player.h"
#include "game.h"

Player::Player(Game* game, sf::Vector2f pos, float size, float speed)
    : Actor {game, pos, speed, size}
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
    ProcessInput(dt);
    shape.setPosition(position);
}

void Player::ProcessInput(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        position.x -= speed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        position.x += speed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        position.y -= speed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        position.y += speed * dt;
    }
}
