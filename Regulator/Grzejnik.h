#pragma once
#include <iostream>

using namespace std;

class Grzejnik
{
private:
	float moc_nominalna;
	float aktualny_poziom_mocy;

public:
	Grzejnik();
	float get_moc_nominalna();
	float get_poziom_mocy();
	float emitowane_cieplo();
	void ustaw_procent_mocy(float procent);
};

