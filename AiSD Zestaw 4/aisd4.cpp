#include <iostream>
#include "aisd4.h"

 void test0(){
     SingleList<int> list;
     list.push_back(1);
     list.push_back(2);
     list.push_back(3);
     assert(list.size() == 3);
     std::cout << "Test 0\n";
 }
void test1() {
     SingleList<int> list;
     for(int i=0;i<5;i++) {
       list.push_front(0);
     }
     assert(list.size() == 5);
     std::cout << "Test 1\n";
 }


void test2() {
     SingleList<int> list;
     list.push_front(1);
     list.pop_back();
     assert(list.empty());
     list.push_back(1);
     list.pop_front();
     assert(list.empty());
     std::cout << "Test 2\n";
 }


void test3() {
     SingleList<int> list;
     list.push_front(3);
     list.push_front(4);
     assert(list.front() == 4);
     assert(list.back() == 3);
     std::cout << "Test 3\n";
 }


void test4() {
   SingleList<int> list;
   list.push_front(1);
   list.push_front(2);
   list.push_back(3);
   list.clear();
   assert(list.empty());
   list.push_front(1);
   assert(list.index(1)==0);
   std::cout << "Test 4\n";
 }

 void test5() {
  SingleList<int> list;
  SingleList<int> list1;
  list.push_back(1);
  list1.push_front(1);
  list.push_back(2);
  list1.push_front(2);
  list.push_back(3);
  list1.push_front(3);
  list.reverse();
  for(size_t i=0;i<list.size();i++) {
   assert(list[i] == list1[i]);}
  std::cout << "Test 5\n";
 }

void test6() {
  SingleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  SingleList<int> list1=std::move(list);
  assert(list1.size() == 4);
  assert(list.empty());
  std::cout << "Test 6\n";
 }

void test7() {

  SingleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  SingleList<int> listCopy = list;
  list.push_back(4);
  assert(list.size() != listCopy.size());
  std::cout<<"Test 7\n";
 }

void test8() {
  SingleList<int> list;
  list.push_back(1);
  list[0]=2;
  assert(list.front() == 2);
  std::cout<<"Test 8\n";
 }

void test9() {
  SingleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  assert(list.index(3) == 2);
  std::cout<<"Test 9\n";
 }

void test10() {

  SingleList<int> list;
  list.push_back(1);
  list.push_back(5);
  list.push_back(4);
  list.push_back(5);
  list.insert(list.index(list.front()),2);
  assert(list.front() == 2);
  std::cout<<"Test 10\n";
 }

void test11() {

  SingleList<int> list;
  list.push_back(9);
  list.push_back(8);
  list.push_back(7);
  list.erase(0);
  assert(list.front() == 8);
  assert(list.size() == 2);
  std::cout<<"Test 11\n";
 }

int main() {
  test0();
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  test11();
  std::cout << "OK!";
    return 0;
}

