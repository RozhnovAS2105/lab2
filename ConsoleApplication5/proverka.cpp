#include "proverka.h"

void clearBuffer() {
	cin.clear();
	cin.ignore(1024, '\n');
}

void printMenu() {
	cout << "1. Добавить трубу" << endl
		<< "2. Добавить КС" << endl
		<< "3. Посмотреть информацию про объекты" << endl
		<< "4. Измените трубу" << endl
		<< "5. Измените КС" << endl
		<< "6. Сохранить в файл" << endl
		<< "7. Загрузить из файла" << endl
		<< "8. Найти трубу по фильтру" << endl
		<< "9. Найти кс по фильтру" << endl
		<< "10. Удаление трубы" << endl
		<< "11. Удаление КС" << endl
		<< "0. ВЫХОД" << endl;
}

bool checkPipeByInRepair(const Pipe& p, bool parametr) {
	return p.getInRepair() == parametr;
}


bool checkByPercent(const Station& s, double parametr) {
	return parametr / 100.0 >= 1.0 - (double)s.getWorkshopInWork() / (double)s.getWorkshop();
}

set<int> GetIdByUserinput() {
	set <int> vvodId;
	string id, name;
	char ch;
	clearBuffer();
	cout << "Пропишите ID через пробел :";
	getline(cin, name);

	for (int i = 0; i < name.size(); i++) {
		ch = name[i];
		if (isdigit(ch)) {
			id += ch;
		}
		else {
			if (id != "") {
				vvodId.emplace(stoi(id));
				id = "";
			}
		}
	}
	if (id != "") {
		vvodId.emplace(stoi(id));
		id = "";
	}
	return vvodId;
}