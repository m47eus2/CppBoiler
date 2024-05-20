#include <iostream>
#include <memory> // Potrzebne dla std::unique_ptr

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructor" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructor" << std::endl;
    }
    void doSomething() {
        std::cout << "Doing something!" << std::endl;
    }
};

int main() {
    // Tworzymy unique_ptr zarządzający dynamicznie alokowanym obiektem MyClass
    std::unique_ptr<MyClass> ptr1(new MyClass());
    ptr1->doSomething();
    
    // Przeniesienie własności do innego unique_ptr
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);
    
    if (!ptr1) {
        std::cout << "ptr1 jest pusty" << std::endl;
    }
    
    ptr2->doSomething();
    
    // Kiedy ptr2 wychodzi z zakresu, zarządzany obiekt jest automatycznie niszczony
    return 0;
}
