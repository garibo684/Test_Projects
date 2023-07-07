#include<iostream>
#include<vector>

template <typename T>
class Queue {
 public:
  Queue() {}

  bool Empty() const {
    return elements_.empty();
  }

  size_t Size() const {
    return elements_.size();
  }

  const T& Front() const {
  if (Empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return elements_.front();
  }
  void Push(const T& value) {
    elements_.push_back(value);
  }
  void Pop() {
    if (Empty()) {
      throw std::out_of_range("Queue is empty");
    }
    elements_.erase(elements_.begin());
  }

 private:
  std::vector<T> elements_;
};
int main_production() {
  Queue<int> queue;

  queue.Push(1);
  queue.Push(2);
  queue.Push(3);

  while (!queue.Empty()) {
    std::cout << "Front Element: " << queue.Front() << std::endl;
    queue.Pop();
  }

  return 0;
}
