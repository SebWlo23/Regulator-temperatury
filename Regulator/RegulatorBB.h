#pragma once
#include "Regulator.h"

class RegulatorBB : public Regulator
{
public:
	float steruj(float zadana_temperatura, float zmierzona_temperatura, float dt) override;
};

