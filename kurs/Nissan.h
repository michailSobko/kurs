#pragma once
#include "BaseBuilder.h"

// ниссан - содержит только переопределённые  методы
class Nissan : public BaseBuilder {
public:
	Nissan();
	void SetModel();
	void SetHeatingSeats();

	Car GetAndSave(); 
	bool GetInFile(ifstream &in);
	void Print();
	void Read();
	void PrintDifference();

	~Nissan();
};

