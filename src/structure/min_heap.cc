
#include "min_heap.h"

#include <iostream>


MinHeap::MinHeap(int heap_size) : real_size_(0), heap_size_(heap_size)
{
  memset(heap_, 0,sizeof(heap_));
  heap_[0] = 0;
  real_size_ = 0;
}

void MinHeap::Add(int element)
{
  if (real_size_ + 1 > heap_size_)
  {
    std::cout << "[Heap]: Add too many elements!" << std::endl;
    return;
  }

  real_size_ += 1;
  heap_[real_size_] = element;
  int index = real_size_;
  int parent = index / 2;
  while (heap_[index] < heap_[parent] && index > 1)
  {
    std::swap(heap_[index], heap_[parent]);
    index = parent;
    parent = index / 2;
  }
}

int MinHeap::Peek() const
{
  return heap_[1];
}

int MinHeap::Pop()
{
  if (real_size_ < 1)
  {
    std::cout << "[Heap]: Empty heap" << std::endl;
    return INT_MAX;
  }

  int remove_element = heap_[1];
  heap_[1] = heap_[real_size_];
  real_size_ -= 1;

  int index = 1;
  while (index < real_size_ && index <= real_size_ / 2)
  {
    int left = index * 2;
    int right = (index * 2) + 1;
    if (heap_[index] > heap_[left] || heap_[index] > heap_[right])
    {
      if (heap_[left] < heap_[right])
      {
        std::swap(heap_[left], heap_[index]);
        index = left;
      }
      else
      {
        std::swap(heap_[right], heap_[index]);
        index = right;
      }
    }
    else
    {
      break;
    }
  }

  return remove_element;
}

int MinHeap::Size() const
{
  return real_size_;
}

void MinHeap::Print()
{
  if (!real_size_)
  {
    std::cout << "[Heap]: Empty heap !" << std::endl;
    return;
  }

  for (int i = 1; i <= real_size_; ++i)
    std::cout << heap_[i] << ' ';
  std::cout << std::endl;
}
