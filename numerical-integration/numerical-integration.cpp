// https://github.com/ejalowiec/nm-numerical-integration

#include <iostream>

// define your function
#define FUNCTION x * x * x + 2

using namespace std;

double linearFunction(float);
double ractangleMethod(unsigned int, float, float);
double trapezoidalRule(unsigned int, float, float);

int main() {
	unsigned int subintervals = NULL;
	float a_interval, b_interval = NULL;
	cout << "Please enter the number of subintervals: "; cin >> subintervals;
	cout << "Please enter the start of the interval: "; cin >> a_interval;
	cout << "Please enter the end of the interval: "; cin >> b_interval;
	cout << endl;

	cout << "Rectangle method (simple: n = 1): " << ractangleMethod(subintervals, a_interval, b_interval) << endl;
	cout << "Rectangle method (compound: n = 550): " << ractangleMethod(550, a_interval, b_interval) << endl;
	cout << "Trapezoidal rule (simple: n = 1): " << trapezoidalRule(subintervals, a_interval, b_interval) << endl;
	cout << "Trapezoidal rule (compound: n = 550): " << trapezoidalRule(550, a_interval, b_interval) << endl;
}

double linearFunction(float x) {
	return FUNCTION;
}

double ractangleMethod(unsigned int n_interval, float a_interval, float b_interval) {
	double dx = (b_interval - a_interval) / n_interval;
	double area = 0.0;
	double interval = a_interval + dx;

	for (int i = 0; i < n_interval; ++i) {
		area += dx * linearFunction(interval);
		interval += dx;
	}
	return area;
}

double trapezoidalRule(unsigned int n_interval, float a_interval, float b_interval) {
	double dx = (b_interval - a_interval) / n_interval;
	double area = 0.0;
	double interval = a_interval;

	for (int i = 0; i < n_interval; ++i) {
		area += dx * (linearFunction(interval) + linearFunction(interval + dx)) / 2;
		interval += dx;
	}
	return area;
}
