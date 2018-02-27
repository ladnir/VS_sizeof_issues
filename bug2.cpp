#include <type_traits>

namespace sb
{
    struct A
    {
        virtual ~A() {};
        virtual int* get() { return nullptr; }
    };

    template<typename U>
    struct B : A
    {
        int* get2()  { return &_u; }            // works
        int* get() override { return &_u; }     // doesn't work
        U _u;
    };

    template<typename T>
    struct C
    {
        template<typename U>
        void operator=(C<U>&& m)
        {}

        template<typename U>
        typename std::enable_if<
            false &&
            (sizeof(B<U>))           // doesnt work with line 15
        >::type               
            operator=(U&& u)
        {}
    };
}

int main()
{

    sb::C<int> c1;
    sb::C<int> c2;
    
    c2 = std::move(c1);

    return 0;
}

