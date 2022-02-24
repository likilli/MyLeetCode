#include <iostream>
#include <vector>

#include "base/list.h"



int main()
{
    std::vector<int> vec{1, 7, 3, 5, 9, 4, 8};
    auto list = List::CreateList(vec);

    while (list)
    {
        std::cout << list->val << ' ';
        list = list->next;
    }
    std::cout << std::endl;


    return 0;
}