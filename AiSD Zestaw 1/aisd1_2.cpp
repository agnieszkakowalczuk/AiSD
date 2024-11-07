#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <array>

template <typename Iterator>
void merge_sort(Iterator first, Iterator last)
{
    if (last - first > 1)
    {
        Iterator middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

void testarray()
{
    std::array<int, 10> a = {21,89,76,10,50,97,70,98,41,79};
    std::cout << "Dane do posortowania (array):\n";
    for (const auto& n : a)
        std::cout << n << ' ';
    merge_sort(a.begin(), a.end());
    assert(std::is_sorted(a.begin(), a.end()));
    std::cout << '\n';
    std::cout << "Dane posortowane (array):\n";
    for (const auto& n : a)
        std::cout << n << ' ';
    std::cout << "\n\n";

}

void testvector()
{
    std::vector<int> v{64,65,45,49,80,46,25,85,26,70};
    std::cout << "Dane do posortowania (vector):\n";
    for (const auto& n : v)
        std::cout << n << ' ';
    merge_sort(v.begin(), v.end());
    assert(std::is_sorted(v.begin(), v.end()));
    std::cout << '\n';
    std::cout << "Dane posortowane (vector):\n";
    for (const auto& n : v)
        std::cout << n << ' ';
    std::cout << "\n\n";


}


void testtablica()
{
    int t[] = { 1,37,82,23,22,16,42,27,43,54 };
    std::cout << "Dane do posortowania (tablica):\n";
    for (const auto& n : t)
        std::cout << n << ' ';
    merge_sort(t, t + (sizeof(t) / sizeof(*t)));
    assert(std::is_sorted(t, t + (sizeof(t) / sizeof(*t))));
    std::cout << '\n';
    std::cout << "Dane posortowane (tablica):\n";
    for (const auto& n : t)
        std::cout << n << ' ';


}

int main()
{
    std::cout<<"MERGE\n\n";
    testvector();
    testarray();
    testtablica();
}

