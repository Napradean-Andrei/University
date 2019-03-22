#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>

template <typename T>
struct Node
{
	T info;
	int next;
	int prev;
};


template <typename T>
class List
{
private:
	int cap = 100;
	int size = 0;
	int firstEmpty = 0;
	int tail = -1;
	int head = -1;
	Node<T> elems[100];
	bool(*r)(T, T);

public:
	List(bool(*cmp)(T, T) = [](T a, T b) {return a <= b; }) : r{ cmp } {

		for (int i = 0; i < 100; ++i) {
			elems[i].next = i + 1;
			elems[i].prev = i - 1;
		}
		elems[0].prev = -1;
		elems[99].next = -1;
	}
	int first() {
		if (size) {
			return 0;
		}
		//throw std::runtime_error{ "Empty list" };
	}
	int last() {
		if (size) {
			return size - 1;
		}
		//throw std::runtime_error{ "Empty list" };

	}
	bool valid(int pos) {
		return pos >= 0 && pos < size;
	}
	int next(int pos) {
		if (valid(pos + 1)) {
			return pos + 1;
		}
		//throw std::runtime_error{ "Invalid position" };

	}
	int prev(int pos) {
		if (valid(pos - 1)) {
			return pos - 1;
		}
		//throw std::runtime_error{ "Invalid position" };
	}
	void getElement(T& e, int p) {
		int current = head;
		if (valid(p)) {
			for (int i = 0; i < p; ++i) {
				current = elems[current].next;
			}
			e = elems[current].info;
		}
	}
	int getPosition(T e) {
		int current = head;
		for (int i = 0; i < size; ++i) {
			if (elems[current].info == e) {
				return i;
			}
			current = elems[current].next;
		}
		throw std::runtime_error{ "Element not found" };
	}
	void insert(T e) {
		//pre: e- TElem
		//post: returns nothing modifies the list

		if (size == cap) {
			throw std::runtime_error{ "List is full" };
		}
		elems[firstEmpty].info = e;
		if (!size) {
			elems[firstEmpty].prev = -1;
			head = firstEmpty;
			tail = head;
			firstEmpty = elems[firstEmpty].next;
			elems[firstEmpty].prev = -1;
			elems[head].next = -1;
			++size;
			return;
		}
		if (r(e, elems[head].info)) {
			int aux = elems[firstEmpty].next;
			elems[firstEmpty].prev = -1;
			elems[firstEmpty].next = head;
			elems[head].prev = firstEmpty;
			head = firstEmpty;
			firstEmpty = aux;
			if (aux != -1) {
				elems[aux].prev = -1;
			}
		}
		else {
			int current = head;
			while (current != -1 && r(elems[current].info, e)) {
				current = elems[current].next;
			}
			if (current == -1) {
				elems[firstEmpty].prev = tail;
				elems[tail].next = firstEmpty;
				tail = firstEmpty;
				firstEmpty = elems[firstEmpty].next;
				if (firstEmpty != -1) {
					elems[firstEmpty].prev = -1;
				}
				elems[tail].next = -1;
			}
			else {
				int aux = elems[firstEmpty].next;
				elems[firstEmpty].next = current;
				elems[firstEmpty].prev = elems[current].prev;
				elems[elems[current].prev].next = firstEmpty;
				elems[current].prev = firstEmpty;
				firstEmpty = aux;
				if (aux != -1) {
					elems[aux].prev = -1;
				}
			}
		}
		++size;
	}
	void remove(int p, T& e) {
		//pre: p is the position e is TElem
		//post: returns nothing modifies the list

		int current = head;
		if (valid(p)) {
			for (int i = 0; i < p; ++i) {
				current = elems[current].next;
			}
			e = elems[current].info;
			if (p == 0) {
				int aux = firstEmpty;
				head = elems[head].next;
				firstEmpty = elems[head].prev;
				elems[firstEmpty].next = aux;
				elems[firstEmpty].prev = -1;
				elems[head].prev = -1;
			}
			else if (p == size - 1) {
				int aux = firstEmpty;
				firstEmpty = tail;
				tail = elems[tail].prev;
				elems[firstEmpty].next = aux;
				elems[firstEmpty].prev = -1;
				elems[tail].next = -1;
				elems[aux].prev = firstEmpty;
			}
			else {
				int aux = firstEmpty;
				elems[elems[current].prev].next = elems[current].next;
				elems[elems[current].next].prev = elems[current].prev;
				firstEmpty = current;
				elems[current].next = aux;
				elems[current].prev = -1;
				elems[aux].prev = current;
			}
		}
		--size;
	}
	bool search(T e) {
		//pre: e is a TElem
		//post: returns true or false wether the elem was found or not

		int current = head;
		while (current != -1) {
			if (elems[current].info == e) {
				return true;
			}
			current = elems[current].next;
		}
		return false;

	}
	void print() {
		std::cout << "\nThe current list is: ";
		int current = head;
		while (current != -1) {
			std::cout << elems[current].info << " ";
			current = elems[current].next;
		}


	}

	void tests()
	{
		List<int> l;
		// for insert function
		l.insert(2);
		assert(l.size() == 1);

		// for search function
		assert(l.search(2) == true);

		// for valid function
		assert(l.valid(0) == true);

		// for first function
		assert(l.first() == 0);

		// for last function
		assert(l.last() == 0);

		// for remove function
		//l.remove(0,2);//

		assert(l.size() == 0);

		l.insert(2);
		l.insert(3);
		l.insert(1);

		// for next function
		assert(l.next(1) == 2);

		// for prev function
		assert(l.prev(1) == 0);

		// for getPosition function
		assert(l.getPosition(2) == 1);


	}
	~List() {}
};

void testList() {
	List<int> l;
	for (int i = 0; i < 5; ++i) {
		l.insert(i);
	}
	l.insert(-1);
	l.insert(3);
	l.insert(9);
	//l.print();
	//std::cout<<std::endl;
	int a;
	l.remove(4, a);
	l.remove(0, a);
	l.remove(5, a);
	//l.print();
	l.insert(0);
	//l.print();
	
}

int main()
{
	List<int> l;
	testList();
	int a, b, value, nr,p;
	char c;
	std::cout << "Please input the instructions (enter 'E' to exit): \n A to add to list\n D to delete \n T to show all\n S to search the first x students with grades grater than value";
	l.insert(5);
	l.insert(2);
	l.insert(3);
	l.insert(7);
	l.insert(10);
	l.insert(10);
	l.insert(9);
	l.insert(7);

	do {
	std::cin >> c;
	switch (c) {
	case 'A':   std::cout << "give element to be added: ";


	std::cin >> a;
	l.insert(a);

	break;
	case 'D':
	std::cout << "give element to be deleted: ";
	std::cin >> a;
	std::cout << "give pos: ";
	std::cin >> p;
	l.remove(p,a);
	break;
	case 'S': std::cout << "give value: ";

	std::cin >> value;

	if(l.search(value))
		std::cout << "student found ";
	else
		std::cout << "student not found";

	break;

	case 'T':  ;
	l.print();
	break;
	case 'E':   std::cout << "\nExiting program...\n\n";
	break;
	default:    std::cout << "\nInvalid input entered\n\n";
	}

	} while (c != 'E');
	
	return 0;
}