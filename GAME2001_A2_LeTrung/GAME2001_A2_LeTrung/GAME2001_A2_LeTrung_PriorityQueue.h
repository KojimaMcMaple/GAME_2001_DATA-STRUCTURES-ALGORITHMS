#pragma once

#include "GAME2001_A2_LeTrung_PriorityQueueDoublyLinkedList.h"
#include <iostream>
using namespace std;

template<class T>
class PriorityQueue {
public:
	PriorityQueue(int size) {
		assert(size > 0);
		this->size = size;
	}

	void Push(T value, int priority) {
		assert(linked_list.GetSize() < size);

		if (linked_list.GetSize() == 0) {
			linked_list.Push(value, priority);
		}
		else {
			LinkIterator<T> iter;
			iter = linked_list.Begin();

			//CMP compare_value;

			//while (iter.IsValid()) {
			//	if (compare_value(value, *iter)) {//overloaded bracket() operation
			//		break;
			//	}

			//	iter++;
			//}

			while (iter.IsValid()) {
				if (priority < iter.GetNodePriority()) {//priority #1 has a higher priority than priority #2, therefore put #1 BEFORE #2
					break;
				}

				iter++;
			}

			if (iter.IsValid()) {
				linked_list.InsertBefore(iter, value, priority);
			}
			else {
				linked_list.Push(value, priority);
			}
		}
	}

	void Pop() {
		linked_list.PopFront();
	}

	T& Front() {
		LinkIterator<T> iter;
		iter = linked_list.Begin();

		return *iter;
	}

	T& Back() {
		LinkIterator<T> iter;
		iter = linked_list.End();

		return *iter;
	}

	int GetSize() {
		return linked_list.GetSize();
	}

	int GetMaxSize() {
		return size;
	}

	bool IsEmpty() {
		return (linked_list.GetSize() == 0);
	}

	void Resize() {
		assert(size > 0);
		this->size = size;
	}

	LinkedList<T>* GetLinkedList() {
		return &linked_list;
	}

	friend ostream& operator<<(ostream& os, PriorityQueue<T>& queue) {
		LinkIterator<T> iter;
		
		iter = queue.GetLinkedList()->Begin();

		while (iter.IsValid()) {
			os << "> Data: " << *iter << "\t- Priority:" << iter.GetNodePriority() << endl;
			
			iter++;
		}

		return os;
	}

private:
	LinkedList<T> linked_list;
	int size;
};