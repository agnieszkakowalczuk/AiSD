#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>
#include <cassert>

template <typename T>
struct SingleNode {

    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {}
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {}
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList();

    SingleList(const SingleList& other)
    {
        if (other.head == nullptr) {
            return;
        }
        SingleNode<T>* node = other.head;
        while (node != nullptr){
            push_back(node->value);
            node = node->next;
        }
    }// usage:   SingleList<int> list2(list1);

    SingleList(SingleList&& other) {

        head=other.head;
        tail=other.tail;
        other.head=nullptr;
        other.tail=nullptr;

    }// move constructor NIEOBOWIAZKOWE
    // usage:   SingleList<int> list2(std::move(list1));

    SingleList& operator=(const SingleList& other) {

        if (this == &other) return *this;
        clear();
        if (other.head == nullptr) {
            return *this;
        }
        SingleNode<T>* node = other.head;
        while (node != nullptr) {
            push_back(node->value);
            node = node->next;
        }
        return *this;
    }
    // copy assignment operator, return *this
    // usage:   list2 = list1;

    SingleList& operator=(SingleList&& other)
    {
        if (this == &other) return *this;
        clear();
        head=other.head;
        tail=other.tail;
        other.head=nullptr;
        other.tail=nullptr;
        return *this;
    }// move assignment operator, return *this
    // usage:   list2 = std::move(list1); NIEOBOWIAZKOWE

    bool empty() const { return head == nullptr; }
    std::size_t size() const // O(n) bo trzeba policzyc
    {
        size_t count = 0;
        SingleNode<T>* node = head;
        while (node != nullptr) {
            count++;
            node = node->next;
        }
        return count;
    }
    void push_front(const T& item); // O(1), L.push_front(item)

    void push_back(const T& item); // O(1), L.push_back(item)

    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(n)
    void clear(); // czyszczenie listy z elementow O(n)
    void display(); // O(n)
    void reverse(); // O(n)
    T& operator[](std::size_t pos) // podstawienie L[pos]=item, odczyt L[pos]
    {
        assert(pos>=0 && pos <= this->size());
        SingleNode<T>* node = head;
        for (std::size_t index = 0; index < pos; ++index) {
            node = node->next;
        }
        return node->value;
    }
    const T& operator[](std::size_t pos) const // dostep do obiektu const
    {
        assert(pos>=0 && pos <= this->size());
        SingleNode<T>* node = head;
        for (std::size_t index = 0; index < pos; ++index) {
            node = node->next;
        }
        return node->value;
    }

    void erase(std::size_t pos) {
        assert(pos>=0 && pos <= this->size());
        SingleNode<T>* node = head;
        if (pos == 0) {
            pop_front();
            return;
        }
        for (std::size_t index = 0; index < pos-1; ++index) {
            node = node->next;
        }
        SingleNode<T>* delete_node = node->next;
        node->next=node->next->next;
        delete delete_node;

    }
    int index(const T& item) // jaki index na liscie (-1 gdy nie ma) O(n)
    {
        SingleNode<T>* node = head;
        int index = 0;
        while (node != nullptr) {
            if (node->value == item) {
                return index;
            }
            node = node->next;
            index++;
        }
        return -1;
    }
    void insert(std::size_t pos, const T& item) {
        assert(pos>=0 && pos <= this->size());
        if (pos == 0) {
            push_front(item);
        } else if (pos == size()) {
            push_back(item);
        } else {
            SingleNode<T>* node = head;
            for (std::size_t index = 0; index < pos-1; ++index) {
                node = node->next;
            }
            node->next = new SingleNode<T>(item, node->next);
        }
    }
    void insert(std::size_t pos, const T&& item) {
        assert(pos>=0 && pos <= this->size());
        if (pos == 0) {
            push_front(item);
        } else if (pos == size()) {
            push_back(item);
        } else {
            SingleNode<T>* node = head;
            for (std::size_t index = 0; index < pos-1; ++index) {
                node = node->next;
            }
            node->next = new SingleNode<T>(std::move(item), node->next);
        }
    }
    
};

template <typename T>
SingleList<T>::~SingleList() {
    // I sposob.
    for (SingleNode<T> *node; !empty(); ) {
        node = head->next; // zapamietujemy
        delete head;
        head = node; // kopiowanie wskaznika
    }
    // II sposob.
    // while (!empty()) { pop_front(); }
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display() {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void SingleList<T>::reverse() {
    SingleNode<T>*  node = head, *prev = nullptr,*next = nullptr;
    tail = head;
    while (node != nullptr) {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    head = prev;
}


template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}




#endif