#include <SFML/Graphics.hpp>
#include <string>
#include <cstdint>
#include <iostream>

int main()
{
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;
	const std::string TITLE = "SFML Tetris!";
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	window.setFramerateLimit(60);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::RectangleShape rect(sf::Vector2f(200, 200));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(sf::Vector2f(100, 100));
	const sf::Color original_rect_color = sf::Color::Green;

	sf::Font font;
	font.loadFromFile("C:\\WINDOWS\\FONTS\\ARIAL.ttf");

	sf::Text text("Hello world", font);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();

		//const float THREAD_SLEEP_TIMER = 0.001f;
		//sf::sleep(sf::seconds(THREAD_SLEEP_TIMER));

		sf::Vector2f current_rect_position = rect.getPosition();

		const float X_OFFSET = 5;
		const float Y_OFFSET = 5;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
			current_rect_position.x > 0)
		{
			current_rect_position += sf::Vector2f(-X_OFFSET, 0);
			std::clog << "Left\n";
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
			current_rect_position.x + rect.getSize().x < WIDTH)
		{
			current_rect_position += sf::Vector2f(X_OFFSET, 0);
			std::clog << "Right\n";
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
			current_rect_position.y + rect.getSize().y < HEIGHT)
		{
			current_rect_position += sf::Vector2f(0, Y_OFFSET);
			std::clog << "Down\n";
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			current_rect_position.y > 0)
		{
			current_rect_position += sf::Vector2f(0, -Y_OFFSET);
			std::clog << "Up\n";
		}		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		{
			rect.setFillColor(sf::Color::White);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (sf::Mouse::getPosition(window).x > current_rect_position.x                    &&
				sf::Mouse::getPosition(window).x < current_rect_position.x + rect.getSize().x &&
				sf::Mouse::getPosition(window).y > current_rect_position.y                    &&
				sf::Mouse::getPosition(window).y < current_rect_position.y + rect.getSize().y)
			{
				rect.setFillColor(sf::Color::Yellow);
			}
			else
			{
				rect.setFillColor(original_rect_color);
			}
		}

		rect.setPosition(current_rect_position);
		window.draw(rect);

		text.setPosition(rect.getPosition() + sf::Vector2f(10, 10));
		window.draw(text);

		window.display();
	}
	return 0;
}
