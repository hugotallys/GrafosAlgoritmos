#include "Utils.hpp"

void print_arr(llint *a, llint n, std::string s)
{
    llint i;

    std::cout << s << std::endl;
    for (i = 0; i < n-1; ++i)
    {
        std::cout << "| " <<a[i] << " ";
    }
    std::cout << "| " << a[i] << " |" << std::endl;
}