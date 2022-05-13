/** @file*/

#ifndef HUD_HPP
#define HUD_HPP

#include <array>
#include <vector>

#include "animation.hpp"
#include "button.hpp"

/** Klasa tworz�ca hud w trakcie rozgrywki.*/

class hud {
private:

	std::array<sf::RectangleShape, 2> m_bars; ///< Tablica dw�ch bia�ych belek oddzielaj�cych hud od obszaru, na kt�rym toczy sie gra
	std::array<sf::RectangleShape, 2> m_fillers; ///< Tablica dw�ch czarnych prostok�t�w, kt�re stanowi� t�o hudu

	std::vector<sf::RectangleShape> m_hearts; ///< Tablica serc, kt�re reprezentuj� �ycia gracza
	sf::Texture m_heart_texture; ///< Tekstura serca
	animation m_heart_animation; ///< Obiekt klasy @ref animation, kt�ry animuje tablic� serc

	sf::Font m_font; ///< Czcionka napis�w hudu 
	
	std::array<button, 6> m_hud_top_textes; ///< Tablica g�rnych tekst�w hudu
	button m_hud_bottom_text; ///< Dolny tekst hudu

	unsigned short m_level = 0; ///< Poziom gry
	unsigned int m_score = 0; ///< Wynik gracza
	unsigned int m_highscore = 0; ///< Najlepszy wynik uzyskany przez gracza

	/** Prywatna metoda statyczna klasy @ref hud
	* �aduje czcionk�.
	* @return Za�adowana czcionka
	*/
	static sf::Font load_font();

	/** Prywatna metoda statyczna klasy @ref hud
	* �aduje Tekstur� serca.
	* @return Za�adowana tekstura serca
	*/
	static sf::Texture load_heart_spritesheet();

public:

	static constexpr unsigned short m_HUD_TOP_HEIGHT = 50; ///< Wysoko�� g�rnej cz�ci hudu
	static constexpr unsigned short m_HUD_BOTTOM_HEIGHT = 30; ///< Wysoko�� dolnej cz�ci hudu

	/** Konstruktor klasy @ref hud
	* @param[in] lives Pocz�tkowa liczba �y� gracza
	* @param[in] level Pocz�tkowy numer poziomu
	*/
	hud(unsigned char lives, unsigned short level);

	/** Metoda klasy @ref hud
	* Uaktualnia liczb� �y� gracza.
	* @param[in] lives Liczba �y� gracza
	*/
	void update_lives(const unsigned char& lives);

	/** Metoda klasy @ref hud
	* Uaktualnia wynik gracza.
	* @param[in] score Wynik gracza
	*/
	void update_score(const unsigned int& score) { m_score = score; }

	/** Metoda klasy @ref hud
	* Uaktualnia poziom gry, zwi�kszaj�c go o jeden.
	*/
	void update_level() { m_level++; }

	/** Metoda klasy @ref hud
	* Rysuje hud w oknie gry.
	* @param[in,out] window Okno gry
	*/
	void draw(sf::RenderWindow& window);

};

#endif
