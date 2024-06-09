/*
#include "control.h"
#include <iostream>
#include "text.h"

Control::Control()
{

}

bool Control::Initialize()
{
	return false;
}

void Control::RunLoop()
{
	while (window.isOpen())
	{
		ProcessInput();
		
			
		}
		window.clear();
		window.draw(menuBg);
		text.draw(window);
		window.display();
	}
}

void Control::InitializeGame()
{
}

void Control::ProcessInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		window.close();
	}

}

void Control::DrawGame()
{

}

void Control::UpdateGame()
{

	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			menu.MoveUp();
			break;
		case sf::Keyboard::Down:
			menu.MoveDown();
			break;
		case sf::Keyboard::Return:
			switch (menu.GetPressedItem())
			{
			case 0:
				std::cout << "Play Button hasBeen pressed." << std::endl;
				break;
			case 1:
				std::cout << "Option Button hasBeen pressed." << std::endl;
				break;
			case 2:
				window.close();
				break;
			}
			break;
		}
		break;
	case sf::Event::Closed:
		window.close();
}



*/