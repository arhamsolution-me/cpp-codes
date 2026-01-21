#include <iostream>
using namespace std;

int main() {
	while (true){
    char symbal_arr[5] = {'@', '$', '%', '&', '*'};
    char inp_arr[100];
    int len=0,special_check=0;
    cout << "\nEnter a password: ";
    cin.getline(inp_arr, 100);
     bool found = false,length_f=false,upercase=false;
    for (int i=0;inp_arr[i]!='\0';i++){
    		len++;
	}
	for (int i=0 ;inp_arr[i]!='\0';i++){
		if(inp_arr[i]>='A'&&inp_arr[i]<='Z'){
			upercase=true;
			break;
		}
	}
   
    if(len>6&&len<16){
    	length_f=true;
    	for (int i = 0; inp_arr[i]!='\0'; i++) {
            for (int j = 0; j < 5; j++) {
	            if (inp_arr[i] == symbal_arr[j]) {
	                found = true;
	                special_check++;
	                break;
	            }
	            special_check++;
            }
            if(found)
            break;
		}
	}
    
	 if(!length_f){
	 	cout<<"length must be 8 to 16 letter ";
		
    }
	else if(special_check==1){
		cout<<"password must start with number or charactor not special charactor";
	}
	else if(!upercase){
		cout<<"password must be 1 upercase letter";
	}
	else if(!found){
		cout<<"invaid,plz add special symboll";
	}

    else{
    	cout<<"valid";
    	break;
	}
}
    return 0;
}
