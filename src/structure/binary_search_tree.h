
#pragma once

#include <vector>


struct BinarySearchTree
{
public:
  BinarySearchTree();
  explicit BinarySearchTree(int val);
  ~BinarySearchTree();

public:
  int val;
  BinarySearchTree *left;
  BinarySearchTree *right;
};


BinarySearchTree* CreateBST(const std::vector<int>& elements);

void Insert(BinarySearchTree *root, int val);
void Insert(BinarySearchTree *root, const std::vector<int>& elements);

void LevelOrderTraversal(BinarySearchTree* root);

void PreorderTraversal(BinarySearchTree* root);
void NonRecursivePreorderTraversal(BinarySearchTree* root);

void InorderTraversal(BinarySearchTree* root);
void NonRecursiveInorderTraversal(BinarySearchTree* root);

void PostorderTraversal(BinarySearchTree* root);
void NonRecursivePostorderTraversal(BinarySearchTree* root);

/*
BinarySearchTree* CreateTreeFromOrders(std::vector<int> preorder, std::vector<int> inorder)
{
  if (preorder.empty() || inorder.empty())
    return nullptr;

  BinarySearchTree *root = nullptr;


}
*/


#if defined(STRUCT_IMPL)
struct BinarySearchTree
{
  int value;
  BinarySearchTree *left;
  BinarySearchTree *right;

  BinarySearchTree();
  explicit BinarySearchTree(int value);
};

BinarySearchTree* CreateBinarySearchTree(const std::vector<int>& vec);


enum class TraversalType : int
{
  kLevelOrder = 0,
  kPreorder,
  kInorder,
  kNonRecursiveInorder,
  kPostorder
};

void TraversalBinarySearchTree(BinarySearchTree* root, TraversalType type);
#endif