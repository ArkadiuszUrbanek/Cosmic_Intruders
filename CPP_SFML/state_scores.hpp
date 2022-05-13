/** @file*/

#ifndef STATE_SCORES_HPP
#define STATE_SCORES_HPP

#include "state_base.hpp"
#include "scores.hpp"
#include "button.hpp"
#include "game.hpp"

#include <array>

#define MAX_RECORDS_PER_PAGE 10
#define RECORD_OUTLINE_THICKNESS 4.0f
#define NUMBER_OF_HEADERS 4

/** Klasa-stan wyniki.*/

class state_scores final : public state_base {
private:

	/** Struktura reprezentuj�ca wiersz w tabeli*/
	struct record {
		sf::RectangleShape m_inner_rect; ///< Kolor wewn�trzny wiersza
		sf::RectangleShape m_outer_rect; ///< Kolor zewn�trzny wiersza (obramowanie)

		/** Konstruktor struktury @ref record
		* @param[in] inner_rect_color Kolor wewn�trzny wiersza
		*/
		record(sf::Color inner_rect_color) {
			m_outer_rect.setFillColor(sf::Color::Black);
			m_outer_rect.setSize({ game::m_WINDOW_WIDTH - 50.0f, 48.0f });
			m_outer_rect.setOrigin({ m_outer_rect.getSize().x / 2, m_outer_rect.getSize().y / 2 });

			m_inner_rect.setFillColor(inner_rect_color);
			m_inner_rect.setSize({ m_outer_rect.getSize().x - RECORD_OUTLINE_THICKNESS, m_outer_rect.getSize().y - RECORD_OUTLINE_THICKNESS });
			m_inner_rect.setOrigin({ m_inner_rect.getSize().x / 2, m_inner_rect.getSize().y / 2 });
		}

		/** Metoda struktury @ref record
		* Ustawia pozycj� wiersza.
		* @param[in] record_position Pozycja wiersza
		*/
		void set_position(sf::Vector2f record_position) {
			m_outer_rect.setPosition(record_position);
			m_inner_rect.setPosition(record_position);

		}
		
		/** Niemodyfikuj�ca metoda struktury @ref record
		* Zwraca rozmiar wiersza, bior�c pod uwag� szeroko�� obramowania.
		* @return Sta�y rozmiar wiersza
		*/
		const sf::Vector2f get_size() const {
			return m_outer_rect.getSize();
		}

		/** Niemodyfikuj�ca metoda struktury @ref record
		* Rysuje wiersz w oknie gry.
		* @param[in,out] window Referencja do okna gry
		*/
		void draw(sf::RenderWindow& window) const {
			window.draw(m_outer_rect);
			window.draw(m_inner_rect);

		}

	};

	sf::Font m_font; ///< Czcionka

	scores m_scores; ///< Obiekt klasy @ref scores

	sf::Text m_number_of_page; ///< Teskt b�d�cy numeracj� strony
	std::array <sf::ConvexShape, 2> m_triangles; ///< Tablica dw�ch tr�jk�t�w r�wnobocznych

	unsigned short m_index_of_current_page = 0; ///< Indeks aktualnej strony
	unsigned short m_number_of_pages; ///< Liczba stron
	unsigned short m_number_of_records_on_the_last_page; ///< Liczba wynik�w wy�wietlanych na ostatniej stronie

	std::array<record, MAX_RECORDS_PER_PAGE> m_array_of_records; ///< Tablica wierszy tabeli
	std::array<sf::Text, NUMBER_OF_HEADERS> m_array_of_headers; ///< Tablica nag��wk�w kolumn tabeli
	std::array<sf::RectangleShape, NUMBER_OF_HEADERS> m_array_of_horizontal_rects; ///< Tablica pionowych dzia�ek tabeli
	std::array<std::array<sf::Text, NUMBER_OF_HEADERS>, MAX_RECORDS_PER_PAGE> m_matrix_of_textes; ///< Macierz tekst�w do wy�wietlenia w tabeli

	/** Prywatna metoda klasy @ref state_scores
	* Uaktualnia zawarto�� m_matrix_of_textes.
	* @param[in] row_index Indeks wiersza z m_matrix_of_textes
	*/
	void update_page_contents(size_t row_index);

public:

	/** Konstruktor klasy @ref state_scores
	* @param[in] machine Referencja do maszyny stan�w
	* @param[in] window Referencja do okna gry
	*/
	state_scores(state_machine& machine, sf::RenderWindow& window);

	/** Przes�oni�ta metoda wirtualna klasy @ref state_scores
	* Zbiera informacje o wydarzeniach.
	*/
	void poll_events() override;

	/** Przes�oni�ta metoda wirtualna klasy @ref state_scores
	* Aktualizuje stan rozgrywki uwzgl�dniaj�c czas jaki up�yna�.
	* @param[in] delta_time Czas mi�dzy kolejnymi klatkami
	*/
	void update(sf::Time delta_time) override;

	/** Przes�oni�ta metoda wirtualna klasy @ref state_playing
	* Rysuje i wy�wietla w oknie gry wype�nion� tabel� wynik�w oraz numeracj� stron.
	*/
	void render() override;

};

#endif