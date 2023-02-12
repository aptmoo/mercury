#ifndef HG_VECTORS_H
#define HG_VECTORS_H
#include <type_traits>

/*
@class Vector3Base A template base for a 3 component vector.
*/
template<typename T, typename = std::enable_if<std::is_arithmetic<T>::value>>
struct Vector3Base
{
    T x, y, z;

    /*
    @brief Return a vector full of zeroes.
    */
    static Vector3Base<T> Zero(){ return {0, 0, 0}; }

    /*
    @brief Return a vector full of ones.
    */
    static Vector3Base<T> One() { return {0, 0, 0}; }
};

typedef Vector3Base<float> Vector3;
typedef Vector3Base<int> Vector3i;

#endif