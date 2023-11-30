#include <iostream>;
#include <vector>;
#include <cmath>;
#include <iomanip>;

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
	// Константы
	double D = 0.1;
	double tay = 0.1;
	double h = 1;
	int N = 10;

	// Поле концентраций
	double X, Y; // Размер поля
	cin >> X >> Y;
	vector <vector<Cell>> concentration_field(X, vector<Cell>(Y));

	// Источник загрязнения
	double X_source, Y_source, C_source;
	cin >> X_source >> Y_source >> C_source;
	concentration_field[X_source][Y_source].C = C_source;
	
	// Конечный автомат (в будущем опишу клеточный) (метод расщепления)
	for (int n = 0; n < N; n++) {
		for (int i = 1; i < X - 1; i++) {
			for (int j = 1; j < Y - 1; j++) {
				concentration_field[i][j].C = concentration_field[i][j].C + D * tay * (concentration_field[i + 1][j].C - 2 * concentration_field[i][j].C + concentration_field[i - 1][j].C) / pow(h, 2);
				concentration_field[i][j].C = concentration_field[i][j].C + D * tay * (concentration_field[i][j + 1].C - 2 * concentration_field[i][j].C + concentration_field[i][j - 1].C) / pow(h, 2);
			}
		}
	}

	// Вывод
	for (int i = 0; i < concentration_field.size(); i++) {
		for (int j = 0; j < concentration_field[i].size(); j++) {
			cout << setprecision(2) << setw(7) << concentration_field[i][j].C << " ";;
		}
		cout << endl;
	}
	return 0;
}