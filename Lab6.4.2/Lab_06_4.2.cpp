#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int* create(int n, const int Low, const int High) {
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
    return a;
}

void print(int* a, int n, int index = 0) {
    if (index >= n) {
        cout << endl;
        return;
    }

    cout << setw(5) << a[index];
    print(a, n, index + 1);
}

int Min(int* a, const int size, int index = 0, int min = INT_MAX) {
    if (index >= size) {
        return min;
    }

    if (abs(a[index]) < abs(min)) {
        min = a[index];
    }

    return Min(a, size, index + 1, min);
}

int sumOfModsAfterZero(int* arr, int size, int index = 0, int sum = 0, bool foundZero = false) {
    if (index >= size) {
        return sum;
    }

    if (!foundZero) {
        foundZero = (arr[index] == 0);
    }
    else {
        sum += abs(arr[index]);
    }

    return sumOfModsAfterZero(arr, size, index + 1, sum, foundZero);
}

void rearrangeArray(int a[], int size, int index = 0) {
    if (index >= size) {
        return;
    }

    int* rearrangedArray = new int[size];
    int i = 0;

    for (int j = index; j < size; j += 2) {
        rearrangedArray[i] = a[j];
        i++;
    }

    for (int j = index + 1; j < size; j += 2) {
        rearrangedArray[i] = a[j];
        i++;
    }

    for (int j = index; j < size; ++j) {
        a[j] = rearrangedArray[j - index];
    }

    delete[] rearrangedArray;

    rearrangeArray(a, size, index + 1);
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    srand((unsigned)time(NULL));
    int Low = -100;
    int High = 100;

    int* a = create(n, Low, High);

    cout << "Array: ";
    print(a, n);
    cout << "min = " << abs(Min(a, n)) << endl;
    if (Min(a, n) == 0) {
        cout << "Sum of absolute values after the first zero: " << sumOfModsAfterZero(a, n) << endl;

    }
    else {
        cout << "sumOfModsAfterZero is impossible to find because there are no 0 in this array" << endl;
    }
    rearrangeArray(a, n);
    cout << "Rearranged array: ";
    print(a, n);

    delete[] a;
    return 0;
}