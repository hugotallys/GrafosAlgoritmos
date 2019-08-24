#include "MinHeap.hpp"

MinHeap::MinHeap(llint n) : size(n), p(-1)
{
    arr = new edge[n];
}

void MinHeap::insert(edge n)
{
    llint i;
    arr[++p] = n;

    i = p;
    while (i != 0 && arr[parent(i)].weight > arr[i].weight)
    {
        swap(&arr[parent(i)], &arr[i]);
        i = parent(i);
    }
}

edge MinHeap::extract_min()
{
    if (p == -1) { return edge(INF, INF); };
    if (p == 0) { return arr[p--]; };

    edge r = arr[0];
    arr[0] = arr[p--];
    min_heapify(0);
    return r;
}

void MinHeap::min_heapify(llint idx)
{
    llint l = left(idx);
    llint r = right(idx);
    llint s = idx;

    if (l <= p && arr[l].weight < arr[idx].weight)
        s = l;
    if (r <= p && arr[r].weight < arr[s].weight)
        s = r;
    if (s != idx)
    {
        swap(&arr[s], &arr[idx]);
        min_heapify(s);
    }
}

void MinHeap::decrease_key(llint v, llint dist_v)
{
    llint i;
    llint idx = 0;

    for (i = 0; i <= p; i++)
    {
        if (arr[i].vertex == v)
        {
            arr[i] = edge(v, dist_v);
            idx = i;
        }
    }
    while (idx != 0 && arr[parent(idx)].weight > arr[idx].weight)
    {
        swap(&arr[parent(idx)],&arr[idx]);
        idx = parent(idx);
    }
}

MinHeap::~MinHeap()
{
    delete [] arr;
}

void swap(edge *a, edge *b)
{
    edge c = *a;
    *a = *b;
    *b = c;
}