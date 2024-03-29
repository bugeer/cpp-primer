#include <string>

int main (int argc, char *argv[]) {
    std::string dots(10, '.');                 //直接初始化
    std::string s(dots);                       //直接初始化
    std::string s2 = dots;                     //拷贝初始化
    std::string null_book = "9-999-99999-9";   //拷贝初始化
    std::string nines = std::string(100, '9'); //拷贝初始化

    return 0;
}
