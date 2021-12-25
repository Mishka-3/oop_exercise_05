#include <iostream>

using namespace std;

template <class T>
Item<T>::Item(const shared_ptr<T>& item) {
	this->item = item;
	this->next = NULL;
}
template <class T>
Item<T>::Item(const shared_ptr<Item<T>>& orig) {
	this->item = orig.item;
	this->next = orig.next;
}

template <class T>
shared_ptr<Item<T>> Item<T>::SetNext(shared_ptr<Item<T>>& next_) {
	shared_ptr<Item<T>> old = this->next;
	this->next = next_;
	return old;
}
template <class T>
shared_ptr<T> Item<T>::GetItem() {
	return this->item;
}
template <class T>
shared_ptr<Item<T>> Item<T>::GetNext() {
	return this->next;
}



template <class T>
ostream&
operator<<(ostream& os,
	const shared_ptr<Item<T>>& obj) { // перегруженный оператор вывода
	if (obj.item) {
		os << "{";
		os << *(obj.item);
		os << "}" << endl;
	}
	return os;
}




