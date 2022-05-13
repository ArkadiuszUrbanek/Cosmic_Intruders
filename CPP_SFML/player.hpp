/** @file*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "collidable.hpp"
#include "projectile.hpp"
#include "animation.hpp"

/** Klasa reprezentujaca statek gracza, dziedzicz�ca po @ref collidable.*/

class player final : public collidable {
private:

	sf::Texture m_player_texture; ///< Tekstura statku gracza

	sf::RectangleShape m_sprite_top; ///< G�rna cz�� statku gracza
	sf::RectangleShape m_sprite_bottom; ///< Dolna cz�� statku gracza

	sf::Texture m_player_death_spritesheet; ///< Tekstura wybuchaj�cego statku gracza
	animation m_player_death_animation; ///< Animacja wybuchu statku gracza
	sf::RectangleShape m_sprite_player_destroyed; ///< Kszta�t prostok�ta, na kt�ry jest nak�adana jest tekstura wybuchu statku gracza

	const float m_max_speed = 100.0f; ///< Domy�lna pr�dko�� maksymalna statku gracza
	const float m_acceleration = 81.25f; ///< Domy�lne przyspieszenie statku gracza
	const sf::Time m_time_to_reach_max_speed = sf::seconds(m_max_speed / m_acceleration); ///< Czas potrzebny do osi�gni�cia pr�dko�ci maksymalnej

	sf::Time m_time_of_movement = sf::seconds(0.0f); ///< Aktualny czas ruchu statku gracza w okre�lon� stron�

	bool m_alive = true; ///< Zmienna sygnalizuj�ca czy gracz �yje

	bool m_stopped = true; ///< Zmienna sygnalizuj�ca czy gracz zatrzyma� sw�j statek w miejscu
	bool m_moving_right = false; ///< Zmienna sygnalizuj�ca czy statek gracza porusza si� w prawo
	bool m_moving_left = false; ///< Zmienna sygnalizuj�ca czy statek gracza porusza si� w lewo

	const sf::Time m_time_interval_between_shots = sf::seconds(0.2f); ///< Czas prze�adowania dzia�a
	sf::Clock m_shot_clock; ///< Zegar zliczaj�cy czas od momentu oddania nowego strza�u przez gracza
	bool m_shot_fired = false; ///< Zmienna sygnalizuj�ca czy gracz odda� strza�

	sf::Clock m_death_timer; ///< Zegar zliczaj�cy czas od momentu zniszczenia statku gracza
	bool m_death_timer_restarted = false; ///< Zmienna sygnalizuj�ca czy zegar odliczaj�cy czas do odrodzenia gracza zosta� uprzednio zrestartowany

	/** Prywatna metoda statyczna klasy @ref player
	* �aduje tekstur� wybuchu gracza.
	* @return Tekstura wybuchu gracza
	*/
	static sf::Texture load_player_death_spritesheet();

	/** Prywatna metoda klasy @ref player
	* Aktualizuje pozycj� gracza w oknie gry.
	* @param[in] delta_time Czas mi�dzy kolejnymi klatkami
	*/
	void update_position(sf::Time delta_time);

public:

	/** Konstruktor klasy @ref player
	* @param[in] speed Pr�dko�� maksymalna gracza
	* @param[in] acceleration Przyspieszenie gracza
	* @param[in] time_interval_between_shots Czas prze�adowania dzia�a
	*/
	player(float speed, float acceleration, sf::Time time_interval_between_shots);

	/** Metoda klasy @ref player
	* Przywraca pocz�tkowe warto�ci p�l klasy.
	*/
	void reset();

	/** Metoda klasy @ref player
	* Odradza gracza.
	*/
	void respawn();

	/** Metoda klasy @ref player
	* Obs�uguje sterowanie statkiem gracza.
	*/
	void handle_input();

	/** Niemodyfikuj�ca metoda inline klasy @ref player
	* Sprawdza czy gracz �yje.
	* @return Warto�� true lub false
	*/
	bool is_alive() const { return m_alive; }

	/** Metoda klasy @ref player
	* Sprawdza czy gracz w danej klatce wystrzeli� pocisk. Je�eli gracz wystrzeli� pocisk to pod pole m_shot_fired jest podstawiana warto�� false.
	* @return Warto�� true lub false
	*/
	bool shot_fired();

	/** Metoda klasy @ref player
	* Aktualizuje wszelkie informacje o graczu.
	* @param[in] delta_time Czas mi�dzy kolejnymi klatkami
	*/
	void update(sf::Time delta_time);

	/** Przes�oni�ta metoda wirtualna klasy @ref player
	* Ustawia pozycj� statku gracza.
	* @param[in] position Nowa pozycja statku gracza
	*/
	virtual void set_position(sf::Vector2f position) override;

	/** Niemodyfikuj�ca metoda klasy @ref player
	* Zwraca aktualn� pozycj� statku gracza.
	* @return Wektor matematyczny
	*/
	sf::Vector2f get_position() const;

	/** Niemodyfikuj�ca metoda klasy @ref player
	* Zwraca aktualn� pozycje dzia�a statku gracza.
	* @return Wektor matematyczny
	*/
	sf::Vector2f get_gun_position() const;

	/** Metoda klasy @ref player
	* Sprawdza kolizj� statku gracza z boxami kolizyjnymi intruder�w.
	* @param[in] collsion_boxes Boxy kolizyjne
	* @return Warto�� true lub false
	*/
	bool intruders_collision(const std::vector<sf::FloatRect>& collsion_boxes);

	/** Metoda klasy @ref player
	* Sprawdza kolizj� statku gracza z boxami kolizyjnymi intruder�w.
	* @param[in] enemy_projectile Pocisk intrudera, z kt�rym jest sprawdzana kolizja
	* @return Warto�� true lub false
	*/
	bool projectile_collision(const projectile& enemy_projectile);

	/** Przes�oni�ta niemodyfikuj�ca metoda wirtualna klasy @ref player
	* Rysuje statek gracza w oknie gry.
	* @param[in,out] window Referencja do okna gry
	*/
	virtual void draw(sf::RenderWindow& window) const override;

};

#endif
