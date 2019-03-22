#pragma once
#include <string>
class Item {
	std::string category;
	std::string name;
	int quantity;

public:
	std::string getCategory();
	std::string getName();
	int getQuantity();

	void setCategory(std::string category);
	void setName(std::string name);
	void setQuantity(int quantity);

	friend std::istream& operator>>(std::istream& inputStream, Item& rightMember);

	Item();
	Item(std::string category, std::string name, int quantity);
	~Item();
};

