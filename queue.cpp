#include <iostream>

// Queue class implementation

class Queue
{
	public:
		Queue(size_t size)
		{
			queue = new int[size];
			qsize = size;

			front = 0;
			rear = 0;
			isFull = false;
		}
		~Queue()
		{
			delete[] queue;
		}
		// Enqueues new element in queue. if queue is full, return 1 (error)
		int enqueue(int el);

		// Dequeues element from queue is the queue is not empty otherway return ???
		bool dequeue(int& el);

		// Checks if the queue is empty
		bool isEmpty();

	private:
		int* queue;
		size_t qsize;
		size_t front;
		size_t rear;
		bool isFull;
};

int Queue::enqueue(int el) {
	if(isFull) return 1;  // queue is full, enqueue unavailable
	
	size_t rear_next = (rear + 1) % qsize;
	queue[rear] = el;
	rear = rear_next;
	if(front == rear) isFull = true;

	return 0;
}

bool Queue::dequeue(int& el) {
	if(isEmpty()) return false;
	el = queue[front];
	front = (front + 1) % qsize;
	isFull = false;
	return true;
}

bool Queue::isEmpty() {
	if(front == rear and !isFull) return true;
	return false;
}

#define QUEUESIZE 4

// driver
int main() {

	Queue* queue = new Queue(QUEUESIZE);

	std::cout << queue->enqueue(5);
	std::cout << queue->enqueue(54);
	std::cout << queue->enqueue(53);
	std::cout << queue->enqueue(5222);

	int el = 0;
	if(queue->dequeue(el)) std::cout << el << std::endl;
	
	if(queue->dequeue(el)) std::cout << el << std::endl;

	if(queue->dequeue(el)) std::cout << el << std::endl;
	if(queue->dequeue(el)) std::cout << el << std::endl;

	if(queue->dequeue(el)) std::cout << el << std::endl;

	if(queue->dequeue(el)) std::cout << el << std::endl;

	return 0;
}