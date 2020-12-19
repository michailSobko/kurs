#pragma once
#include "BaseBuilder.h"

// киа - содержит только переопределённые  методы
class Kia : public BaseBuilder {
public:
	Kia();
	void SetModel();
	void SetHeatingMirrors();

	bool GetInFile(ifstream &in);
	void Print(); 
	Car GetAndSave();
	void Read();
	void PrintDifference();

	~Kia();
};

