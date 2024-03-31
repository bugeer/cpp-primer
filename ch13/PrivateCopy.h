#ifndef __PRIVATE_COPY__
#define __PRIVATE_COPY__

class PrivateCopy {
    PrivateCopy(const PrivateCopy&);
    PrivateCopy &operator= (const PrivateCopy &);

public:
    PrivateCopy() = default;
    ~PrivateCopy();
};

#endif // !__PRIVATE_COPY__
