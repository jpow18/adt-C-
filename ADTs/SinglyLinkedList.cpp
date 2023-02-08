#include "List.h"
using namespace ssl;

SinglyLinkedList::SinglyLinkedList() {
	head = nullptr;
	tail = nullptr;
}
void SinglyLinkedList::insertAfter(Node* curNode, Node* newNode) {
	if (head == nullptr) { // List is empty
		head = newNode;
		tail = newNode;
	}
	else if (curNode == tail) {
		 tail->set_next(newNode);
		 tail = newNode;
	}
	else {
		newNode->set_next(curNode->get_next());
		curNode->set_next(newNode);
	}
}
void SinglyLinkedList::removeAfter(Node* curNode) {
	// Special case, remove head
	if (curNode == nullptr && head != nullptr) {
		Node* nextNode = head->get_next();
		head = nextNode;
		
		if (nextNode == nullptr) { // removed the last item
			tail = nullptr;
		}
	}
	else if (curNode->get_next() != nullptr) {
		Node* nextNode = curNode->get_next()->get_next();
		curNode->set_next(nextNode);
		if (nextNode == nullptr) { // removed tail
			tail = curNode;
		}
	}
	else {
		tail = curNode;
	}
}
Node* search(int target);
void listTraverse();
void insertionSort();
void selectSort();