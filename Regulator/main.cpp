#include <iostream>
#include "Symulacja.h"


using namespace std;


int get_safe_intiger(int dol, int gora)
{
	int x;
	cin >> x;
	while (cin.fail() || x <= dol || x >= gora)
	{
		cout << "Podaj poprawna wartosc:";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> x;
	}
	return x;
}

Regulator* zbuduj_regulator(int wybor)
{
	if (wybor == 1)
	{
		return new RegulatorBB();
	}
	return new RegulatorPID();
}


int main()
{

	cout << "Witaj w regulatorze temperatury!" << endl;
	cout << "Ktorego regulatora chcesz uzyc?" << endl;
	cout << "1 - Regulator BB (Bang-Bang)" << endl;
	cout << "2 - Regulator PID" << endl;
	cout << "0 - Wyjscie z programu" << endl;
	cout << "Wybieram:";


	int wybor = get_safe_intiger(-1, 3);

	if (wybor == 0)
	{
		return 0;
	}

	auto* regulator = zbuduj_regulator(wybor);
	try
	{
		Symulacja wirtual(regulator);
		wirtual.przebieg(3000, 5);
	}

	catch (const exception& e)
	{
		cout << "Blad symulacji z powodu: " << endl;
		cout << e.what() << endl;
	}
	return 0;
}