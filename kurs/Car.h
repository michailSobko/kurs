#pragma once
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

// машина
class Car {
public:
	string modelavto = ""; // модель 
	string color = ""; // цвет
	string engineType = ""; // тип двигателя
	double engineVolume = 0; // объём двигателя
	string dimention = ""; // габариты
	int year = 0; // год прозводства
	int doorCount = 0; // количество дверей
	string model = ""; // марка
	string mark = ""; // марка шин
	double VolumeTrunk = 0; // объём багажника

	bool TrunkRoof = false; // возвожность установить багажник на крыше(только для ВАЗ-а)
	bool heatingMirrors = false; // возможность подогрева зеркал (KIA)
	bool heatingSeats = false; // возможность подогрева сидений(Nissan)
	bool AKPP = false; // установка АКРР

	Car();
	~Car();
};

