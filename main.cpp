#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<double> list = LinkedList<double>();
    cout << list.empty() << endl;
    cout << list.size() << endl;
    list.push_back(1);
    list.push_back(2);
    cout << list.size() << endl;
    cout << *list[1] << endl;
    list.at(1, 3);
    cout << *list[1] << "  " << list.size() << endl;
    list.remove(1);
    list.pop_back();
    cout << list.size() << endl;
    list.insert(0, 6);
    cout << list.size() << endl;
    list.insert(0, 5);
    cout << list.size() << endl;
    cout << list << endl;
    for (auto el : list) {
        cout << el << endl;
    }
    list.clear();
    cout << list.size() << endl;
    return 0;
}
