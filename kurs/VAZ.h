#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include "BaseBuilder.h"

// ваз - содержит только переопределённые  методы
class VAZ: public BaseBuilder {
public:
	VAZ();
	void SetModel();
	void SetTrunkRoof();

	Car GetAndSave();
	bool GetInFile(ifstream &in);
	void Print();
	void Read();
	void PrintDifference();
	~VAZ();
};

