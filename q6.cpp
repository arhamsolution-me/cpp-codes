#include <iostream>
using namespace std;

void multiplyArrays(int A[], int B[], int size) {
    int result[2 * size] = {0};

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i + j] += A[i] * B[j];
        }
    }

    for (int i = 0; i < 2 * size - 1; i++) {
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    cout << "Resultant Array: {";
    bool first = true;
    for (int i = 2 * size - 1; i >= 0; i--) {
        if (result[i] != 0 || !first) {
            cout << result[i]<<" ";
            first = false;
        }
    }
    cout << "}" << endl;
}

int main() {
    int size;
    cout<<"Size: ";
    cin >> size;

    int A[size], B[size];
cout<<"1st inputs: ";
    for (int i = 0; i < size; i++) {
        cin >> A[i];
    }
cout<<"2nd inputs: ";
    for (int i = 0; i < size; i++) {
        cin >> B[i];
    }

    multiplyArrays(A, B, size);

    return 0;
}
