#include "Recipe.h"
#include <stdexcept>

using namespace std;

Recipe::Recipe(int id, string name, string description, int servings, int prepTimeMin) {
    if (name.empty()) throw invalid_argument("Recipe name cannot be empty");
    if (servings <= 0) throw invalid_argument("Servings must be positive");
    if (prepTimeMin < 0) throw invalid_argument("Prep time cannot be negative");
    this->id = id;
    this->name = name;
    this->description = description;
    this->servings = servings;
    this->prepTimeMin = prepTimeMin;
}

Recipe::Recipe(const Recipe& other)
    : id(other.id), name(other.name), description(other.description),
      ingredients(other.ingredients), steps(other.steps),
      servings(other.servings), prepTimeMin(other.prepTimeMin),
      tags(other.tags) {}

Recipe& Recipe::operator=(const Recipe& other) {
    if (this == &other) return *this;
    id = other.id;
    name = other.name;
    description = other.description;
    ingredients = other.ingredients;
    steps = other.steps;
    servings = other.servings;
    prepTimeMin = other.prepTimeMin;
    tags = other.tags;
    return *this;
}

void Recipe::addIngredient(const Ingredient& ing) {
    ingredients.push_back(ing);
}

void Recipe::addStep(const string& step) {
    steps.push_back(step);
}

void Recipe::addTag(const Tag& tag) {
    tags.push_back(tag);
}

void Recipe::scaleServings(int n) {
    if (n <= 0) throw invalid_argument("Servings must be positive");
    float factor = (float)n / servings;
    for (int i = 0; i < (int)ingredients.size(); i++) {
        ingredients[i] = ingredients[i].scale(factor);
    }
    servings = n;
}

bool Recipe::matchesTag(string tagName) const {
    for (int i = 0; i < (int)tags.size(); i++) {
        if (tags[i].getName() == tagName) return true;
    }
    return false;
}

bool Recipe::containsIngredient(string ingName) const {
    for (int i = 0; i < (int)ingredients.size(); i++) {
        if (ingredients[i].getName() == ingName) return true;
    }
    return false;
}

int Recipe::getId() const { return id; }
string Recipe::getName() const { return name; }
string Recipe::getDescription() const { return description; }
int Recipe::getServings() const { return servings; }
int Recipe::getPrepTimeMin() const { return prepTimeMin; }
const vector<Ingredient>& Recipe::getIngredients() const { return ingredients; }
const vector<string>& Recipe::getSteps() const { return steps; }
const vector<Tag>& Recipe::getTags() const { return tags; }

void Recipe::setName(const string& name) {
    if (name.empty()) throw invalid_argument("Name cannot be empty");
    this->name = name;
}

void Recipe::setDescription(const string& desc) {
    this->description = desc;
}

ostream& operator<<(ostream& out, const Recipe& r) {
    out << "[" << r.id << "] " << r.name
        << " | Servings: " << r.servings
        << " | Prep: " << r.prepTimeMin << " min";
    return out;
}
