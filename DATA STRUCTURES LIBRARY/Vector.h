#pragma once

template <typename T>
class Vector {

private:
	T* m_data;
	size_t m_count;
	size_t m_allocated_size;

	void			realocate(size_t new_allocated_size);

public:
	Vector();
	Vector(const Vector& other);
	~Vector();

	T&				operator[](size_t index);
	void			allocate(size_t size);
	void			push_back(T val);
	T				pop_back();
	int				size();
	void			clear();
	void			delete_at_index(size_t index);
	void			add_to_front(T val);
};


template <typename T>
Vector<T>::Vector()
	: m_data(new T[2]), m_count(0), m_allocated_size(2)
{
	realocate(2);
}

template <typename T>
Vector<T>::Vector(const Vector& other) {
	m_allocated_size = other.m_allocated_size;
	m_count = other.m_count;
	T* new_data = new T[m_allocated_size];
	delete[] m_data;
	memcpy(new_data, other.m_data, m_allocated_size);
	m_data = new_data;
}

template <typename T>
Vector<T>::~Vector() {
	delete[] m_data;
}

template <typename T>
void Vector<T>::allocate(size_t size) {
	realocate(size);
};

template <typename T>
void Vector<T>::push_back(T val) {

	if (m_count >= m_allocated_size) {
		m_allocated_size *= 2;
		realocate(m_allocated_size);
	}

	m_data[m_count] = val;
	m_count++;
}

template <typename T>
T Vector<T>::pop_back() {

	if (m_count <= m_allocated_size / 2) {
		m_allocated_size = m_allocated_size / 2;
		realocate(m_allocated_size);
	}
	if (m_count > 0) {
		m_count--;
		return m_data[m_count];
	}
	else {
		//cout << "Vector is empty" << endl;
	}
}

template <typename T>
T& Vector<T>::operator[](size_t index) {

	if (index >= m_count) {
		//cout << "Index out of range" << endl;
	}
	else {
		return m_data[index];
	}
}

template <typename T>
int Vector<T>::size() { return m_count; }

template <typename T>
void Vector<T>::clear() {

	size_t size = m_count;
	for (size_t i = 0; i < size; i++) {
		pop_back();
	}
}

template <typename T>
void Vector<T>::delete_at_index(size_t index) {

	if (index < 0 || index >= m_count)
		return;

	if (m_count <= m_allocated_size / 2) {
		m_allocated_size = m_allocated_size / 2;
		realocate(m_allocated_size);
	}
	m_count--;

	for (size_t i = index; i < m_count; i++) {
		m_data[i] = m_data[i + 1];
	}
}

template <typename T>
void Vector<T>::add_to_front(T val) {

	if (m_count >= m_allocated_size) {
		m_allocated_size *= 2;
		realocate(m_allocated_size);
	}

	for (size_t i = m_count; i > 0; i--) {
		m_data[i] = m_data[i - 1];
	}

	m_data[0] = val;
	m_count++;
}

template <typename T>
void Vector<T>::realocate(size_t new_allocated_size) {

	T* new_data = new T[new_allocated_size];

	for (size_t i = 0; i < m_count; i++) {
		new_data[i] = m_data[i];
	}
	delete[] m_data;
	m_data = new_data;
}
