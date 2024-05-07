#include <iostream>
#include <vector>

#include "list.h"


using ListNode = ListNodes<int>;

int main()
{
    const std::vector<int> vec{1, 7, 3, 5, 9, 4, 8};
    auto list = CreateList(vec);


    TraversalList(list);

    auto res = ReverseList(list);
    TraversalList(res);


    return 0;
}