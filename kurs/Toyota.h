#pragma once
#include "BaseBuilder.h"

// тойота - содержит только переопределённые  методы
class Toyota : public BaseBuilder {
public:
	Toyota();
	void SetModel();
	void SetAKPP();

	bool GetInFile(ifstream &in);
	void Print();
	void Read();
	void PrintDifference();

	Car GetAndSave(); 
	~Toyota();
};

