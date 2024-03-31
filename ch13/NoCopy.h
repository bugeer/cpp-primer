#ifndef __NO_COPY__
#define __NO_COPY__

class NoCopy {
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete;
    NoCopy operator=(const NoCopy&) = delete;
    ~NoCopy() = delete;
};

#endif // !__NO_COPY__
