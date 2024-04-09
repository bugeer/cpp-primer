#include <cstddef>
#include <string>
#include <iostream>
#include <memory>

int main (int argc, char *argv[]) {
    std::allocator<std::string> alloc;
    constexpr size_t n = 10;

    auto const p = alloc.allocate(n);
    std::string s;
    auto q = p;

    while(std::cin >> s && q != p+n) {
        alloc.construct(q++, s);
    }

    const size_t sz = q-p;

    for(auto pos=p; pos!=q; ++pos) {
        std::cout << *pos << std::endl;
    }

    while (q != p) {
        alloc.destroy(--q);
    }

    alloc.deallocate(p, n);

    return 0;
}
