// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>// assert()
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <string.h>

template <typename T>
class ArrayList {
    T* tab;
    int msize; // najwieksza mozliwa liczba elementow
    int last; // pierwsza wolna pozycja
public:

    ArrayList(int s=10) : msize(s), last(0) {
        assert( s > 0 );
        tab = new T[s];
        assert( tab != nullptr );

    } // default constructor
    ~ArrayList() { delete [] tab; } // destruktor



    ArrayList(const ArrayList& other) // copy constructor
    {
        tab = new T[other.msize];
        memcpy(tab, other.tab, other.msize * sizeof(T));
        msize= other.msize;
        last = other.last;
    }

    ArrayList(ArrayList&& other) // move constructor NIEOBOWIAZKOWE
    {
        tab= other.tab;
        msize= other.msize;
        last = other.last;
        other.tab = nullptr;
        other.msize = 0;
        other.last = 0;

    }// usage:   ArrayList<int> list2(std::move(list1));


    ArrayList& operator=(const ArrayList& other) // copy assignment operator, return *this
    {
        if (this == &other) return *this;
        tab = new T[other.msize];
        memcpy(tab, other.tab, other.msize * sizeof(T));
        msize=other.msize;
        last=other.last;
        return *this;
    }// usage:   list2 = list1;

    ArrayList& operator=(ArrayList&& other) // move assignment operator, return *this
    {
        if (this == &other) return *this;
        tab= other.tab;
        msize= other.msize;
        last = other.last;
        other.tab = nullptr;
        other.msize = 0;
        other.last = 0;
        return *this;
    }// usage:   list2 = std::move(list1); NIEOBOWIAZKOWE


    bool empty() const { return last == 0; } // checks if the container has no elements
    bool full() const { return last == msize; } // checks if the container is full
    int size() const { return last; } // liczba elementow na liscie
    int max_size() const { return msize; } // najwieksza mozliwa liczba elementow


    void push_front(const T& item) {
        if (full()) {
            throw std::overflow_error("Error: Lista pełna");
        }
        for (int i = last; i > 0; --i) {
            tab[i] = tab[i - 1];
        }
        tab[0] = item;
        last++;
    }

    void push_back(const T& item) {
        if (full()) {
            throw std::overflow_error ("Error: Lista pełna\n");
        }
        tab[last++] = item;
    }

    T& front() // zwraca poczatek, nie usuwa, error dla pustej listy
    {
        if (empty()) {
            throw std::out_of_range ("Error: Lista pusta\n");
        }
        return tab[0];
    }

    T& back() // zwraca koniec, nie usuwa, error dla pustej listy
    {
        if (empty()) {
            throw std::out_of_range("Error: Lista pusta\n");
        }
        return tab[last-1];
    }

    void pop_front() // usuwa poczatek, error dla pustej listy
    {
        if (empty()) {
            throw std::out_of_range("Error: Lista pusta\n");
        }
        for (int i = 0; i < last - 1; i++) {
            tab[i] = tab[i + 1];
        }
        last--;
    }
    void pop_back() // usuwa koniec, error dla pustej listy
    {
        if (empty()) {
            throw std::out_of_range("Error: Lista pusta\n");
        }
        last--;
    }
    void clear() // czyszczenie listy z elementow
    {

        last=0;
    }
    void display() // lepiej zdefiniowac operator<<
    {
        for (int i=0;i<last;i++) {
            std::cout<<tab[i]<<" ";
        }
        std::cout<<"\n";
    }
    void reverse() // odwracanie kolejnosci
    {
        std::reverse(tab, tab + last);
    }

    void sort()// sortowanie listy
    {
        std::sort(tab, tab + last);
    }


    // Operacje z indeksami. NIEOBOWIAZKOWE
    // https://en.cppreference.com/w/cpp/language/operators
    // Array subscript operator
    T& operator[](int pos) // podstawienie L[pos]=item, odczyt L[pos]
    {
        if (pos < 0 || pos >= last) {
            throw std::out_of_range("Error: Index poza zakresem\n");
        }
        return tab[pos];
    }
    const T& operator[](int pos) const // dostep do obiektu const
    {
        if (pos < 0 || pos >= last) {
            throw std::out_of_range("Error: Index poza zakresem\n");
        }
        return tab[pos];
    }
    void erase(int pos) // usuniecie elementu na pozycji pos
    {
        if (pos < 0 || pos >= last) {
            throw std::out_of_range("Error: Index poza zakresem\n");
        }
        std::copy(tab+pos+1, tab+last,tab+pos);
        last--;
    }

    int index(const T& item)// jaki index na liscie (-1 gdy nie ma)
    {
        auto it = std::find(tab, tab + last, item);
        if (it != tab + last) {
            return std::distance(tab, it);
        }
        return -1;

    }

    void insert(int pos, const T& item)// inserts item before pos
    {
        if(pos==0){
            push_front(item);
        }
        else if(pos==size()){
            push_back(item);
        }
        else if (pos < 0 || pos >= last) {
            throw std::out_of_range("Error: Index poza zakresem\n");
        }
        else {
            if (full()) {
                throw std::overflow_error("Error: Lista pełna\n");
            }
            std::copy(tab + pos, tab + last, tab + pos + 1);
            tab[pos] = item;
            last++;
        }

    }

    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) { // odwolanie L.last
            os << L.tab[i] << " ";   // odwolanie L.tab
        }
        return os;
    } // usage:   std::cout << L << std::endl;
};

#endif

// EOF

