/** @file*/

#ifndef INTRUDER_MANAGER_HPP
#define INTRUDER_MANAGER_HPP

#include <array>
#include <vector>

#include "intruder.hpp"
#include "animation.hpp"

#define INTRUDER_ROWS 6
#define INTRUDER_COLUMNS 8

/** Klasa zarz�dzaj�ca grup� intruder�w.*/

class intruder_manager {
private:
	std::array<sf::Texture, 3> m_intruders_textures; ///< Tablica tekstur intruder�w
	std::array<animation, 3> m_intruders_animations; ///< Tablica animacji intruder�w

	std::vector<std::vector<intruder>> m_intruders_matrix; ///< Macierz intruder�w

	unsigned short m_number_of_living_intruders_in_row[INTRUDER_ROWS]; ///< Tablica �ywych intruder�w w rz�dzie, z kt�rego ma nastapi� oderwanie losowego intrudera
	unsigned short m_index_of_lowest_living_row; ///< Indeks najni�szego rz�du, w kt�rym �yje co najmniej jeden intruder
	bool m_detach_intruder = true; ///< Zmienna sygnalizuj�ca czy nale�y oderwa� intrudera od grupy

	const unsigned short m_default_number_of_enemies_alive = INTRUDER_COLUMNS * INTRUDER_ROWS; ///< Domy�lna liczba �ywych intruder�w
	unsigned short m_number_of_enemies_alive = m_default_number_of_enemies_alive; ///< Liczba �ywych intruder�w
	unsigned short m_number_of_enemies_alive_in_group = m_default_number_of_enemies_alive; ///< Liczba �ywych intruder�w, kt�rzy si� nie oderwali od grupy
	
	bool m_group_moving_left = true; ///< Zmienna sygnalizuj�ca czy grupa intruder�w porusza si� w lewo
	bool m_group_moving_down = false; ///< Zmienna sygnalizuj�ca czy dany grupa intruder�w porusza si� w d�

	sf::Clock m_step_clock; ///< Zegar zliczaj�cy czas od ostatniego kroku grupy intruder�w

	const sf::Time m_default_step_gap = sf::seconds(0.5f); ///< Domy�lny czas pomi�dzy kolejnymi krokami intruder�w
	sf::Time m_step_gap = m_default_step_gap; ///< Aktualny czas pomi�dzy kolejnymi krokami intruder�w

	sf::Clock m_intruders_shot_clock; ///< Zegar zliczaj�cy czas od ostatniego wystrzelenia pocisku ze strony intruder�w

	const sf::Time m_default_time_interval_between_shots = sf::seconds(6.0f); ///< Domy�lny czas pomi�dzy kolejnymi wystrza�ami pocisk�w ze strony intruder�w
	sf::Time m_time_interval_between_shots = m_default_time_interval_between_shots; ///< Aktualny czas pomi�dzy kolejnymi wystrza�ami pocisk�w ze strony intruder�w
	
	bool m_points_returned = true; ///< Zmienna sygnalizuj�ca czy zwr�cono punkty za zestrzelenie intrudera
	unsigned int m_points = 0; ///< Punkty za zestrzelenie intrudera

	/** Prywatna metoda statyczna klasy @ref intruder_manager
	* �aduje tekstury intruder�w.
	* @return Tablica za�adowanych tekstur intruder�w
	*/
	static std::array<sf::Texture, 3> load_textures();

	/** Prywatna niemodyfikuj�ca metoda klasy @ref intruder_manager
	* Sprawdza czy dany intruder nie wyszed� poza okno gry.
	* @param[in] intruder Przeciwnik, kt�rego po�o�enie jest sprawdzane
	* @return Warto�� true lub false
	*/
	bool test_intruder_position(const intruder& intruder) const;

	/** Prywatna metoda klasy @ref intruder_manager
	* Uaktualnia czas mi�dzy kolejnymi krokami intruder�w. Wraz ze zmiejszaj�c� si� liczb� intruder�w czas mi�dzy kolejnymi krokami jest skracany.
	*/
	void update_step_gap();

	/** Prywatny, niemodyfikuj�cy szablon metody klasy @ref intruder_manager
	* Losuje liczb� z podanego przedzia�u.
	* @tparam[in] low Dolny zakres
	* @tparam[in] high G�rny zakres
	* @return Sta�a referencja do wylosowanej liczby
	*/
	template<typename T>
	const T& get_number_in_range(T low, T high) const;

public:

	/** Konstruktor klasy @ref intruder_manager
	* @param[in] step_gap Czas pomi�dzy kolejnymi krokami intruder�w
	* @param[in] time_interval_between_shots Czas pomi�dzy kolejnymi wystrza�ami pocisk�w ze strony intruder�w
	*/
	intruder_manager(sf::Time step_gap, sf::Time time_interval_between_shots);

	/** Metoda klasy @ref intruder_manager
	* Przywraca pocz�tkowe warto�ci p�l klasy.
	*/
	void reset();

	/** Metoda klasy @ref intruder_manager
	* Uaktualnia wszelkie informacje o grupie intruder�w.
	*/
	void update();

	/** Metoda klasy @ref intruder_manager
	* Zwraca punkty za zestrzelenie intrudera.
	* @return Punkty za zestrzelenie intrudera
	*/
	unsigned int return_points();

	/** Niemodyfikuj�ca metoda inline klasy @ref intruder_manager
	* Sprawdza czy jacykolwiek intruderzy jeszcze �yj�.
	* @return Warto�� true lub false
	*/
	bool are_intruders_alive() const { return m_number_of_enemies_alive > 0; }

	/** Metoda klasy @ref intruder_manager
	* Sprawdza czy nastapi�a kolizja pocisku z grup� intruder�w.
	* @param[in] projectile Sta�a referencja do pocisku, z kt�rym b�dzie badana kolizja
	* @return Warto�� true lub false
	*/
	bool projectile_collision(const projectile& projectile);

	/** Niemodyfikuj�ca metoda klasy @ref intruder_manager
	* Tworzy pionowe boxy kolizujne na podstawie aktualnie �yj�cych intruder�w.
	* @return Tablica box�w kolizyjnych
	*/
	const std::vector<sf::FloatRect> get_collision_boxes() const;

	/** Metoda klasy @ref intruder_manager
	* Zwraca pozycj� intrudera, kt�ry oddaje strza�. W przypadku, gdy �aden intruder nie odda� strza�u lub wszyscy intruderzy ju� nie �yj� zwracana jest warto�� {-1, -1}.
	* @return Matematyczny wektor
	*/
	sf::Vector2f get_shooter_position();

	/** Niemodyfikuj�ca metoda klasy @ref intruder_manager
	* Rysuje grup� intruder�w w oknie gry.
	* @param[in,out] window Referencja do okna gry
	*/
	void draw(sf::RenderWindow& window) const;

};

#endif