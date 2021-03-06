
// CarsBuilder.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h";
#include <vector>
#include <locale.h>
#include <cstdlib>
#include "BaseBuilder.h";

#include "Kia.h";
#include "Nissan.h";
#include "Toyota.h";
#include "VAZ.h";

using namespace std;

// добавление ваза
void CreateVAZ(vector<BaseBuilder*> &cars) {
	VAZ vaz;
	vaz.Read();

	cars.push_back(new VAZ(vaz));

}

void Edit(vector<BaseBuilder*>& cars) {
	int i,number;
	string color, dimention, mark, engineType, modelavto;
	int year, doorCount;
	double engineVolume, VolumeTrunk;
	cout << "Какой автомобиль вы хотите изменить ?" << endl;
	cin >> i;
	i--;
	cout << "Что хотите изменить?" << endl;
	cout << "1. модель автомобиля" << endl;
	cout << "2. цвет автомобиля" << endl;
	cout << "3. тип двигателя автомобиля" << endl;
	cout << "4. объем двигателя автомобиля" << endl;
	cout << "5. габариты автомобиля" << endl;
	cout << "6. год выпуска автомобиля" << endl;
	cout << "7. число дверей автомобиля" << endl;
	cout << "8. объем багажника автомобиля" << endl;
	cout << "9. марка шин " << endl;
	cout << "0. ВЫход" << endl;
	cin >> number;
	while (number < 0 || number > 9) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некорректный пункт. Введите ещё раз: ";
		cin >> number; // считываем пункт меню заново
	}
	cout << "Напишите новый параметр" << endl;
	switch (number) {
	case 1:
		cin >> modelavto;
		cars[i]->SetModelavto(modelavto);
		break;
	case 2:
		cin >> color;
		cars[i]->SetColor(color);
		break;
	case 3:
		cin >> engineType;
		cars[i]->SetEngineType(engineType);
		break;
	case 4:
		cin >> engineVolume;
		cars[i]->SetEngineVolume(engineVolume);
		break;
	case 5:
		cin >> dimention;
		cars[i]->SetDimention(dimention);
		break;
	case 6:
		cin >> year;
		cars[i]->SetYear(year);
		break;
	case 7:
		cin >> doorCount;
		cars[i]->SetDoorCount(doorCount);
		break;
	case 8:
		cin >> VolumeTrunk;
		cars[i]->SetVolumeTrunk(VolumeTrunk);
		break;
	case 9:
		cin >> mark;
		cars[i]->SetMark(mark);
		break;

	
	}
	ofstream out("kia.txt");
	out.close();
	out.open("ВАЗ.txt");
	out.close();
	out.open("toyota.txt");
	out.close();
	out.open("nissan.txt");
	out.close();
	for (int j = 0; j < cars.size(); j++)
		cars[j]->GetAndSave();

}

void Delete(vector<BaseBuilder*>& cars) {
	
	cout << "Введите № автомобиля, который нужно удалить";
	int i;
	cin >> i;

	while (i < 1 || i > cars.size()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некорректный пункт. Введите ещё раз: ";
		cin >> i; // считываем пункт меню заново
	}
	i--;
	cars.erase(cars.begin() + i);
	ofstream out("kia.txt");
	out.close();
	out.open("ВАЗ.txt");
	out.close();
	out.open("toyota.txt");
	out.close();
	out.open("nissan.txt");
	out.close();
	for (int j = 0; j < cars.size(); j++)
		cars[j]->GetAndSave();
}



// добавление kia
void CreateKia(vector<BaseBuilder*> &cars) {
	Kia kia;
	kia.Read();

	cars.push_back(new Kia(kia));
}

// добавление nissan 
void CreateNissan(vector<BaseBuilder*> &cars) {
	Nissan nissan;
	nissan.Read();

	cars.push_back(new Nissan(nissan));
}

// добавление toyota
void CreateToyota(vector<BaseBuilder*> &cars) {
	Toyota toyota;
	toyota.Read();

	cars.push_back(new Toyota(toyota));
}

// создание машины
void Create(vector<BaseBuilder*> &cars) {
	cout << "Какой автомобиль хотите создать? " << endl;
	cout << "1. ВАЗ" << endl;
	cout << "2. Kia" << endl;
	cout << "3. Nissan" << endl;
	cout << "4. Toyota" << endl;
	int item;

	cin >> item; // считываем пункт меню

	// обрабатываем некорректный ввод
	while (item < 1 || item > 4) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некорректный пункт. Введите ещё раз: ";
		cin >> item; // считываем пункт меню заново
	}


	// в зависимости от выбранного пункта выполняем действие
	switch (item) {
	case 1:
		CreateVAZ(cars);
		break;

	case 2:
		CreateKia(cars);
		break;

	case 3:
		CreateNissan(cars);
		break;

	case 4:
		CreateToyota(cars);
		break;
	}

	cars[cars.size() - 1]->GetAndSave();
}

// вывод всех машин
void Print(vector<BaseBuilder*> cars) {
	for (size_t i = 0; i < cars.size(); i++) {
		cout << "Текущий номер машины: " << (i + 1);
		cars[i]->Print();
	}
}

void ReadInFile(vector<BaseBuilder*> &cars) {
	int item;

	cout << "Вы хотите считать машины из файла(1) или начать с пустой базой(2)?" << endl;
	cin >> item;

	while (item < 1 || item > 2) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Некорректный пункт. Введите ещё раз: ";
		cin >> item;
	}

	if (item == 2) {
		// очистка всех файлов
		ofstream f("ВАЗ.txt");
		f.close();

		f.open("kia.txt");
		f.close();

		f.open("toyota.txt");
		f.close();

		f.open("nissan.txt");
		f.close(); 
		
		return;
	}
	
	// считывание из всех файлов всех машин
	ifstream f1("ВАЗ.txt");

	if (f1) {
		while (!f1.eof()) {
			VAZ vaz;
			if (vaz.GetInFile(f1))
				cars.push_back(new VAZ(vaz));
		}

		f1.close();
	}

	ifstream f2("kia.txt");

	if (f2) {
		while (!f2.eof()) {
			Kia kia;
			if (kia.GetInFile(f2))
				cars.push_back(new Kia(kia));
		}

		f2.close();
	}

	ifstream f3("toyota.txt");

	if (f3) {
		while (!f3.eof()) {
			Toyota toyota;
			if (toyota.GetInFile(f3))
				cars.push_back(new Toyota(toyota));
		}

		f3.close();
	}

	ifstream f4("nissan.txt");

	if (f4) {
		while (!f4.eof()) {
			Nissan nissan;
			if (nissan.GetInFile(f4))
				cars.push_back(new Nissan(nissan));
		}

		f4.close();
	}

	if (cars.size() > 0) {
		cout << "Считанные автомобили: " << endl << endl;
		Print(cars);
	}
	else
		cout << "База была пуста";

	system("pause"); // задерживаем экран
}

int main() {
	setlocale(LC_ALL, "Russian"); // задаём русский текст
	system("chcp 1251"); // настраиваем кодировку консоли
	vector<BaseBuilder*> cars;

	ReadInFile(cars);

	int item; // выбираемый пункт меню

	do {
		system("cls"); // очищаем экран
					   // выводим меню
		cout << "Что хотите сделать?" << endl;
		cout << "1. Создать автомобиль" << endl;
		cout << "2. Вывести автомобиль" << endl;
		cout << "3. Изменить автомобиль" << endl;
		cout << "4. Удалить автомобиль" << endl;
		cout << "5. Выход" << endl;
		cout << ">";
		cin >> item; 
		// считываем пункт меню
		// обрабатываем некорректный ввод
		while (item < 1 || item > 5) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Некорректный пункт. Введите ещё раз: ";
			cin >> item; // считываем пункт меню заново
		}

		// в зависимости от выбранного пункта выполняем действие
		switch (item) {
		case 1:
			Create(cars);
			break;

		case 2:
			Print(cars);
			break;
		case 3:
			Print(cars);
			Edit(cars);
			break;
		case 4:
			Print(cars);
			Delete(cars);
			break;
		}

		if (item != 5) {
			system("pause"); // задерживаем экран
		}
	} while (item != 5); // повторяем, пока не решим выйти

	return 0;
}