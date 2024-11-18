#include <iostream>
using namespace std;

int main() {
int n;
cout << "Enter the number of books: ";
cin >> n;
int arr[100];
cout << "Enter the costs of the books: ";
for (int i = 0; i < n; i++) {
cin >> arr[i];
 }
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = B[i];
                arr[i] = arr[j];
                arr[j] = temp;
 }
 }
    }

    // Copy costs less than 500 to a new array
    int newArr[100];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 500) {
            newArr[j] = arr[i];
            j++;
        }
    }

    // Delete duplicate entries using a temporary array
    int temp[100];
    j = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int k = 0; k < j; k++) {
            if (arr[i] == temp[k]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }
    n = j;

    // Delete duplicate entries without using a temporary array
    j = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int k = 0; k < j; k++) {
            if (arr[i] == arr[k]) {
                found = true;
                break;
            }
        }
        if (!found) {
            arr[j] = arr[i];
            j++;
        }
    }
    n = j;

    // Count books with cost greater than 500
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 500) {
            count++;
        }
    }

    cout << "Number of books with cost greater than 500: " << count << endl;

    return 0;
}


	

