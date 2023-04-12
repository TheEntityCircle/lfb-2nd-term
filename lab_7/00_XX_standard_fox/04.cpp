#include <array>
#include <cassert>
#include <iostream>
 
template <typename T, std::size_t Z, std::size_t Y, std::size_t X>
struct Array3d
{
    std::array<T, X * Y * Z> m{};
 
    constexpr T& operator[](std::size_t z, std::size_t y, std::size_t x) // C++23
    {
        assert(x < X and y < Y and z < Z);
        return m[z * Y * X + y * X + x];
    }
};
 
int main()
{
    Array3d<int, 4, 3, 2> v;
    v[3, 2, 1] = 42;
    std::cout << "v[3, 2, 1] = " << v[3, 2, 1] << '\n';
}
