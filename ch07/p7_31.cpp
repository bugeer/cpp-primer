class X;
class Y;

class X {
public:
    Y* py;
};

class Y {
public:
    X* px;
};

int main() {
    X x;
    Y y;

    x.py = &y;
    y.px = &x;
}
