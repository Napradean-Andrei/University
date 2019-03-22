#include "Dog.h"
#include "DynamicVector.h"
#include "AdoptionList.h"
#include "Repo.h"
#include "UI.h"
#include "Controller.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include "FileAdoptionList.h"
#include "HTMLAdoptionList.h"
#include "Serializer.h"
#include "CSVAdoptionList.h"

using namespace std;

int main()
{

	int i;
	printf("press 1. Text file\n press 2. HTML file\n");
	scanf("%d", &i);
	if (i == 1)
	{
		CSVAdoptionList temp;
		Serializer* temp1 = &temp;
		UI UII(temp1);
		UII.startUI();
		system("pause");
	}
	else
	{
		HTMLAdoptionList temp;
		Serializer* temp2 = &temp;
		UI UII(temp2);
		UII.startUI();
		system("pause");
	}
	
	return 0;
}