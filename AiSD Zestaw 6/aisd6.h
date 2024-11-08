#ifndef AISD6_H
#define AISD6_H

#include <iostream>
#include <cassert>

template <typename T>
class MyDeque {
    T* tab;
    std::size_t msize; // największa możliwa liczba elementów plus jeden
     // pierwsza wolna pozycja
public:
    std::size_t head; // pierwszy do pobrania
    std::size_t tail;

    MyDeque(std::size_t s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor
    ~MyDeque() { delete [] tab; }
    MyDeque(const MyDeque& other) {
        tab = new T[other.msize];
        memcpy(tab, other.tab, other.msize * sizeof(T));
        msize=other.msize;
        head= other.head;
        tail= other.tail;
    }; // copy constructor
    MyDeque& operator=(const MyDeque& other) {
        if (this == &other) return *this;
        tab = new T[other.msize];
        memcpy(tab, other.tab, other.msize * sizeof(T));
        msize=other.msize;
        head= other.head;
        tail= other.tail;
        return *this;
    }// copy assignment operator, return *this
    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    std::size_t size() const { return (tail - head + msize) % msize; }
    std::size_t max_size() const { return msize-1; }
    void push_front(const T& item); // dodanie na początek O(1)
    void push_back(const T& item); // dodanie na koniec O(1)
    T& front() { return tab[head]; } // zwraca poczatek
    T& back() { return tab[(tail + msize -1) % msize]; } // zwraca koniec
    void pop_front(); // usuwa początek kolejki O(1)
    void pop_back(); // usuwa koniec kolejki O(1)
    void clear(); // czyszczenie listy z elementów
    void display();
    void display_reversed();
};
template <typename T>
void MyDeque<T>::push_front(const T& item) {
    assert(!full());
    head = (head + msize -1) % msize;
    tab[head] = item;
}
template <typename T>
void MyDeque<T>::push_back(const T& item) {
    assert(!full());
    tab[tail] = item;
    tail = (tail + 1) % msize;
}

template <typename T>
void MyDeque<T>::pop_front() {
    assert(!empty());
    if (head==tail-1) {
        head=tail=0;
        return;
    }
    head = (head+1) % msize;
}
template <typename T>
void MyDeque<T>::pop_back() {
    assert(!empty());
    if (head == tail-1) {
        tail=head=0;
        return;
    }
    tail = (tail + msize-1) % msize;
}


template <typename T>
void MyDeque<T>::display() {
    for (std::size_t i = head; i != tail; i=(i+1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}
template <typename T>
void MyDeque<T>::display_reversed() {
    for (std::size_t i = tail-1; i != head-1; i=(i-1+msize) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}
template <typename T>
void MyDeque<T>::clear() {
    for (std::size_t i = head; i != tail; i=(i+1) % msize) {
        tab[i]=T();
    }
    head=tail=0;
}



#endif //AISD6_H
