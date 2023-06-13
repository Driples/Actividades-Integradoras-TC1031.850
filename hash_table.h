#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include "ip_summary.h"

class HashTable {
public:
    HashTable(size_t size);

    void insert(const IPSummary& summary);
    IPSummary& get(const std::string& ip);
    int getTotalCollisions() const;

private:
    std::vector<IPSummary> table;
    int total_collisions;

    int hash(const std::string& ip) const;
};

#endif
