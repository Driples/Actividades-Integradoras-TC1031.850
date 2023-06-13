#include "log_parser.h"
#include <stdexcept>

LogParser::LogParser(const std::string& filename) : file(filename) {
    if (!file) {
        throw std::runtime_error("Unable to open file: " + filename);
    }
}

std::vector<Event> LogParser::parse() {
    int n, m;
    file >> n >> m;

    std::vector<std::string> ips(n);
    for (int i = 0; i < n; i++) {
        file >> ips[i];
    }

    std::vector<Event> events(m);
    for (int i = 0; i < m; i++) {
        file >> events[i].month >> events[i].day >> events[i].hour;
        std::string source_ip_port, target_ip_port;
        file >> source_ip_port >> target_ip_port >> events[i].weight;
        std::getline(file, events[i].reason);
        
        // Remove port from IPs
        events[i].source_ip = source_ip_port.substr(0, source_ip_port.find(':'));
        events[i].target_ip = target_ip_port.substr(0, target_ip_port.find(':'));
    }

    return events;
}

HashTable LogParser::createHashTable(const std::vector<Event>& events) {
    HashTable table(events.size());

    for (const auto& event : events) {
        try {
            auto& summary = table.get(event.source_ip);
            summary.total_accessed++;
            summary.accessed_ips.push_back(event.target_ip);
        } catch (const std::runtime_error&) {
            table.insert({event.source_ip, 1, 0, {event.target_ip}});
        }

        try {
            auto& summary = table.get(event.target_ip);
            summary.total_accessed_from++;
        } catch (const std::runtime_error&) {
            table.insert({event.target_ip, 0, 1, {}});
        }
    }

    return table;
}
