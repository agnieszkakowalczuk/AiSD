#include "aisd5.h"
#include <iostream>

void test1() {
    DoubleList<int> list;
    list.push_front(0);
    list.push_back(1);
    list.push_front(2);
    list.push_back(3);
    assert(list.size() == 4);
    std::cout << "Test 1\n";
}

void test2() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    assert(list.front() == 1);
    assert(list.back() == 4);
    list.push_back(5);
    list.push_back(6);
    assert(list.size() == 6);
    std::cout << "Test 2\n";
}

void test3() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    assert(list.front() == 2);
    assert(list.size() == 2);
    std::cout << "Test 3\n";
}


void test4() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << "Display: ";
    list.display();
    std::cout << "Display reversed: ";
    list.display_reversed();
    assert(list.front() == 1);
    assert(list.back() == 3);
    std::cout << "Test 4\n";
}

void test5() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    DoubleList<int> list1(list);  // Kopiowanie
    std::cout << "Oryginalna lista: ";
    list.display();
    std::cout << "Lista, copy constructor: ";
    list1.display();
    list1.push_back(4);
    assert(list.back() == 3);
    assert(list1.size() != list.size());
    std::cout << "Test 5\n";
}

void test6() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    assert(list.empty());
    std::cout << "Test 6\n";
}

void test7() {

    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    DoubleList<int> list1=list;
    list.push_back(4);
    assert(list1.back() != 4);
    list1.push_back(5);
    assert(list.back() == 4);
    std::cout<<"Test 7\n";
}

void test8() {
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    DoubleList<int> list1=std::move(list);
    assert(list1.size() == 4);
    assert(list.empty());
    std::cout << "Test 8\n";
}



int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    std::cout << "OK!\n";

    return 0;
}
