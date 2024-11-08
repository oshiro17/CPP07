#include "iter.hpp"

template <typename T>
static void 	func(T& t) {
    std::cout << "Non-const version called: " << t << std::endl;
}

template <typename T>
static void 	func(const T& t) {
    std::cout << "Const version called: " << t << std::endl;
}
int main(void)
{
    std::string arry_str[] = {"hell" , "o" ,"taka"};
    size_t len_s = 3;
    iter(arry_str,len_s,&func);

    const int  arry_n[] = {1,2,3};
    iter(arry_n,len_s,&func);

    return (0);
}