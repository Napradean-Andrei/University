#pragma once

template <typename T>
class DynamicVector
{
private:
	T * elems;
	int size;
	int capacity;

public:
	
	DynamicVector(int capacity = 10);

	
	DynamicVector(const DynamicVector& v);

	
	~DynamicVector();

	
	DynamicVector& operator=(const DynamicVector& v);
	DynamicVector& operator-(const T& e);
	

	
	T& operator[](int pos);

	void add(const T e);
	int getSize() const;

	void deleteArray(unsigned int pos);

private:

	void resize(double factor = 2);

};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}
template <typename T>
void DynamicVector<T>::add(T d)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = d;
	this->size++;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= factor;

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}
template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	T* aux;
	aux = new T[this->capacity];

	delete[] this->elems;

	this->elems = aux;
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator-(const T& e)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->elems[i] == e)
		{
			this->deleteArray(i);
			i = this->size;
		}
	}
	return *this;
}



template <typename T>
void DynamicVector<T>::deleteArray(unsigned int pos)
{
	for (int i = pos; i < this->size - 1; i++)
	{
		this->elems[i] = this->elems[i + 1];
	}
	this->size--;
}

template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

