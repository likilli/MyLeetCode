
#pragma once

#include <string>

constexpr int kDefaultHeapSize = 5;

class MaxHeap
{
public:
  explicit MaxHeap(int heap_size);

  void Add(int element);
  int Peek() const;
  int Pop();
  int Size() const;
  void Print();

private:
  int heap_[kDefaultHeapSize];
  const int heap_size_;
  int real_size_;
};