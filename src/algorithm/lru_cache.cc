
#include "lru_cache.h"

DoubleLinkedList::DoubleLinkedList() : key_(0), value_(0), prev_(nullptr), next_(nullptr)
{}

DoubleLinkedList::DoubleLinkedList(int key, int value) : key_(key), value_(value), prev_(nullptr), next_(nullptr)
{}

LRUCache::LRUCache(int capacity) : capacity_(capacity), size_(0)
{
  head_ = new DoubleLinkedList;
  tail_ = new DoubleLinkedList;

  head_->next_ = tail_;
  tail_->prev_ = head_;
}

void LRUCache::Put(int key, int value)
{
  if (!caches_.count(key))
  {
    DoubleLinkedList *node = new DoubleLinkedList(key, value);
    caches_[key] = node;
    size_ += 1;
    AddToHead(node);

    if (size_ > capacity_)
    {
      auto last_node = RemoveTail();
      caches_.erase(last_node->key_);
      delete last_node;
      --size_;
    }
  }
  else
  {
    auto node = caches_[key];
    node->value_ = value;
    MoveToHead(node);
  }
}

int LRUCache::Get(int key)
{
  if (!caches_.count(key))
    return -1;

  auto node = caches_[key];
  MoveToHead(node);

  return node->value_;
}

void LRUCache::AddToHead(DoubleLinkedList *node)
{
  head_->next_->prev_ = node;
  node->next_ = head_->next_;
  head_->next_ = node;
  node->prev_ = head_;
}
void LRUCache::MoveToHead(DoubleLinkedList *node)
{
  RemoveNode(node);
  AddToHead(node);
}

DoubleLinkedList* LRUCache::RemoveTail()
{
  auto node = tail_->prev_;
  RemoveNode(node);
  return node;
}

void RemoveNode(DoubleLinkedList *node)
{
  node->prev_->next_ = node->next_;
  node->next_->prev_ = node->prev_;
}


