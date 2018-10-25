//
// Created by kacper on 21.10.18.
//

#include "strset.h"
#ifdef __cplusplus
#include <iostream>
#include <set>
#include <unordered_map>
#include <string>

namespace
{
#endif
    std::unordered_map < unsigned long, std::set <std::string> > sets;
    unsigned long id = 0;
    const bool debug = true;
#ifdef __cplusplus
}
#endif

unsigned long jnp1::strset_new()
{
    ++id;
    sets[id] = std::set<std::string> {"a","b"};
    return id;
}

size_t jnp1::strset_size(unsigned long id)
{
    return sets[id].size();
}

void jnp1::strset_delete(unsigned long id)
{
    sets.erase(id);
}

void jnp1::strset_insert(unsigned long id, const char *value)
{
    sets[id].insert(std::string(value));
}

void jnp1::strset_remove(unsigned long id, const char *value)
{
    sets[id].erase(value);
}

int jnp1::strset_test(unsigned long id, const char *value)
{
    if(  sets.find(id) == sets.end() || sets[id].find(value) == sets[id].end()) { return 0; }
    else { return 1; }
}