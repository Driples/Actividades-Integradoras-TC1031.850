#ifndef EVENT_H
#define EVENT_H

#include <string>

struct Event {
    std::string month;
    int day;
    std::string hour;
    std::string source_ip;
    std::string target_ip;
    int weight;
    std::string reason;
};

#endif

