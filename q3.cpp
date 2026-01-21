#include<iostream>
using namespace std;

int main(){
	int n1,n2,num=1;
	cout<<"Enter 1st number : ";
	cin>>n1;
	cout<<"Enter 2nd number: ";
	cin>>n2;
	for(int i=0;i<n2;i++){
		num*=n1;
	}
	cout<<"Answer is: "<<num;
	return 0;
}