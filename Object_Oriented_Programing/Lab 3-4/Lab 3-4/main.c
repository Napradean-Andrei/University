#include "OfferRepository.h"
#include "UI.h"
#include "windows.h"

int main() {

	

	OfferRepo repo = createRepo();
	OfferRepo repo2 = createRepo();
	Controller ctrl = createController(&repo, &repo2);


	addOffer(&ctrl, "house", "Titulescu9", 50, 110);
	addOffer(&ctrl, "appartment", "Luchian", 75, 100);
	addOffer(&ctrl, "house", "Titulescu4", 50, 50);
	addOffer(&ctrl, "house", "Titulescu2", 60, 200);
	addOffer(&ctrl, "house", "Titulescu3", 500, 70);

	
	

	UI ui = createUI(&ctrl);
	startUI(&ui);
	system("pause");
	return 0;
}