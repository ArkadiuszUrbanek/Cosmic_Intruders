/** @file*/

#ifndef DIFFICULTY_SETTINGS_HPP
#define DIFFICULTY_SETTINGS_HPP

#include <SFML/Graphics.hpp>
#include <utility>
#include <array>

/** Klasa przechowuj�ca informacj� o ustawieniach gry.*/

class difficulty_settings {
public:

	/// Silny typ wyliczeniowy okre�laj�cy poziomy trudno�ci w grze
	enum class difficulty : char { 
		EASY, ///< �atwy
		NORMAL, ///< Normalny
		HARD ///< Trudny
	};

private:
	static difficulty m_selected_difficulty; ///< Zmienna statyczna przechowuj�ca informacj� o aktualnie wybranym poziomie trudno�ci

	/** Struktura przechowuj�ca ustawienia dla klasy @ref state_playing*/
	struct state_playing_settings {
		unsigned char m_max_player_lives; ///< Maksymalna ilo�� �y� gracza
	};

	static std::array<std::pair<difficulty_settings::difficulty, state_playing_settings>, 3> m_state_playing_settings; ///< Tablica ustawie� dla trzech poziom�w trudno�ci dla klasy @ref state_playing 

	/** Struktura przechowuj�ca ustawienia dla klasy @ref player*/
	struct player_settings {
		float m_player_max_speed; ///< Maksymalna pr�dko�� gracza
		float m_player_acceleration; ///< Maksymalne przy�pieszenie gracza
		sf::Time m_time_interval_between_shots; ///< Czas prze�adowania dzia�a gracza
	};

	static std::array<std::pair<difficulty_settings::difficulty, player_settings>, 3> m_player_settings; ///< Tablica ustawie� dla trzech poziom�w trudno�ci dla klasy @ref player 

	/** Struktura przechowuj�ca ustawienia dla klasy @ref intruder_manager*/
	struct intruder_manager_settings {
		sf::Time m_step_gap; ///< Odst�p czasu pomi�dzy kolejnymi krokami intruder�w
		sf::Time m_time_interval_between_shots; ///< Odst�p czasu pomi�dzy kolejnymi pociskami wystrzelonymi przez intruder�w
	};

	static std::array<std::pair<difficulty_settings::difficulty, intruder_manager_settings>, 3> m_intruder_manager_settings; ///< Tablica ustawie� dla trzech poziom�w trudno�ci dla klasy @ref intruder_manager 

public:

	/** Metoda statyczna klasy @ref difficulty_settings
	* Zwraca ustawienia dla aktualnie wybranego poziomu trudno�ci dla klasy @ref state_playing.
	* @return Para warto�ci: poziom trudno�ci i struktura z ustawieniami
	*/
	static std::pair<difficulty_settings::difficulty, state_playing_settings> get_state_playing_difficulty_settings();

	/** Metoda statyczna klasy @ref difficulty_settings
	* Zwraca ustawienia dla aktualnie wybranego poziomu trudno�ci dla klasy @ref player.
	* @return Para warto�ci: poziom trudno�ci i struktura z ustawieniami
	*/
	static std::pair<difficulty_settings::difficulty, player_settings> get_player_difficulty_settings();

	/** Metoda statyczna klasy @ref difficulty_settings
	* Zwraca ustawienia dla aktualnie wybranego poziomu trudno�ci dla klasy @ref intruder_manager.
	* @return Para warto�ci: poziom trudno�ci i struktura z ustawieniami
	*/
	static std::pair<difficulty_settings::difficulty, intruder_manager_settings> get_intruder_manager_difficulty_settings();

	/** Metoda statyczna klasy @ref difficulty_settings
	* Zwraca nazw� aktualnie wybranego poziomu trudno�ci.
	* @return Sta�y �a�cuch znak�w
	*/
	static const std::string get_selected_difficulty_name(); 

	/** Metoda statyczna klasy @ref difficulty_settings
	* Zwraca nazw� przekazanego przez argument poziomu trudno�ci.
	* @param[in] difficulty Poziom trudno�ci
	* @return Sta�y �a�cuch znak�w
	*/
	static const std::string get_difficulty_name(difficulty_settings::difficulty difficulty);

	/** Metoda statyczna klasy @ref difficulty_settings
	* Zwraca aktualnie wybrany poziom trudno�ci.
	* @return Poziom trudno�ci
	*/
	static difficulty_settings::difficulty get_selected_difficulty() { return m_selected_difficulty;  }

	/** Metoda statyczna klasy @ref difficulty_settings
	* Zmienia poziom trudno�ci na taki jaki zosta� przekazany jako argument.
	* @param[in] difficulty Poziom trudno�ci
	*/
	static void change_selected_difficulty_to(difficulty_settings::difficulty difficulty) { m_selected_difficulty = difficulty; }

};

#endif