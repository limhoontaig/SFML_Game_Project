#pragma once
#include <iostream>
#include <vector>

#include "Npc.h"

class NPC_Set
{
public:
	NPC_Set(int num);
	void update();
	void draw(sf::RenderWindow& _window);
	void checkHit(sf::FloatRect _rect);

private:
	std::vector<NPC> npcs;

};
