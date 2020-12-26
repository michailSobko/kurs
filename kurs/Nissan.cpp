#include "stdafx.h"
#include "Nissan.h"


Nissan::Nissan()
{
}

// мен€ем модель
void Nissan::SetModel() {
	car.model = "Nissan";
}

// мен€ем установку особого параметра
void Nissan::SetHeatingSeats() {
	car.heatingSeats = true;
}

// считывание из файла
bool Nissan::GetInFile(ifstream &in) {
	car.model = "Nissan";
	
	if (!(in >> car.modelavto))
		return false;

	if (!(in >> car.color))
		return false;

	if (!(in >> car.engineType))
		return false;

	if (!(in >> car.engineVolume))
		return false;

	if (!(in >> car.dimention))
		return false;

	if (!(in >> car.year))
		return false;

	if (!(in >> car.doorCount))
		return false;

	if (!(in >> car.mark))
		return false;

	if (!(in >> car.VolumeTrunk))
		return false;

	if (!(in >> car.TrunkRoof))
		return false;

	if (!(in >> car.heatingMirrors))
		return false;

	if (!(in >> car.heatingSeats))
		return false;

	if (!(in >> car.AKPP))
		return false;

	return true;
}

// вывод 
void Nissan::Print() {
	cout << endl;
	PrintModelavto();
	PrintModel();
	PrintColor();
	PrintEngineType();
	PrintEngineVolume();
	PrintDimention();
	PrintYear();
	PrintDoorCount();
	PrintMark();
	PrintVolumeTrunk();
	PrintDifference();
	cout << endl;
}

// чтение с клавиатуры
void Nissan::Read() {
	string color, dimention, mark, engineType, modelavto;
	int year, doorCount;
	double engineVolume, VolumeTrunk;
	
	cout << "¬ведите модель: ";
	cin >> modelavto;
	SetModelavto(modelavto);

	cout << "¬ведите цвет: ";
	cin >> color;

	SetColor(color);

	cout << "¬ведите тип двигател€: ";
	cin >> engineType;
	SetEngineType(engineType);

	cout << "¬ведите объЄм двигател€: ";
	cin >> engineVolume;
	SetEngineVolume(engineVolume);

	cout << "¬ведите габариты: ";
	cin >> dimention;
	SetDimention(dimention);

	cout << "¬ведите год выпуска: ";
	cin >> year;
	SetYear(year);

	cout << "¬ведите количество дверей: ";
	cin >> doorCount;
	SetDoorCount(doorCount);

	cout << "¬ведите марку шин: ";
	cin >> mark;
	SetMark(mark);

	cout << "¬ведите объЄм багажника: ";
	cin >> VolumeTrunk;
	SetVolumeTrunk(VolumeTrunk);

	SetModel();
	SetHeatingSeats();
}

// изменение вывода особенности
void Nissan::PrintDifference() {
	cout << "ќсобенность: возможность установки подогрева сидений" << endl;
}

// сохранение в файл и вывод на экран
Car Nissan::GetAndSave() {
	Print();
	ofstream out("nissan.txt", ios::app);
	
	out << car.modelavto << " ";
	out << car.color << " ";
	out << car.engineType << " ";
	out << car.engineVolume << " ";
	out << car.dimention << " ";
	out << car.year << " ";
	out << car.doorCount << " ";
	out << car.mark << " ";
	out << car.VolumeTrunk << " ";
	out << (car.TrunkRoof ? "1" : "0") << " ";
	out << (car.heatingMirrors ? "1" : "0") << " ";
	out << (car.heatingSeats ? "1" : "0") << " ";
	out << (car.AKPP ? "1" : "0") << endl;

	out.close();

	return car;
}

Nissan::~Nissan()
{
}
