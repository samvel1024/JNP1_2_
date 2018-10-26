#include "strsetconst.h"
#include "strset.h"
#include <string>

void log(std::string str);
unsigned long set_immutable_singleton(const char *str);



unsigned long jnp1::strset42() {
    log("strset42() init invoked");
    unsigned long id = set_immutable_singleton("42");
    return id;
}
