
#include "strset.h"

#include <iostream>
#include <unordered_map>
#include <set>

void log_debug(std::string &msg) {
    std::cerr << msg << std::endl;
}

void log_prod(std::string msg) {
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

namespace {
    std::unordered_map<unsigned long, std::set<std::string> > sets;
    unsigned long id = 0;
    int immutable_set_id = -1;
}

void add_immutable_set(){

}


unsigned long jnp1::strset_new() {
    log("strset_new()");
    ++id;
    sets[id] = std::set<std::string>{"a", "b"};
    log("strset_new: set " + std::to_string(id) + " created");
    return id;
}

size_t jnp1::strset_size(unsigned long id) {
    return sets[id].size();
}

void jnp1::strset_delete(unsigned long id) {
    sets.erase(id);
}

void jnp1::strset_insert(unsigned long id, const char *value) {
    sets[id].insert(std::string(value));
}

void jnp1::strset_remove(unsigned long id, const char *value) {
    sets[id].erase(value);
}

int jnp1::strset_test(unsigned long id, const char *value) {
    if (sets.find(id) == sets.end() || sets[id].find(value) == sets[id].end()) { return 0; }
    else { return 1; }
}
