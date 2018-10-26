#include "strset.h"

#include <cassert>

using jnp1::strset_new;
using jnp1::strset_insert;
using jnp1::strset_delete;
using jnp1::strset_test;

#include "strsetconst.h"


namespace {
    unsigned long test() {
        unsigned long id = ::jnp1::strset_new();
        ::jnp1::strset_insert(id, "testowy");
        return id;
    }

    unsigned long id = ::jnp1::strset42();
}

int main() {
    ::jnp1::strset_insert(id, nullptr);
    ::jnp1::strset_delete(id);
}
