#pragma once
#include <cassert>

// DECLARE CLASSES SO LinkNode CAN ACCESS THEM
template <class T> class LinkIterator;
template <class T> class LinkedList;

template <class T>
class LinkNode {
public:
	// Now class LinkedList can 
	// access private members of Node 
	friend class LinkIterator<T>;
	friend class LinkedList<T>;

	/*int GetPriority() {
		return priority;
	}

	T GetData() {
		return data;
	}*/
private:
	int priority; //priority #1 has a higher priority than priority #2, therefore put #1 BEFORE #2
	T data;
	LinkNode* next_node;
	LinkNode* prev_node;
};

template <class T>
class LinkIterator {
public:
	friend class LinkedList<T>;

	LinkIterator() {
		node = NULL;
	}

	~LinkIterator(){}

	void operator=(LinkNode<T>* node) {
		this->node = node;
	}

	T& operator*() {
		assert(node != NULL);
		return node->data;
	}

	void operator++() {
		assert(node != NULL);
		node = node->next_node;
	}

	void operator++(int) { //POSTFIX
		assert(node != NULL);
		node = node->next_node;
	}
	
	void operator--() {
		assert(node != NULL);
		node = node->prev_node;
	}

	void operator--(int) { //POSTFIX
		assert(node != NULL);
		node = node->prev_node;
	}

	bool operator!=(LinkNode<T>* node) {
		return (this->node != node);
	}

	bool operator==(LinkNode<T>* node) {
		return (this->node == node);
	}

	bool IsValid() {
		return(node != NULL);
	}

	int GetNodePriority() {
		return node->priority;
	}
private:
	LinkNode<T>* node;
};

template <class T>
class LinkedList {
public:
	LinkedList() : size(0), root_node(0), last_node(0){}
	~LinkedList() {
		while (root_node) { //deletion so should not use FOR
			Pop();
		}
	}

	LinkNode<T>* Begin() {
		assert(root_node != NULL);
		return root_node;
	}

	LinkNode<T>* End() {
		return NULL;
	}

	LinkNode<T>* Last() {
		return last_node;
	}

	void InsertBefore(LinkIterator<T>& iter, T new_data, int priority) {
		assert(iter.node != NULL);

		LinkNode<T>* node = new LinkNode<T>;
		assert(node != NULL);

		// LINK NEW NODE TO EXISTING
		node->data = new_data;
		node->priority = priority;
		node->next_node = iter.node;
		node->prev_node = iter.node->prev_node;

		// LINK EXISTING TO NEW NODE
		if (node->next_node != NULL) {
			node->prev_node->next_node = node;
		}
		iter.node->prev_node = node;

		// SPECIAL CASE
		if (iter.node == root_node) {
			root_node = node;
		}

		size++;
	}

	void InsertAfter(LinkIterator<T>& iter, T new_data, int priority) {
		assert(iter.node != NULL);

		LinkNode<T>* node = new LinkNode<T>;
		assert(node != NULL);

		// LINK NEW NODE TO EXISTING
		node->data = new_data;
		node->priority = priority;
		node->next_node = iter.node->next_node;
		node->prev_node = iter.node;

		// LINK EXISTING TO NEW NODE
		if (node->next_node != NULL) {
			node->next_node->prev_node = node;
		}
		iter.node->next_node = node;

		// SPECIAL CASE
		if (iter.node == last_node) {
			last_node = node;
		}

		size++;
	}

	void PushFront(T new_data, int priority) {
		// INIT NEW NODE
		LinkNode<T>* node = new LinkNode<T>;

		assert(node != NULL);
		node->data = new_data;
		node->priority = priority;
		node->next_node = NULL;
		node->prev_node = NULL;

		// ADD NEW NODE TO LIST
		if (root_node != NULL) { //linked list not empty
			node->next_node = root_node;
			root_node->prev_node = node;
			root_node = node;
		}
		else { //linked list empty
			root_node = node;
			last_node = node;
		}

		size++;
	}

	void Push(T new_data, int priority) {
		// INIT NEW NODE
		LinkNode<T>* node = new LinkNode<T>;

		assert(node != NULL);
		node->data = new_data;
		node->priority = priority;
		node->next_node = NULL;
		node->prev_node = NULL;

		// ADD NEW NODE TO LIST
		if (last_node != NULL) { //linked list not empty
			last_node->next_node = node;
			node->prev_node = last_node;
		}
		else { //linked list empty
			root_node = node;
		}
		last_node = node;

		size++;
	}

	void PopFront() {
		assert(root_node != NULL);

		LinkNode<T>* temp_node = root_node;

		root_node = root_node->next_node;

		// ERROR PREVENTION
		if (root_node != NULL) {
			root_node->prev_node = NULL;
		}
		else {
			last_node = NULL;
		}

		// CLEANING TEMP
		delete temp_node;
		temp_node = NULL;

		size = (size == 0 ? size : size - 1);
	}

	void Pop() {
		assert(root_node != NULL);

		if (root_node->next_node == NULL) { //one element left
			delete root_node;
			root_node = NULL;
			last_node = NULL;
		}
		else { //2 or more elems left
			LinkNode<T>* second_last_node = last_node->prev_node;
			
			/*while (second_last_node->next_node != NULL && second_last_node != last_node) {
				second_last_node = second_last_node->next_node;
			}*/

			second_last_node->next_node = NULL;
			delete last_node;
			last_node = second_last_node;

			second_last_node = NULL;
		}

		size = (size == 0 ? size : size - 1);
	}

	int GetSize() {
		return size;
	}

private:
	int size;
	LinkNode<T>* root_node;
	LinkNode<T>* last_node;
};

class GAME2001_A2_LeTrung_DoublyLinkedList
{
};

