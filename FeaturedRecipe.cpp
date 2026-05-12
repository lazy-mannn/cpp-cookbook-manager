#include "FeaturedRecipe.h"
#include <iostream>

using namespace std;

FeaturedRecipe::FeaturedRecipe(int id, string name, string description,
                               int servings, int prepTimeMin,
                               string authorNote, string difficulty)
    : Recipe(id, name, description, servings, prepTimeMin),
      authorNote(authorNote), difficulty(difficulty) {}

void FeaturedRecipe::display() const {
    cout << "=== [FEATURED] " << name << " ===" << endl;
    cout << "ID: " << id << endl;
    cout << "Description: " << description << endl;
    cout << "Servings: " << servings << endl;
    cout << "Prep Time: " << prepTimeMin << " min" << endl;
    cout << "Difficulty: " << difficulty << endl;
    cout << "Author Note: " << authorNote << endl;

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

Recipe* FeaturedRecipe::clone() const {
    return new FeaturedRecipe(*this);
}

string FeaturedRecipe::getAuthorNote() const { return authorNote; }
string FeaturedRecipe::getDifficulty() const { return difficulty; }
