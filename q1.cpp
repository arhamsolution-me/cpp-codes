#include<iostream>
using namespace std;
bool prime(int num){
	if(num<=1){
		return false;
	}
	for(int i=2;i<-num;i++){
		if(num%i==0){
		return false;	
		}
		return true;
	}
}
int main(){
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	
	if(prime(n)){
		cout<<n << " is prime number";
	}
	else{
		cout<<n << " is not prime numer";
	}
	return 0;
}