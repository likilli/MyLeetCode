/*
 * list.h
 * Created by likai on 2022/02/24 23:32
 * This file used for learning and training
 */

#pragma once


#include <vector>


using DataType = int;

struct ListNode
{
    DataType val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {}

    explicit ListNode(int x) : val(x), next(nullptr)
    {}

    ListNode(int x, ListNode *next) : val(x), next(next)
    {}
};


class List
{
public:
    static ListNode* CreateList(const std::vector<DataType>& vec)
    {
        if (vec.empty())
            return nullptr;

        auto root = new ListNode(vec.at(0));
        ListNode *node = root;
        for (size_t i = 1; i < vec.size(); i++)
        {
            node->next = new ListNode(vec.at(i));
            node = node->next;
        }

        return root;
    }
};