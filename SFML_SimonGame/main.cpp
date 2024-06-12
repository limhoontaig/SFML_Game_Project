#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#define CIRCLE_RADIUS 100.0f
void play_sound_detail(const std::string& filename)
{
	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile(filename))
	{
		std::cout << "LoadFromFile Error !!" << std::endl;
		return;
	}

	std::cout << filename << "을 재생중: " << std::endl;
	std::cout << " " << buffer.getDuration().asSeconds() << " sec" << std::endl;
	std::cout << " " << buffer.getSampleRate() << " samples / sec" << std::endl;
	std::cout << " " << buffer.getChannelCount() << " channel" << std::endl;

	sf::Sound sound(buffer);
	sound.play();

	/*
	while (sound.getStatus() == sf::Sound::Playing)
	{
		sf::sleep(sf::milliseconds(100));
		std::cout << "\r제생 중...." << sound.getPlayingOffset().asSeconds() << std::endl;
		std::cout << std::flush;
	}
	std::cout << std::endl << std::endl;	
	*/
}


int textPrint(sf::Text& textMsg, sf::Font& font, int size, float x, float y,
	const sf::Color& color, const sf::Color& outColor, sf::String p)
{
	textMsg.setFont(font);
	textMsg.setCharacterSize(size);
	textMsg.setPosition(x, y);
	textMsg.setFillColor(color);
	textMsg.setOutlineColor(outColor);
	textMsg.setOutlineThickness(1.0f);
	textMsg.setString(p);
	return 0;
}

int main()
{
	// Text 
	
	sf::Text text1, text2, text3;
	sf::Uint8 r = 0, g = 0, b = 0;
	sf::String msgStr = "Ready Go! Maincodes !!";

	float x = 0, y = 0;
	
	// Circle Shape oblect
	sf::CircleShape circle_shape(CIRCLE_RADIUS);
	circle_shape.setFillColor(sf::Color::Green);
	circle_shape.setRadius(CIRCLE_RADIUS);
	circle_shape.setOutlineColor(sf::Color::Red);
	circle_shape.setOutlineThickness(20.0f);
	circle_shape.setPosition(x, y);

	// rectangle shape object
	//sf::RectangleShape rectangle(sf::Vector2f{ 200.0f, 200.0f });
	//rectangle.setFillColor(sf::Color::Blue);

	// clock 
	sf::Clock clock;
	sf::Clock ai_Timer;
	float interval = 0, delay1 = 8.0f;
	float timer = 0;
	int count = 0;

	// sound
	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile("../resources/music/CantinaBand60.wav"))
	{
		std::cout << "LoadFromFile Error !!" << std::endl;
		return -1;
	}

	sf::Sound sound(buffer);

	// timer variables
	const sf::Time ai_time = sf::seconds(0.5f);

	std::cout << "프로그램이 시작되었습니다. " << std::endl;

	// texture and sprite
	sf::Texture color_off, color_on;
	sf::Sprite sprite_on, sprite_off;

	color_on.loadFromFile("../resources/sprites/SpaceShooterAssetPack_Characters.png");
	color_off.loadFromFile("../resources/sprites/SpaceShooterAssetPack_Ships.png");

	sprite_on.setTexture(color_on);
	sprite_on.setTextureRect(sf::IntRect(0, 0, 30, 30));
	sprite_on.setPosition(sf::Vector2f{ 300.0f, 250.0f });
	sprite_on.scale(sf::Vector2f{ 2.0f, 2.0f });

	sprite_off.setTexture(color_off);
	sprite_off.setTextureRect(sf::IntRect(0, 0, 50, 50));
	sprite_off.setPosition(sf::Vector2f{ 100.0f, 150.0f });




	// font load
	sf::Font font;
	if (!font.loadFromFile("../resources/font/DS-DIGIB.TTF"))
	{
		return false;
	}

	textPrint(text1, font, 30, 0, 0, sf::Color::Yellow, sf::Color::White, msgStr);
	textPrint(text2, font, 80, 150, 100, sf::Color::White, sf::Color::White, msgStr);
	textPrint(text3, font, 100, 150, 210, sf::Color::Blue, sf::Color::White, msgStr);

	text1.setOrigin(400.0f, 400.0f);
	text1.setPosition(text1.getOrigin());

	sf::RectangleShape rect_shape(sf::Vector2f{ 200.0f, 200.0f });

	sf::RectangleShape small_rect_shape;

	rect_shape.setFillColor(sf::Color::Green);
	rect_shape.setOutlineColor(sf::Color::Red);
	rect_shape.setOutlineThickness(20.0f);
	rect_shape.setPosition(x, y);

	small_rect_shape.setSize(sf::Vector2f{10.0f, 10.0f});
	small_rect_shape.setFillColor(sf::Color::Yellow);
	small_rect_shape.setOutlineColor(sf::Color::Blue);
	small_rect_shape.setOutlineThickness(20.0f);
	small_rect_shape.setPosition(x, y);
	for (int i = 0; i < 5; i++)
	{
	}


	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML Works");
	window.setFramerateLimit(30);


	while (window.isOpen())
	{
		// cycling time and elapsed time 
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		interval += time;
		timer += time;
		
		// event processor
		sf::Event event;

		// window close event process
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
				std::cout << "프로그램이 종료되었습니다." << std::endl;
			}

			// key pressed
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
				{
					x -= 10;
					break;
				}
				case sf::Keyboard::Right:
				{
					x += 10;
					break;
				}
				case sf::Keyboard::Up:
				{
					y -= 10;
					break;
				}
				case sf::Keyboard::Down:
				{
					y += 10;
					break;
				}
				}
				
				
				/*
				if (event.key.code == sf::Keyboard::Space)
				{
					float speed = 3.0f;
					for (int i = 0; i < 50; i += speed)
					{
						small_rect_shape[0].move(speed * 1, speed*1);
						window.draw(small_rect_shape[0]);
						window.display();
					}
					small_rect_shape[0].setPosition(sf::Vector2f{ (float)x, (float)y });
					break;
				}
				*/
				
			}



			// mouse press event process
			if (event.type == sf::Event::MouseButtonPressed)
			{
				switch (event.key.code)
				{
				case sf::Mouse::Left:
				{
					circle_shape.setFillColor(sf::Color::Yellow);
					sf::Vector2i pos = sf::Mouse::getPosition(window);
					rect_shape.setOrigin(sf::Vector2f{ (float)pos.x, (float)pos.y});
					std::cout << "왼쪽버튼 눌림 : pos.x = " << pos.x << " pos.y : " << pos.y << std::endl;
					break;
				}
				case sf::Mouse::Right:
				{
					circle_shape.setFillColor(sf::Color::Magenta);
					sf::Vector2i pos = sf::Mouse::getPosition(window);
					float x_f = (float)pos.x + CIRCLE_RADIUS;
					float y_f = (float)pos.y + CIRCLE_RADIUS;
					circle_shape.setPosition(sf::Vector2f{ x_f, y_f });
					std::cout << "오른쪽버튼 눌림 : pos.x = " << pos.x << " pos.y : " << pos.y << std::endl;
					break;
				}
				}
			}

			// mouse release event
			if (event.type == sf::Event::MouseButtonReleased)
			{
				switch (event.key.code)
				{
				case sf::Mouse::Left:
				{
					circle_shape.setFillColor(sf::Color::Green);
					sf::Vector2i pos = sf::Mouse::getPosition(window);
					float x_f = (float)pos.x - CIRCLE_RADIUS;
					float y_f = (float)pos.y - CIRCLE_RADIUS;
					circle_shape.setPosition(sf::Vector2f{x_f, y_f});
					std::cout << "왼쪽버튼 뗌 : pos.x = " << pos.x << " pos.y : " << pos.y << std::endl;
					break;
				}
				case sf::Mouse::Right:
				{
					circle_shape.setFillColor(sf::Color::Green);
					sf::Vector2i pos = sf::Mouse::getPosition(window);
					std::cout << "오른쪽버튼 뗌 : pos.x = " << pos.x << " pos.y : " << pos.y << std::endl;
					break;
				}
				case sf::Mouse::Middle:
				{
					circle_shape.setFillColor(sf::Color::Green);
					sf::Vector2i pos = sf::Mouse::getPosition(window);
					std::cout << "중간버튼 뗌 : pos.x = " << pos.x << " pos.y : " << pos.y << std::endl;
					break;
				}
				}
			}
		}




		/*

		// ai_time period action (current 0.5sec)
		if (ai_Timer.getElapsedTime() > ai_time)
		{
			ai_Timer.restart();
			std::cout << "ai_Timer..." << interval << std::endl;
		}

		// delay1 time period action (current 4sec)
		if (interval > delay1 )
		{
			ai_Timer.restart();
			std::cout << "interval = " << interval << " count : " << count << std::endl;

			interval = 0;
			count++;
		}
		

		// interval 
		if (((int)interval % 2) == 0)
		{
			window.clear(sf::Color::Black);
			x += 1.0;
			y += 1.0;
			text1.setPosition(x, y);
			window.draw(text1);
			window.draw(text2);
			window.draw(text3);

			// window.draw(rectangle);
			// window.draw(sprite_on);
			if (x > 800) { x = 0, y = 0; }
		}
		else
		{
			window.clear(sf::Color::Black);
			window.draw(sprite_off);
		}
		
		if (((int)interval % 5) == 0)
		{
			std::cout << "interval = " << interval << std::endl;
			play_sound_detail("../resources/music/BabyElephantWalk60.wav");

			std::cout << "resources/music/BabyElephantWalk60.wav" << std::endl;
			sound.play();
		}
		*/
		//배경화면을 흰색으로 clear
		window.clear(sf::Color::White);

		//rect_shape 위치 보정
		rect_shape.setPosition(sf::Vector2f( (float)x + 100.0f, y + 100.f));
		window.draw(rect_shape);


		//텍스트 이동
		text1.move(1.f, 1.f);

		//글자 위치 재설정
		if (text1.getPosition().x == 1000 || text1.getPosition().y == 1000)
			text1.setPosition(10, 10);

		//타이머에 맞춰 글자 크기를 확대
		text1.setScale(timer * 1.5f, timer * 1.2f);

		//글자 크기 재설정
		if (text1.getScale().x == 100 || text1.getScale().y == 100)
			text1.setScale(1.0f, 1.0f);


		//글자 로테이션 설정
		text3.setRotation(timer * 5);
		window.draw(text3);

		/*
		//작은 사각형 이동
		for (int i = 0; i < 5; i++)
		{
			small_rect_shape[i].move(0, 5.f);

			if (small_rect_shape[i].getPosition().y == 1000)
				small_rect_shape[i].setPosition(x + ((i + 1) * 100), y);

			window.draw(small_rect_shape[i]);
		}
		*/
		//큰 사각형 로테이션
		/*
		for (int i = 0; i < 20; i++)
		{
			window.draw(rect_shape);
			//rect_shape.setRotation(timer * 1.5f);
			//window.draw(rect_shape);

		}
		*/
		rect_shape.setRotation(timer * 15.0f);
		rect_shape.setPosition({ (float)(rand() % 200), (float)(rand() % 200) });


		//약 5초 후에는 타이머 재설정
		if (timer > 15)
			timer = 0;
		std::cout << "timerRotate = " << timer << std::endl;

		//프레임을 스크린에 출력
		//window.display();
	

		//window.clear(sf::Color::White);
		//circle_shape.setPosition(sf::Vector2f{ x + 100.0f, y + 100.0f });
		window.draw(circle_shape);
		window.display();
	}
	return 0;
}