#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#include <iostream>

using namespace std;

template<int size, typename T>
class Array
{
    
public:
    int Size() return size;
    
    void insert_at(int index, T value) {
		if (index >= size) {
			cout << "Index out of bounds" << endl;
			return;
        }
        else {
			arr[index] = value;
        }
    }
    
    T get_at(int index) {
		return arr[index];
    }

    T& operator[](int index) {
        return arr[index]
    }

private:
    T arr[size] = { 0 };
};



int main(void)
{
  /*  Array<10, double> array;
	array.insert_at(0, 1.0);
	array.insert_at(1, 2.0);
	array.insert_at(2, 3.0);
    
	for (int i = 0; i < array.get_size(); i++) {
		cout << array.get_at(i) << endl;
	}*/
    
    int i;

    vector v;
    vector_init(&v);

    vector_add(&v, "Bonjour");
    vector_add(&v, "tout");
    vector_add(&v, "le");
    vector_add(&v, "monde");

    for (i = 0; i < vector_total(&v); i++)
        printf("%s ", (char*)vector_get(&v, i));
    printf("\n");

    vector_delete(&v, 3);
    vector_delete(&v, 2);
    vector_delete(&v, 1);

    vector_set(&v, 0, "Hello");
    vector_add(&v, "World");

    for (i = 0; i < vector_total(&v); i++)
        printf("%s ", (char*)vector_get(&v, i));
    printf("\n");

    vector_free(&v);

}