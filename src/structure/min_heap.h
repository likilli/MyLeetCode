
#pragma once

#include <string>

constexpr int kDefaultHeapSize = 5;

class MinHeap
{
public:
  explicit MinHeap(int heap_size);

  void Add(int element);
  int Peek() const;
  int Pop();
  int Size() const;
  void Print();

private:
  int heap_[kDefaultHeapSize];
  int real_size_;
  const int heap_size_;
};