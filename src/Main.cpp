#include "Game.h"
#include <time.h>



//$$	- Main -    $$
int main() {

	srand(time(static_cast<unsigned>(0)));

	Game game;

		game.run();

// End of application			
	return 0;
}
//---------------------------------------------------------

//Tasks to be undertaken :
//You are to implement a version of the classic arcade game Space Invaders in C++
//using the Visual Studio IDE with the SFML libraries.The mechanics of the game are
//as follows :
//• The player controls a horizontal moving ship with a laser which is rectangular
//in shape.The ship moves left and right.These movements should be linked to
//the arrow keys.
//• The laser is used to destroy aliens that are gradually descending towards the
//bottom.The firing of the laser should be linked to the space key.
//• The game has three areas on screen.The bottom of the screen where the
//ship moves, a collection of blockades to help protect the laser and the area
//that the aliens move down into.
//• The aliens fire lasers toward the ship which can destroy it and also destroy the
//blockades.
//• The blockades have three stages – complete, partial damage, destroyed.
//• The player has three lives.After the three lives are exhausted, the game
//finishes.
//• The player loses a life if the ship is hit or one of the aliens reaches the bottom
//of the screen.
//• The player wins by destroying all of the aliens.

