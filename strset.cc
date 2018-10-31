
#include "strset.h"

#include <iostream>
#include <unordered_map>
#include <set>
#include <experimental/optional>


using set_id = unsigned long;

namespace {

    bool is_immutable_present = false;
    set_id immutable_set_id = 0;

#ifdef NDEBUG
#define LOG(msg)
#else
#define LOG(msg) log_debug(msg)
#endif
    
    //Initialize global variable
    static auto &sets() {
        static auto *mysets = new std::unordered_map<set_id, std::set<std::string> >();
        return *mysets;
    }

}

void log_debug(const std::string &msg) {
    std::cerr << msg << std::endl;
}

//Check if immutalbe set already exists
bool is_immutable(set_id id) {
    if (is_immutable_present && immutable_set_id == id) {
        LOG("is_immutable(" + std::to_string(id) +
            "): cannot perform modifications to the immutable set");
        return true;
    }
    return false;
}


std::experimental::optional<std::set<std::string>> get_by_id(set_id id) {
    if (sets().count(id) == 0) {
        return std::experimental::nullopt;
    }
    return {sets()[id]};
}

//Creates new set and returns it's id
set_id jnp1::strset_new() {
    static set_id id = 0;

    LOG("strset_new()");
    ++id;
    sets()[id] = std::set<std::string>();
    LOG("strset_new: set " + std::to_string(id) + " created");
    return id;
}

//if set exits, returns it's size
size_t jnp1::strset_size(set_id id) {
    LOG("strset_size()");

    auto it = sets().find(id);
    //Chceck if set exists
    if (it != sets().end()) {
        return it->second.size();
    } else {
        LOG("strset_size: set" + std::to_string(id) + " doesn't exist");
        return 0;
    }
}
//If set exists, delete it
void jnp1::strset_delete(set_id id) {
    LOG("strset_delete()");

    if (is_immutable(id)) {
        return;
    }

    auto it = sets().find(id);
    //Chceck if set exists
    if (it != sets().end()) {
        sets().erase(id);
        LOG("strset_delete: set" + std::to_string(id) + " removed");
    } else {
        LOG("strset_insert: set" + std::to_string(id) + " doesn't exist");
    }
}
//Insert element into set
void jnp1::strset_insert(set_id id, const char *value) {
    LOG("strset_insert()");

    if (is_immutable(id)) {
        return;
    }

    if (value == nullptr) {
        LOG("strste_insert: value cannot be null");
        return;
    }

    auto it = sets().find(id);

    if (it != sets().end()) {
        it->second.insert(value);
        LOG("strset_insert: set" + std::to_string(id)
            + " element " + value + " inserted");
    } else {
        LOG("strset_insert: set" + std::to_string(id) + " doesn't exist");
    }
}
//
void jnp1::strset_remove(set_id id, const char *value) {
    LOG("strset_remove()");

    if (is_immutable(id))
        return;

    auto it = sets().find(id);

    if (it != sets().end()) {
        it->second.erase(value);
        LOG("strset_remove: set" + std::to_string(id) +
            " element " + value + " removed");
    } else {
        LOG("strset_remove: set" + std::to_string(id) + " doesn't exist");
    }
}

int jnp1::strset_test(set_id id, const char *value) {
    LOG("strset_test()");

    auto it = sets().find(id);

    if (it == sets().end()) {
        LOG("strset_test: set" + std::to_string(id) + " doesn't exist");
        return 0;
    } else if (it->second.find(value) != it->second.end()) {
        LOG("strset_remove: set" + std::to_string(id) +
            " element " + value + " is here");
        return 1;
    }

    LOG("strset_remove: set" + std::to_string(id) +
        " element " + value + " is not inside set");
    return 0;
}

void jnp1::strset_clear(unsigned long id) {

    LOG("strset_clear()");

    if (is_immutable(id)) {
        return;
    }

    auto it = sets().find(id);

    if (it == sets().end()) {
        LOG("strset_clear: set" + std::to_string(id) + " doesn't exist");
    } else {
        LOG("strset_test: set" + std::to_string(id) + " cleared");
        it->second.clear();
    }

}


int jnp1::strset_comp(set_id id1, set_id id2) {
    auto s1 = get_by_id(id1);
    auto s2 = get_by_id(id2);

    return s1 < s2 ? -1 : s1 == s2 ? 0 : 1;
}

set_id set_immutable_singleton(const char *value) {
    if (is_immutable_present) {
        LOG("add_immutable_set(): only one immutable set is supported");
    } else {
        set_id id = jnp1::strset_new();
        jnp1::strset_insert(id, value);
        immutable_set_id = id;
        is_immutable_present = true;
    }

    return immutable_set_id;
}
