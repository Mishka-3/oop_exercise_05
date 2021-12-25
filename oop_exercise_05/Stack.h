//Листинг Файла Stack.h

#include "Item.h"
#include "titerator.h"

template <class T>
class Stack {
public:
	Stack();
	Stack(const Stack<T>& orig);
	bool empty();
	shared_ptr<T> top();
	void push(shared_ptr<T>& item);
	void insert(shared_ptr<T>& obj, int n);
	void erase(int n);
	shared_ptr<T> pop();
	template <class A>
	friend std::ostream& operator<<(std::ostream& os, const Stack<A>& stack);
	~Stack();
	Titerator<Item<T>, T> begin();
	Titerator<Item<T>, T> end();
public:
	int size;
	shared_ptr<Item<T>> head;
};
#include "Stack.inl"





