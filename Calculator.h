#pragma once
#ifndef CALCULATOR_H

#define CALCULATOR_H

#include <iostream>
#include "Operations.h"
#include <string>
#include <sstream>

class Calculator {
	private:
		double num1, num2;
		char operation;
		Operations* op;
		

	public:

		bool processInput(const std::string& input, double& num1, char& op, double& num2) {
			std::istringstream iss(input);
			if (iss >> num1 >> op) {
				if (op == '~') {
					num2 = 0;
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

		void calculate() {
			if (op) {
				double result = op->compute(num1, num2);
				if (std::isnan(result)) {
					std::cout<<"Result is undefined\n";
				}
				else {
					std::cout<<"Result: "<<result<<"\n";
				}
			}
		}

		void run() {
			std::string input;
			
			while (true) {
				std::cout<<"Enter an expression (or 'exit' to quit): \n";
				std::getline(std::cin, input);
				if (input == "exit") {
					break;
				}

				double num1, num2;
				char op;
				if (!processInput(input, num1, op, num2)) {
					continue;
				}

				std::unique_ptr<Operations> operation = getOperation(op);
				if (!operation) {
					continue;
				}

				try {
					double result = operation->compute(num1, num2);
					std::cout<<"Result: "<<result<<"\n";
				}
				catch (const std::exception& e) {
					std::cout<<e.what()<<"\n";
				}
				
			}
			std::cout<<"Calculator Exited. Goodbye\n";
		}
};
#endif // !CALCULATOR_H