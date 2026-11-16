#pragma once
#include <string>


struct InputClosed {};

std::string readLine(const std::string& prompt);
int readInt(const std::string& prompt, int lo, int hi);  
double readPrice(const std::string& prompt);             
