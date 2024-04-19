#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const int ROWS = 8;
const int COLS = 13;
const char EMPTY_SEAT = ' ';
const char OCCUPIED_SEAT = 'X';

// Function prototypes
int findRowIndex(char thisRow);
int findSeatIndex(int thisSeat);
void displaySeatChart(char seats[][COLS]);
bool reserveSeat(char seats[][COLS], int row, int column);

int main() {
    char seats[ROWS][COLS] = {
        {'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', EMPTY_SEAT}, // Row 1
        {'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', EMPTY_SEAT}, // Row 2
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Row 3 (Empty)
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1'},         // Row 4
        {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3'},         // Row 5
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},   // Row 6 (Empty)
        {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},         // Row 7
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}          // Row 8
    };

    // Display initial seating chart
    cout << "Initial Seating Chart:" << endl;
    displaySeatChart(seats);

    // Accept seat requests until all seats are filled or user signals to end
    while (true) {
        cout << "Enter seat (e.g., D11) or 'q' to quit: ";
        string input;
        getline(cin, input);

        if (input == "q") {
            cout << "Exiting program." << endl;
            break;
        }

        char row;
        int seatNumber;
        stringstream(input) >> row >> seatNumber;

        int rowIndex = findRowIndex(row);
        int seatIndex = findSeatIndex(seatNumber);

        if (rowIndex == -1 || seatIndex == -1) {
            cout << "Invalid seat. Please try again." << endl;
            continue;
        }

        if (!reserveSeat(seats, rowIndex, seatIndex)) {
            cout << "Seat " << input << " is already occupied. Please choose another seat." << endl;
            continue;
        }

        cout << "Seat " << input << " reserved successfully." << endl;

        // Display updated seating chart
        cout << "Updated Seating Chart:" << endl;
        displaySeatChart(seats);
    }

    return 0;
}

// Function to find the row index
int findRowIndex(char thisRow) {
    int rowIndex = -1; // Default value for error

    switch (thisRow) {
    case 'D':
        rowIndex = 0;
        break;
    case 'C':
        rowIndex = 1;
        break;
    case 'B':
        rowIndex = 6;
        break;
    case 'A':
        rowIndex = 7;
        break;
    }

    return rowIndex;
}

// Function to find the seat index
int findSeatIndex(int thisSeat) {
    if (thisSeat < 1 || thisSeat > COLS || (thisSeat == 13 && (thisSeat == 3 || thisSeat == 13))) {
        return -1; // Invalid seat index
    }
    else {
        return thisSeat - 1; // Adjust for zero-based indexing
    }
}

// Function to display the seating chart
void displaySeatChart(char seats[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << setw(2) << seats[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to reserve a seat
bool reserveSeat(char seats[][COLS], int row, int column) {
    if (seats[row][column] == OCCUPIED_SEAT) {
        return false; // Seat is already occupied
    }
    else {
        seats[row][column] = OCCUPIED_SEAT;
        return true;
    }
}
