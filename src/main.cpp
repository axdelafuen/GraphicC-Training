#include <iostream>
#include "game.hpp"

int main(){

	Game game{};

	while (game.getWindowIsOpen()){
		game.update();
		game.render();
    	}
	return 0;
}
