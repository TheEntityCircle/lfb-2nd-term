#include <ranges>
 
int main()
{
    std::ranges::empty_view<long> e;
    static_assert(std::ranges::empty(e));
    static_assert(0 == e.size());
    static_assert(nullptr == e.data());
    static_assert(nullptr == e.begin());
    static_assert(nullptr == e.end());
}
