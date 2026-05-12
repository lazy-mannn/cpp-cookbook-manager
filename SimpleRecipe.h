#ifndef SIMPLERECIPE_H
#define SIMPLERECIPE_H

#include "Recipe.h"

class SimpleRecipe : public Recipe {
public:
    SimpleRecipe(int id, std::string name, std::string description,
                 int servings, int prepTimeMin);

    void display() const override;
    Recipe* clone() const override;
};

#endif
