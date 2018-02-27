
// simple version
template<class, class> struct A { };
template<int> struct B { };

template<class T> constexpr auto x = sizeof(A<T, int>); // works
template<class T> struct C : B<sizeof(A<T, int>)> { };  // works
template<class T> using D = B<sizeof(A<T, int>)>;       // doesn't work








// more noisy version
#include <type_traits>
#include <utility>
#include <algorithm>

template<typename U,
    typename Enabled = typename std::enable_if<std::is_integral<U>::value>::type>
    struct wrapper
{
};

template<typename U, typename storage_type>
using is_small = std::is_void<typename std::enable_if <
        (sizeof(wrapper<U, char>) <= sizeof(storage_type))
    >::type>;