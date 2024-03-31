struct NoDotr {
    NoDotr() = default;
    ~NoDotr() = delete;
};

int main (int argc, char *argv[]) {
    // NoDotr nd; // can't define a NoDotr object;
    NoDotr *p = new NoDotr();
    // delete p; // can't delete p, cause Destructor is deleted.

    return 0;
}
