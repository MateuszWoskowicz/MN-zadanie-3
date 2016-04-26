// MN zadanie 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>

double schemat_hornera(double tablica[], double argument_wielomianu, int stopien);
void wczytaj_wezly();
void pisz_do_pliku(double a, double b, int choice);

int main()
{
	int choice = 0;
	std::cout << "WYBIERZ FUNKCJE: " << std::endl;
	std::cout << "1. Wielomianowa" << std::endl;
	std::cout << "2. Trygonometryczna \n";
	std::cout << "3. |x| \n";
	std::cout << "4. Wymierna \n";
	std::cin >> choice;

	while ((choice > 4) || (choice < 1))
	{
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
	pisz_do_pliku(a, b, choice);
	wczytaj_wezly();

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

void wczytaj_wezly()
{
	int z = 0, a = 0;
	std::fstream polozenie;
	polozenie.open("polozenie.txt", std::ios_base::in);
	if (polozenie.good() == false) std::cout << "\nPlik z wezlami nie istnieje!\n\n";  else std::cout << "\n\nPlik z wezlami otworzony poprawnie!\n\n";
	while (polozenie >> a) z++;
	polozenie.close();
	z = z / 2;
	// z = ilosc par wezlow
	std::cout << "ZET WYNOSI" << z << std::endl; // TODO
	double **wezly = new double *[z];
	for (int i = 0; i < z; i++)
		wezly[i] = new double[2];

	polozenie.open("polozenie.txt", std::ios_base::in);

	for (int i = 0; i < z; i++)
		for (int j = 0; j < 2; j++)
		{
			polozenie >> wezly[i][j];
		}

	//TODO
	for (int i = 0; i < z; i++)
		for (int j = 0; j < 2; j++)
		{
			std::cout << "WEZLY[" << i << "]" << "[" << j << "]" << wezly[i][j] << std::endl;
		}
}

void pisz_do_pliku(double a, double b, int choice)
{
	std::fstream danewykresu;
	danewykresu.open("plik.txt", std::ios_base::in);
	if (danewykresu.good() == false) std::cout << "\nBLAD OTWARCIA";
	else
	{
		if (choice == 1)
		{
			for (double i = a; i < b; i = i + 0.1)
			{
				danewykresu >> i, 2 * i;
			}
		}

		else if (choice == 2)
		{
		}
		else if (choice == 3)
		{
		}
		else if (choice == 4)
		{
		}
	}
}