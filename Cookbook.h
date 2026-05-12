#ifndef COOKBOOK_H
#define COOKBOOK_H

#include <vector>
#include "Recipe.h"
#include "Tag.h"
#include "WeeklyMenu.h"

class Cookbook {
private:
    std::vector<Recipe*> recipes;
    std::vector<Tag> tags;
    WeeklyMenu menu;
    int nextId;
    int nextTagId;

public:
    Cookbook();
    ~Cookbook();
    Cookbook(const Cookbook& other);
    Cookbook& operator=(const Cookbook& other);

    int getNextId();

    void addRecipe(Recipe* r);
    void removeRecipe(int id);
    Recipe* findById(int id) const;

    void searchByIngredient(std::string ingName) const;
    void searchByTag(std::string tagName) const;
    void filterByTime(int maxMin) const;

    Tag addTag(std::string name);
    const std::vector<Tag>& getTags() const;

    WeeklyMenu& getMenu();
    void listAll() const;
};

#endif
