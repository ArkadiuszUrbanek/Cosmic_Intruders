/** @file*/

#ifndef INTRUDER_HPP
#define INTRUDER_HPP

#include "collidable.hpp"
#include "projectile.hpp"

/** Klasa reprezentujaca intrudera, dziedzicz�ca po @ref collidable.*/

class intruder final : public collidable {
public:

	/// Silny typ wyliczeniowy okre�laj�cy rodzaj intrudera
	enum class intruder_type : char { 
		OCTOPUS = 10, ///< O�miornica
		CRAB = 20, ///< Krab
		SQUID = 30 ///< Ka�amarnica
	};

private:

	const intruder_type m_intruder_type; ///< Zmienna przechowuj�ca informacj� o rodzaju intrudera
	sf::RectangleShape m_sprite; ///< Kszta�t prostok�ta, na kt�ry jest nak�adana odpowiednia tekstura intrudera
	
	/// Silny typ wyliczeniowy okre�laj�cy faz� odrywania si� intrudera od grupy
	enum class detached_intruder_state : unsigned char { 
		FIRST_PHASE = 1, ///< Pierwsza faza odrywania si� od grupy
		SECOND_PHASE, ///< Druga faza odrywania si� od grupy
		THIRD_PHASE ///< Trzecia faza odrywania si� od grupy
	};

	detached_intruder_state m_detached_intruder_state; ///< Zmienna przechowuj�ca informacj� o aktualnej fazie odrywania si� intrudera

	bool m_alive = true; ///< Zmienna sygnalizuj�ca czy dany intruder �yje

	bool m_detached = false; ///< Zmienna sygnalizuj�ca czy dany intruder od��czy� si� od grupy
	bool m_moving_left; ///< Zmienna sygnalizuj�ca czy intruder od��czony od grupy porusza si� w lewo

public:

	/** Konstruktor klasy @ref intruder
	* @param[in] texture Wska�nik na tekstur� intrudera
	* @param[in] intruder_type Rodzaj intrudera
	*/
	intruder(sf::Texture* texture, intruder_type intruder_type);

	/** Metoda klasy @ref intruder
	* Przywraca pocz�tkowe warto�ci p�l klasy.
	*/
	void reset();

	/** Metoda klasy @ref intruder
	* Zwraca punkty za zestrzelenie intrudera.
	* @return Punkty za zestrzelenie intrudera
	*/
	unsigned int return_points();

	/** Metoda klasy @ref intruder
	* Sprawdza kolizj� intrudera z pociskiem.
	* @param[in] projectile Sta�a referencja do pocisku, z kt�rym b�dzie badana kolizja
	* @return Warto�� true lub false
	*/
	bool projectile_collision(const projectile& projectile);

	/** Metoda klasy @ref intruder
	* Uaktualnia koordynaty obrazka intrudera.
	* @param[in] rect Sta�a referencja do obiektu klasy IntRect
	*/
	void update_texture_rect(const sf::IntRect& rect);

	/** Niemodyfikuj�ca metoda inline klasy @ref intruder
	* Zwraca rodzaj intrudera.
	* @return Rodzaj intrudera
	*/
	const intruder_type& get_intruder_type() const { return m_intruder_type; }

	/** Metoda klasy @ref intruder
	* Przesuwa nieod��czonego intrudera w oknie gry o zadany wektor.
	* @param[in] distance Matematyczny wektor 
	*/
	void move(sf::Vector2f distance);

	/** Niemodyfikuj�ca metoda inline klasy @ref intruder
	* Sprawdza czy intruder �yje.
	* @return Warto�� true lub false
	*/
	bool is_alive() const { return m_alive; }

	/** Niemodyfikuj�ca metoda inline klasy @ref intruder
	* Sprawdza czy intruder od��czy� si� od grupy.
	* @return Warto�� true lub false
	*/
	bool is_detached() const { return m_detached;  }

	/** Metoda inline klasy @ref intruder
	* Od��cza intrudera od grupy.
	*/
	void detach() { m_detached = true; m_detached_intruder_state = detached_intruder_state::FIRST_PHASE; }

	/** Metoda klasy @ref intruder
	* Przesuwa od��czonego intrudera w oknie gry o zadany wektor.
	* @param[in] distance Matematyczny wektor
	*/
	void move_detached(sf::Vector2f distance);

	/** Metoda inline klasy @ref intruder
	* Ustawia kierunek ruchu intrudera w lewo.
	*/
	void set_moving_left() { m_moving_left = true; }

	/** Metoda inline klasy @ref intruder
	* Ustawia kierunek ruchu intrudera w prawo.
	*/
	void set_moving_right() { m_moving_left = false; }

	/** Niemodyfikuj�ca metoda inline klasy @ref intruder
	* Sprawdza czy od��czony od grupy intruder porusza si� w lewo.
	* @return Warto�� true lub false
	*/
	bool is_moving_left() const { return m_moving_left; }

	/** Metoda inline klasy @ref intruder
	* Zmienia kierunek ruchu od��czonego intrudera na przeciwny.
	*/
	void switch_moving_direction() { if (m_detached_intruder_state == detached_intruder_state::THIRD_PHASE) m_moving_left = !m_moving_left; }

	/** Niemodyfikuj�ca metoda inline klasy @ref intruder
	* Zwraca aktualn� pozycj� intrudera.
	* @return Sta�y matematyczny wektor
	*/
	const sf::Vector2f& get_position() const { return m_sprite.getPosition(); }

	/** Przes�oni�ta metoda wirtualna klasy @ref intruder
	* Ustawia pozycj� intrudera.
	* @param[in] position Nowa pozycja intrudera
	*/
	virtual void set_position(sf::Vector2f position) override;

	/** Przes�oni�ta niemodyfikuj�ca metoda wirtualna klasy @ref intruder
	* Rysuje intrudera w oknie gry.
	* @param[in,out] window Referencja do okna gry
	*/
	virtual void draw(sf::RenderWindow& window) const override;

};

#endif
