#pragma once
#ifndef OPERATIONS_H

#define OPERATIONS_H

#include <limits>
#include <math.h>
#include <stdexcept>
class Operations {
	public:
		virtual double compute(double num1, double num2) = 0;
};

class Add : public Operations {
	public:
		double compute(double num1, double num2) {
			return num1 + num2;
		}
};

class Subtract : public Operations {
	public:
		double compute(double num1, double num2) {
			return num1 - num2;
		}
};

class Multiply : public Operations {
	public:
		double compute(double num1, double num2) {
			return num1 * num2;
		}
};

class Divide : public Operations {
	public:
		double compute(double num1, double num2) {
			if (num2 == 0) {
				throw std::runtime_error("Cannot divide by zero");
			}
			return num1 / num2;
		}
};

class Modulus : public Operations {
	public:
		double compute(double num1, double num2) {
			return (int)num1 % (int)num2;
		}
};

class Power : public Operations {
	public:
		double compute(double num1, double num2) {
			return pow(num1, num2);
		}
};

class SquareRoot : public Operations {
	public:
		double compute(double num1, double num2) {
			if (num1 < 0) {
				throw std::runtime_error("Cannot take square root of a negative number");
			}
			return sqrt(num1);
		}
};

#endif // !OPERATIONS_H