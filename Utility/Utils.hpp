#ifndef UTILS
#define UITLS

#include <iostream>
#include <string>

typedef long long int llint;

#define blank_line std::cout << std::endl

const llint INF = 999999999;

void print_arr(llint *a, llint n, std::string s);

inline llint access(llint i, llint j, llint num_col) {return i * num_col + j ; }

inline llint min(llint a, llint b) { return a < b ? a : b ; }

#endif