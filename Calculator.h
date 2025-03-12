#pragma once
#ifndef CALCULATOR_H

#define CALCULATOR_H

#include <iostream>
#include "Operations.h"
#include <string>
#include <sstream>
#include <vector>

class Calculator {
	private:
		double num1, num2;
		char operation;
		Operations* op;
		std::vector<double> history;

	public:
		void addToHistory(double result) {
			history.push_back(result);
		}

		void printhistory() {
			if (history.empty()) {
				std::cout << "No past calculations yet.\n";
				return;
			}

			std::cout << "\n Past Calculations:\n";
			for (size_t i = 0; i < history.size(); i++) {
				std::cout << i + 1 << ". " << history[i] << "\n";
			}
		}

		bool processInput(const std::string& input, double& num1, char& op, double& num2) {
			std::istringstream iss(input);
			if (iss >> num1 >> op) {
				if (op == '~') {
					num2 = 0;
					return true;
				}
				if (iss >> num2) {
					return true;
				}
			}
			else {
				std::cout<<"Invalid input\n";
				return false;
			}
		}

		std::unique_ptr<Operations> getOperation(char operation) {
			switch (operation) {
				case '+':
					return std::make_unique<Add>();
				case '-':
					return std::make_unique<Subtract>();
				case '*':
					return std::make_unique<Multiply>();
				case '/':
					return std::make_unique<Divide>();
				case '%':
					return std::make_unique<Modulus>();
				case '^':
					return std::make_unique<Power>();
				case '~':
					return std::make_unique<SquareRoot>();
				default:
					std::cout<<"Invalid operation\n";
					return nullptr;
			}
		}

		void calculate(std::unique_ptr<Operations>& operation, double num1, double num2) {
			if (operation) {
				try {
					double result = operation->compute(num1, num2);
					std::cout<< "Result: "<<result<<"\n";
					addToHistory(result);
				}
				catch (const std::exception& e) {
					std::cout<<"Error: " << e.what() << "\n";
				}
			}
		}

		void run(const std::string& firstInput) {
			std::string input = firstInput;
			
			while (true) {
				if (input == "exit") {
					break;
				}

				if (input == "history") {
					printhistory();
					std::cout << "Enter an expression (or 'exit' to quit): \n";
					std::getline(std::cin, input);
					continue;
				}
				else {
					double num1, num2;
					char op;
					if (!processInput(input, num1, op, num2)) {
						continue;
					}
					else {
						std::unique_ptr<Operations> operation = getOperation(op);
						if (operation) {
							calculate(operation, num1, num2);
						}
					}
				}

				std::cout << "Enter an expression (or 'exit' to quit): \n";
				std::getline(std::cin, input);
				
			}
			std::cout<<"Calculator Exited. Goodbye\n";
		}
};
#endif // !CALCULATOR_H