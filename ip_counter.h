#include <string>
#include <unordered_map>
#include <vector>

class IPCounter {
public:
  struct IPData {
    std::string ip;
    int count;

    bool operator<(const IPData &other) const { return count < other.count; }
  };

  void addIP(const std::string &ip);
  std::vector<IPData> getIPData() const;

private:
  std::unordered_map<std::string, int> ipCounts;
};
