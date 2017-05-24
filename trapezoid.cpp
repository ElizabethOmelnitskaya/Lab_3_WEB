#include <iostream>
#include <fstream>
#include <math.h>
#include "trapezoid.h"

using namespace std;

void Trapezoid::changeSize(double times){
	if (times > 0) {
		side1 *= times;
		side2 *= times;
		base1 *= times;
		base2 *= times;
	}
	else if (times < 0) {
		times = -times;
		side1 /= times;
		side2 /=  times;
		base1 /= times;
		base2 /=  times;
	}
}
double Trapezoid::Per(){ return side1 + side2 + base1 + base2; }
double Trapezoid::Area(){ return ((base1 + base2) / 2)*height(); }
double Trapezoid::height(){return sqrt(pow(side1, 2) - pow(((pow(base1 - base2, 2) + pow(side1, 2) - pow(side2, 2)) / (2 * (base1 - base2))), 2)); }
double Trapezoid::midline() { return (base1 + base2) / 2; }

double Trapezoid::coef_basess() const { return base1 / base2; }
double Trapezoid::coef_sides() const { return side1 / side2; }
bool Trapezoid::simplesimilarity(Trapezoid const& tr){
	return
		(coef_basess() == tr.coef_basess() && coef_sides() == tr.coef_sides())||
		(1/coef_basess()== tr.coef_basess()&& coef_sides()==tr.coef_sides())||
		(coef_basess() == tr.coef_basess() && 1/coef_sides() == tr.coef_sides())||
		(1/coef_basess() == tr.coef_basess() && 1/coef_sides() == tr.coef_sides())
		;
}

Trapezoid::Trapezoid(double _side1, double _side2, double _base1, double _base2) {
	side1 = _side1;
	side2 = _side2;
	base1 = _base1;
	base2 = _base2;
}