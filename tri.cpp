#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArray(int arr[], int size, bool ascending) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void printMenu() {
    cout << "\n1001 A Sort Odyssey" << endl;
    cout << "1 - Start (displays list of 1001 random integers)" << endl;
    cout << "2 - Sort in ascending order" << endl;
    cout << "3 - Sort in descending order" << endl;
    cout << "4 - Quit Program" << endl;
}

void generateArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10001; // Random numbers between 0 and 9999
    }
}

bool inputValidation() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    const int ARRAY_SIZE = 1000;
    int *array = new int[ARRAY_SIZE];
    bool arrayInitialized = false;

    srand(static_cast<unsigned int>(time(nullptr)));

    int choice;

    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (!inputValidation()) {
            cout << "\nInvalid input. Please enter an integer." << endl;
            continue;
        }

        if (!arrayInitialized && (choice == 2 || choice == 3)) {
            cout << "\nPlease start by generating the array (Option 1) or quit (Option 4)." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                generateArray(array, ARRAY_SIZE);
                arrayInitialized = true;
                cout << "\nOriginal Array:" << endl;
                printArray(array, ARRAY_SIZE);
                break;
            case 2:
                sortArray(array, ARRAY_SIZE, true);
                cout << "\nSorted in ascending order:" << endl;
                printArray(array, ARRAY_SIZE);
                break;
            case 3:
                sortArray(array, ARRAY_SIZE, false);
                cout << "\nSorted in descending order:" << endl;
                printArray(array, ARRAY_SIZE);
                break;
            case 4:
                cout << "Goodbye\n" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    delete[] array;
    return 0;
}
