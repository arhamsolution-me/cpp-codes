#include <iostream>
using namespace std;

int main(){
    int n;
    while(true){
    cout<<"\nHow many numbers you want to disply ";
    cin>>n;
   
    if(n < 1){
        cout<<"\nPlease enter a positive number";
        continue;
    }
    else 
    break;
}
    double series[n];

    series[0] = 2;
    series[1] = 4;
    series[2] = 6;

    for (int i=0;i<n;i++) {
        if(i>=3){
          series[i] =(series[i-3]+series[i-2]+series[i-1])/ 3.0;
        }

        cout<<series[i];
        if (i!=n-1) {
            cout<<"  ";
        }
    }

    return 0;
}
