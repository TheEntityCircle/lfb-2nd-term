#include <ranges>
#include <vector>
#include <iostream>
 
template <typename T>
struct range_t : private T {
    using T::begin, T::end; /*...*/
};
static_assert(std::ranges::range< range_t<std::vector<int>> >);
 
template <typename T> struct scalar_t { T t{}; /* no begin/end */ };
static_assert(not std::ranges::range< scalar_t<int> >);
 
int main() {
    if constexpr (range_t<std::vector<int>> r; std::ranges::range<decltype(r)>) {
        std::cout << "r is a range\n";
    }
 
    if constexpr (scalar_t<int> s; not std::ranges::range<decltype(s)>) {
        std::cout << "s is not a range\n";
    }
}
