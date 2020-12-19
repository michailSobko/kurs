#include "stdafx.h"
#include "VAZ.h"


VAZ::VAZ()
{
}

// меняем модель
void VAZ::SetModel() {
	car.model = "ВАЗ";
}

// меняем установку особого параметра
void VAZ::SetTrunkRoof() {
	car.TrunkRoof = true;
}

// считывание из файла
bool VAZ::GetInFile(ifstream &in) {
	car.model = "ВАЗ";
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
void VAZ::Print() {
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
void VAZ::Read() {
	string color, dimention, mark, engineType;
	int year, doorCount;
	double engineVolume, VolumeTrunk;

	cout << "Введите цвет: ";
	cin >> color;

	SetColor(color);

	cout << "Введите тип двигателя: ";
	cin >> engineType;
	SetEngineType(engineType);

	cout << "Введите объём двигателя: ";
	cin >> engineVolume;
	SetEngineVolume(engineVolume);

	cout << "Введите габариты: ";
	cin >> dimention;
	SetDimention(dimention);

	cout << "Введите год выпуска: ";
	cin >> year;
	SetYear(year);

	cout << "Введите количество дверей: ";
	cin >> doorCount;
	SetDoorCount(doorCount);

	cout << "Введите марку шин: ";
	cin >> mark;
	SetMark(mark);

	cout << "Введите объём багажника: ";
	cin >> VolumeTrunk;
	SetVolumeTrunk(VolumeTrunk);

	SetModel();
	SetTrunkRoof();
}

// изменение вывода особенности
void VAZ::PrintDifference() {
	cout << "Особенность: возможность установки багажника на крышу" << endl;
}


// сохранение в файл и вывод на экран
Car VAZ::GetAndSave() {
	Print();
	ofstream out("ВАЗ.txt", ios::app);

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

VAZ::~VAZ()
{
}
