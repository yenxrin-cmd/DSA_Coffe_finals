CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
SRC      = $(wildcard src/*.cpp)

coffee_shop: $(SRC) $(wildcard src/*.h)
	$(CXX) $(CXXFLAGS) $(SRC) -o coffee_shop
