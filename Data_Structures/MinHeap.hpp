#ifndef MIN_HEAP
#define MIN_HEAP

#include "Graph.hpp"

void swap(edge *a, edge *b);

class MinHeap
{
private:
    llint p;
    llint size;
    edge *arr;
public:
    MinHeap(llint n);
    void insert(edge n);
    edge extract_min();
    void min_heapify(llint idx);
    void decrease_key(llint v, llint dist_v);

    int is_empty() { return p == -1; };
    llint parent(llint idx) { return (idx - 1) / 2; };
    llint left(llint idx) { return (2*idx) + 1; };
    llint right(llint idx) { return (2*idx) + 2; };

    ~MinHeap();
};

#endif