#include <iostream>
using namespace std;

int findGCD(int a, int b) {
    while (b!= 0) {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int findLCM(int a, int b) {
    return(a*b)/findGCD(a,b);
}

int main(){
    int num1, num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;

    if (num1==0||num2==0){
        cout << "LCM of zero is undefined"<< endl;
        return 0;
    }
    cout<<findLCM(num1, num2)<<endl;

    return 0;
}
