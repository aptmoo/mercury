#ifndef HG_VEC3_H
#define HG_VEC3_H
#include <memory>

template<typename T, typename =  std::enable_if_t<std::is_arithmetic<T>::value>>
struct Vector3Base
{
    T x, y, z;

    static Vector3Base<T> Zero() { return 0, 0, 0; }
    static Vector3Base<T> One() { return 1, 1, 1 };

    /**
     * @brief Add two vector3's.
     * 
     * @param other 
     * @return Vector3Base<T> 
     */
    Vector3Base<T> operator+(const Vector3Base<T>& other)
    {
        Vector3Base result;
        result.x = x + other.x;
        result.y = y + other.y;
        result.z = z + other.z;
        return result;
    }

    /**
     * @brief Subtract two vector3's.
     * 
     * @param other 
     * @return Vector3Base<T> 
     */
    Vector3Base<T> operator-(const Vector3Base<T>& other)
    {
        Vector3Base result;
        result.x = x - other.x;
        result.y = y - other.y;
        result.z = z - other.z;
        return result;
    }

    /**
     * @brief Multiply two vector3's.
     * 
     * @param other 
     * @return Vector3Base<T> 
     */
    Vector3Base<T> operator*(const Vector3Base<T>& other)
    {
        Vector3Base result;
        result.x = x * other.x;
        result.y = y * other.y;
        result.z = z * other.z;
        return result;
    }

    /**
     * @brief Divide two vector3's.
     * 
     * @param other 
     * @return Vector3Base<T> 
     */
    Vector3Base<T> operator/(const Vector3Base<T>& other)
    {
        Vector3Base result;
        result.x = x / other.x;
        result.y = y / other.y;
        result.z = z / other.z;
        return result;
    }
};

using Vector3 = Vector3Base<float>;
using Vector3f = Vector3Base<float>;
using Vector3d = Vector3Base<double>;
using Vector3i = Vector3Base<double>;

#endif