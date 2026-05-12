#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <ostream>

class Ingredient {
private:
    std::string name;
    float quantity;
    std::string unit;

public:
    Ingredient(std::string name, float quantity, std::string unit);

    std::string getName() const;
    float getQuantity() const;
    std::string getUnit() const;

    Ingredient scale(float factor) const;
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& out, const Ingredient& i);
};

#endif
