#include "ip_counter.h"

void IPCounter::addIP(const std::string &ip) { ipCounts[ip]++; }

std::vector<IPCounter::IPData> IPCounter::getIPData() const {
  std::vector<IPData> ipData;
  for (const auto &entry : ipCounts) {
    ipData.push_back({entry.first, entry.second});
  }
  return ipData;
}
