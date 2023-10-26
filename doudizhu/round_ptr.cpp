#include "round_ptr.h"

round_ptr::round_ptr() : cur(nullptr) {}

void round_ptr::to_next() {
    cur = cur->next;
}

client &round_ptr::get_client() {
    return cur->cl;
}

round_ptr &round_ptr::operator=(client_box *ptr) {
    cur = ptr;
    return *this;
}

client &round_ptr::operator*() {
    return cur->cl;
}