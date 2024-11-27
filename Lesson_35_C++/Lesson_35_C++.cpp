#include"MyList.h"
#include"DList.h"
#include <list>
#include <string>
int main()
{
	/*using namespace MyList;
	Node<int> first(7);
	Node<int> second(3);
	first.next = &second;
	Node<int> third(9);
	second.next = &third;
	Node<int> fourth(4);
	third.next = &fourth;
	

	Node<int>* p = &first;
	while (p != nullptr)
	{
		p->show();
		p = p->next;
	}*/

	/*MyList::List<int> a;
	a.showList();
	a.push_back(9);
	a.push_back(3);
	a.push_back(7);
	a.push_back(4);
	a.showList();*/

	/*DNode<int> first(7);
	DNode<int> second(3);
	first.next = &second;
	second.prev = &first;
	DNode<int> third(4);
	DNode<int> fourth(9);
	second.next = &third;
	third.prev = &second;
	third.next = &fourth;
	fourth.prev = &third;

	DNode<int>* p = &first;
	while (p != nullptr)
	{
		p->show();
		p = p->next;
	}
	p = &fourth;
	while (p != nullptr)
	{
		p->show();
		p = p->prev;
	}*/

	DList <int> b;
	b.showList();
	b.push_back(7);
	b.push_back(4);
	b.push_back(9);
	b.push_back(3);
	
	/*DNode<int>* item = b.findByIndex(2);
	if (item == nullptr)
		cout << "Not found\n";
	else
		item->show();*/

	b.insertBefore(2, 66);
	b.insertAfter(2, 77);
	b.showList();
	b.erase(7);
	cout << endl;
	cout << endl;
	cout << endl;
	b.showList();
	cout << endl;
	cout << endl;
	//Перевірка
	b.findByIndex(0)->show();




	/*std::list<std::string> p33;
	p33.push_back("Yaroslav");
	p33.push_back("Andriy");
	p33.push_back("Stepan");
	p33.push_back("Ivan");
	p33.push_back("Kyrylo");
	std::list<std::string>::iterator p;
	for (p = p33.begin(); p != p33.end(); p++)
	{
		cout << *p << " ";
	}cout << endl;
	p33.sort();
	for (auto item : p33)
	{
		cout << item << " ";
	}*/

}