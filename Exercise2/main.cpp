#include <iostream>
#include "min_heap.h"  // Sørg for at navnet matcher din headerfil

using namespace std;

int main()
{
    cout << "===== MinHeap Test =====" << endl;

    MinHeap<int> heap;

    // Test 1: isEmpty på en tom heap
    cout << "Heap tom? " << (heap.isEmpty() ? "Ja" : "Nej") << endl;

    // Test 2: Indsæt nogle elementer
    cout << "\nIndsætter elementer: 5, 2, 8, 1, 7, 3\n";
    heap.insert(5);
    heap.insert(2);
    heap.insert(8);
    heap.insert(1);
    heap.insert(7);
    heap.insert(3);

    cout << "Heap tom? " << (heap.isEmpty() ? "Ja" : "Nej") << endl;
    cout << "Min (peek): " << heap.peek() << endl;

    // Test 3: Fjern elementer én ad gangen
    cout << "\nFjerner elementer i rækkefølge:\n";
    while (!heap.isEmpty())
    {
        cout << "Peek: " << heap.peek() << "  -->  Fjernes\n";
        heap.remove();

        if (!heap.isEmpty())
            cout << "Nyt min (peek): " << heap.peek() << endl;
        else
            cout << "Heap er nu tom.\n";
    }

    // Test 4: Prøv at fjerne fra en tom heap (for at teste exception)
    cout << "\nTester fjernelse fra tom heap...\n";
    try {
        heap.remove();
    }
    catch (const std::underflow_error& e) {
        cout << "Forventet fejl: " << e.what() << endl;
    }

    // Test 5: Prøv peek() på tom heap
    cout << "\nTester peek på tom heap...\n";
    try {
        cout << heap.peek() << endl;
    }
    catch (const std::underflow_error& e) {
        cout << "Forventet fejl: " << e.what() << endl;
    }

    cout << "\n===== Test afsluttet =====" << endl;
    return 0;
}
