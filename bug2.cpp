
// ==============================================
//   NOT A BUG, ignore...
//   http://eel.is/c++draft/temp.inst#10
// =============================================

//#include <type_traits>
//
//
//
//// sizeof interacting weirdly with virtual functions
//struct A
//{
//    virtual ~A() {};
//    virtual int* get() { return nullptr; }
//};
//
//template<typename U>
//struct B : A
//{
//    int* get2() { return &_u; }             // works with line 29
//    int* get() override { return &_u; }     // doesn't work with line 29
//    U _u;
//};
//
//template<typename T>
//struct C
//{
//    template<typename U>
//    void operator=(C<U>&& m)
//    {}
//
//    template<typename U>
//    typename std::enable_if<
//        false &&
//        (sizeof(B<U>))           // doesnt work with line 15, appears to full instantiate B<U>.
//    >::type
//        operator=(U&& u)
//    {}
//};
//
//int main()
//{
//
//    C<int> c1;
//    C<int> c2;
//
//    c2 = std::move(c1);
//
//    return 0;
//}
//
