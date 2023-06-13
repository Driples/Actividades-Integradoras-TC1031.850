#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <string>

struct HeapNode{
    std::string ip;
    int grado;

    bool operator<(const HeapNode& rhs) const
    {
        return grado < rhs.grado;
    }
};

#endif
