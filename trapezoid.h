#pragma once

class Trapezoid {
//private:
	//double side1, side2, base1, base2; // base1, base2 - ���������
	                                   //side1, side2 - ������� �������
public:
	double side1, side2, base1, base2;
	void initialize();
	void print();
	void changeSize(double times); // ��������� ������ � ������������ ���-�� ���
	double Per(); // ����� ���������� ��������� � �������
	double Area(); // ����� ���������� ��������� � �������
	double coef_basess() const;
	bool simplesimilarity(Trapezoid const& tr); // ������� �� ������ �������� ������
	double coef_sides() const;
	double midline();// ����� ���������� ������� ����� 
	double height(); // ����� ���������� ������

	Trapezoid(double, double, double, double);

};