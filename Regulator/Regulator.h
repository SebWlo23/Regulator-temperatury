#pragma once
#include <iostream>


class Regulator
{
public:
	
	virtual float steruj(float zadana_temperatura, float zmierzona_temperatura, float dt) = 0;
};

