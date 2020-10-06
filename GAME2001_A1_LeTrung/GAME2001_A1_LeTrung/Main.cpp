#include <iostream>
using namespace std;

#include "BaseArray.h"
#include "UnorderedArray.h"
#include "OrderedArray.h"

int main() {
	const int test_arr_size = 10;
	int test_value_arr[test_arr_size] = { 7,4,9,666,100,0,2020,99,300,0 };
	
	UnorderedArray<int> chaotic_arr(1, false);
	OrderedArray<int> the_order_1886(1, true);

	cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
	cout << ">>>>> Testing UnorderedArray <<<<<" << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	for (int i = 0; i < test_arr_size; i++) {
		chaotic_arr.Push(test_value_arr[i]);
		cout << chaotic_arr;
		cout << endl;
	}

	cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
	cout << ">>>>> Testing OrderedArray <<<<<" << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	for (int i = 0; i < test_arr_size; i++) {
		the_order_1886.Push(test_value_arr[i]);
		cout << the_order_1886;
		cout << endl;
	}

	return 1;
}