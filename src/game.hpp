#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>



class Game{
private: 
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::CircleShape circle;
	sf::CircleShape enemy;

	void initVariables();
	void initWindow();

	void UpCircle();
	void DownCircle();
	void LeftCircle();
	void RightCircle();

	void enemyMoov();

public:
	Game();
	virtual ~Game();
		
	void update();
	void pollEvent();
	void render();

	bool getWindowIsOpen()const;
};

#endif // RG_HPP
