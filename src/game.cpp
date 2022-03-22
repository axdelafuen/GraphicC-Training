#include "game.hpp"

// Const / Dest

Game::Game(){
	this-> initVariables();
	this-> initWindow();
}

Game::~Game(){
	delete this->window;
}

// Init variables & fenetre

void Game::initVariables(){
	// init window
	this->window = nullptr;

	// init le cercle (le joueur)
	this->circle.setRadius(60.f);
	this->circle.setPosition(0,0);
	this->circle.setFillColor(sf::Color::Green);

	// init un enemy
	this->enemy.setRadius(25.f);
	this->enemy.setPosition(500,500);
	this->circle.setFillColor(sf::Color::Red);
}

void Game::initWindow(){
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Rogue Like !");
}

// Update et render de la fenetre

void Game::update(){
	this->pollEvent();

	this->enemyMoov();
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		this->LeftCircle();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		this->RightCircle();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		this->DownCircle();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		this->UpCircle();
	}
}

void Game::pollEvent(){
	while (this->window->pollEvent(this->ev)){
		if (this->ev.type == sf::Event::Closed)
               	this->window->close();
       	}
}

void Game::render(){
	this->window->clear(sf::Color(64,64,64,255));

	this->window->draw(this->circle);
	this->window->draw(this->enemy);

	this->window->display();
}		

// Getter

bool Game::getWindowIsOpen()const{
	return this->window->isOpen();
}

// Methode 

void Game::UpCircle(){
	this->circle.setPosition(this->circle.getPosition().x,this->circle.getPosition().y-1.f);
}

void Game::DownCircle(){
	this->circle.setPosition(this->circle.getPosition().x,this->circle.getPosition().y+1.f);
}

void Game::LeftCircle(){
	this->circle.setPosition(this->circle.getPosition().x-1.f,this->circle.getPosition().y);
}

void Game::RightCircle(){
	this->circle.setPosition(this->circle.getPosition().x+1.f,this->circle.getPosition().y);
}

void Game::enemyMoov(){
	this->enemy.setRotation(this->enemy.getRotation()+0.3);
}

