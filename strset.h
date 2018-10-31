#ifndef JNP2_STRSET_H
#define JNP2_STRSET_H

#include "stddef.h"

#ifdef __cplusplus

#include <iostream>
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
    extern int strset_comp(unsigned long id1, unsigned long id2);

#ifdef __cplusplus
    }
}
#endif
#endif //JNP2_STRSET_H
