/** @file*/

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>

/** Klasa zmieniaj�ca obrazek w okre�lonych odst�pach czasu.*/

class animation {
private:
	sf::IntRect m_image_rect; ///< Obiekt klasy IntRect, kt�ry przechowuje informacj� o aktualnych koordynatach obrazka  

	const sf::Vector2u m_image_count; ///< Sta�y obiekt klasy Vector2u, informuj�cy o liczebno�ci obrazk�w w cyklu animacji 
	sf::Vector2u m_current_image; ///< Obiekt klasy Vector2u, informuj�cy o aktualnym rz�dzie i kolumnie, w kt�rym znajduje si� obrazek 

	sf::Time m_total_time; ///< Obiekt klasy Time, s�u��cy do zliczania czasu, kt�ry up�yn�� od pocz�tku kolejnej klatki animacji
	const sf::Time m_switch_time; ///< Sta�y obiekt klasy Time, przechowuj�cy informacj� o tym ile czasu ma by� wy�wietlana jedna klatka animacji

public:

	/** Konstruktor tr�jargumentowy klasy @ref animation
	* @param[in] texture Wska�nik na tekstur�
	* @param[in] image_count Ilo�� obrazk�w w rz�dzie oraz ilo�� rz�d�w obrazk�w
	* @param[in] switch_time Czas wy�wietlania jednej klatki animacji
	*/
	animation(sf::Texture* texture, sf::Vector2u image_count, sf::Time switch_time);

	/** Metoda klasy @ref animation
	* Aktualizuje czas, kt�ry up�yna� od ostatniego wywo�ania metody update i w razie konieczno�ci zmienia obrazek na kolejny w podanym rz�dzie.
	* @param[in] row Rz�d obrazk�w
	* @param[in] delta_time Czas, kt�ry up�yn�� od ostatniego wywo�ania metody update
	*/
	void update(int row, sf::Time delta_time);

	/** Metoda klasy @ref animation
	* Wymusza zmian� obrazka.
	* @param[in] row Rz�d obrazk�w
	*/
	void force_update(int row);

	/** Metoda klasy @ref animation
	* Resetuje animacj�. Ustawia na pierwszy obrazek animacji.
	* @param[in] row Rz�d obrazk�w
	*/
	void reset(int row);

	/** Metoda klasy @ref animation
	* Zwraca koordynaty aktualnego obrazka.
	* @return sta�y obiekt klasy IntRect, kt�ry przechowuje informacj� o koordynatach aktualnego obrazka 
	*/
	const sf::IntRect& get_image_rect() const { return m_image_rect; }

};

#endif
