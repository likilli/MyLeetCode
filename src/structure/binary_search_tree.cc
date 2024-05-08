
#include "binary_search_tree.h"

#include <queue>
#include <stack>
#include <iostream>


BinarySearchTree::BinarySearchTree() : val(0), left(nullptr), right(nullptr)
{}

BinarySearchTree::BinarySearchTree(int val) : val(val), left(nullptr), right(nullptr)
{}

BinarySearchTree::~BinarySearchTree()
{}

BinarySearchTree* CreateBST(const std::vector<int>& elements)
{
  if (elements.empty())
    return nullptr;

  const int kSize = static_cast<int>(elements.size());
  BinarySearchTree *root = new BinarySearchTree(elements.at(0));
  for (int i = 1; i < kSize; ++i)
  {
    Insert(root, elements[i]);
  }

  return root;
}

void Insert(BinarySearchTree *root, int val)
{

  BinarySearchTree *mid = root;
  while (mid)
  {
    if (val >= mid->val)
    {
      if (mid->right) mid = mid->right;
      else
      {
          mid->right = new BinarySearchTree(val);
          break;
      }
    }
    else
    {
      if (mid->left) mid = mid->left;
      else
      {
        mid->left = new BinarySearchTree(val);
        break;
      }
    }
  }
}

void Insert(BinarySearchTree *root, const std::vector<int> &elements)
{
  if (elements.empty())
    return;

  for (const auto & e : elements)
    Insert(root, e);
}

void LevelOrderTraversal(BinarySearchTree *root)
{
  if (!root)
    return;

  std::cout << "[Level Order]: ";
  std::queue<BinarySearchTree*> q{};
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

void PreorderTraversal(BinarySearchTree *root)
{
  if (!root)
    return;

  std::cout << "[Preorder Traversal]: ";
  std::cout << std::endl;
}

void InorderTraversal(BinarySearchTree *root)
{
  if (!root)
    return;

  std::cout << "[Inorder Traversal]: ";
  InorderTraversal(root->left);
  std::cout << root->val << ", ";
  InorderTraversal(root->right);
  std::cout << '\n';
}

void PostorderTraversal(BinarySearchTree *root)
{
  if (!root)
    return;

  std::cout << "[Postorder Traversal]: ";
  PostorderTraversal(root->left);
  PostorderTraversal(root->right);
  std::cout << root->val << ", ";
  std::cout << std::endl;
}

#pragma mark Non-Recursive-Traversal

void NonRecursivePreorderTraversal(BinarySearchTree *root)
{
  if (!root)
    return;

  std::cout << "[Non-Recursive Preorder Traversal]: ";
  std::stack<BinarySearchTree*> stk;
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

void NonRecursiveInorderTraversal(BinarySearchTree *root)
{
  if (!root)
    return;

  std::cout << "[Non-Recursive Inorder Traversal]: ";

  std::stack<BinarySearchTree*> stk;
  stk.push(root);
  BinarySearchTree *cur = root->left;

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


  /*
  if (!root)
    return;

  std::cout << "[Non-Recursive Inorder Traversal]: ";

  std::stack<BinarySearchTree*> stk;
  stk.push(root);

  while (!stk.empty())
  {
    auto node = stk.top();

  }

  while ()
   */
}

void NonRecursivePostorderTraversal(BinarySearchTree *root)
{
  if (!root)
    return;

  std::cout << "[Non-Recursive Postorder Traversal]: ";

  std::stack<BinarySearchTree*> stk;
  std::vector<int> vec;
  stk.push(root);

  BinarySearchTree *cur = root;

  while (!stk.empty())
  {
    cur = stk.top();
    stk.pop();
    vec.push_back(cur->val);

    if (cur->left) stk.push(cur->left);
    if (cur->right) stk.push(cur->right);
  }

  std::cout << "Non-Reversed: ";
  for (const auto & v : vec)
    std::cout << v << ", ";
  std::cout << std::endl;

  std::reverse(vec.begin(), vec.end());


  for (const auto & v : vec)
    std::cout << v << ", ";
  std::cout << std::endl;

}



#if defined(STRUCT_IMPL)
BinarySearchTree::BinarySearchTree() : value(0), left(nullptr), right(nullptr)
{}

BinarySearchTree::BinarySearchTree(int value) : value(value), left(nullptr), right(nullptr)
{}

BinarySearchTree* CreateBinarySearchTree(const std::vector<int>& vec)
{
  BinarySearchTree *root = nullptr;
  BinarySearchTree *mid = nullptr;
  for (const auto & e : vec)
  {
    if (root == nullptr)
    {
      root = new BinarySearchTree(e);
    }
    else
    {
      mid = root;
      while (mid)
      {
        if (e >= mid->value)
        {
          if (mid->right)
          {
            mid = mid->right;
          }
          else
          {
            mid->right = new BinarySearchTree(e);
            break;
          }
        }
        else
        {
          if (mid->left)
          {
            mid = mid->left;
          }
          else
          {
            mid->left = new BinarySearchTree(e);
            break;
          }
        }
      }
    }
  }

  return root;
}



void LevelOrderTraversal(BinarySearchTree* root)
{
  if (!root)
    return;

  std::cout << "[INFO]: Level order traversal: ";
  std::queue<BinarySearchTree*> q;
  q.push(root);

  while (!q.empty())
  {
    auto node = q.front();
    q.pop();
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
    std::cout << node->value << ' ';
  }
}

void PreorderTraversal(BinarySearchTree* root)
{
  if (!root)
    return;

  std::cout << root->value << ' ';
  PreorderTraversal(root->left);
  PreorderTraversal(root->right);
}

void InorderTraversal(BinarySearchTree* root)
{
  if (!root)
    return;

  InorderTraversal(root->left);
  std::cout << root->value << ' ';
  InorderTraversal(root->right);
}

void NonRecursiveInorderTraversal(BinarySearchTree *root)
{
  if (!root)
    return;

  std::stack<BinarySearchTree*> stk;
}

void PostorderTraversal(BinarySearchTree* root)
{
  if (!root)
    return;

  PostorderTraversal(root->left);
  PostorderTraversal(root->right);
  std::cout << root->value << ' ';
}

void TraversalBinarySearchTree(BinarySearchTree* root, TraversalType type)
{
  switch (type)
  {
  case TraversalType::kLevelOrder:
    LevelOrderTraversal(root);
    break;
  case TraversalType::kPreorder:
    PreorderTraversal(root);
    break;
  case TraversalType::kInorder:
    InorderTraversal(root);
    break;
  case TraversalType::kPostorder:
    PostorderTraversal(root);
    break;
  default:
    LevelOrderTraversal(root);
  }
  std::cout << '\n';
}
#endif
