/** @file*/

#ifndef STATE_SETTINGS_HPP
#define STATE_SETTINGS_HPP

#include "state_base.hpp"
#include "button.hpp"

#include <array>

/** Klasa-stan ustawienia gry.*/

class state_settings final : public state_base {
private:
	sf::Font m_font; ///< Czcionka
	unsigned int m_selected_index; ///< Indeks wybranego poziomu trudno�ci

	button m_title; ///< Tytu� "Select difficulty"
	std::array<button, 3> m_array_of_buttons; ///< Tablica przycisk�w z nazwami poziom�w trudno�ci
	std::array <sf::ConvexShape, 2> m_triangles; ///< Tablica dw�ch tr�jk�t�w r�wnobocznych

public:

	/** Konstruktor klasy @ref state_settings
	* @param[in] machine Referencja do maszyny stan�w
	* @param[in] window Referencja do okna gry
	*/
	state_settings(state_machine& machine, sf::RenderWindow& window);

	/** Przes�oni�ta metoda wirtualna klasy @ref state_settings
	* Zbiera informacje o wydarzeniach.
	*/
	void poll_events() override;

	/** Przes�oni�ta metoda wirtualna klasy @ref state_settings
	* Aktualizuje stan rozgrywki uwzgl�dniaj�c czas jaki up�yna�.
	* @param[in] delta_time Czas mi�dzy kolejnymi klatkami
	*/
	void update(sf::Time delta_time) override;

	/** Przes�oni�ta metoda wirtualna klasy @ref state_playing
	* Rysuje i wy�wietla w oknie gry napis "Select difficulty" oraz nazw� wybranego poziomu trudno�ci.
	*/
	void render() override;

};

#endif