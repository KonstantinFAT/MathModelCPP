#include <iostream>;
#include <vector>;
#include <cmath>;
#include <iomanip>;

using namespace std;

class Cell {
public:
	// ���� ������
	double x;
	double y;
	double t;
	double C = 0; // ��������� ������� - ������������ ���� � ������ ������� 0 ������ �� ���� ����� 0 
	// ������
};

int main() {
	// ���������
	double D = 0.1;
	double tay = 0.1;
	double h = 1;
	int N = 10;

	// ���� ������������
	double X, Y; // ������ ����
	cin >> X >> Y;
	vector <vector<Cell>> concentration_field(X, vector<Cell>(Y));

	// �������� �����������
	double X_source, Y_source, C_source;
	cin >> X_source >> Y_source >> C_source;
	concentration_field[X_source][Y_source].C = C_source;
	
	// �������� ������� (� ������� ����� ���������) (����� �����������)
	for (int n = 0; n < N; n++) {
		for (int i = 1; i < X - 1; i++) {
			for (int j = 1; j < Y - 1; j++) {
				concentration_field[i][j].C = concentration_field[i][j].C + D * tay * (concentration_field[i + 1][j].C - 2 * concentration_field[i][j].C + concentration_field[i - 1][j].C) / pow(h, 2);
				concentration_field[i][j].C = concentration_field[i][j].C + D * tay * (concentration_field[i][j + 1].C - 2 * concentration_field[i][j].C + concentration_field[i][j - 1].C) / pow(h, 2);
			}
		}
	}

	// �����
	for (int i = 0; i < concentration_field.size(); i++) {
		for (int j = 0; j < concentration_field[i].size(); j++) {
			cout << setprecision(2) << setw(7) << concentration_field[i][j].C << " ";;
		}
		cout << endl;
	}
	return 0;
}