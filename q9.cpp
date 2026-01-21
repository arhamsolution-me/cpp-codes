#include <iostream>
#include<cctype>
using namespace std;

int main() {
    char str[100];
    cin.getline(str, 100);
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = tolower(str[i]) ;
        }
    }
    
    cout << str << endl;
    return 0;	
}
