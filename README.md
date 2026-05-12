# Cookbook Manager

A CLI-based cookbook and meal planning system written in C++ as part of an object-oriented programming course.

## Features

- **Recipe Management** — add Simple or Featured recipes with ingredients and step-by-step instructions; view, edit, and delete by ID
- **Tag System** — create global tags and assign them to recipes for easy categorisation
- **Search by Ingredient** — find all recipes that contain a specific ingredient
- **Scale Servings** — display adjusted ingredient quantities for any target serving count

## Build

```bash
make
```

## Run

```bash
./cookbook
```

## Clean

```bash
make clean
```

## Project Structure

| Class | Description |
|-------|-------------|
| `Ingredient` | Name, quantity, and unit; supports non-destructive scaling |
| `Tag` | A label with an ID that can be assigned to recipes |
| `Recipe` | Abstract base class — holds ingredients, steps, tags, and metadata |
| `SimpleRecipe` | Concrete recipe with standard display |
| `FeaturedRecipe` | Recipe extended with author note and difficulty rating |
| `WeeklyMenu` | Assigns recipes to each day of the week; generates a shopping list |
| `Cookbook` | Top-level container managing all recipes, global tags, and the menu |

## Technical Notes

- Standard library only — no external dependencies
- Compiled with `g++ -std=c++11 -Wall -Wextra`
- All class data is private/protected; public interface via getters and setters
- Rule of Three applied where classes manage raw memory
- Polymorphism used for recipe types via `Recipe*` base pointers
