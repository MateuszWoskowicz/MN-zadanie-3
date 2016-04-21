// MN zadanie 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>

double schemat_hornera(double tablica[], double argument_wielomianu, int stopien);

int main()
{
	int choice = 0;
	std::cout << "WYBIERZ FUNKCJE: " << std::endl;
	std::cout << "1. Wielomianowa" << std::endl;
	std::cout << "2. Trygonometryczna \n";
	std::cout << "3. |x| \n";
	std::cout << "4. Wymierna \n";
	std::cin >> choice;

	while (	(choice > 4) || (choice < 1) || (std::cin.fail() )	)
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
		double *tablica = new double[*size];
		double *wspolczynnik = new double;
		for (int i = 0; i < *size; i++)
		{
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