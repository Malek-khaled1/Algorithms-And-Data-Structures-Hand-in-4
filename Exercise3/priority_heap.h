#pragma once
#include "priority_queue.h"
#include "C:\Users\mkabd\OneDrive - Aarhus universitet\COMTEKAU\3.Semester\Github_repoes\Algorithms-And-Data-Structures-Hand-in-4\Exercise2\min_heap.h"

template<typename T>
class MinHeapPriorityQueue : public PriorityQueue<T>
{

    private:
        MinHeap<T> heap;

    public:
        void push(const T& x) override {heap.insert(x);}
        void pop() override {heap.remove();}
        T top() override {return heap.peek();}
        bool empty() const override {return heap.isEmpty();}

};
