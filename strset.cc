
#include "strset.h"

#include <iostream>
#include <unordered_map>
#include <set>


using set_id = unsigned long;
const bool debug = true;

void log_debug(const std::string &msg) {
    std::cerr << msg << std::endl;
}

void log_prod(const std::string &msg) {
    // Disable logging when not in debug
}

void log(const std::string &msg);

void log(const std::string &msg){
    if(debug) {
        log_debug(msg);
    } else{
        log_prod(msg);
    }
}

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
    sets[id] = std::set<std::string> ();
    log("strset_new: set " + std::to_string(id) + " created");
    return id;
}

size_t jnp1::strset_size(set_id id) {
    log("strset_size()");
    auto it = sets.find(id);

    if(it != sets.end()) {
        return it -> second.size();
    } else{
        log("strset_size: set" + std::to_string(id) + " doesn't exist");
        return 0;
    }
}

void jnp1::strset_delete(set_id id) {
    log("strset_delete()");
    if (is_immutable(id))
        return;

    sets.erase(id);
    log("strset_delete: set" + std::to_string(id) + " removed");
}

void jnp1::strset_insert(set_id id, const char *value) {
    log("strset_insert()");
    if (is_immutable(id))
        return;

    auto it = sets.find(id);
    if(it != sets.end()) {
        it -> second.insert(value);
        log("strset_insert: set" + std::to_string(id) + " element " + value + " inserted");
    } else{
        log("strset_insert: set" + std::to_string(id) + " doesn't exist");
    }
}

void jnp1::strset_remove(set_id id, const char *value) {
    log("strset_insert()");
    if (is_immutable(id))
        return;

    auto it = sets.find(id);
    if(it != sets.end()) {
        it -> second.erase(value);
        log("strset_remove: set" + std::to_string(id) +
            " element " + value + " removed");
    } else{
        log("strset_remove: set" + std::to_string(id) + " doesn't exist");
    }
}

int jnp1::strset_test(set_id id, const char *value) {
    log("strset_test()");

    auto it = sets.find(id);
    if (it == sets.end()) {
        log("strset_test: set" + std::to_string(id) + " doesn't exist");
        return 0;
    }
    else if(it -> second.find(value) != it -> second.end()) {
        log("strset_remove: set" + std::to_string(id) +
            " element " + value + " is here");
        return 1;
    }
    log("strset_remove: set" + std::to_string(id) +
        " element " + value + " is not inside set");
    return 0;
}

void jnp1::strset_clear(unsigned long id) {
    log("strset_clear()");

    auto it = sets.find(id);
    if(it == sets.end())
    {
        log("strset_clear: set" + std::to_string(id) + " doesn't exist");
    } else {
        log("strset_test: set" + std::to_string(id) + " cleared");
        it -> second.clear();
    }
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
