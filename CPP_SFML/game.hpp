/** @file*/

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "state_machine.hpp"

/** Klasa tworz�ca gr�.*/

class game {
private:
	state_machine m_machine; ///< Maszyna stan�w
	sf::RenderWindow m_window; ///< Okno gry

public:

	static constexpr unsigned char m_FPS_LIMIT = 75; ///< Limit klatek na sekund�
	static constexpr unsigned short int m_WINDOW_WIDTH = 800; ///< Szeroko�� okna gry 
	static constexpr unsigned short int m_WINDOW_HEIGHT = 600; ///< Wysoko�� okna gry

	/** Domy�lny konstruktor klasy @ref game*/
	game();

	/** Domy�lny destruktor klasy @ref game*/
	~game();

	/** Metoda klasy @ref game
	* Rozpoczyna gr�.
	*/
	void run();

};

#endif