#include "RegulatorPID.h"

float RegulatorPID::steruj(float zadana_temperatura, float zmierzona_temperatura, float dt)
{	


	//czesc proporcjonalna
	float e = zadana_temperatura - zmierzona_temperatura;
	float u_p = Kp * e;

	//czesc calkujacy
	e_calka = e_calka + e * dt;
	float u_i = Ki * e_calka;

	//czesc rozniczkujaca;
	float delta_e = (e - e_poprzednie) / (dt);
	e_poprzednie = e;
	float u_d = Kd * delta_e;
	float u = (u_p + u_i + u_d)/100;
	return u;
}