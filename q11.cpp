#include<iostream>
using namespace std;
void reverseWords(string str){
    string words[100];
    int i=0;
    string temp="";
    for(int j=0;j<=str.length();j++){
        if(str[j]==' '||str[j]=='\0'){
            words[i]=temp;
            i++;
            temp="";
        }
        else{
            temp+=str[j];
        }
    }
    for(int j=i-1;j>=0;j--){
        cout<<words[j]<<" ";
    }
    cout<<endl;
}
int main(){
    string str="My first lab in OOP";
    reverseWords(str);
}
