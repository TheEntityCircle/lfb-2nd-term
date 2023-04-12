#include <concepts>
#include <iostream>
 
template<std::semiregular T>
// Credit Alexander Stepanov
// concepts are requirements on T
// Requirement on T: T is semiregular
// T a(b); or T a = b; => copy constructor
// T a; => default constructor
// a = b; => assignment
struct Single {
    T value;
    // Aggregation initialization for Single behaves like following constructor:
    // explicit Single(const T& x) : value(x){}
 
    // Implicitly declared special member functions behave like following definitions,
    // except that they may have additional properties:
    // Single(const Single& x) : value(x.value){}
    // Single(){}
    // ~Single(){}
    // Single& operator=(const Single& x) { value = x.value; return *this; }
    // comparison operator is not defined; it is not required by `semiregular` concept
    // bool operator== (Single const& other) const = delete;
};
 
void print(std::semiregular auto x)
{
    std::cout << x.value << ' ';
}
 
int main()
{
    Single<int> myInt1{4};      // aggregate initialization: myInt1.value = 4
    Single<int> myInt2(myInt1); // copy constructor
    Single<int> myInt3;         // default constructor
    myInt3 = myInt2;            // copy assignment operator
//  myInt1 == myInt2;           // Error: operator== is not defined
 
    print(myInt1); // ok: Single<int> is a `semiregular` type
    print(myInt2);
    print(myInt3);
 
}   // Single<int> variables are destroyed here
