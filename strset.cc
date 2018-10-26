
#include "strset.h"

#include <iostream>
#include <unordered_map>
#include <set>

void log_debug(std::string &msg) {
    std::cerr << msg << std::endl;
}

void log_prod(std::string &msg) {
    // Disable logging when not in debug
}

void log(std::string msg);

#ifdef DNDEBUG
void log(std::string &msg){
    log_debug(msg);
}
#else

void log(std::string msg) {
    log_prod(msg);
}

#endif

using set_id=unsigned long;

namespace {
    std::unordered_map<set_id, std::set<std::string> > sets;
    set_id id = 0;
    bool is_immutable_present = false;
    set_id immutable_set_id = 0;
}


bool is_immutable(set_id id) {
    if (is_immutable_present && immutable_set_id == id) {
        log("is_not_immutable(" + std::to_string(id) + "): cannot perform modifications to the immutable set");
        return true;
    }
    return false;
}

set_id jnp1::strset_new() {
    log("strset_new()");
    ++id;
    sets[id] = std::set<std::string>{"a", "b"};
    log("strset_new: set " + std::to_string(id) + " created");
    return id;
}

size_t jnp1::strset_size(set_id id) {
    return sets[id].size();
}

void jnp1::strset_delete(set_id id) {
    if (is_immutable(id))
        return;
    sets.erase(id);
}

void jnp1::strset_insert(set_id id, const char *value) {
    if (!is_immutable(id))
        return;
    sets[id].insert(std::string(value));
}

void jnp1::strset_remove(set_id id, const char *value) {
    if (!is_immutable(id))
        return;
    sets[id].erase(value);
}

int jnp1::strset_test(set_id id, const char *value) {
    if (sets.find(id) == sets.end() || sets[id].find(value) == sets[id].end())
        return 0;
    else
        return 1;
}

void jnp1::strset_clear(unsigned long id){
    //TODO soon
}


int jnp1::strset_comp(set_id id1, set_id id2) {
    //TODO soon
    return 0;
}

set_id set_immutable_singleton(const char *value) {
    if (is_immutable_present) {
        log("add_immutable_set(): only one immutable set is supported");
    } else {
        set_id id = jnp1::strset_new();
        jnp1::strset_insert(id, value);
        immutable_set_id = id;
        is_immutable_present = true;
    }
    return immutable_set_id;
}
