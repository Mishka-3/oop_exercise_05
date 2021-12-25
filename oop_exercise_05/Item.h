//Листинг Файла Item.h


#include "Trapezoid.h"
#include <memory>

using namespace std;

template <typename T>
class Item {
public:
	Item() = default;
	Item(const shared_ptr<T>& item);
	Item(const shared_ptr<Item<T>>& orig);
	shared_ptr<Item<T>> SetNext(shared_ptr<Item<T>>& next_);
	shared_ptr<Item<T>> GetNext();
	shared_ptr<T> GetItem();
	~Item() = default;
	friend ostream& operator<<(ostream& os, const shared_ptr<Item<T>>& obj);
public:
	shared_ptr<T> item;
	shared_ptr<Item<T>> next;
};
#include "Item.inl"
