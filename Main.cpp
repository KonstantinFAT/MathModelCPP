#include <iostream>;
#include <vector>

using namespace std;

class Cell {
public:
	// Поля класса
	double x;
	double y;
	double t;
	double C = 0; // Начальное условие - концентрация СДЯВ в момент времени 0 секунд на поле равна 0 
	// Методы
};

int main() {
	// Поле концентраций
	double X, Y; // Размер поля
	cin >> X >> Y;
	vector <vector<Cell>> concentration_field(X, vector<Cell>(Y));

	// Источник загрязнения
	double X_source, Y_source, C_source;
	cin >> X_source >> Y_source >> C_source;
	concentration_field[X_source][Y_source].C = C_source;

	// Вывод
	for (int i = 0; i < concentration_field.size(); i++) {
		for (int j = 0; j < concentration_field[i].size(); j++) {
			cout << concentration_field[i][j].C << " ";;
		}
		cout << endl;
	}
	return 0;
}