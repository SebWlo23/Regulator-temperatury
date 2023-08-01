#include "RegulatorBB.h"

float RegulatorBB::steruj(float zadana_temperatura, float zmierzona_temperatura, float dt)
{
	if (zmierzona_temperatura >= zadana_temperatura)
	{
		return 0;
	}
	return 1;
}