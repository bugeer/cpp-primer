#include <iostream>

class ClassA;
class ClassB;

class ClassB {
public:
    void friendFunc(ClassA& objA); // ClassB 的成员函数声明为 ClassA 的友元函数
};

class ClassA {
private:
    int privateData;
public:
    ClassA(int data) : privateData(data) {}

    friend void ClassB::friendFunc(ClassA& objA);

    void funcA() {
        std::cout << "ClassA::funcA() called. privateData: " << privateData << std::endl;
    }
};

// ClassB 的成员函数定义为 ClassA 的友元函数
void ClassB::friendFunc(ClassA& objA) {
    objA.privateData = 42; // 可以直接访问 ClassA 的私有成员
    objA.funcA(); // 可以调用 ClassA 的成员函数
}

int main() {
    ClassA objA(10);
    ClassB objB;

    objB.friendFunc(objA); // 调用 ClassB 的友元函数

    return 0;
}
