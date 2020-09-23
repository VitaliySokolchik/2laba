#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Kotik {
private:
	int id = 0;
	string name, tmp, diognoz="инфекция";
public:
	friend class Veterinar;
	Kotik() {
		int defaultId = 1;
		id = defaultId;
	}
	Kotik(int number) {
		id = number;
	}
	int set_diognoses(string diog) {
		
		tmp = diog;
		return 0;
	}
	void nameSetter(string userName) {
		name = userName;
		return;
	}
	friend void print(Kotik&);
	~Kotik() {

	}
};

void print(Kotik& a) {

	cout << "Данные котика:\n"<< "Id:" << a.id << endl;
	cout << a.name<<endl;
}

class Veterinar {
public:
	int set_diognoz(Kotik& object) {
		object.diognoz = object.tmp;
		cout << "Диагноз котика:" << object.diognoz<<endl;
		return 0;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите имя котика\n";

    Kotik kotik;
	Veterinar v;
	string userName, diognoz;
	int id;

	cin >> userName;
	std::cout << "Введите диагноз котика\n";
	cin >> diognoz;
	cout << "=======================\n";
	kotik.nameSetter(userName);

	kotik.set_diognoses(diognoz);
	print(kotik);
	v.set_diognoz(kotik);
	cout << "=======================\n";
	Kotik kotiki[3];
	Veterinar vet;
	for (int i = 0; i < 3; i++) {
		cout << endl <<"Введите имя " << i + 1 << " котика" << endl;
		cin >> userName;
		kotiki[i].nameSetter(userName);
		cout << "Введите id " << i + 1 << " котика (1 < x < 100)" << endl;
		cin >> id;
		if (1 < id < 100)
		{
			string diag;
			cout << "Введите диагноз\n";
			cin >> diag;
			cout << "=======================\n";
			kotiki[i].set_diognoses(diag);
			print(kotiki[i]);
			vet.set_diognoz(kotiki[i]);
			cout << "=======================\n";
		}
	}
}