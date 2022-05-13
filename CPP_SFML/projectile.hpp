/** @file*/

#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "collidable.hpp"

/** Klasa reprezentujaca wszystkie pociski w grze. Dziedziczy po @ref collidable.*/

class projectile final : public collidable {
private:

	sf::Texture m_projectile_texture; ///< Tekstura pocisku
	sf::RectangleShape m_sprite; ///< Kszta�t prostok�ta, na kt�ry jest nak�adana tekstura pocisku

	float m_speed; ///< Pr�dko�� pocisku

	bool m_destroyed = false; ///< Zmienna sygnalizuj�ca czy pocisk zosta� zniszczony

	bool m_moving_up; ///< Zmienna sygnalizuj�ca czy pocisk porusza si� w g�r�

public:

	/** Konstruktor klasy @ref projectile
	* @param[in] position Pozycja startowa pocisku
	* @param[in] speed Pr�dko�� pocisku
	*/
	projectile(sf::Vector2f position, float speed);

	/** Metoda klasy @ref projectile
	* Aktualizuje pozycj� pocisku w oknie gry.
	* @param[in] delta_time Czas mi�dzy kolejnymi klatkami
	*/
	void update_position(sf::Time delta_time);

	/** Przes�oni�ta metoda wirtualna klasy @ref projectile
	* Ustawia pozycj� pocisku.
	* @param[in] position Nowa pozycja pocisku
	*/
	virtual void set_position(sf::Vector2f position) override;

	/** Niemodyfikuj�ca metoda inline klasy @ref projectile
	* Sprawdza czy pocisk porusza si� w g�r�.
	* @return Warto�� true lub false
	*/
	bool is_moving_up() const { return m_moving_up; }

	/** Niemodyfikuj�ca metoda inline klasy @ref projectile
	* Sprawdza czy pocisk zosta� zniszczony.
	* @return Warto�� true lub false
	*/
	bool is_destroyed() const { return m_destroyed; }

	/** Metoda inline klasy @ref projectile
	* Niszczy pocisk.
	*/
	void destroy() { m_destroyed = true; }

	/** Niemodyfikuj�ca metoda klasy @ref projectile
	* Zwraca aktualn� pozycj� pocisku.
	* @return Wektor matematyczny
	*/
	sf::Vector2f get_position() const;

	/** Metoda klasy @ref projectile
	* Sprawdza kolizj� pocisku z innym pociskiem.
	* @param[in] other_projectile Pocisk, z kt�rym jest sprawdzana kolizja
	* @return Warto�� true lub false
	*/
	bool projectile_collision(const projectile& other_projectile);

	/** Niemodyfikuj�ca metoda inline klasy @ref projectile
	* Zwraca globalne koordynaty pocisku.
	* @return Sta�y obiekt klasy FloatRect
	*/
	const sf::FloatRect get_global_bounds() const { return m_sprite.getGlobalBounds(); }

	/** Przes�oni�ta niemodyfikuj�ca metoda wirtualna klasy @ref projectile
	* Rysuje pocisk w oknie gry.
	* @param[in,out] window Referencja do okna gry
	*/
	virtual void draw(sf::RenderWindow& window) const override;

};

#endif