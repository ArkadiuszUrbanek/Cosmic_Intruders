/** @file*/

#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <initializer_list>
#include <string>

#include "button.hpp"

/** Klasa reprezentuj�ca menu.*/

class menu {
private:

	sf::Font m_font; ///< Czcionka tekst�w, kt�re reprezentuj� opcje menu
	int m_number_of_options; ///< Liczba wszystkich opcji menu
	int m_selected_option_index; ///< Indeks aktualnie wybranej opcji z menu
	button* m_ptr_options_array; ///< Wska�nik na tablic� przycisk�w

public:

	/** Konstruktor klasy @ref menu
	* @param[in] window Sta�a referencja do okna gry
	* @param[in] options_list Lista nazw opcji menu
	*/
	menu(const sf::RenderWindow& window, std::initializer_list<std::string> options_list);

	/** Destruktor klasy @ref menu */
	~menu();

	/** Niemodyfikuj�ca metoda klasy @ref menu
	* Rysuje menu w oknie gry.
	* @param[in,out] window Referencja do okna gry
	*/
	void draw(sf::RenderWindow& window) const;

	/** Metoda klasy @ref menu
	* Zmienia wybran� opcj� z menu na poprzedni� z opcji menu.
	*/
	void option_previous();

	/** Metoda klasy @ref menu
	* Zmienia wybran� opcj� z menu na nast�pn� z opcji menu.
	*/
	void option_next();

	/** Metoda klasy @ref menu
	* Sprawdza nad kt�r� opcj� z menu znajduje si� kursor myszy.
	* @param[in] window Sta�a referencja do okna gry
	* @return Indeks aktualnie wybranej opcji z menu
	*/
	int option_mouse_hover(const sf::RenderWindow& window);

	/** Niemodyfikuj�ca metoda klasy @ref menu
	* Zwraca aktualnie wybran� opcj� z menu.
	* @return Indeks aktualnie wybranej opcji z menu
	*/
	int get_selected_option_index() const;

};

#endif