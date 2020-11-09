#pragma once


#include "GAME2001_A2_LeTrung_PriorityQueue.h"
#include <iostream>
using namespace std;
//
//template<class T>
//class LessCompare {
//public:
//	inline bool operator()(T left_val, T right_val) {
//		return (left_val < right_val);
//	}
//};
//
//template<class T>
//class LessComparePtr {
//public:
//	inline bool operator()(T left_val, T right_val) {
//		return ((*left_val) < (*right_val));
//	}
//};
//
//template<class T>
//class GreaterCompare {
//public:
//	inline bool operator()(T left_val, T right_val) {
//		return !(left_val < right_val); //compare cheat with "!"
//	}
//};
//
//template<class T>
//class GreaterComparePtr {
//public:
//	inline bool operator()(T left_val, T right_val) {
//		return !((*left_val) < (*right_val)); //compare cheat with "!"
//	}
//};

int main() {
	PriorityQueue<float> FloatQueue(7);

	cout << "GAME2001_A2_LeTrung" << endl;
	cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
	cout << ">>>>> Testing PriorityQueue <<<<<" << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

	cout << ">>>>> PUSH TEST <<<<<" << endl;
	FloatQueue.Push(100.0, 1);
	FloatQueue.Push(19.63, 5);
	FloatQueue.Push(2108.1991, 2);
	FloatQueue.Push(198.4, 1);
	FloatQueue.Push(31.10, 3);
	FloatQueue.Push(1.992, 4);
	FloatQueue.Push(24.08, 1);
	cout << FloatQueue;
	cout << endl;

	cout << ">>>>> POP TEST <<<<<" << endl;
	FloatQueue.Pop();
	cout << FloatQueue;
	cout << endl;

	cout << ">>>>> FRONT TEST <<<<<" << endl;
	cout << FloatQueue.Front();
	cout << endl;

	return 0;
}