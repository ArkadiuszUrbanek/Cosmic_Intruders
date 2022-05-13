/** @file*/

#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include "SFML/Graphics.hpp"
#include "state_base.hpp"

#include <memory>
#include <stack>

/** Klasa zarz�dzaj�ca stanami w programie.*/

class state_machine {
public:
	enum command : char;

private:
	std::stack<std::unique_ptr<state_base>> m_stack_of_ptr_states; ///< Stos inteligentnych wska�nik�w na stany w programie
	std::unique_ptr<state_base> m_ptr_new_state; ///< Inteligentny wska�nik na nowy stan, kt�ry ma trafi� na stos
	bool m_wait; ///< Zmienna sygnalizuj�ca czy maszyna stan�w ma wykonywa� okre�lone polecenie

	state_machine::command m_command; ///< Polecenie dla maszyny stan�w

public:

	/// Silny typ wyliczeniowy okre�laj�cy dost�pne polecenia dla maszyny stan�w
	enum command : char { 
		ADD, ///< Polecenie powoduj�ce dodanie na stos nowy stan
		REMOVE, ///< Polecenie powoduj�ce usuni�cie ze szczytu stosu stanu 
		REPLACE ///< Polecenie b�d�ce po��czeniem polecenia ADD i REMOVE
	};

	/** Domy�lny konstruktor klasy @ref state_machine*/
	state_machine();

	/** Statyczna metoda klasy @ref state_machine
	* @param[in] state Inteligentny wska�nik na stan bazowy
	* @param[in] command Polecenie dla maszyny stan�w
	*/
	void run_state(std::unique_ptr<state_base> state, state_machine::command command);

	/** Metoda klasy @ref state_machine
	* Usuwa aktualny stan ze stosu.
	*/
	void remove_state();

	/** Metoda klasy @ref state_machine
	* Wykonuje operacje na stosie, kt�re s� zwi�zane z aktualnie wydanym poleceniem.
	*/
	void process_state_changes();

	/** Metoda klasy @ref state_machine
	* Wywo�uje metod� poll_events stanu ze szczytu stosu.
	*/
	void poll_events();

	/** Metoda klasy @ref state_machine
	* Wywo�uje metod� update stanu ze szczytu stosu.
	*/
	void update(sf::Time delta_time);

	/** Metoda klasy @ref state_machine
	* Wywo�uje metod� render stanu ze szczytu stosu.
	*/
	void render();

	/** Statyczny szablon metody klasy @ref state_machine
	* Zwraca inteligentny wska�nik na nowo utworzony stan.
	* @param[in] machine Referencja do maszyny stan�w
	* @param[in] window Referencja do okna gry
	* @return Inteligentny wska�nik na nowo utworzony stan
	*/
	template <typename T>
	static std::unique_ptr<T> create_state(state_machine& machine, sf::RenderWindow& window);

};

#endif
