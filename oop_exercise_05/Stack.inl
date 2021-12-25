#include <iostream>
using namespace std;

template <class T>
Stack<T>::Stack() {
    this->head = NULL;
}
template <class T>
Stack<T>::Stack(const Stack<T>& orig) {
    head = orig.head;
}

template <class A>
std::ostream& operator<<(std::ostream& os, const Stack<A>& stack) {
    shared_ptr<Item<T>> item = stack.head;
    while (item != NULL) {
        os << *item;
        item = item->GetNext();
    }
    return os;
}

template <class T>
void Stack<T>::push(shared_ptr<T>& item) {
    std::shared_ptr<Item<T>> other = std::make_shared<Item<T>>(item);
    other->SetNext(head);
    head = other;
    size++;
}

template <class T>
void Stack<T>::insert(shared_ptr<T>& item, int n) {
    Stack* s_tmp = new Stack();
    for (int i = 0; i < n - 1; i++)
    {
        s_tmp->push(head->item);
        this->pop();
    }
    this->push(item);
    for (int i = 0; i < n - 1; i++)
    {
        this->push(s_tmp->head->item);
        s_tmp->pop();
    }
}
template <class T>
void Stack<T>::erase(int n) {
    Stack* s_tmp = new Stack();
    for (int i = 0; i < n - 1; i++)
    {
        s_tmp->push(head->item);
        this->pop();
    }
    this->pop();
    for (int i = 0; i < n - 1; i++) {
        this->push(s_tmp->head->item);
        s_tmp->pop();
    }
}

template <class T>
bool Stack<T>::empty() {
    return head == NULL;
}

template <class T> shared_ptr<T> Stack<T>::pop() {
    shared_ptr<T> result=NULL;
    if (head) {
    shared_ptr<Item<T>> old_head = head;
    result = old_head->GetItem();
    head = head->GetNext();
    size--;
    return result;
    }
    return result;
}

template <class T>
shared_ptr<T> Stack<T>::top() {
    shared_ptr<T> result;
    if (head != NULL) {
        result = head->GetItem();
    }
    return result;
}

template <class T>
Stack<T>::~Stack() {
    head=NULL;
}
template <class T> Titerator<Item<T>, T> Stack<T>::begin() {
    return Titerator<Item<T>, T>(head);
}

template <class T> Titerator<Item<T>, T> Stack<T>::end() {
    return Titerator<Item<T>, T>(NULL);
}


