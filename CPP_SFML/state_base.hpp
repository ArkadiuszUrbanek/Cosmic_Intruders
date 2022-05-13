/** @file*/

#ifndef STATE_BASE_HPP
#define STATE_BASE_HPP

#include "SFML/Graphics.hpp"

class state_machine;

/** Klasa abstrakcyjna, stanowi�ca baz� dla ka�dego stanu, kt�ry wyst�puje w programie.*/

class state_base {
protected:
	state_machine& m_machine; ///< Referencja do maszyny stan�w
	sf::RenderWindow& m_window; ///< Referencja do okna gry
	sf::Event m_event; ///< Wydarzenie, kt�re jest zwi�zane z myszk� lub klawiatur�

public:

	/** Konstruktor klasy @ref state_base
	* @param[in] machine Maszyna stan�w
	* @param[in] window Okno gry
	*/
	state_base(state_machine& machine, sf::RenderWindow& window);

	/** Metoda czysto wirtualna klasy @ref state_base
	* Zbiera informacje o wydarzeniach.
	*/
	virtual void poll_events() = 0;

	/** Metoda czysto wirtualna klasy @ref state_base
	* Atualizuje stan uwzgl�dniaj�c czas jaki up�yna�.
	* @param[in] delta_time Czas mi�dzy kolejnymi klatkami
	*/
	virtual void update(sf::Time delta_time) = 0;

	/** Metoda czysto wirtualna klasy @ref state_base
	* Rysuje i wy�wietla w oknie gry elementy nale��ce do stanu.
	*/
	virtual void render() = 0;

};

#endif
