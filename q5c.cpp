#include<iostream>
using namespace std;
int main(){
    int n=10;
    for(int i=n;i>0;i--){
        for(int j=0;j<n-i;j++) cout<<" ";
        for(int j=0;j<2*i-1;j++){
            if(j==0||j==2*i-2) cout<<"*";
            else cout<<" ";
        }
        for(int j=0;j<2*(n-i)+1;j++) cout<<" ";
        for(int j=0;j<2*i-1;j++){
            if(j==0||j==2*i-2) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
