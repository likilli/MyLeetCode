
#pragma once

#include <unordered_map>

struct DoubleLinkedList
{
  int key_;
  int value_;
  DoubleLinkedList *prev_;
  DoubleLinkedList *next_;

  DoubleLinkedList();
  DoubleLinkedList(int key, int value);
};

class LRUCache
{
public:
  explicit LRUCache(int capacity);
  ~LRUCache();

  void Put(int key, int value);
  int Get(int key);

private:
  void AddToHead(DoubleLinkedList *node);
  void MoveToHead(DoubleLinkedList *node);
  DoubleLinkedList* RemoveTail();
  void RemoveNode(DoubleLinkedList *node);

private:
  const int capacity_;
  int size_;
  std::unordered_map<int, DoubleLinkedList*> caches_;
  DoubleLinkedList *head_;
  DoubleLinkedList *tail_;
};


/*

struct DLinkedNode
{
  int key_;
  int value_;
  DLinkedNode *prev_;
  DLinkedNode *next_;

DLinkedNode() : key_(0), value_(0), prev_(nullptr), next_(nullptr)
{}

DLinkedNode(int key, int value) : key_(key), value_(value), prev_(nullptr), next_(nullptr)
{}
};

class LRUCache
{
public:
  explicit LRUCache(int capacity) : capacity_(capacity), size_(0)
  {
    head_ = new DLinkedNode;
    tail_ = new DLinkedNode;
    head_->next_ = tail_;
    tail_->prev_ = head_;
  }

  int get(int key)
  {
    if (!caches_.count(key))
      return -1;

    auto node = caches_[key];
    MoveToHead(node);
    return node->value_;
  }

  void put(int key, int value)
  {
    if (!caches_.count(key))
    {
      auto node = new DLinkedNode(key, value);
      caches_[key] = node;
      AddToHead(node);
      size_ += 1;

      if (size_ > capacity_)
      {
        auto removed = RemoveTail();
        caches_.erase(removed->key_);
        delete removed;
        size_ -= 1;
      }
    }
    else
    {
      auto node = caches_[key];
      node->value_ = value;
      MoveToHead(node);
    }
  }

private:
  void AddToHead(DLinkedNode *node)
  {
    node->next_ = head_->next_;
    node->prev_ = head_;

    head_->next_->prev_ = node;
    head_->next_ = node;
  }

  void MoveToHead(DLinkedNode *node)
  {
    RemoveNode(node);
    AddToHead(node);
  }

  void RemoveNode(DLinkedNode *node)
  {
    node->prev_->next_ = node->next_;
    node->next_->prev_ = node->prev_;
  }

  DLinkedNode* RemoveTail()
  {
    auto node = tail_->prev_;
    RemoveNode(node);
    return node;
  }

private:
  const int capacity_;
  int size_;
  DLinkedNode *head_;
  DLinkedNode *tail_;
  std::unordered_map<int, DLinkedNode*> caches_;
};

 */