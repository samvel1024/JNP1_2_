#include "strsetconst.h"
#include "strset.h"
#include "strset.cc"

#include <set>
#include <string>

unsigned long jnp1::strset42()
{
    log("strsetconst init invoked");
    unsigned long id = jnp1::strset_new();
    jnp1::strset_insert(id,"42");
    return id;
}
