#include <iostream>

#include "Grzejnik.h"

using namespace std;

Grzejnik::Grzejnik()
{
	moc_nominalna = 3000;
	ustaw_procent_mocy(0.7);
}

float Grzejnik::get_moc_nominalna()
{
	return moc_nominalna;
}

float Grzejnik::get_poziom_mocy()
{
	return aktualny_poziom_mocy;
}

float Grzejnik::emitowane_cieplo()
{
	float temp;
	temp = get_moc_nominalna() * get_poziom_mocy();
	return temp;
}

void Grzejnik::ustaw_procent_mocy(float procent)
{
	if (procent < 0)
	{
		aktualny_poziom_mocy = 0;
	}
	else if (procent > 1)
	{
		aktualny_poziom_mocy = 1;
	}
	else 
	{
		aktualny_poziom_mocy = procent;
	}	
}