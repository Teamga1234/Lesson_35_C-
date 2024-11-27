#pragma once
#include <iostream>
using std::cout;
using std::endl;

namespace MyList {
	template <typename T>
	class Node {
	public:
		T info;
		Node* next;
		Node(T value) { info = value; next = nullptr; }
		void show()const {
			cout << "Info: " << info << endl;
			cout << "\tnext: " << next << endl;
		}
	};


	template <typename T>
	class List {
		Node<T>* head;
		Node<T>* current;
	public:
		List() {
			head = nullptr;
			current = nullptr; }
		void push_back(T value) {
			Node<T>* el = new Node<T>(value);
			if (head == nullptr) {
				head = el;
				current = el;

			}
			else
			{
				current->next = el;
				current = el;
			}
		}
		void showList() const {
			if (head == nullptr)
				cout << "List is Empty\n";
			else {
				Node<T>* p = head;
				while (p != nullptr)
				{
					p->show();
					p = p->next;
				}
			}
			
		}
	};
}