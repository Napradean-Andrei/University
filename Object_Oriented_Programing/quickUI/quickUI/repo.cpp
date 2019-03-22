#include "repo.h"
#include <assert.h>
#include "Bill.h"



int Repo::getSum(std::string name) {

// Descr: computes the sum by iterating through the list and is the name is right and is not paied it ads it to the sum
// pre: string name
//post: int s

	
	int s=0;

	for (int i = 0; i < this->List.size(); i++) {
		
		if ((this->List[i].getName() == name)&& (this->List[i].getIsPaid()==0))
			s+= this->List[i].getSum();
	}

	return s;
}
std::vector<Bill> Repo::getAll() {

	
		return this->List;

	
}
void Repo::readFromFile() {

	std::ifstream file("data.txt");
	Bill tempItem;
	while (file >> tempItem) {
		this->List.push_back(tempItem);
	}

	file.close();
}
void Repo::test()
	{
		
		Bill a = Bill("a", "b", 1, 0);
			
		//assert(a.getSum(a) == 1);
	}

Repo::Repo() {
}


Repo::~Repo() {
}
