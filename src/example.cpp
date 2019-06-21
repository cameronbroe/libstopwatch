#include "example.h"

namespace shared_lib {

example::example() {
    this->m_message = "";
}

example::~example() {}

void example::setMessage(std::string message) {
    this->m_message = message;
}

std::string example::getMessage() {
    return this->m_message;
}

}
