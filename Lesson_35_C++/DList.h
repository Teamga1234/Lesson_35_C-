#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class DNode {
public:
	T info;
	DNode* prev;
	DNode* next;

	DNode(T value) { info = value; next = prev = nullptr; }
	void show()const {
		cout << "info: " << info << endl;
		cout << "\tprev: " << prev << endl;
		cout << "\tnext: " << next << endl;
	}
};


template<typename T>
class DList {
	DNode<T>* head;
	DNode<T>* current;
public:
	DList() { head = current = nullptr; }

	void push_back(T value) {
		
		DNode<T>* el = new DNode<T>(value);
		if (head == nullptr) { 
			head = el;
			current = el;
		}
		else {
			current->next = el; 
			el->prev = current;
			current = el;
		}
	}

	void showList() {
		if (head == nullptr) cout << "List is empty\n";
		else {
			DNode<T>* p = head;
			while (p != nullptr) {
				p->show();
				p = p->next;
			}
		}
	}

	void showReverseList() {
		if (head == nullptr) cout << "List is empty\n";
		else {
			DNode<T>* p = current;
			while (p != nullptr) {
				p->show();
				p = p->prev;
			}
		}
	}
	DNode<T>* search(T value)
	{
		DNode<T>* p = head;
		while (p != nullptr)
		{
			if (p->info == value)
				return p;
			p = p->next;
		}
		return nullptr;
	}
	void push_front(T value)
	{ 
		DNode<T>* el = new DNode<T>(value);
		if (head == nullptr) {
			head = el;
			current = el;
		}
		else {
			head->prev = el;
			el->next = head;
			head = el;
		}
	}
	DNode<T>* findByIndex(int index)
	{ 
		DNode<T>* temp = head;
		while (temp)
		{
			if (index > 0 && temp)
			{
				temp = temp->next;
				index--;
			}
			else
			{
				if (temp)
					return temp;
				return nullptr;
			}
		}
		
	}
	void insertBefore(T before, T value)
	{ 
		{
			DNode<T>* p = head;
			int index = 0;
			while (p) 
			{
				if (index == before) 
				{
					DNode<T>* temp = new DNode<T>(value);
					temp->next = p;
					temp->prev = p->prev;
					if (p->prev) 
					{
						p->prev->next = temp;
					}
					else 
					{
						head = temp;
					}
					p->prev = temp;
					return;
				}
				p = p->next;
				index++;
			}
			cout << "Error: Index out of bounds\n";
		}
	}
	void insertAfter(T after, T value) 
	{  
	if(after >= 0)
	{
		DNode<T>* p = new DNode<T>(value);
		DNode<T>* temp = findByIndex(after);
		p->prev = temp;
		p->next = temp->next;
		temp->next->prev = p;
		temp->next = p;
	}
	}
	void erase(T value)
	{  
		DNode<T>* p = head;
		if (head->info == value)
		{
			//
			/*if(&& p->info == value)
			head->next->prev = nullptr;
			head = head->next;
			delete p;
			return;*/
			//
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
			return;

		}
		if (current->info == value)
		{
			/*current->prev->next = nullptr;
			current = current->prev;
			delete p;
			return;*/
			current = current->prev;
			delete current->next;
			current->next = nullptr;
			return;

		}
		while (p)
		{
			if (p->info == value)
			{
				
				
				p->next->prev = p->prev;
				p->prev->next = p->next;
				delete p;
				return;
			}
			p = p->next;
		}
	}

};