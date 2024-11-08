#include <iostream>
#include "aisd6.h"
#include <cassert>


void test0() {
    MyDeque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_front(3);
    deque.push_front(4);
    deque.display();
    deque.display_reversed();
    std::cout << "Test 0\n";
}
void test1() {
    MyDeque<int> deque;
    deque.push_front(1);
    deque.push_front(1);
    deque.push_front(1);
    assert(deque.size() == 3);
    std::cout << "Test 1\n";
}

int main() {

    test0();
    test1();
    std::cout << "OK!\n";
    return 0;
}
