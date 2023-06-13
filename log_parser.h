#ifndef LOG_PARSER_H
#define LOG_PARSER_H

#include <fstream>
#include <vector>
#include "event.h"
#include "hash_table.h"

class LogParser {
public:
    LogParser(const std::string& filename);

    std::vector<Event> parse();
    HashTable createHashTable(const std::vector<Event>& events);

private:
    std::ifstream file;
};

#endif
