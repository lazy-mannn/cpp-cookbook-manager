#include "WeeklyMenu.h"
#include "Recipe.h"
#include <iostream>
#include <vector>
#include "Ingredient.h"

using namespace std;

WeeklyMenu::WeeklyMenu() {
    for (int i = 0; i < 7; i++) {
        days[i] = nullptr;
    }
}

void WeeklyMenu::setDay(int day, Recipe* r) {
    if (day < 0 || day > 6) throw out_of_range("Day must be 0-6");
    days[day] = r;
}

Recipe* WeeklyMenu::getDay(int day) const {
    if (day < 0 || day > 6) throw out_of_range("Day must be 0-6");
    return days[day];
}

void WeeklyMenu::display() const {
    const string dayNames[7] = {
        "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday", "Sunday"
    };
    cout << "=== WEEKLY MENU ===" << endl;
    for (int d = 0; d < 7; d++) {
        cout << dayNames[d] << ": ";
        if (days[d] == nullptr) {
            cout << "(no recipe)" << endl;
        } else {
            cout << *days[d] << endl;
        }
    }
}

void WeeklyMenu::generateShoppingList() const {
    vector<Ingredient> list;

    for (int d = 0; d < 7; d++) {
        if (days[d] == nullptr) continue;
        const vector<Ingredient>& ings = days[d]->getIngredients();
        for (int i = 0; i < (int)ings.size(); i++) {
            bool found = false;
            for (int j = 0; j < (int)list.size(); j++) {
                if (list[j].getName() == ings[i].getName() &&
                    list[j].getUnit() == ings[i].getUnit()) {
                    Ingredient combined(ings[i].getName(),
                                        list[j].getQuantity() + ings[i].getQuantity(),
                                        ings[i].getUnit());
                    list[j] = combined;
                    found = true;
                    break;
                }
            }
            if (!found) {
                list.push_back(ings[i]);
            }
        }
    }

    cout << "=== SHOPPING LIST ===" << endl;
    if (list.empty()) {
        cout << "No ingredients (no recipes assigned to the menu)." << endl;
        return;
    }
    for (int i = 0; i < (int)list.size(); i++) {
        cout << "  " << list[i] << endl;
    }
}
