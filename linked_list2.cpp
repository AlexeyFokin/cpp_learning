#include <iostream>

class Node
{
	public:
		int data;
		Node* next;
};

class LinkedList
{
	public:
		LinkedList() {
			head = NULL;
		}

		// inserts a node in front of all other nodes in LinkedList
		Node* insertFront(int data);

		// upon given node gives next node in LinkedList
		Node* next(Node* node);

		// deletes first node in a LinedList
		void deleteFront();

		// prints all nodes in LinkedList starting form node
		void display();

		// checks is LinkedList have loop inside
		bool isLooped();

	private:
		Node* head;
};

Node* LinkedList::insertFront(int data) {
	Node* newNode = new Node();

	newNode->data = data;
	newNode->next = head;
	head = newNode;
	return newNode;
}

Node* LinkedList::next(Node* node) {
	return node->next;
}

void LinkedList::deleteFront() {
	Node* headToDel = head;
	if(head == NULL) {
		std::cout << "LinkedList is empty, nothing to delete" << std::endl;
		return;
	}
	head = head->next;
}

void LinkedList::display() {
	Node* currentNode = head;
	
	while (currentNode != NULL) {
		std::cout << "Node ref " << currentNode << " has data " << currentNode->data << std::endl;
		currentNode = currentNode->next;
	}
}

// to find loop in LinkedList we use two running pointers with different speed
// if after number of steps two pointers will point to same Node - list has loop
bool LinkedList::isLooped() {
	Node* first;
	Node* second;

	first = head;
	second = head;

	if(head == NULL) return false;	// empty LinkedList - no loop

	while(first->next != NULL) {
		first = first->next;

		if(second->next == NULL) return false;
		second = second->next;
		if(second->next == NULL) return false;
		second = second->next;

		if(first == second) return true;
	}
	return false;
}

int main()
{
	LinkedList* linked_list = new LinkedList();

	auto endNode = linked_list->insertFront(25);
	linked_list->insertFront(2);
	linked_list->insertFront(325);
	linked_list->insertFront(23335);
	auto firstNode = linked_list->insertFront(2235);
	//endNode->next = firstNode;

	linked_list->display();
	// linked_list->deleteFront();

	// linked_list->display();

	bool isLoop = linked_list->isLooped();
	std::cout << "is looped? " << isLoop << std::endl;
}
