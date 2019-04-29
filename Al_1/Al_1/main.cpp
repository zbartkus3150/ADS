#include <iostream>

struct Node {
	int val;
	struct Node* next;
};


class Queue {
	Node* head;
	Node* tail;
public:
	Queue();
	~Queue() = default;
	void Enqueue(int x);
	void Dequeue();
	bool Empty();
	void Print();
};

Queue::Queue() {
	head = nullptr;
	tail = nullptr;
}

void Queue::Enqueue(int x) {
	Node* n = new Node;
	n->val = x;
	n->next = nullptr;

	if (head == nullptr) {
		head = n;
		tail = n;
	}
	else {
		n->next = head;
		head = n;
	}
}

void Queue::Dequeue() {
	if (head != nullptr) {
		Node* n;
		n = head;
		while (n->next != nullptr) {
			n = n->next;
		}
		std::cout << "Dequeue element: " << tail->val << std::endl;
		delete tail;
		tail = n;
	}
	else
		std::cout << "Queue is empty!" << std::endl;
}

bool Queue::Empty() {
	if (head != nullptr)
		return true;
	else
		return false;
}

void Queue::Print() {
	if (head != nullptr) {
		Node* n = head;
		std::cout << "Queue:" << std::endl;
		do {
			std::cout << n->val << " ";
			n = n->next;
		} while (n->next != tail);
		std::cout << n->val << " ";
		std::cout << std::endl;
	}
	else
		std::cout << "Queue is empty!" << std::endl;
}

int main() { //Coœ nie dzia³a//
	Queue q;
	q.Dequeue();
	q.Enqueue(5);
	q.Enqueue(1);
	q.Enqueue(2);
	q.Print();
	q.Dequeue();
	q.Enqueue(8);
	q.Print();
	system("Pause");
	return 0;
}