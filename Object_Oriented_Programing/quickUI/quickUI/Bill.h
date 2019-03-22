#pragma once
#include <string>
class Bill {
	std::string name;
	std::string code;
	int sum;
	int isPaid;

public:
	std::string getName();
	std::string getCode();
	int getSum();
	int getIsPaid();

	void setName(std::string Name);
	void setCode(std::string Code);
	void setSum(int Sum);
	void setIsPaid(int IsPaid);


	friend std::istream& operator>>(std::istream& inputStream, Bill& rightMember);

	Bill();
	Bill(std::string name, std::string code, int sum,int isPaid);
	~Bill();
};

