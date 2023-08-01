#pragma once
#include "Regulator.h"
class RegulatorPID : public Regulator
{

private:
	float e_calka = 0;
	float e_poprzednie = 0;

	const float Kp = 4.0f;
	const float Ki = 0.02f;
	const float Kd = 0.1f;

public:
float steruj(float zadana_temperatura, float zmierzona_temperatura, float dt) override;

};

