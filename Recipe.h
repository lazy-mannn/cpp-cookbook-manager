#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>
#include <ostream>
#include "Ingredient.h"
#include "Tag.h"

class Recipe {
protected:
    int id;
    std::string name;
    std::string description;
    std::vector<Ingredient> ingredients;
    std::vector<std::string> steps;
    int servings;
    int prepTimeMin;
    std::vector<Tag> tags;

public:
    Recipe(int id, std::string name, std::string description, int servings, int prepTimeMin);
    Recipe(const Recipe& other);
    Recipe& operator=(const Recipe& other);
    virtual ~Recipe() {}

    virtual void display() const = 0;
    virtual Recipe* clone() const = 0;

    void addIngredient(const Ingredient& ing);
    void addStep(const std::string& step);
    void addTag(const Tag& tag);
    void scaleServings(int n);
    bool matchesTag(std::string tagName) const;
    bool containsIngredient(std::string ingName) const;

    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    int getServings() const;
    int getPrepTimeMin() const;
    const std::vector<Ingredient>& getIngredients() const;
    const std::vector<std::string>& getSteps() const;
    const std::vector<Tag>& getTags() const;

    void setName(const std::string& name);
    void setDescription(const std::string& desc);

    friend std::ostream& operator<<(std::ostream& out, const Recipe& r);
};

#endif
