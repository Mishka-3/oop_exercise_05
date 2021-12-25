// oop_exercise_05.cpp: определяет точку входа для приложения.
//

#include "oop_exercise_05.h"
#include "Trapezoid.h"
#include "Stack.h"
#include <iostream>
#include "titerator.h"

using namespace std;
int main() {

    Stack<Trapezoid> stack;
    std::shared_ptr<Trapezoid> ptr;
    int c;
    stack.size = 0;
    while (1) {
        cout << "1-Add Trapezoid " << "2-Print stack " << "3-Insert Item via index " << "4-stack size " << "5-Delete Item via index " <<  "6-Remove stack " << "7-Exit" << '\n';
        cin >> c;
        if (c == 1) {
            cout << "coordinates of the vertices\n";
            ptr = make_shared<Trapezoid>(cin);
            stack.push(ptr);
        }
        if (c == 2) {
            for (auto x : stack) {
                cout << *x << endl;
            }
        }
        if (c == 3) {
            int index;
            cout << "index\n";
            cin >> index;
            if (index <= stack.size && index >= 1) {
                cout << "coordinates of the vertices\n";
                ptr = make_shared<Trapezoid>(cin);
                stack.insert(ptr, index);
            } else {
                cout << "index error\n";
            }
        }
        if (c == 4) {
            cout << stack.size << "\n";  
        }
        if (c == 5) {
            int index;
            cout << "index\n";
            cin >> index;
            if (index <= stack.size && index >= 1) {
                stack.erase(index);
            }
            else {
                cout << "index error\n";
            }
        }
        if (c == 6) {
            stack.~Stack();
        }
        if (c == 7) {
            return 0;
        }
    }
    return 0;
}

