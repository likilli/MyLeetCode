#include <iostream>
#include <vector>

#include "list.h"
#include "binary_search_tree.h"


using ListNode = ListNodes<int>;

int main()
{
    // list
    const std::vector<int> vec{1, 7, 3, 5, 9, 4, 8};
    auto list = CreateList(vec);


    TraversalList(list);

    auto res = ReverseList(list);
    TraversalList(res);

    // BST
    const std::vector<int> tree_ele = {10, 5, 15, 1, 7, 12, 20};
    auto tree = CreateBST(tree_ele);
    PreorderTraversal(tree);



    return 0;
}