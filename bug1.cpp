
// sizeof inside aliased template
template<class, class> struct A { };
template<int> struct B { };

template<class T> constexpr auto x = sizeof(A<T, int>); // works
template<class T> struct C : B<sizeof(A<T, int>)> { };  // works
template<class T> using D = B<sizeof(A<T, int>)>;       // doesn't work




