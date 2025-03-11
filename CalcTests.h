#pragma once
#ifndef CALC_TEST_H

#define CALC_TEST_H

#include "Operations.h"
#include "Calculator.h"
#include <iostream>
#include <cmath>
#include <sstream>

inline void runTest(const std::string& expression, double expected, double actual) {
	std::istringstream iss(expression);
    std::cout << expression << ": ";
    if (std::fabs(expected - actual) < 1e-6) { // Check if values are approximately equal
        std::cout << "Passed\n";
    }
    else {
        std::cout << "Failed (Expected: " << expected << ", Got: " << actual << ")\n";
    }
}

inline void runTestCases() {
    Add add;
    Subtract subtract;
    Multiply multiply;
    Divide divide;
    Modulus modulus;
    Power power;
    SquareRoot squareRoot;

    runTest("1 + 2", 3, add.compute(1, 2));
    runTest("1 - 2", -1, subtract.compute(1, 2));
    runTest("1 * 2", 2, multiply.compute(1, 2));
    runTest("1 / 2", 0.5, divide.compute(1, 2));
    runTest("1 % 2", 1, modulus.compute(1, 2));
    runTest("1 ^ 2", 1, power.compute(1, 2));
    runTest("1 ~ 0", 1, squareRoot.compute(1, 0));

    runTest("5 + 3", 8, add.compute(5, 3));
    runTest("10 - 4", 6, subtract.compute(10, 4));
    runTest("3 * 3", 9, multiply.compute(3, 3));
    runTest("10 / 2", 5, divide.compute(10, 2));
    runTest("10 % 3", 1, modulus.compute(10, 3));
    runTest("2 ^ 3", 8, power.compute(2, 3));
    runTest("16 ~ 0", 4, squareRoot.compute(16, 0));

    try {
        double result = divide.compute(10, 0);
        runTest("10 / 0", NAN, result);
    }
    catch (...) {
        std::cout << "10 / 0: Passed (Exception Caught: division by zero)\n";
    }

    try {
        double result = squareRoot.compute(-4, 0);
        runTest("-4 ~ 0", NAN, result);
    }
    catch (...) {
        std::cout << "-4 ~ 0: Passed (Exception Caught: square rooting a negative)\n";
    }
}

#endif // !CALC_TEST_H