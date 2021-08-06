#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int W = 650;
int H = 650; // you can change this to full window size later

int n = 0;
float c = 4;
int red = 0;
int green = 200;
int blue = 40;
float Angle = 137.5;

int main()
{

	cout << "Spacing [0.0 - 10.0] : ";
    cin >> c;
	cout << "Angle [0 - 360]: ";
	cin >> Angle;
	cout << "Colours [0 - 255]" << "\n";
	cout << "Red: ";
	cin >> red;
	cout << "Green: ";
	cin >> green;
	cout << "Blue: ";
	cin >> blue;

	if (red <= 0)
		red = 1;

	if (blue <= 0)
		blue = 1;

	if (green <= 0)
		green = 1;

	if (c > 10)
		c = 10;

	if (Angle > 360)
		Angle = 360;

	sf::ContextSettings settings;
	sf::RenderWindow window(sf::VideoMode(W, H), "Phyllotaxis", sf::Style::Close);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (n < 5000) {
			float a = n * Angle;
			float r = c * sqrt(n);
			int x = r * cos(a) + W/2;
			int y = r * sin(a) + H/2;

			CircleShape point(4);
			point.setFillColor(Color(n % red, n % green, n % blue));
			point.setOutlineThickness(1);
			point.setOutlineColor(Color(0, 0, 0));
			point.setPosition(x, y);

			window.draw(point);
			window.display();
			n++;
		}
	}
	return NULL;
}
