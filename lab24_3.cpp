#include <iostream>
#include <set>

int count(int data[], int size) {
    std::set<int> uniqueElements;
    for (int i = 0; i < size; ++i) {
        uniqueElements.insert(data[i]);
    }
    return uniqueElements.size();
}
