// MN zadanie 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include "gnuplot_i.hpp"
#define GNUPLOT_PATH "C:\\gnuplot\\bin"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

double schemat_hornera(double tablica[], double argument_wielomianu, int stopien);
void polozenie_wezlow();
void rysuj(int wybor);

int main()
{
	int choice = 0;
	std::cout << "WYBIERZ FUNKCJE: " << std::endl;
	std::cout << "1. Wielomianowa" << std::endl;
	std::cout << "2. Trygonometryczna \n";
	std::cout << "3. |x| \n";
	std::cout << "4. Wymierna \n";
	std::cin >> choice;

	while ((choice > 4) || (choice < 1) || (std::cin.fail()))
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Niepoprawny wybor. Jeszcze raz:\n";
		std::cin >> choice;
	}

	if (choice == 1)
	{
		std::cout << "Stopien wielomianu";
		int *size = new int;
		std::cin >> *size;
		*size = *size + 1;
		double *tablica = new double[*size];
		double *wspolczynnik = new double;
		for (int i = 0; i < *size; i++)
		{
			std::cout << "wspolczynnik stopnia: " << i << std::endl;
			std::cin >> *wspolczynnik;
			tablica[i] = *wspolczynnik;
		}
	}

	double a, b;
	std::cout << "Podaj przedzial interpolacji:\n";
	std::cout << "Podaj a:\n";
	std::cin >> a;
	std::cout << "Podaj b:\n";
	std::cin >> b;
	polozenie_wezlow();
	rysuj(choice);

	return 0;
}

double schemat_hornera(double tablica[], double argument_wielomianu, int stopien_wielomianu)
{
	double wynik = tablica[0];
	for (int i = 1; i <= stopien_wielomianu; i++)
	{
		// cout << "tab["<< i << "] wynosi" << tablica[i] << endl;
		wynik = wynik * argument_wielomianu + tablica[i];
		// cout << wynik << "WYNIK PO <<" << i << "PETLI WYNOSI" << wynik <<endl;
	}

	return wynik;
}

void polozenie_wezlow()
{
	int z = 0, a = 0;
	std::fstream polozenie;
	polozenie.open("polozenie.txt", std::ios_base::in);
	if (polozenie.good() == false) std::cout << "\nPlik z wezlami nie istnieje!\n\n";  else std::cout << "\n\nPlik z wezlami otworzony poprawnie!\n\n";
	while (polozenie >> a) z++;
	std::cout << "ZET" << z;
	polozenie.close();
	// z = ilosc_wezlow ;
	double *wezly = new double[z - 1];
	polozenie.open("polozenie.txt", std::ios_base::in);

	for (int i = 0; i < z; i++)
	{
		polozenie >> wezly[i];
	}

	for (int i = 0; i < z; i++) std::cout << "WEZLY[" << i << "]" << wezly[i] << std::endl;
}

void rysuj(int wybor)
{
	double x;
	//Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
	//Gnuplot main_plot;
	std::cout << "OTWARTE";

	std::fstream plik;
	std::cout << "OTWARTE2";

	plik.open("plik.txt", std::ios_base::out, std::ios_base::in);
	/*
	if (wybor == 1)
	{
		for (int i = -30; i < 30; i++)
		{
			std::cout << "KURWA";
			x = 2 * i;
			plik << i << 2 * i;
		}

		// Podpisy na wykresie, zeby bylo wiadomo co na nim widac
		//main_plot.set_title("Funkcja wielomianowa");
		//main_plot.set_xlabel("os x");
	//	main_plot.set_ylabel("os y");
		// styl rysowania wykresu
	//	main_plot.set_style("lines");
		// siatka poprawia czytelnosc
	//	main_plot.set_grid();
		// zakres osi x
	//	main_plot.set_xrange(-30, 30);
	//	main_plot.plotfile_xy("plik.txt", 1, 2, "funkcja");
	}
	/*
	else if (wybor == 2)
	{
		// Podpisy na wykresie, zeby bylo wiadomo co na nim widac
		main_plot.set_title("Funkcja trygonometryczna");
		main_plot.set_xlabel("os x");
		main_plot.set_ylabel("os y");
		// styl rysowania wykresu
		main_plot.set_style("lines");
		// siatka poprawia czytelnosc
		main_plot.set_grid();
		// zakres osi x
		main_plot.set_xrange(-30, 30);
		main_plot.plotfile_xy("plik.txt", 1, 2, "funkcja");
	}

	else if (wybor == 3)
	{
		// Podpisy na wykresie, zeby bylo wiadomo co na nim widac
		main_plot.set_title("Funkcja |x|");
		main_plot.set_xlabel("os x");
		main_plot.set_ylabel("os y");
		// styl rysowania wykresu
		main_plot.set_style("lines");
		// siatka poprawia czytelnosc
		main_plot.set_grid();
		// zakres osi x
		main_plot.set_xrange(-30, 30);
		main_plot.plotfile_xy("plik.txt", 1, 2, "funkcja");
	}

	else if (wybor == 4)
	{
		// Podpisy na wykresie, zeby bylo wiadomo co na nim widac
		main_plot.set_title("Funkcja wymierna");
		main_plot.set_xlabel("os x");
		main_plot.set_ylabel("os y");
		// styl rysowania wykresu
		main_plot.set_style("lines");
		// siatka poprawia czytelnosc
		main_plot.set_grid();
		// zakres osi x
		main_plot.set_xrange(-30, 30);
		main_plot.plotfile_xy("plik.txt", 1, 2, "funkcja");
	}
	}*/
}