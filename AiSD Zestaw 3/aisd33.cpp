#include <iostream>
#include "aisd33.h"
#include <iterator>
#include <algorithm>
#include <cassert>


void test0() {
    ArrayList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ArrayList<int> list1(list);
    assert(list1.front()==1);
    list1.push_front(5);
    ArrayList<int> list2;
    list2= list1;
    assert(list2.size() == 4);
    std::cout << "Test 0\n";
}
void test1() {
    ArrayList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.size() == 3);
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 3);
    std::cout << "Test 1\n";
}

void test2() {
        ArrayList<int> list(2);
        list.push_front(5);
        list.push_front(8);
        assert(list.size() == list.max_size());
        list.pop_front();
        assert(list[0]==5);
        list.pop_front();
    try {
        list.pop_front();
    }catch(std::out_of_range& e) {list.push_front(1);}
        assert(!list.empty());
    std::cout << "Test 2\n";
}



void test3() {

    ArrayList<int> list;
    list.push_back(5);
    list.push_back(2);
    list.push_back(1);
    list.insert(1,4);
    int x=list.index(5);
    list.erase(x);
    list.reverse();
    assert(list.back() == 4);
    std::cout << "Test 3\n";
}

void test4() {

    ArrayList<int> list;
    list.push_back(7);
    list.push_back(2);
    list.push_front(3);
    list.push_back(1);
    list.push_back(4);
    list[2]=9;
    list.pop_front();
    assert(list.front() == 7);
    list.sort();
    assert(list.back()==9);
    std::cout << "Test 4\n";
}

void test5() {
    ArrayList<int> list(3);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ArrayList<int> list1(std::move(list));
    assert(list1.size() == 3);
    assert(list1[0] == 1);
    assert(list1[1] == 2);
    assert(list1[2] == 3);
    try {
        list.insert(0,2);
    }catch(std::overflow_error& e) {list1[0]=8;}
    assert(list1[0] == 8);
    std::cout << "Test 5\n";
}

int main() {

    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    std::cout << "OK!\n";
    return 0;
}

