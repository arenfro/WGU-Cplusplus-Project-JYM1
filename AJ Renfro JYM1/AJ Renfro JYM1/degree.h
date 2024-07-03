#pragma once
#include <string>

enum DegreeProgram { UNKNOWN, SECURITY, NETWORK, SOFTWARE };
static const std::string degreeProgramStrings[] = { "UNKNOWN", "SECURITY", "NETWORK", "SOFTWARE" };

//char at index 2 of each string/enum type is unique. K, C, T, F.