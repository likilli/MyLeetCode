
#pragma once

#include <vector>
#include <queue>
#include <stack>

#include <iostream>


template <typename T>
struct BSTNode
{
  BSTNode();
  explicit BSTNode(T val);

  T val;
  BSTNode *left;
  BSTNode *right;
};

template <typename T>
BSTNode<T>::BSTNode() :val(0), left(nullptr), right(nullptr)
{}

template <typename T>
BSTNode<T>::BSTNode(T val) : val(val), left(nullptr), right(nullptr)
{}

template <typename T>
BSTNode<T>* CreateBST(const std::vector<T>& elements)
{
    if (elements.empty())
        return nullptr;

    const int kSize = static_cast<int>(elements.size());
    auto *root = new BSTNode<T>(elements.at(0));
    for (int i = 1; i < kSize; ++i)
    {
        Insert(root, elements[i]);
    }

    return root;
}

template <typename T>
void Insert(BSTNode<T> *root, int val)
{

    BSTNode<T> *mid = root;
    while (mid)
    {
        if (val >= mid->val)
        {
            if (mid->right) mid = mid->right;
            else
            {
                mid->right = new BSTNode<T>(val);
                break;
            }
        }
        else
        {
            if (mid->left) mid = mid->left;
            else
            {
                mid->left = new BSTNode<T>(val);
                break;
            }
        }
    }
}


template <typename T>
void LevelOrderTraversal(BSTNode<T>* root)
{
    if (!root)
        return;

    std::cout << "----------- [Level order] -----------\n";
    std::queue<BSTNode<T>*> q;
    q.push(root);

    while (!q.empty())
    {
        auto node = q.front();
        std::cout << node->val << ", ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        q.pop();
    }
    std::cout << std::endl;
}

template <typename T>
void PreorderTraversal(BSTNode<T>* root)
{
    if (!root)
        return;

    std::cout << "----------- [Preorder Traversal]: -----------\n";
    std::stack<BSTNode<T>*> stk;
    stk.push(root);

    while (!stk.empty())
    {
        auto node = stk.top();
        stk.pop();
        std::cout << node->val << ", ";
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);

    }
    std::cout << std::endl;
}

template <typename T>
void InorderTraversal(BSTNode<T>* root)
{
    if (!root)
        return;

    std::cout << "----------- [Inorder Traversal] -----------\n";

    std::stack<BSTNode<T>*> stk;
    stk.push(root);
    BSTNode<T> *cur = root->left;

    while (!stk.empty() || cur)
    {
        while (cur)
        {
            stk.push(cur);
            cur = cur->left;
        }

        cur = stk.top();
        stk.pop();
        std::cout << cur->val << ", ";
        cur = cur->right;
    }

    std::cout << std::endl;
}

template <typename T>
void PostorderTraversal(BSTNode<T>* root)
{
    if (!root)
        return;

    std::cout << "----------- [Postorder Traversal] -----------\n";

    std::stack<BSTNode<T>*> stk;
    std::vector<int> vec;
    stk.push(root);

    BSTNode<T> *cur = nullptr;

    while (!stk.empty())
    {
        cur = stk.top();
        stk.pop();
        vec.push_back(cur->val);

        if (cur->left) stk.push(cur->left);
        if (cur->right) stk.push(cur->right);
    }

    std::reverse(vec.begin(), vec.end());
    for (const auto & v : vec)
        std::cout << v << ", ";
    std::cout << std::endl;
}


