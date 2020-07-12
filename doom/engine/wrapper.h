#pragma once
#include <stdint.h>

#ifdef __cplusplus

extern "C"
{
#endif

    void pushRect(int, int, __uint32_t *);
    void getKeyStates(__uint8_t *, __uint8_t);
    void sleep(__uint32_t);
    __uint32_t millis();

#ifdef __cplusplus
}
#endif
