#ifndef TESTING_HPP
#define TESTING_HPP

#include "MyInt.hpp"
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <functional>
#include <map>
#include <string>


std::string PrettyArray(MyInt* elements, int numElements);
void GenerateData(MyInt* elements, int numElements, int numRange);
int ContentsCheck(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName);
int StabilityChecks(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName);
int ScalingTest(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName, MyInt* elementsA, int numElementsA, MyInt* elementsB, int numElementsB, std::string scaling, std::string dataType);
int ScalingTests(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName, std::map<std::string, std::string> scaling, int numElements, int numRange);
int AssignmentTests(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName, MyInt* data, int numElements, int numAssignments);
int ComparisonTests(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName, MyInt* data, int numElements, int numComparisons);

#endif //TESTING_HPP