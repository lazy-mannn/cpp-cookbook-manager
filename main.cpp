#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Cookbook.h"
#include "SimpleRecipe.h"
#include "FeaturedRecipe.h"

using namespace std;

// ---------- input helpers ----------

string readLine(const string& prompt) {
    cout << prompt;
    string line;
    getline(cin, line);
    return line;
}

int readInt(const string& prompt) {
    string line = readLine(prompt);
    istringstream iss(line);
    int val = -1;
    iss >> val;
    return val;
}

float readFloat(const string& prompt) {
    string line = readLine(prompt);
    istringstream iss(line);
    float val = 0;
    iss >> val;
    return val;
}

// ---------- recipe CRUD ----------

void doAddRecipe(Cookbook& cookbook) {
    cout << "\n--- ADD RECIPE ---" << endl;
    int type = readInt("Type (1=Simple, 2=Featured): ");

    string name = readLine("Name: ");
    string desc = readLine("Description: ");
    int servings = readInt("Servings: ");
    int prep = readInt("Prep time (minutes): ");

    int id = cookbook.getNextId();
    Recipe* r = nullptr;

    try {
        if (type == 2) {
            string note = readLine("Author note: ");
            string diff = readLine("Difficulty: ");
            r = new FeaturedRecipe(id, name, desc, servings, prep, note, diff);
        } else {
            r = new SimpleRecipe(id, name, desc, servings, prep);
        }
    } catch (invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        return;
    }

    cout << "--- Add Ingredients (leave name empty to stop) ---" << endl;
    while (true) {
        string ingName = readLine("  Ingredient name: ");
        if (ingName.empty()) break;
        float qty = readFloat("  Quantity: ");
        string unit = readLine("  Unit: ");
        try {
            r->addIngredient(Ingredient(ingName, qty, unit));
        } catch (invalid_argument& e) {
            cout << "  Error: " << e.what() << endl;
        }
    }

    cout << "--- Add Steps (leave empty to stop) ---" << endl;
    int stepNum = 1;
    while (true) {
        ostringstream prompt;
        prompt << "  Step " << stepNum << ": ";
        string step = readLine(prompt.str());
        if (step.empty()) break;
        r->addStep(step);
        stepNum++;
    }

    cookbook.addRecipe(r);
    cout << "Recipe added with ID: " << id << endl;
}

void doViewAll(const Cookbook& cookbook) {
    cout << "\n--- ALL RECIPES ---" << endl;
    cookbook.listAll();
}

void doViewById(const Cookbook& cookbook) {
    cout << "\n--- VIEW RECIPE ---" << endl;
    int id = readInt("Recipe ID: ");
    Recipe* r = cookbook.findById(id);
    if (r == nullptr) {
        cout << "Recipe not found." << endl;
        return;
    }
    r->display();
}

void doEditRecipe(Cookbook& cookbook) {
    cout << "\n--- EDIT RECIPE ---" << endl;
    int id = readInt("Recipe ID: ");
    Recipe* r = cookbook.findById(id);
    if (r == nullptr) {
        cout << "Recipe not found." << endl;
        return;
    }
    int choice = readInt("Edit (1=Name, 2=Description): ");
    try {
        if (choice == 1) {
            string name = readLine("New name: ");
            r->setName(name);
            cout << "Name updated." << endl;
        } else if (choice == 2) {
            string desc = readLine("New description: ");
            r->setDescription(desc);
            cout << "Description updated." << endl;
        } else {
            cout << "Invalid option." << endl;
        }
    } catch (invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void doDeleteRecipe(Cookbook& cookbook) {
    cout << "\n--- DELETE RECIPE ---" << endl;
    int id = readInt("Recipe ID: ");
    try {
        cookbook.removeRecipe(id);
        cout << "Recipe deleted." << endl;
    } catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void recipeMenu(Cookbook& cookbook) {
    while (true) {
        cout << "\n--- RECIPE MANAGEMENT ---" << endl;
        cout << "1. Add Recipe" << endl;
        cout << "2. View All Recipes" << endl;
        cout << "3. View Recipe by ID" << endl;
        cout << "4. Edit Recipe" << endl;
        cout << "5. Delete Recipe" << endl;
        cout << "0. Back" << endl;
        int choice = readInt("Choice: ");

        if (choice == 0) break;
        else if (choice == 1) doAddRecipe(cookbook);
        else if (choice == 2) doViewAll(cookbook);
        else if (choice == 3) doViewById(cookbook);
        else if (choice == 4) doEditRecipe(cookbook);
        else if (choice == 5) doDeleteRecipe(cookbook);
        else cout << "Invalid option." << endl;
    }
}

// ---------- main ----------

int main() {
    Cookbook cookbook;

    while (true) {
        cout << "\n=== COOKBOOK MANAGER ===" << endl;
        cout << "1. Recipe Management" << endl;
        cout << "0. Exit" << endl;
        int choice = readInt("Choice: ");

        if (choice == 0) break;
        else if (choice == 1) recipeMenu(cookbook);
        else cout << "Invalid option." << endl;
    }

    cout << "Goodbye!" << endl;
    return 0;
}
