#include "NPC_Set.h"

NPC_Set::NPC_Set(int num)
{
	int inc = 0;
	sf::Color colors[4] = { sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color::Yellow };

	for (int i = 0; i < num; i++)
	{
		NPC npc(30.0f + inc, 30.0f + inc, (i + 1) , colors[i%4]);
		npcs.push_back(npc);
		inc += 20.0f;
	}
}

void NPC_Set::update()
{
	for (auto& _e : npcs)
	{
		_e.update();
	}
}

void NPC_Set::draw(sf::RenderWindow& _window)
{
	for (auto& _e : npcs)
	{
		_e.draw(_window);
	}
}
