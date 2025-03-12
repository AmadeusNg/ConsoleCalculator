// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CalcTests.h"


bool isValidInput(std::string input) {
    bool hasNumber = false;
    for (char c : input) {
        if (std::isdigit(c)) {
            hasNumber = true;  // At least one number should be present
        }
        else if (!std::isspace(c) && c != '+' && c != '-' && c != '*' &&
            c != '/' && c != '%' && c != '^' && c != '~') {
            return false; // Invalid character found
        }
    }
	return hasNumber;
}
int main()
{   
    std::string input;
    std::cout << "Welcome to the Calculator! Type 'test' to run tests or enter an expression:\n";

    while (true) {
        std::getline(std::cin, input);

        Calculator calc;
        if (input == "test") {
            runTestCases();
            std::cout << "Enter an expression (or 'exit' to quit): \n";
            continue;
	    }
        if (input == "history") {
            calc.printhistory();
            std::cout << "Enter an expression (or 'exit' to quit): \n";
            continue;
        }

        if (!isValidInput(input)) {
            std::cout << "Invalid input! Only numbers and operators (+, -, *, /, %, ^, ~) are allowed.\n";
            std::cout << "Please try again.\n";
            continue;
        }

        calc.run(input);
        break;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
