#ifndef IP_SUMMARY_H
#define IP_SUMMARY_H

#include <string>
#include <vector>

struct IPSummary {
    std::string ip;
    int total_accessed;
    int total_accessed_from;
    std::vector<std::string> accessed_ips;
};

#endif