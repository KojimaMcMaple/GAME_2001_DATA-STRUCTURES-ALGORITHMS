#pragma once

#include "BaseArray.h"

template<class T>
class UnorderedArray : public BaseArray<T> {
public:
	UnorderedArray(int size, bool is_unique_array = false, int grow_by = 2) :
		BaseArray<T>{ size, is_unique_array, grow_by } {}

	~UnorderedArray() {}

	int Push(T val) {
		assert(this->array_ptr != NULL);

		// EXPAND
		if (this->array_num_elements >= this->array_max_size) {
			this->Expand();
		}

		// PUSH
		//2)	Add the ability for the ordered array to prevent duplicate data (constructor flag, push method)
		if (this->is_unique_array) {
			if (Search(val) != -1) {
				return -1;
			}
		}
		
		this->array_ptr[this->array_num_elements] = val;
		this->array_num_elements++;

		return (this->array_num_elements) - 1;
	}

	int Search(T val) {
		assert(this->array_ptr != NULL);

		for (int i = 0; i < this->array_num_elements; i++) {
			if (this->array_ptr[i] == val) {
				return i;
			}
		}

		return -1;
	}
};