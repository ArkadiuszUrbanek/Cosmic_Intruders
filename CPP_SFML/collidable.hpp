/** @file*/

#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP

#include <SFML/Graphics.hpp>

/** Klasa abstrakcyjna, stanowi�ca baz� dla ka�dego obiektu, z kt�rym sprawdzane s� kolizje w trakcie rozgrywki.*/

class collidable {
protected:
	sf::Vector2f m_box; ///< Obiekt klasy Vector2f, przechowuj�cy wymiary boxa obiektu w grze

public:
	/** Konstruktor klasy @ref collidable
	* @param[in] box Wymiary boxa obiektu
	*/
	collidable(sf::Vector2f box) : m_box(box) {}

	/** Niemodyfikuj�ca metoda klasy @ref collidable
	* Zwraca wymiary boxa obiektu.
	* @return Wymiary boxa obiektu
	*/
	sf::Vector2f get_box() const { return m_box; }

	/** Metoda czysto wirtualna klasy @ref collidable
	* Ustawia pozycj� obiektu.
	* @param[in] position Nowa pozycja obiektu
	*/
	virtual void set_position(sf::Vector2f position) = 0;

	/** Niemodyfikuj�ca metoda czysto wirtualna klasy @ref collidable
	* Rysuje obiekt w oknie gry.
	* @param[in,out] window Referencja do okna gry
	*/
	virtual void draw(sf::RenderWindow& window) const = 0;

};

#endif