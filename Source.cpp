#include <iostream>

using namespace std;

int main() {
    const int numRows = 8;
    const int numCols = 13;

    char arr[numRows][numCols] = {
        {'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', ' '},   // 1 row
        {'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', ' '},   // 2 row
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},   // 3 row (empty)
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1'}, // 4 row
        {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},    // 6 row
        {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'}    // 7 row

    };

    // Printing the 2D array
    cout << "Array:" << endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
