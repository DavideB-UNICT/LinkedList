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
    cout << list[1] << endl;
    return 0;
}
