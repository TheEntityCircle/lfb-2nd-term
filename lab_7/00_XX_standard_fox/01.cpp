#include <ranges>
#include <vector>
#include <array>
#include <deque>
#include <valarray>
#include <list>
#include <set>
 
template<typename T> concept RAR = std::ranges::random_access_range<T>;
 
int main()
{
    int a[4];
    static_assert(
            RAR<std::vector<int>> and
            RAR<std::vector<bool>> and
            RAR<std::deque<int>> and
            RAR<std::valarray<int>> and
            RAR<decltype(a)> and
        not RAR<std::list<int>> and
        not RAR<std::set<int>> and
            RAR<std::array<std::list<int>,42>>
    );
}
