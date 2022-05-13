/** @file*/

#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "collidable.hpp"
#include "projectile.hpp"

/** Klasa reprezentuj�ca os�ony, za kt�rymi mo�e schowa� si� gracz. Dziedziczy po klasie @ref collidable. Pojedyncza os�ona jest podzielona na dwana�cie sekcji, kt�re s� kwadratami lub tr�jk�tami.*/

class shield final : public collidable {
private:

	sf::Texture m_square_texture; ///< Tekstura kwadratu
	sf::Texture m_triangle_texture; ///< Tekstura tr�jk�ta

	/// Silny typ wyliczeniowy okre�laj�cy rodzaj sekcji os�ony
	enum class section_style { 
		square, ///< Kwadrat
		slope_0, ///< Tr�jk�t obr�cony rogiem w lewo
		slope_90, ///< Tr�jk�t obr�cony rogiem w prawo
		slope_180, ///< Tr�jk�t odwr�cony do g�ry nogami i obr�cony rogiem w prawo
		slope_270 ///< Tr�jk�t odwr�cony do g�ry nogami i obr�cony rogiem w lewo
	};

	/** Struktura przechowuj�ca informacje o danej sekcji os�ony*/
	struct shield_section {
		sf::RectangleShape m_sprite; ///< Kszta�t prostok�ta, na kt�ry jest nak�adana tekstura kwadratu lub tekstura tr�jk�ta
		shield::section_style m_style; ///< Rodzaj sekcji os�ony
		bool m_destroyed; ///< Zmienna sygnalizuj�ca czy sekcja zosta�a zniszczona
	};
	
	static constexpr unsigned int m_TOTAL_NUMBER_OF_ROWS = 3; ///< Liczba rz�d�w sekcji os�ony
	static constexpr unsigned int m_TOTAL_NUMBER_OF_COLUMNS = 4; ///< Liczba kolumn sekcji os�ony

	shield_section m_array_of_shield_sections[m_TOTAL_NUMBER_OF_ROWS][m_TOTAL_NUMBER_OF_COLUMNS]; ///< Macierz informacji o wszystkich sekcjach os�ony

public:

	/** Domy�lny konstruktor klasy @ref shield*/
	shield();

	/** Metoda klasy @ref shield
	* Przywraca pocz�tkowe warto�ci p�l klasy.
	*/
	void reset();

	/** Przes�oni�ta metoda wirtualna klasy @ref shield
	* Ustawia pozycj� os�ony.
	* @param[in] position Nowa pozycja os�ony
	*/
	virtual void set_position(sf::Vector2f position) override;

	/** Przes�oni�ta niemodyfikuj�ca metoda wirtualna klasy @ref shield
	* Rysuje os�on� w oknie gry.
	* @param[in,out] window Referencja do okna gry
	*/
	virtual void draw(sf::RenderWindow& window) const override;

	/** Metoda klasy @ref shield
	* Sprawdza kolizj� os�ony z boxami kolizyjnymi intruder�w.
	* @param[in] collsion_boxes Boxy kolizyjne
	*/
	void intruders_collision(const std::vector<sf::FloatRect>& collsion_boxes);

	/** Metoda klasy @ref shield
	* Sprawdza kolizj� os�ony z pociskiem.
	* @param[in] projectile Pocisk, z kt�rym jest badana kolizja
	*/
	void projectile_collision(projectile& projectile);

};

#endif
