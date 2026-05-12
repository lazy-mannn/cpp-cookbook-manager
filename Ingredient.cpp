#include "Ingredient.h"
#include <stdexcept>
#include <sstream>

using namespace std;

Ingredient::Ingredient(string name, float quantity, string unit) {
    if (name.empty()) throw invalid_argument("Ingredient name cannot be empty");
    if (quantity < 0) throw invalid_argument("Quantity cannot be negative");
    this->name = name;
    this->quantity = quantity;
    this->unit = unit;
}

string Ingredient::getName() const { return name; }
float Ingredient::getQuantity() const { return quantity; }
string Ingredient::getUnit() const { return unit; }

Ingredient Ingredient::scale(float factor) const {
    if (factor <= 0) throw invalid_argument("Scale factor must be positive");
    return Ingredient(name, quantity * factor, unit);
}

string Ingredient::toString() const {
    ostringstream oss;
    oss << quantity << " " << unit << " " << name;
    return oss.str();
}

ostream& operator<<(ostream& out, const Ingredient& i) {
    out << i.quantity << " " << i.unit << " " << i.name;
    return out;
}
