#include <algorithm>
#include <vector>

template <typename T> class Heap {
public:
  bool isEmpty() const { return data.empty(); }

  void insert(const T &value) {
    data.push_back(value);
    std::push_heap(data.begin(), data.end());
  }

  T extractMax() {
    std::pop_heap(data.begin(), data.end());
    T maxValue = data.back();
    data.pop_back();
    return maxValue;
  }

private:
  std::vector<T> data;
};
