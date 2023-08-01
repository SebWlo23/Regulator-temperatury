#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"

using namespace std;

class Symulacja
{
private:
	Regulator* regulator;
	vector <float> czas;
	vector <float> temperatura;
	vector <float> moc;
	Grzejnik ogrzewanie;
	Pomieszczenie* pokoj;

public:
	void iteracja(float zmiana_czasu);
	void przebieg(int ilosc_iteracji, float zmienna_czasu);
	Symulacja(Regulator* r);
	~Symulacja();
	float uplyniety_czas();
	void automatyczny_zapis(string nazwa);

};

