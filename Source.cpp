#include <iostream>
#include "LinkedListStack.hpp"
using namespace std;

int main() {
    LinkedListStack<int> s;

    cout << "push() and peek()" << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.peek() << endl << endl;;

    cout << "pop()" << endl;
    s.pop();
    cout << "After pop: " << s.peek() << endl; 

    cout << "\n clear() " << endl;
    s.clear();
    cout << "empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    cout << "\n copy() " << endl;
    s.push(10);
    s.push(20);
    LinkedListStack<int> t(s); 
    cout << "Copy: " << t.peek() << endl; 

    cout << "\n rotate() " << endl;
    s.push(30);
    s.push(40);
    cout << "Before rotate: ";
    s.print();
    s.rotate(Stack<int>::RIGHT);
    cout << "rotate right:  ";
    s.print();
    s.rotate(Stack<int>::LEFT);
    cout << "rotate left:   ";
    s.print();

    return 0;
}