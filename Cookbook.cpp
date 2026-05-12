#include "Cookbook.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Cookbook::Cookbook() : nextId(1), nextTagId(1) {}

Cookbook::~Cookbook() {
    for (int i = 0; i < (int)recipes.size(); i++) {
        delete recipes[i];
    }
}

Cookbook::Cookbook(const Cookbook& other)
    : tags(other.tags), nextId(other.nextId), nextTagId(other.nextTagId) {
    for (int i = 0; i < (int)other.recipes.size(); i++) {
        recipes.push_back(other.recipes[i]->clone());
    }
    // menu is default-initialized (all nullptr): copied menu pointers
    // would reference old cookbook's recipes, which is unsafe
}

Cookbook& Cookbook::operator=(const Cookbook& other) {
    if (this == &other) return *this;
    for (int i = 0; i < (int)recipes.size(); i++) {
        delete recipes[i];
    }
    recipes.clear();
    for (int i = 0; i < (int)other.recipes.size(); i++) {
        recipes.push_back(other.recipes[i]->clone());
    }
    tags = other.tags;
    nextId = other.nextId;
    nextTagId = other.nextTagId;
    menu = WeeklyMenu();
    return *this;
}

int Cookbook::getNextId() {
    return nextId++;
}

void Cookbook::addRecipe(Recipe* r) {
    recipes.push_back(r);
}

void Cookbook::removeRecipe(int id) {
    for (int i = 0; i < (int)recipes.size(); i++) {
        if (recipes[i]->getId() == id) {
            for (int d = 0; d < 7; d++) {
                if (menu.getDay(d) == recipes[i]) {
                    menu.setDay(d, nullptr);
                }
            }
            delete recipes[i];
            for (int j = i; j < (int)recipes.size() - 1; j++) {
                recipes[j] = recipes[j + 1];
            }
            recipes.pop_back();
            return;
        }
    }
    throw out_of_range("Recipe not found");
}

Recipe* Cookbook::findById(int id) const {
    for (int i = 0; i < (int)recipes.size(); i++) {
        if (recipes[i]->getId() == id) return recipes[i];
    }
    return nullptr;
}

void Cookbook::searchByIngredient(string ingName) const {
    bool found = false;
    for (int i = 0; i < (int)recipes.size(); i++) {
        if (recipes[i]->containsIngredient(ingName)) {
            cout << "  " << *recipes[i] << endl;
            found = true;
        }
    }
    if (!found) cout << "  No recipes found containing \"" << ingName << "\"." << endl;
}

void Cookbook::searchByTag(string tagName) const {
    bool found = false;
    for (int i = 0; i < (int)recipes.size(); i++) {
        if (recipes[i]->matchesTag(tagName)) {
            cout << "  " << *recipes[i] << endl;
            found = true;
        }
    }
    if (!found) cout << "  No recipes found with tag \"" << tagName << "\"." << endl;
}

void Cookbook::filterByTime(int maxMin) const {
    bool found = false;
    for (int i = 0; i < (int)recipes.size(); i++) {
        if (recipes[i]->getPrepTimeMin() <= maxMin) {
            cout << "  " << *recipes[i] << endl;
            found = true;
        }
    }
    if (!found) cout << "  No recipes found within " << maxMin << " minutes." << endl;
}

Tag Cookbook::addTag(string name) {
    Tag t(nextTagId++, name);
    tags.push_back(t);
    return t;
}

const vector<Tag>& Cookbook::getTags() const {
    return tags;
}

WeeklyMenu& Cookbook::getMenu() {
    return menu;
}

void Cookbook::listAll() const {
    if (recipes.empty()) {
        cout << "  No recipes in the cookbook." << endl;
        return;
    }
    for (int i = 0; i < (int)recipes.size(); i++) {
        cout << "  " << *recipes[i] << endl;
    }
}
