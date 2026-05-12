#ifndef WEEKLYMENU_H
#define WEEKLYMENU_H

class Recipe;

class WeeklyMenu {
private:
    Recipe* days[7];

public:
    WeeklyMenu();

    void setDay(int day, Recipe* r);
    Recipe* getDay(int day) const;
    void generateShoppingList() const;
    void display() const;
};

#endif
