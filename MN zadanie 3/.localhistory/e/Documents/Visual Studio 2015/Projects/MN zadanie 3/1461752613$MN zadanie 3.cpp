// MN zadanie 3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <vector>

double schemat_hornera(double tablica[], double argument_wielomianu, int stopien);
void wczytaj_wezly(int, double**);
void dane_wykresu(double a, double b, int choice);

int main()
{
	int choice, size = 0;
	double *tablica = NULL;
	std::cout << "WYBIERZ FUNKCJE: " << std::endl;
	std::cout << "1. Wielomianowa" << std::endl;
	std::cout << "2. Trygonometryczna y = 3sin(x + 2) + cos(x) - 15x\n";
	std::cout << "3. |x| \n";
	std::cout << "4. Liniowa y = 2x+2\n";
	std::cin >> choice;
	while ((choice > 4) || (choice < 1))
	{
		std::cout << "Niepoprawny wybor. Jeszcze raz:\n";
		std::cin >> choice;
	}

	if (choice == 1)
	{
		std::cout << "Stopien wielomianu";

		std::cin >> size;
		tablica = new double[size];

		double wspolczynnik;
		for (int i = 0; i < size; i++)
		{
			std::cout << "wspolczynnik stopnia: " << i << std::endl;
			std::cin >> wspolczynnik;
			tablica[i] = wspolczynnik;
		}
	}
	std::cout << "SAJZ" << size;

	std::cout << "TABLICA HEHE " << tablica[0];
	double a, b;
	std::cout << "Podaj przedzial interpolacji:\n";
	std::cout << "Podaj a:\n";
	std::cin >> a;
	std::cout << "Podaj b:\n";
	std::cin >> b;
	int z = 0;
	int *temp = new int;
	std::fstream line_check;
	line_check.open("polozenie.txt", std::ios_base::in);
	if (line_check.good() == false) std::cout << "\nPlik z wezlami nie istnieje!\n\n";  else std::cout << "\n\nPlik z wezlami otworzony poprawnie!\n\n";
	while (line_check >> *temp) z++;
	line_check.close();
	delete temp;
	z = z / 2;
	// z = ilosc par wezlow
	std::cout << "ZET WYNOSI" << z << std::endl; // TODO
	double **wezly = new double *[z];
	for (int i = 0; i < z; i++)
		wezly[i] = new double[2];

	wczytaj_wezly(z, wezly);
	dane_wykresu(a, b, choice);

	delete[] wezly;

	for (int i = 0; i < size; i++) delete[](tablica + i);
	delete[] tablica;
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

void wczytaj_wezly(int z, double **wezly)
{
	std::fstream polozenie;
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

void dane_wykresu(double a, double b, int choice)
{
	std::fstream danewykresu;
	danewykresu.open("plik.txt", std::ios_base::trunc | std::ios_base::out);
	if (danewykresu.good() == false) std::cout << "\nBLAD OTWARCIA";
	else
	{
		if (choice == 1)
		{
			for (double i = a; i < b; i = i + 0.1)
			{
				danewykresu << i << " " << 2 * i << std::endl;
			}
		}

		else if (choice == 2)
		{
			for (double i = a; i < b; i = i + 0.1)
			{
				danewykresu << i << " " << 3 * sin(i + 2) + cos(i) - 15 * i << std::endl;
			}
		}
		else if (choice == 3)
		{
			for (double i = a; i < b; i = i + 0.1)
			{
				danewykresu << i << " " << fabs(i) << std::endl;
			}
		}
		else if (choice == 4)
		{
			for (double i = a; i < b; i = i + 0.1)
			{
				danewykresu << i << " " << 2 * i + 2 << std::endl;
			}
		}
	}
	danewykresu.close();
}