#include <iostream>
using namespace std;

int main() {
    int num, temp, sum = 0, digit, n = 0;
    
    cin >> num;
    
    temp = num;
    
    while (temp != 0) {
        temp /= 10;
        n++;
    }

    temp = num;
    while (temp != 0) {
        digit = temp % 10;
        sum += digit * digit * digit;
        temp /= 10;
    }
    
    if (sum == num)
        cout << "Yes it is Armstrong number" << endl;
    else
        cout << "No it is not Armstrong number" << endl;
    
    return 0;
}
