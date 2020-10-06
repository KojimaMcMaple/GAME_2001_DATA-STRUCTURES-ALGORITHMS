#pragma once

#include "BaseArray.h"

template<class T>
class OrderedArray : public BaseArray<T> {
public:
	OrderedArray(int size, bool is_unique_array = false, int grow_by = 2) :
		BaseArray<T>{ size, is_unique_array, grow_by } {}

	~OrderedArray() {}

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
		int i, j;
		// FIND INDEX TO PUSH
		for (i = 0; i < this->array_num_elements; i++) {
			if (val < this->array_ptr[i]) {
				break;
			}
		}
		// MOVE ELEMENTS BACK
		for (j = this->array_num_elements; j > i; j--) {
			this->array_ptr[j] = this->array_ptr[j - 1];
		}
		// ACTUAL PUSH
		this->array_ptr[i] = val;
		// UPDATE NUM ELEMS
		this->array_num_elements++;

		// RETURN IDX
		return i;
	}
	
	int BinarySearch(T val, int lower_bound, int upper_bound) {
		assert(this->array_ptr != NULL);
		assert(lower_bound >= 0);
		assert(upper_bound < this->array_num_elements);

		int current = (lower_bound + upper_bound) >> 1;

		if (val == this->array_ptr[current]) {
			return current;
		}
		else if (lower_bound > upper_bound) {
			return -1;
		}
		else {
			if (val > this->array_ptr[current]) {
				return BinarySearch(val, current + 1, upper_bound);
			}
			else {
				return BinarySearch(val, lower_bound, current - 1);
			}
		}

		return -1;
	}

	int Search(T val) {
		/*assert(this->array_ptr != NULL);

		for (int i = 0; i < this->array_num_elements; i++) {
			if (this->array_ptr[i] == val) {
				return i;
			}
		}

		return -1;*/

		return BinarySearch(val, 0, this->array_num_elements - 1);
	}
};