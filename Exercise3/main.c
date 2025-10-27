#include <iostream>
#include "priority_heap.h"

using namespace std;

int main()
{
    MinHeapPriorityQueue<int> pq;

    cout << "Indsætter elementer: 5, 2, 8, 1\n";
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);

    cout << "Top (min): " << pq.top() << endl; // 1
    pq.pop();
    cout << "Efter pop, ny top: " << pq.top() << endl; // 2

    cout << "\nTømmer køen:\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
