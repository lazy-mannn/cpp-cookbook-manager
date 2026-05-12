#ifndef FEATUREDRECIPE_H
#define FEATUREDRECIPE_H

#include "Recipe.h"

class FeaturedRecipe : public Recipe {
private:
    std::string authorNote;
    std::string difficulty;

public:
    FeaturedRecipe(int id, std::string name, std::string description,
                   int servings, int prepTimeMin,
                   std::string authorNote, std::string difficulty);

    void display() const override;
    Recipe* clone() const override;

    std::string getAuthorNote() const;
    std::string getDifficulty() const;
};

#endif
