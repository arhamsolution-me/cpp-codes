#include <iostream>
using namespace std;

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x, y;
    cout << "x : ";
    cin>>x;
    cout<<"y :";
    cin>>y;

   
    cout << "The greatest common divisor is "<<findGCD(x, y);

    return 0;
}