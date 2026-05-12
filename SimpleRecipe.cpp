#include "SimpleRecipe.h"
#include <iostream>

using namespace std;

SimpleRecipe::SimpleRecipe(int id, string name, string description,
                           int servings, int prepTimeMin)
    : Recipe(id, name, description, servings, prepTimeMin) {}

void SimpleRecipe::display() const {
    cout << "=== " << name << " ===" << endl;
    cout << "ID: " << id << endl;
    cout << "Description: " << description << endl;
    cout << "Servings: " << servings << endl;
    cout << "Prep Time: " << prepTimeMin << " min" << endl;

    if (!tags.empty()) {
        cout << "Tags: ";
        for (int i = 0; i < (int)tags.size(); i++) {
            if (i > 0) cout << ", ";
            cout << tags[i].getName();
        }
        cout << endl;
    }

    if (!ingredients.empty()) {
        cout << "Ingredients:" << endl;
        for (int i = 0; i < (int)ingredients.size(); i++) {
            cout << "  - " << ingredients[i] << endl;
        }
    }

    if (!steps.empty()) {
        cout << "Steps:" << endl;
        for (int i = 0; i < (int)steps.size(); i++) {
            cout << "  " << (i + 1) << ". " << steps[i] << endl;
        }
    }
}

Recipe* SimpleRecipe::clone() const {
    return new SimpleRecipe(*this);
}
