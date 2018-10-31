#include "strsetconst.h"
#include "strset.h"

unsigned long set_immutable_singleton(const char *str);

#ifdef NDEBUG
#define LOG(msg)
#else
#define LOG(msg) std::cerr<<msg<<std::endl;
#endif



unsigned long jnp1::strset42() {
    LOG("strset42() init invoked");
    unsigned long id = set_immutable_singleton("42");
    return id;
}
