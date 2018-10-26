#ifndef JNP2_STRSET_H
#define JNP2_STRSET_H

#include "stdio.h"

#ifdef __cplusplus

namespace jnp1 {

    extern "C"
    {
#endif
    extern unsigned long strset_new();
    extern void strset_delete(unsigned long id);
    extern size_t strset_size(unsigned long id);
    extern void strset_insert(unsigned long id, const char *value);
    extern void strset_remove(unsigned long id, const char *value);
    extern void strset_clear(unsigned long id);
    extern int strset_test(unsigned long id, const char *value);
#ifdef __cplusplus
    }
}
#endif
#endif //JNP2_STRSET_H
