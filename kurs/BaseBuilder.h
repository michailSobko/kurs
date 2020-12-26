#pragma once

#include "Car.h"
#include<fstream>
#include<iostream>
#include<string>
#include <vector>

using namespace std;

//класс-строитель
class BaseBuilder {
protected:
	Car car; // машина
public:
	BaseBuilder();

	// виртуальные методы для переопределения в нужном класс=
	virtual void SetModel() {};
	virtual void SetTrunkRoof() {};
	virtual void SetHeatingMirrors() {};
	virtual void SetHeatingSeats() {};
	virtual void SetAKPP() {};
	
	// установка всех параметров
	void SetColor(string color);
	void SetEngineType(string engineType);
	void SetEngineVolume(double engineVolume);
	void SetDimention(string dimention);
	void SetYear(int yesr);
	void SetDoorCount(int doorCount);
	void SetMark(string mark);
	void SetModelavto(string modelavto);
	void SetVolumeTrunk(double volumeTrunk);

	

	virtual void PrintDifference() = 0; // функция вывода особенности

	// функции вывода параметров
	void PrintModelavto();
	void PrintModel();
	void PrintColor();
	void PrintEngineType();
	void PrintEngineVolume();
	void PrintDimention();
	void PrintYear();
	void PrintDoorCount();
	void PrintMark();
	void PrintVolumeTrunk();

	virtual Car GetAndSave() = 0; // получение и сохранение машины
	virtual bool GetInFile(ifstream &in) = 0; // считывание из файла
	virtual void Print() = 0; // вывод
	virtual void Read() = 0; // считывание
	
	~BaseBuilder();
};

