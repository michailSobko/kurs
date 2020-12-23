#include "stdafx.h"
#include "Kia.h"


Kia::Kia()
{
}

// мен€ем модель
void Kia::SetModel() {
	car.model = "Kia";
}

// мен€ем установку особого параметра
void Kia::SetHeatingMirrors() {
	car.heatingMirrors = true;
}

// считывание из файла
bool Kia::GetInFile(ifstream &in) {
	car.model = "Kia";
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
void Kia::Print() {
	cout << endl;
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
void Kia::Read() {
	string color, dimention, mark, engineType;
	int year, doorCount;
	double engineVolume, VolumeTrunk;

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
	SetHeatingMirrors();
}

// изменение вывода особенности
void Kia::PrintDifference() {
	cout << "ќсобенность: возможность установки подогрева зеркал заднего вида" << endl;
}

// сохранение в файл и вывод на экран
Car Kia::GetAndSave() {
	Print();
	ofstream out("kia.txt", ios::app);

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

Kia::~Kia()
{
}
