#include "strsetconst.h"
#include "strset.h"

#include <set>
#include <string>

unsigned long jnp1::strset42()
{
    unsigned long id = jnp1::strset_new();
    jnp1::strset_insert(id,"42");
    return id;
}
