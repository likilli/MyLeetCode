
#include "max_heap.h"

#include <iostream>


MaxHeap::MaxHeap(int heap_size) : heap_size_(heap_size)
{
  memset(heap_, 0, sizeof(heap_));
  heap_[0] = 0;
  real_size_ = 0;
}

void MaxHeap::Add(int element)
{

  if (real_size_ + 1 > heap_size_)
  {
    std::cout << "[HEAP]: Add too many elements" << std::endl;
    return;
  }

  real_size_ += 1;
  heap_[real_size_] = element;
  int index = real_size_;
  int parent = index / 2;
  while (heap_[index] > heap_[parent] && index > 1)
  {
    std::swap(heap_[index], heap_[parent]);
    index = parent;
    parent = index / 2;
  }
}

int MaxHeap::Peek() const
{
  return heap_[1];
}

int MaxHeap::Pop()
{
  if (real_size_ < 1)
  {
    std::cout << "[HEAP]: Heap is empty" << std::endl;
    return -1;
  }

  int remove_element = heap_[1];
  heap_[1] = heap_[real_size_];
  --real_size_;

  int index = 1;
  while (index < real_size_ && index <= real_size_ / 2)
  {
    int left = index * 2;
    int right = (index * 2) + 1;
    if (heap_[index] < heap_[left] || heap_[index] < heap_[right])
    {
      if (heap_[left] > heap_[right])
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

int MaxHeap::Size() const
{
  return real_size_;
}

void MaxHeap::Print()
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

