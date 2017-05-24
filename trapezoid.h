#pragma once

class Trapezoid {
//private:
	//double side1, side2, base1, base2; // base1, base2 - основания
	                                   //side1, side2 - боковые стороны
public:
	double side1, side2, base1, base2;
	void initialize();
	void print();
	void changeSize(double times); // изменение сторон в определенное кол-во раз
	double Per(); // метод вычисления периметра и площади
	double Area(); // метод вычисления периметра и площади
	double coef_basess() const;
	bool simplesimilarity(Trapezoid const& tr); // подобна ли другая трапеция данной
	double coef_sides() const;
	double midline();// метод вычисления средней линии 
	double height(); // метод вычисления высоты

	Trapezoid(double, double, double, double);

};