#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
	T* arr;
	int currentSize;
	int capacity;

	void erase();
	void copy(const Vector& other);
	void resize();

public:
	Vector();
	Vector(const Vector& other);
	Vector& operator = (const Vector& other);
	Vector(T* other, int size, int capacity);
	void print() const;
	T operator[](size_t index);
	void insert(T element);
	void insertAt(int index, T element);
	bool contains(T element);
	bool remove(T element);
	void removeAt(size_t index);
	size_t getCurrentSize() const;
	size_t getCapacity() const;
	~Vector();
};

template <typename T>
Vector<T>::Vector() {
	this->arr = NULL;
	this->currentSize = 0;
	this->capacity = 0;
}

template <typename T>
void Vector<T>::erase() {
	delete[] this->arr;
}

template<typename T>
void Vector<T>::copy(const Vector& other) {
	this->arr = new T[other.capacity];
	for (size_t i = 0; i < this->currentSize; i++) {
		this->arr[i] = other.arr[i];
	}
	this->currentSize = other.currentSize;
	this->capacity = other.capacity;
}

template <typename T>
void Vector<T>::resize() {
	this->capacity = this->capacity * 2;
	T* temp = new T[this->capacity];
	for (size_t i = 0; i < this->currentSize; i++) {
		temp[i] = this->arr[i];
	}
	this->erase();
	this->arr = temp;
}
template <typename T>
void Vector<T>::print() const {
	for (size_t i = 0; i < this->currentSize; i++) {
		cout << this->arr[i] << " ";
	}
}

template <typename T>
Vector<T>::Vector(const Vector& other) {
	this->copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}
}

template <typename T>
Vector<T>::Vector(T* other, int size, int capacity) {
	this->arr = new T[capacity];
	for (size_t i = 0; i < size; i++) {
		this->arr[i] = other[i];
	}
	this->currentSize = size;
	this->capacity = capacity;
}

template <typename T>
T Vector<T>::operator[](size_t index) {
	return this->arr[index];
}

template <typename T>
void Vector<T>::insert(T element) {
	this->currentSize++;
	if (this->currentSize >= this->capacity) {
		this->resize();
	}
	this->arr[currentSize] = element;
}

template <typename T>
void Vector<T>::insertAt(int index, T element) {
	this->currentSize++;
	if (this->currentSize >= this->capacity) {
		this->resize();
	}
	for (size_t i = index; i < this->currentSize; i++) {
		this->arr[i + 1] = this->arr[i];
	}
	this->arr[index] = element;
}

template <typename T>
bool Vector<T>::contains(T element) {
	for (size_t i = 0; i < this->currentSize; i++) {
		if (this->arr[i] == element) {
			return true;
		}
	}
	return false;
}

template <typename T>
bool Vector<T>::remove(T element) {
	bool result = false;
	for (size_t i = 0; i < this->currentSize; i++) {
		if (this->arr[i] == element) {
			this->currentSize--;
			result = true;
			for (size_t j = i; j < this->currentSize; j++) {
				arr[i] = arr[i + 1];
			}
		}
	}
	return result;
}

template <typename T>
void Vector<T>::removeAt(size_t index) {
	if (index >= this->capacity) {
		return;
	}
	this->currentSize--;
	for (size_t i = index; i < this->currentSize; i++) {
		arr[i] = arr[i + 1];
	}
}

template <typename T>
size_t Vector<T>::getCapacity() const {
	return this->capacity;
}

template <typename T>
size_t Vector<T>::getCurrentSize() const {
	return this->currentSize;
}

template <typename T>
Vector<T>::~Vector() {
	this->erase();
}
