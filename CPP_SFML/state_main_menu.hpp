/** @file*/

#ifndef STATE_MAIN_MENU_HPP
#define STATE_MAIN_MENU_HPP

#include "state_base.hpp"
#include "menu.hpp"

/** Klasa-stan menu g��wne.*/

class state_main_menu final : public state_base {
private:

	menu m_menu; ///< Obiekt klasy @ref menu

public:

	/** Konstruktor klasy @ref state_main_menu
	* @param[in] machine Referencja do maszyny stan�w
	* @param[in] window Referencja do okna gry
	*/
	state_main_menu(state_machine& machine, sf::RenderWindow& window);

	/** Przes�oni�ta metoda wirtualna klasy @ref state_main_menu
	* Zbiera informacje o wydarzeniach.
	*/
	void poll_events() override;

	/** Przes�oni�ta metoda wirtualna klasy @ref state_main_menu
	* Aktualizuje stan main menu uwzgl�dniaj�c czas jaki up�yna�.
	* @param[in] delta_time Czas mi�dzy kolejnymi klatkami
	*/
	void update(sf::Time delta_time) override;

	/** Przes�oni�ta metoda wirtualna klasy @ref state_main_menu
	* Rysuje i wy�wietla w oknie gry opcje klasy @ref menu.
	*/
	void render() override;

};

#endif