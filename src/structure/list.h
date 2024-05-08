
#pragma once

#include <vector>
#include <iostream>

template <typename DataType>
struct ListNodes
{
    explicit ListNodes(const DataType& value);
    ListNodes(const DataType& value, ListNodes* next);

    DataType val;
    ListNodes *next;
};

template <typename DataType>
ListNodes<DataType>::ListNodes(const DataType &value) : val(value) {
    next = nullptr;
}

template <typename DataType>
ListNodes<DataType>::ListNodes(const DataType &value, ListNodes *next) : val(value), next(next)
{}

template <typename DataType>
ListNodes<DataType>* CreateList(const std::vector<DataType>& vec) {
    auto *root = new ListNodes<DataType>(0);
    ListNodes<DataType> *cur = root;
    for (const auto & e : vec) {
        cur->next = new ListNodes<DataType>(e);
        cur = cur->next;
    }

    auto res = root->next;
    delete root;
    root = nullptr;

    return res;
}

template <typename DataType>
void TraversalList(ListNodes<DataType>* root)
{
    ListNodes<DataType> *cur = root;
    while (cur)
    {
        std::cout << cur->val << ' ';
        cur = cur->next;
    }
    std::cout << std::endl;
}

template <typename DataType>
ListNodes<DataType>* ReverseList(ListNodes<DataType>* root)
{
    if (!root)
        return nullptr;

    ListNodes<DataType> *prev = nullptr;
    ListNodes<DataType> *next = nullptr;
    while (root)
    {
        next = root->next;
        root->next = prev;
        prev = root;
        root = next;

    }
    return prev;
}
