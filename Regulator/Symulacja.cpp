#include <iostream>
#include <fstream>
#include <string>
#include"Symulacja.h"

using namespace std;


Symulacja::Symulacja(Regulator* r)
{
	regulator = r;
	czas.push_back(0.0);
	temperatura.push_back(20.0);
	pokoj = new Pomieszczenie(5.0, 4.0, 3.0);
	moc.push_back(0);
}

Symulacja::~Symulacja()
{
	delete regulator;
	delete pokoj;
}

void Symulacja::iteracja(float zmiana_czasu)
{
		moc.push_back(ogrzewanie.emitowane_cieplo());
		float temp = pokoj->getTemperatura();
		float zadana_moc_grzejnika = regulator->steruj(25, temp, zmiana_czasu);
		ogrzewanie.ustaw_procent_mocy(zadana_moc_grzejnika);
		pokoj->dodajCieplo(ogrzewanie.emitowane_cieplo());
		pokoj->aktualizuj(zmiana_czasu);


		temperatura.push_back(pokoj->getTemperatura());	
		czas.push_back(zmiana_czasu + czas.back());
}

void Symulacja::przebieg(int ilosc_cyklow, float zmienna_czasu)
{
	string nazwa;

	for (int i = 0; i < ilosc_cyklow; i++)
	{		
		iteracja(zmienna_czasu);		
	}
	cout << "Pod jaka nazwa chcesz zapisac przebieg?(nie zapomnij o .csv):";
	cin >> nazwa;

	automatyczny_zapis(nazwa);
	cout << endl;
	cout << "Zapisano w pliku " << nazwa << endl;
}

float Symulacja::uplyniety_czas()
{
	return czas.back();
}

void Symulacja::automatyczny_zapis(string nazwa)
{

	fstream plik;
	locale pol("pl_PL");
	plik.imbue(pol);

	plik.open(nazwa, ios::out);
	if (plik.is_open())
	{
		plik << "\n";
		plik << "Uplyniety czas" << ";" << "Aktualna temperatura" << ";" << "Moc wyjsciowa" << endl;
		for (int i = 0; i < czas.size(); i++)
		{
			plik << czas[i] << ";" << temperatura[i] << ";" << moc[i] << endl;
		}
	}
	plik.close();
}
