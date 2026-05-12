CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

SRCS = main.cpp Ingredient.cpp Tag.cpp Recipe.cpp SimpleRecipe.cpp \
       FeaturedRecipe.cpp WeeklyMenu.cpp Cookbook.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = cookbook

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
