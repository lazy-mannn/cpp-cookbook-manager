# Architecture Changes

## Added `clone()` pure virtual method to Recipe

**What changed:** Added `virtual Recipe* clone() const = 0;` to the `Recipe` abstract class, implemented in `SimpleRecipe` and `FeaturedRecipe`.

**Why:** `Cookbook` owns its `Recipe*` pointers and needs a destructor to free them. Under the Rule of Three, defining a destructor also requires defining the copy constructor and assignment operator. To correctly deep-copy polymorphic pointers in those operations, the virtual clone pattern is used — it allows a base-class pointer to produce a correctly-typed copy without needing casts or type checks.
