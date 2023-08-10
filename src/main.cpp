#include <iostream>
#include <algorithm>
#include <vector>
#include "code_caprice.h"

int main()
{
    CodeCarprice* codeCarprice = new CodeCarprice();
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    codeCarprice->question209(7, nums);

    return 0;
}