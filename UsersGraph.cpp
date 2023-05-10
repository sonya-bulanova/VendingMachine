#include <iostream>
#include <string>
#include <vector>

#define SIZE 100
#define NAMELENGTH 32
typedef char StringName[NAMELENGTH];
//Граф задавать методом матриц

class GraphHandshake {
public:

	struct Person {
		Person();
		Person(const StringName Name, int id);
		Person(const Person& Other);

		Person& operator=(const Person& Other);
		bool operator==(const Person& Other);

		StringName Name;
		int id; //ака номер человека -- номер вершины
	};
	GraphHandshake();
	~GraphHandshake();
	void AddNewPerson(const StringName Name); // добавить вершину
	void DeletePerson(const StringName Name); // удалить вершину
	void AddHandshake(const StringName Name1, const StringName Name2); // добавить связь
	void DeleteHandshake(const StringName Name1, const StringName Name2); // удалить связь
	void AllThreeHandshakes(); //все рукопожатия менее чем через три связи

private:
	bool are_friends(const Person& p1, const Person& p2);
	int HandshakeMatrix[SIZE][SIZE]; //матрица, содержащая контакты людей
	std::vector<GraphHandshake::Person>person; //массив людей -- ака вершин
	std::vector<bool>BusyID; // массив занятых айди -- типа 1 юзер -- первое айди...
	Person FindByName(const StringName name);
};

GraphHandshake::Person& GraphHandshake::Person::operator=(const Person& other) {
	strcpy_s(Name, other.Name);
	id = other.id;
	return *this;
}

GraphHandshake::Person::Person(){
	this->id = -1;
}

GraphHandshake::Person::Person(const StringName Name, int id) : id(id) {
	strcpy_s(this->Name, Name);
}

GraphHandshake::Person::Person(const Person& Other) {
	strcpy_s(this->Name, Other.Name);
	this->id = Other.id;
}

bool GraphHandshake::Person::operator==(const Person & Other) {
	return Other.id == this->id;
}

GraphHandshake::GraphHandshake() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			HandshakeMatrix[i][j] = 0;
		}
	}
	for (int i = 0; i < SIZE; i++) {
		BusyID.push_back(false);
	}
}

GraphHandshake::~GraphHandshake() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			HandshakeMatrix[i][j] = 0;
		}
	}
}

void GraphHandshake::AddNewPerson(const StringName Name) {
	Person human = FindByName(Name);
	if (human.id >= 0) {
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		if ( !BusyID[i] ) {
			break;
		}
		BusyID[i] = true;
		person.push_back(Person(Name, i));
	}	
}

void GraphHandshake::DeletePerson(const StringName Name) {
	Person human = FindByName(Name);
	if (human.id < 0) {
		return;
	}
	int idx = human.id;
	BusyID[human.id] = false;
	for (size_t i = 0; i < person.size(); i++) {
		HandshakeMatrix[i][human.id] = 0;
		HandshakeMatrix[human.id][i] = 0;
	}
	std::vector<GraphHandshake::Person>::iterator iter = person.begin() + human.id;
	person.erase(iter);
}

void GraphHandshake::AddHandshake(const StringName Name1, const StringName Name2) {
	Person p1 = FindByName(Name1);
	Person p2 = FindByName(Name2);
	if (p1.id < 0 || p2.id < 0) {
		return;
	}
	HandshakeMatrix[p1.id][p2.id] = 1;
	HandshakeMatrix[p2.id][p1.id] = 1;
}

void GraphHandshake::DeleteHandshake(const StringName Name1, const StringName Name2) {
	Person p1 = FindByName(Name1);
	Person p2 = FindByName(Name2);
	if (p1.id < 0 || p2.id < 0) {
		return;
	}
	HandshakeMatrix[p1.id][p2.id] = 0;
	HandshakeMatrix[p2.id][p1.id] = 0;
}

void GraphHandshake::AllThreeHandshakes() {
	int WavesLevel[SIZE];
	for (int i = 0; i < SIZE; i++) {
		WavesLevel[i] = -1;
	}
	WavesLevel[0] = 0;
	std::vector<int> queue;
	queue.push_back(0);

	while (queue.size()) {
		int currentManIndex = queue[0];
		std::vector<int>::iterator iter = queue.begin();
		queue.erase(iter);
		for (size_t i = 0; i < person.size(); i++) {
			if (are_friends(person[currentManIndex], person[i]) &&
				WavesLevel[i] == -1)
			{
				WavesLevel[i] = WavesLevel[currentManIndex] + 1;
				queue.push_back(i);
			}
		}
	}

	for (size_t i = 0; i < person.size(); i++) {
		for (size_t j = i + 1; j < person.size(); j++) {
			if (abs(WavesLevel[i] - WavesLevel[j]) <= 3) {
				std::cout << person[i].Name << " " << person[j].Name << std::endl;
			}
		}
	}
}

bool GraphHandshake::are_friends(const Person& p1, const Person& p2) {
	return HandshakeMatrix[p1.id][p2.id] == 1;
}

GraphHandshake::Person GraphHandshake::FindByName(const StringName name) {
	for (size_t i = 0; i < person.size(); i++) {
		if (!strcmp(name, person[i].Name)) {
			return person[i];
		}
	}
	return Person();
}

int main() {
	GraphHandshake gr;

	gr.AddNewPerson("Oleg");
	gr.AddNewPerson("Kostya");
	gr.AddNewPerson("Misha");
	gr.AddNewPerson("Vika");
	gr.AddNewPerson("Lesha");

	gr.DeletePerson("Vika");
	gr.AddNewPerson("Anya");

	gr.AddHandshake("Oleg", "Kostya");
	gr.AddHandshake("Kostya", "Misha");
	gr.AddHandshake("Misha", "Anya");
	gr.AddHandshake("Anya", "Lesha");

	gr.AllThreeHandshakes();

}
