#include "hash_table.h"
#include <stdexcept>

HashTable::HashTable(size_t size) : table(size), total_collisions(0) {}

void HashTable::insert(const IPSummary& summary) {
    int index = hash(summary.ip);

    for (int i = 0; i < table.size(); i++) {
        int probe_index = (index + i * i) % table.size();

        if (table[probe_index].ip.empty()) {
            table[probe_index] = summary;
            return;
        } else {
            total_collisions++;
        }
    }

    throw std::runtime_error("Hash table is full");
}

IPSummary& HashTable::get(const std::string& ip) {
    int index = hash(ip);

    for (int i = 0; i < table.size(); i++) {
        int probe_index = (index + i * i) % table.size();

        if (table[probe_index].ip == ip) {
            return table[probe_index];
        }
    }

    throw std::runtime_error("IP not found in hash table");
}

int HashTable::getTotalCollisions() const {
    return total_collisions;
}

int HashTable::hash(const std::string& ip) const {
    int hash = 0;
    for (char c : ip) {
        hash += c;
    }
    return hash % table.size();
}
