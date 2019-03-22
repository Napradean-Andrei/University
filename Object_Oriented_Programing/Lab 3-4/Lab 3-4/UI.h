#pragma once
#include "OfferController.h"

typedef struct
{
	Controller* ctrl;
} UI;

UI createUI(Controller* c);

void startUI(UI* ui);