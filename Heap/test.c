#include "max-heap.c"

int main() {
    MaxHeap *heap = initHeap(20);

    insert(heap, 1);
    insert(heap, 3);
    insert(heap, 5);
    insert(heap, 4);
    insert(heap, 6);
    insert(heap, 13);
    insert(heap, 10);
    insert(heap, 9);
    insert(heap, 8);
    insert(heap, 15);
    insert(heap, 17);

    heapSort(heap);
}