#include "strsetconst.h"
#include "strset.h"

void log_debug(const std::string &msg);
unsigned long set_immutable_singleton(const char *str);

#ifdef NDEBUG
#define LOG(msg)
#else
#define LOG(msg) log_debug(msg)
#endif



unsigned long jnp1::strset42() {
    LOG("strset42() init invoked");
    unsigned long id = set_immutable_singleton("42");
    return id;
}
