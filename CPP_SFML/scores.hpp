/** @file*/

#ifndef SCORES_HPP
#define SCORES_HPP

#include <fstream>
#include <string>
#include <vector>
#include <tuple>

/** Klasa s�u��ca do zapisu i odczytu wynik�w.*/

using trio = std::tuple<std::string, std::string, unsigned int>;

class scores {
private:

	std::vector<trio> m_scores; ///< Tablica tr�jek ( pseudonim gracza, poziom trudno�ci, wynik )

	const std::string m_file_path; ///< �cie�ka do pliku z wynikami
	const char m_separator; ///< Separator u�yty do oddzielania warto�ci w pliku .csv

	std::fstream m_file_stream; ///< Strumie� WE/WY plikowy

	bool m_scores_sorted = false; ///< Zmienna sygnalizuj�ca czy wyniki zosta�y posortowane
	bool m_all_scores_were_loaded = false; ///< Zmienna sygnalizuj�ca czy wszystkie wyniki zosta�y za�adowane

public:

	/** Konstruktor klasy @ref scores
	* @param[in] file_path �cie�ka do pliku z wynikami
	* @param[in] separator Separator u�yty do oddzielania warto�ci w pliku .csv
	*/
	scores(std::string file_path = "scores.csv", const char separator = ';');

	/** Metoda klasy @ref scores
	* Dopisuje wynik gracza do tablicy wynik�w i do pliku.
	* @param[in] nickname Pseudonim gracza
	* @param[in] difficulty Poziom trudno�ci
	* @param[in] score Uzyskany wynik
	*/
	void append_score(std::string nickname, std::string difficulty, unsigned int score);

	/** Metoda klasy @ref scores
	* �aduje wyniki z pliku do tablicy wynik�w.
	*/
	void load_scores();

	/** Metoda klasy @ref scores
	* Sortuje tablic� wynik�w po wynikach malej�co.
	*/
	void sort_scores_desc();

	/** Metoda klasy @ref scores
	* Zwraca najlepszy wynik z tablicy wynik�w.
	* @return Najlepszy wynik
	*/
	const unsigned int get_highest_score();

	/** Niemodyfikuj�ca metoda inline klasy @ref scores
	* Zwraca d�ugo�� tablicy wynik�w.
	* @return D�ugo�� tablicy wynik�w
	*/
	size_t get_number_of_scores() const { return m_scores.size(); }

	/** Przeci��ony operator tablicowy klasy @ref scores
	* Zwraca (tylko do odczytu) tr�jk� ( pseudonim gracza, poziom trudno�ci, wynik ) z tablicy wynik�w.
	* @return Tr�jka ( pseudonim gracza, poziom trudno�ci, wynik )
	*/
	const trio& operator [](size_t index);

};

#endif