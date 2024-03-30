#ifndef __NUMBERED__
#define __NUMBERED__

#include <cstddef>

class Numbered {
public:
    static size_t obj_count;

    size_t mysn;

    Numbered();
    Numbered(const Numbered &);

};

#endif // !__NUMBERED__
