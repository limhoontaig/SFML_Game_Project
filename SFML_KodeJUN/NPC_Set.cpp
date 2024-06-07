#include "NPC_Set.h"

NPC_Set::NPC_Set(int num)
{
	sf::Color colors[4] = { sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color::Yellow };

	for (int i = 0; i < num; i++)
	{
		int inc = rand()% 300;
		NPC npc(30.0f + inc, 30.0f + inc, (float)(i + 1) , colors[i%4]);
		npcs.push_back(npc);
		inc += 20;
	}
}

void NPC_Set::update()
{
	for (auto& _e : npcs)
	{
		//checkHit(ect);
		if(_e.destroyed==false)
			_e.update();
	}
}

void NPC_Set::draw(sf::RenderWindow& _window)
{
	for (auto& _e : npcs)
	{
		if (_e.destroyed==false)
	       _e.draw(_window);
	}
}

void NPC_Set::checkHit(sf::FloatRect _rect)
{
	for (auto& _e : npcs)
	{
		if (_rect.intersects(_e.GetArea()) == true)
		{
			_e.destroyed = true;
		}
	}
}
