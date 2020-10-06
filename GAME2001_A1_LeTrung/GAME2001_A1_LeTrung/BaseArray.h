#pragma once
#include <iostream>
using namespace std;

#include <cassert>

template<class T>
class BaseArray {
public:
	BaseArray() :
		array_ptr(NULL), array_max_size(0), array_grow_size(0), array_num_elements(0), is_unique_array(false){
	}
	
	BaseArray(int size, bool is_unique_array = false, int grow_by = 1) :
		array_ptr(NULL), array_max_size(0), array_grow_size(0), array_num_elements(0), is_unique_array(false) {
		if (size) {
			array_max_size = size;
			array_ptr = new T[array_max_size];
			memset(array_ptr, 0, sizeof(T) * array_max_size);
			array_grow_size = ((grow_by > 0) ? grow_by : 0);
			this->is_unique_array = is_unique_array;
		}
	}

	~BaseArray()
	{
		if (array_ptr != NULL) {
			delete[] array_ptr;
			array_ptr = NULL;
		}
	}

	//virtual int Push(T val) {

	//}

	void Pop() {
		if (array_num_elements > 0) {
			array_num_elements--;
		}
	}

	void Remove(int idx) {
		assert(array_ptr != NULL);

		if (idx > array_num_elements) {
			return;
		}

		for (int i = idx; i < array_num_elements; i++) {
			if (i + 1 < array_num_elements) {
				array_ptr[i] = array_ptr[i + 1];
			}
		}

		array_num_elements--;
	}

	//virtual int Search(T val) {

	//}

	T& operator[](int idx) {
		assert(array_ptr != NULL && idx < array_num_elements);
		return array_ptr[idx];
	}

	void Clear() {
		array_num_elements = 0;
	}

	T* GetArrPtr() {
		return array_ptr;
	}
	int GetSize() {
		return array_num_elements;
	}
	int GetMaxSize() {
		return array_max_size;
	}
	int GetGrowSize() {
		return array_grow_size;
	}
	void SetGrowSize(int val) {
		assert(val >= 0);
		array_grow_size = val;
	}

	friend ostream& operator<<(ostream& os, BaseArray<T>& arr) {
		os << "> array_max_size: " << arr.GetMaxSize() << endl;
		os << "> array_grow_size: " << arr.GetGrowSize() << endl;
		os << "> array_num_elements: " << arr.GetSize() << endl;
		os << "> elems: " << endl;
		os << "{" << endl;
		if (arr.GetSize()) {
			for (int i = 0; i < arr.GetSize(); i++)
			{
				os << "\t" << arr.array_ptr[i] << endl;
			}
		}
		os << "}" << endl;

		return os;
	}

protected:
	T* array_ptr;
	int array_max_size;
	int array_grow_size;
	int array_num_elements;
	bool is_unique_array;

	bool Expand() {
		if (array_grow_size <= 0) {
			return false;
		}

		T* temp = new T[array_max_size + array_grow_size];
		assert(temp != NULL);

		memcpy(temp, array_ptr, sizeof(T) * array_max_size);

		delete[] array_ptr;

		array_ptr = temp;
		temp = NULL;

		array_max_size += array_grow_size;

		//1)	The Expand function should expand based on an increasing value (2, 4, 8, 16, etc)
		array_grow_size += array_grow_size;

		return true;
	}
};