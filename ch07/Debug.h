#ifndef __DEBUG__
#define __DEBUG__

class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any() const { return hw || io || other; }

    constexpr void set_hw   (bool b) { hw    = b; }
    constexpr void set_io   (bool b) { io    = b; }
    constexpr void set_other(bool b) { other = b; }
private:
    bool hw;
    bool io;
    bool other;
};

#endif // !__DEBUG__
