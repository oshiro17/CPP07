#ifndef ITER_HPP
# define ITER_HPP
#include <iostream> 
#include <stddef.h> 

// template <typename T>
// void	iter(T* arr, int len, void (*func)(T&)) {
//     if (!arr||!func)
//         return;
//     for (int i =0 ; i < len ; i++)
//         func(arr[i]);
// }

template <typename T>
void	iter(T* arr, size_t len, void (*func)(T&)) {
    if (!arr||!func)
        return;
    for (size_t i =0 ; i < len ; i++)
        func(arr[i]);
}
template <typename T>
void	iter(const T* arr, size_t len, void (*func)(const T&)) {
    if (!arr||!func)
        return;
    for (size_t i =0 ; i < len ; i++)
        func(arr[i]);
}

#endif