#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, int rowCount, int colCount, int currentRow);
void SwapRows(int** a, const int row1, const int row2, const int colCount);
void Calculate(int** a, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

int main() {
    srand((unsigned)time(NULL));

    int Low = -31;
    int High = 54;
    int rowCount = 9;
    int colCount = 5;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    Sort(a, rowCount, colCount, 0);
    Print(a, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calculate(a, rowCount, colCount, S, k);

    cout << "Sum : " << S << endl;
    cout << "Count: " << k << endl;

    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, int rowCount, int colCount, int currentRow) {
    if (currentRow == rowCount - 1)
        return;

    for (int i = 0; i < rowCount - currentRow - 1; i++) {
        if (a[i][0] > a[i + 1][0]) {
            SwapRows(a, i, i + 1, colCount);
        }
        else if (a[i][0] == a[i + 1][0] && a[i][1] < a[i + 1][1]) {
            SwapRows(a, i, i + 1, colCount);
        }
        else if (a[i][0] == a[i + 1][0] && a[i][1] == a[i + 1][1] && a[i][3] > a[i + 1][3]) {
            SwapRows(a, i, i + 1, colCount);
        }
    }

    Sort(a, rowCount, colCount, currentRow + 1);
}

void SwapRows(int** a, const int row1, const int row2, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        int temp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = temp;
    }
}

void Calculate(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j) {
    if (i == rowCount)
        return;

    if (a[i][j] > 0 && a[i][j] % 5 != 0) {
        S += a[i][j];
        k++;
        a[i][j] = 0;
    }

    if (j < colCount - 1)
        Calculate(a, rowCount, colCount, S, k, i, j + 1);
    else
        Calculate(a, rowCount, colCount, S, k, i + 1, 0);
}
