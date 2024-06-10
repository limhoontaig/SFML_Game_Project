#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RectangleShape rectangle(sf::Vector2f{ 200.0f, 200.0f });
	rectangle.setFillColor(sf::Color::Blue);

	sf::Clock clock;
	sf::Clock ai_Timer;
	float interval = 0, delay1 = 4.0f;
	int count = 0;

	const sf::Time ai_time = sf::seconds(0.5f);

	std::cout << "프로그램이 시작되었습니다. " << std::endl;

	sf::RenderWindow window(sf::VideoMode(504, 504), "SFML Works");
	window.setFramerateLimit(120);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		interval += time;
		
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
				std::cout << "프로그램이 종료되었습니다." << std::endl;
			}
		}

		if (ai_Timer.getElapsedTime() > ai_time)
		{
			ai_Timer.restart();
			std::cout << "interval = " << interval <<  " count : " << count << std::endl;
			interval = 0;
			count ++;
		}

		if (((int)interval % 2) == 0)
			window.clear(sf::Color::White);
		else
			window.clear(sf::Color::Blue);

		//window.clear(sf::Color::White);
		window.draw(rectangle);
		window.display();
	}
	return 0;
}