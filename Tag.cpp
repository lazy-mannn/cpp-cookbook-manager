#include "Tag.h"
#include <stdexcept>

using namespace std;

Tag::Tag(int id, string name) {
    if (name.empty()) throw invalid_argument("Tag name cannot be empty");
    this->id = id;
    this->name = name;
}

int Tag::getId() const { return id; }
string Tag::getName() const { return name; }

ostream& operator<<(ostream& out, const Tag& t) {
    out << "[" << t.id << "] " << t.name;
    return out;
}
