#pragma once
#include <string>
#include <vector>
#include "Product.h"



std::vector<Product> linearKeywordSearch(const std::vector<Product>& all,
                                         const std::string& keyword, int& comparisons);


int lowerBoundPrice(const std::vector<Product>& v, double value, int& steps);  
int upperBoundPrice(const std::vector<Product>& v, double value, int& steps); 
