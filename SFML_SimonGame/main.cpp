#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;

#define KEYPAD_START_X 0
#define KEYPAD_START_Y 0
#define TEXT_MSG_X 180.f
#define TEXT_MSG_Y 200.f
#define KEYPAD_BTN_WIDTH 252
#define KEYPAD_BTN_HEIGHT 252

string com_numbers = "";
int level = 1;

//Generate random number
int generate_random_number()
{
	com_numbers.clear();
	srand((unsigned int)time(NULL));
	for (int i = 0; i < level; i++)
		com_numbers += to_string(rand() % 4);
	
	#if 0
		cout << "-----------------------------------------" << endl;
		cout << "[ COM]Level:" << level << " Random Number:" << comNumbers << endl;
		cout << "-----------------------------------------" << endl;
	#endif
	return 0;
}

// function for display text
int print_text(Text& textMsg, Font& font, int size,
	float x, float y, const Color& color, const Color& outColor, string p)
{
	textMsg.setFont(font);
	textMsg.setCharacterSize(size);
	textMsg.setPosition(x, y);
	textMsg.setFillColor(color);
	textMsg.setOutlineColor(outColor);
	textMsg.setString(p);
	return 0;
}

int main()
{
	Texture tex_color_off, tex_color_on;
	Sprite sprite_off[5], sprite_on[5], sprite_start_logo;
	Font font_level, font_message;
	Text text_level, text_message;

	string input_numbers = "";
	int levelLoop = 0;

	int x = 0, y = 0, n = 0;
	int color_grid[2][2] = { 0 };
	int xx = 0, yy = 0;

	Clock clock;

	float number_order = 0, delay_number_order = 1.5; //inerval for show each color
	float game_start = 0, delay_game_start = 3.0; //wait for game start
	float ready = 0, delay_ready = 2.0; //Show "Ready, Go" message for 2 seconds
	float rotate_time = 0;   

	string level_string = "Level : " + to_string(level);
	string message_string = "Ready, Go!";
	bool isgamestart = false;
	int index = 0;

	RenderWindow app(VideoMode(504, 504), "Remember It - https://maincodes.tistory.com/");
	app.setFramerateLimit(60);

	//Load resources from files
	if (tex_color_off.loadFromFile("../resources/sprites/SpaceShooterAssetPack_Projectiles.png") == false)
	{
		cout << "loadFromeFile err" << endl;
		return - 1;
	}

	if (tex_color_on.loadFromFile("../resources/sprites/SpaceShooterAssetPack_Characters.png") == false)
	{
		cout << "loadFromeFile err" << endl;
		return - 1;
	}


	if (font_level.loadFromFile("../resources/font/BinggraeMelona.ttf") == false)
	{
		cout << "loadFromeFile err" << endl;
		return - 1;
	}

	if (font_message.loadFromFile("../resources/font/DS-DIGIB.ttf") == false)
	{
		cout << "loadFromeFile err" << endl;
		return - 1;
	}

	//Set logo
	sprite_start_logo.setTexture(tex_color_off);
	sprite_start_logo.setOrigin(sf::Vector2f(tex_color_off.getSize()) / 2.f);
	sprite_start_logo.setPosition(sprite_start_logo.getOrigin());


	print_text(text_level, font_level, 30, 10.f, 10.f,
		Color::White, Color::White, level_string);
	print_text(text_message, font_message, 30, TEXT_MSG_X, TEXT_MSG_Y,
		Color::White, Color::White, message_string);

	//Init. Color pad & Color grid
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sprite_off[n].setTexture(tex_color_off);
			sprite_off[n].setTextureRect(IntRect(j * KEYPAD_BTN_WIDTH, i * KEYPAD_BTN_HEIGHT,
				KEYPAD_BTN_WIDTH, KEYPAD_BTN_HEIGHT));
			color_grid[i][j] = n;

			sprite_on[n].setTexture(tex_color_on);
			sprite_on[n].setTextureRect(IntRect(j * KEYPAD_BTN_WIDTH, i * KEYPAD_BTN_HEIGHT,
				KEYPAD_BTN_WIDTH, KEYPAD_BTN_HEIGHT));
			n++;
		}
	}

	generate_random_number();

	while (app.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		number_order += time;
		game_start += time;
		ready += time;
		rotate_time += time;

		Event event;

		while (app.pollEvent(event)) {
			if (event.type == Event::EventType::Closed)
				app.close();
		}

		if (event.type == Event::MouseButtonPressed)
		{
			if (event.key.code == Mouse::Left)
			{
				if (isgamestart == true)
				{
					Vector2i pos = Mouse::getPosition(app);
					x = (pos.y - KEYPAD_START_Y) / KEYPAD_BTN_HEIGHT;
					y = (pos.x - KEYPAD_START_X) / KEYPAD_BTN_WIDTH;
					n = color_grid[x][y];
					cout << "[USER]Pressed:: x=" << y << " y = " << x << " n=" << n << endl;

					//Save input numbers
					if (input_numbers.length() < level)
						input_numbers += to_string(n);

					//Pressed effect
					for (int i = 0; i < 10; i++) {
						sprite_on[n].setPosition(
							(float)((y)*KEYPAD_BTN_WIDTH) + KEYPAD_START_X,
							(float)KEYPAD_START_Y + ((x)*KEYPAD_BTN_HEIGHT));

						app.draw(sprite_on[n]);
						app.display();
					}
				}
			}
			else //Pressed Mouse right button
				isgamestart = true;
		}

		if (input_numbers.length() == level)
		{
			if (com_numbers == input_numbers)
			{
				input_numbers.clear();
				level++;

				level_string = "Level : " + to_string(level) + " | Correct :)";
				print_text(text_level, font_level, 30, 10.f, 10.f,
					Color::White, Color::White, level_string);
			}
			else {

				level_string = "Level : " + to_string(level) + " | Wrong :(";
				print_text(text_level, font_level, 30, 10.f, 10.f,
					Color::White, Color::White, level_string);
				input_numbers.clear();
			}

			generate_random_number();

			game_start = 0;
			levelLoop = 0;
			clock.restart();
			number_order += time;
		}

		app.clear(Color::White);

		if (isgamestart == false)
		{
			//sprite_start_logo.setRotation(rotate_time * 1000);
			app.draw(sprite_start_logo);

			level_string = "Press Mouse Right button to start.";
			print_text(text_message, font_message, 30, 10.f, TEXT_MSG_Y,
				Color::Red, Color::Green, level_string);

			game_start = 0;
			number_order = 0;
		}
		else {
			//draw color grid
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					int n = color_grid[i][j];
					sprite_off[n].setPosition(
						(float)j * KEYPAD_BTN_WIDTH + KEYPAD_START_X,
						(float)KEYPAD_START_Y + (i * KEYPAD_BTN_HEIGHT));
					app.draw(sprite_off[n]);
				}
			}

		//Remove "Ready, Go ! message after 2 seconds
		if (ready > delay_ready) {
			print_text(text_message, font_message, 30, TEXT_MSG_X, TEXT_MSG_Y,
				Color::Red, Color::Red, "");
		}

		//Game Start after 3.0 seconds
		if (game_start > delay_game_start)
		{
			//Show the sprite_on image every 1 second each color
			if (number_order > delay_number_order)
			{
				if (levelLoop < level)
				{
					index = (com_numbers.at(levelLoop)) - '0';
					cout << "[ COM]Pressed idx = " << index << endl;
					switch (index)
					{
						case 0: xx = 0; yy = 0; break;
						case 1: xx = 1; yy = 0; break;
						case 2: xx = 0; yy = 1; break;
						case 3: xx = 1; yy = 1; break;
					}

					//Press effect
					for (int i = 0; i < 15; i++)
					{
						sprite_on[index].setPosition(
							(float)((xx)*KEYPAD_BTN_WIDTH) + KEYPAD_START_X,
							(float)KEYPAD_START_Y + ((yy)*KEYPAD_BTN_HEIGHT));
						app.draw(sprite_on[index]);
						app.display();
					}

					levelLoop++;
				}
				number_order = 0;
			}
		}
		}
		app.draw(text_level);
		app.draw(text_message);
		app.display();
	}

	return 0;
}