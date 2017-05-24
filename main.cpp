#include "trapezoid.h"
#include<conio.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int trapecParamCount = 4;

char *splitter = ","; // разделитель

const char *changeSize = "R";
const char *perimeterOfTrap = "P";
const char *areaOfTrap = "A";
const char *midlineOfTrap = "M";
const char *heightOfTrap = "H";
const char *similarityOfTrap = "S";
const char *infoAboutTrap = "I";

void writeInfo(Trapezoid *trapec, ostream *stream){
	*stream << "<p><strong>Side1:</strong> " << trapec->side1 << "<br>"; 
	*stream << "<strong>Side2:</strong> " << trapec->side2 << "<br>";
	*stream << "<strong>Base1:</strong> " << trapec->base1 << "<br>";
	*stream << "<strong>Base2:</strong> " << trapec->base2 << "</p>";
}

int getArgCount(char *string, char splitter){ //возвращает кол-во аргументов
	int count = 1;

	for (int i = 0; i < strlen(string); i++)
		if (string[i] == splitter)
			count++;

	return count;
}

char** getArgFromString(char* string, char* splitter){
	int count = getArgCount(string, splitter[0]); // каунт равен кол-ву аргументов, вызываем функцию, которая их посчитает
	int j = 0;
	char *copyString = new char[256]{ NULL };			
	strcpy(copyString, string);							

	char** arg = new char*[count] { NULL };		// объявляем пустой массив, размером в наш каунт, который равен кол-ву аргументов 
	for (int i = 0; i < count; i++)
		arg[i] = new char[10]{ NULL };			//каждый элемент массив

	char *p = strtok(copyString, splitter);				//тут разбиваем строку по запятым на аргументы

	while (p != NULL) {
		strcpy(arg[j], p);						//пока р не пустая, копируем каждый из элементов в массив аргументов
		p = strtok(NULL, splitter);

		j++;
	}

	delete copyString;
	return arg;									//возвращаем наш массив аргументов
}

Trapezoid** Parse(int num, char**arg){ //заполняем массив трапеций
	Trapezoid **res = new Trapezoid*[num];
	for (int i = 0; i < num; i++){
		double side1 = atoi(arg[i*trapecParamCount]),
		       side2 = atoi(arg[i*trapecParamCount+1]),
			   base1 = atoi(arg[i*trapecParamCount + 2]),
			   base2 = atoi(arg[i*trapecParamCount + 3]);
		cout << side1 << " " << side2 << " " << base1 << " " << base2 << " ";
		res[i] = new Trapezoid(side1, side2, base1, base2);
	}
	
	return res;
}

int main(){
	char *queryString = getenv("QUERY_STRING");

	cout << "Content-type: text/html\n\n";
	cout << "<html><body>\n";
	cout << "<title>Lab</title>\n";

	cout << "<p>R - Resize <br>";
	cout << "P - Perimeter <br>";
	cout << "A - Area <br>";
	cout << "M - MidLine <br>";
	cout << "H - Height <br>";
	cout << "S - Similarity <br> ";
	cout <<"I - Print </p>";

	if (queryString){
		char **arg = getArgFromString(queryString, splitter); //строка аргументов

		int num = atoi(arg[0]),		//кол-во трапеций, задается первым
			count = getArgCount(queryString, splitter[0]);

		Trapezoid **trap = Parse(num, arg + 1);

		for (int i = 0; i < num; i++)
			writeInfo(trap[i], &cout); //вывод каждой трапеции

		int pointer = num * trapecParamCount + 1; //показывает номер аргумента, с которым мы работаем
		while (pointer < count){
			int index = atoi(arg[pointer++]) - 1;
			char *command = arg[pointer++];
			
			cout << "<p><strong>Trapezoid:</strong> " << (index + 1)
				<< ", <strong>command:</strong> " << command << "</p>";
			
			if (strcmp(command, changeSize) == 0) {	//тут мы проверяем равна ли наша команда любому из возможных вариантов.
				int percent = atoi(arg[pointer++]);
				trap[index]->changeSize(percent);
				cout << "<p>After increasing</p>";
				writeInfo(trap[index], &cout);
				}

			else if (strcmp(command, perimeterOfTrap) == 0) {
				cout << "<p><strong>Perimeter:</strong> "
					<< trap[index]->Per() << "</p>";
			}
			else if (strcmp(command, areaOfTrap) == 0) {
				cout << "<p><strong>Area:</strong> "
					<< trap[index]->Area() << "</p>";
			}
			else if (strcmp(command, heightOfTrap) == 0) {
				cout << "<p><strong>Height:</strong> "
					<< trap[index]->height() << "</p>";
			}
			else if (strcmp(command, midlineOfTrap) == 0) {
				cout << "<p><strong>Midline:</strong> "
					<< trap[index]->midline() << "</p>";
			}
			else if (strcmp(command, similarityOfTrap) == 0){

			}
			else if (strcmp(command, infoAboutTrap) == 0) {
				writeInfo(trap[index], &cout);
			}
			else {
				cout << "<p><strong>Incorrect command!</strong></p>";
			}
		}
	}

	cout << "</body></html>" << endl;
	return 0;
}