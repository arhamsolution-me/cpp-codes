                                                       //Group 8
                                            // leader Arham   f2024266796 
                                            // member Mustafa f2024266794
                                            // member M.Taha  f2024266775
                                            // member usman   f2024266778
#include <iostream>
using namespace std;
// databasee used to save data also read its report
const int MAX_ACCOUNTS = 10000;
int account_count_number = 0;
char username_DB[MAX_ACCOUNTS][50];
char password_DB[MAX_ACCOUNTS][50];
char Mobile_number_DB[MAX_ACCOUNTS][50];
char ID_DB[MAX_ACCOUNTS][20];
int Balance_DB[MAX_ACCOUNTS];
char ID[20], password[50];
//function declaration
void Menu_of_Account();
void Open_Account();
void login();
void search();
void transfer_Balance();
bool String_Equal(char S_C_1[], char S_C_2[]) ;

int main() {
    Menu_of_Account();
    return 0;
}

void Menu_of_Account() {
    bool found = false;

    while (true) {
        int choice;
        system("cls");
        cout << " \n      __________Welcome to AR_Bank___________";
        cout << " \n     |                                       |";
        cout << " \n     |   Enter 1 to open an account          |";
        cout << " \n     |   Enter 2 to Login account            |";                                  
        cout << " \n     |   Enter 3 to Search data              |";
        cout << " \n     |   Enter 4 to transfer a Balance       |";
        cout << " \n     |   Enter 5 to Exit                     |";
        cout << " \n     |_______________________________________|";
        cout << "\n\n===================";

        bool _choice = false;
        while (!_choice) {
            cout << "\nEnter Your choice: ";
      
            if (cin >> choice) { 
           
                if (choice>=1&&choice<=5) {
                    switch (choice) {
                        case 1:
                            system("cls");
                            Open_Account();
                            _choice = true;
                            break;
                        case 2:
                            system("cls");
                            login();
                            _choice = true;
                            break;
                        case 3:
                            system("cls");
                            search();
                            _choice = true;
                            break;
                        case 4:
                            system("cls");
                            transfer_Balance();
                            _choice = true;
                            break;
                        case 5:
                        	cout<<"exit";
                        	exit(0);
                    }
                }
				else {
                    cout << "\nInvalid choice \n";
                }
            }
			else{
                cout << "\nInvalid input\n";
                cin.clear(); 
             cin.ignore(10000, '\n');  

            }
        }
        char choose;
        cout << "\nEnter any other key (else Enter key) to show Menu: ";
        cin>>choose;
        if (choose) {
            cout<<"";
        }
    }
}

void Open_Account() {
    if (account_count_number >= MAX_ACCOUNTS) {
        cout << "Maximum account limit reached!" << endl;
        return;
    }

    char username_[50], password_[50], mobile_[15];
    cout << "\n\n----------Opening a new account----------\n";
    cout << "\nImportant note!\n";
    cout << "Enter input without space, otherwise data cannot be saved.\n";

    bool found = false;
    while (true) {
        cout << "\nEnter a Username: ";
        cin.ignore();  // Ignore any leftover input in the buffer
        cin.getline(username_, 50);

        found = false;  
        for (int i = 0; i < account_count_number; ++i) {
            if (String_Equal(username_DB[i], username_)) {
                found = true;
                break;  
            }
        }
        
        if (found) {
            cout << "Username already exists. Please choose another.\n";
        } else {
            break;  
        }
    }

    cout << "Enter a Password: ";
    cin.getline(password_, 50);

    while (true) {
        cout << "Enter your Mobile Number: +92 ";
        cin.getline(mobile_, 15);

        bool valid = true;
        int len = 0;
 
        for (int i = 0; mobile_[i] != '\0'; ++i) {
            len++;
           
            if (mobile_[i] < '0' || mobile_[i] > '9') {
                valid = false;
                break;
            }
        }

        if (len!= 11) {
            valid=false;
        }

        if (valid) {
            break;  
        } else {
            cout<<"Invalid mobile number. Please enter a valid 11-digit number without any symbols or letters\n";
        }
    }

    for (int i = 0; i < 50; ++i) {
        username_DB[account_count_number][i] = username_[i]; 
        if (username_[i] == '\0') 
            break; 
    }

    for (int i = 0; i < 50; ++i) {
        password_DB[account_count_number][i] = password_[i];
        if (password_[i] == '\0')
            break; 
    }

    for (int i = 0; i < 15; ++i) {
        Mobile_number_DB[account_count_number][i] = mobile_[i]; 
        if (mobile_[i] == '\0') 
            break; 
    }

    ID_DB[account_count_number][0] = 'A';
    ID_DB[account_count_number][1] = 'R';
    ID_DB[account_count_number][2] = '0' + account_count_number + 1;

    cout << "\nYour account has been created! Your ID is " << ID_DB[account_count_number] << endl;
    Balance_DB[account_count_number] = 0;
    account_count_number++; // Increment because next user's data saves in next index
    return;
}

void login() {
    cout << "\n---------- Account Login ----------";
    cout << "\n-----------------------------------";
    cout << "\nEnter Account ID: ";
    cin >> ID;
    cout << "Enter Password: ";
    cin >> password;

    int choice;
    bool found = false;

    for (int i = 0; i < account_count_number; i++) {
        if (String_Equal(password_DB[i], password) && String_Equal(ID_DB[i], ID)) {
            while (true) {
                system("cls");
                cout << "\n------------------------------------";
                cout << "\nAccount details for ID: " << ID_DB[i];
                cout << "\nUsername: " << username_DB[i];
                cout << "\nMobile Number: " << Mobile_number_DB[i];
                cout << "\nBalance: $" << Balance_DB[i] << endl;
                cout << "\n------------------------------------";        
                cout << "\nEnter 1 to Deposit";
                cout << "\nEnter 2 to Withdraw";
                cout << "\nEnter 3 to Change Data";
                cout << "\nEnter 4 to Logout\n";                

                bool validChoice = false;
                while (!validChoice) {
                    cout << "\nEnter your choice: ";
                    cin >> choice;
                    if (choice >= 1 && choice <= 4) {
                        validChoice = true;
                    } else {
                        cout << "\nInvalid choice! Please enter a number between 1 and 4.\n";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                }

                switch (choice) {
                    case 1: {
                        float amount;
                        while (true) {
                            cout << "\nEnter amount to deposit: $";
                            if (cin >> amount && amount > 0) {
                                Balance_DB[i] += amount;
                                cout << "\nDeposit successful! New balance: $" << Balance_DB[i] << endl;
                                break;
                            } else {
                                cout << "\nDeposit amount must be greater than 0!" << endl;
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                        }
                        break;
                    }
                    case 2: {
                        char ch ;
                        float amount_ ;
                        while (true) {
                            cout << "\nEnter amount to withdraw: $";
                            if (cin >> amount_ && amount_ > 0) {
                                if (amount_ > Balance_DB[i]) {
                                    cout << "\nInsufficient balance!" << endl;
                                    cout << "\nPress any key to continue: ";
                                    if (cin >> ch) 
									break;
                                } 
								else {
                                    Balance_DB[i] -= amount_;
                                    cout << "\nWithdrawal successful! New balance: $" << Balance_DB[i] << endl;
                                    break;
                                }
                            } 
							else {
                                cout << "\nWithdrawal amount must be greater than 0!" << endl;
                                cin.clear();
                                cin.ignore(100000, '\n');
                            }
                        }
                        break;
                    }

                    case 3: {
                        int choice_;
                        cout << "\nDo you want to change any details?";
                        cout << "\n------------------------------------";
                        cout << "\nEnter 1 to Change Username";
                        cout << "\nEnter 2 to Change Mobile Number";
                        cout << "\nEnter 3 to Change Password";
                        cout << "\nEnter 4 to Exit ";
                        cout << "\n------------------------------------";
    
                        while (true) {
                            cout << "\n\nEnter your choice: ";
                            cin >> choice_;
                            if (choice_ >= 1 && choice_ <= 4) {
                                break;
                            } else {
                                cout << "\nInvalid input! Please enter a valid choice between 1 and 4.\n";
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                        }

                        char username_[50], password_[50], mobile_[15];
    
                        switch (choice_) {
                            case 1:
                                while (true) {
                                    cout << "\nEnter a Username: ";
                                    cin >> username_;

                                    bool usernameExists = false;
                                    for (int j = 0; j < account_count_number; ++j) {
                                        if (String_Equal(username_DB[j], username_)) {
                                            usernameExists = true;
                                            break;
                                        }
                                    }
                                    if (usernameExists) {
                                        cout << "Username already exists. Please choose another.\n";
                                    } else {
                                        for (int j = 0; j < 50; ++j) {
                                            username_DB[i][j] = username_[j];
                                            if (username_[j] == '\0') break;
                                        }
                                        cout << "Username updated successfully!" << endl;
                                        break;
                                    }
                                }
                                break;
                            
                            case 2: {
                                char mobile_[15];
                                while (true) {
                                    cout << "Enter your Mobile Number (11 digits): +92 ";
                                    cin >> mobile_;

                                    bool valid = true;
                                    int len = 0;
                                    
                                    for (int i = 0; mobile_[i] != '\0'; ++i) {
                                        len++;
                                        if (mobile_[i] < '0' || mobile_[i] > '9') {
                                            valid = false;
                                            break;
                                        }
                                    }

                                    if (len != 11) {
                                        valid = false;
                                    }

                                    if (!valid) {
                                        cout << "Invalid mobile number. Please ensure it contains only digits and is 11 digits long.\n";
                                    } else {
                                        bool mobileExists = false;
                                        for (int j = 0; j < account_count_number; ++j) {
                                            if (String_Equal(Mobile_number_DB[j], mobile_)) {
                                                mobileExists = true;
                                                break;
                                            }
                                        }

                                        if (mobileExists) {
                                            cout << "Mobile number already exists. Please choose another.\n";
                                        } else {
                                            for (int j = 0; j < 15; ++j) {
                                                Mobile_number_DB[i][j] = mobile_[j];
                                                if (mobile_[j] == '\0') break;
                                            }
                                            account_count_number++; // Increment the account count
                                            cout << "Mobile number updated successfully!" << endl;
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                            
                            case 3:
                                while (true) {
                                    cout << "\nEnter a Password: ";
                                    cin >> password_; // Read the password

                                    bool passwordExists = false;
                                    for (int j = 0; j < account_count_number; ++j) {
                                        if (String_Equal(password_DB[j], password_)) {
                                            passwordExists = true;
                                            break;
                                        }
                                    }

                                    if (passwordExists) {
                                        cout << "Password already exists. Please choose another.\n";
                                    } else {
                                        for (int j = 0; j < 50; ++j) {
                                            password_DB[i][j] = password_[j];
                                            if (password_[j] == '\0') break;
                                        }
                                        cout << "Password updated successfully!" << endl;
                                        break;
                                    }
                                }
                                break;
                                
                            case 4:
                                cout << "Exiting...\n";
                                break;
                        }
                        break;
                    }
                    
                    case 4: {
                        cout << "\nLogged out!" << endl;
                        Menu_of_Account();
                    }
                    default:
                        cout << "\nInvalid choice! Please try again." << endl;
                         system("cls");
                }
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Account not found!" << endl;
    }
}

void search() {
    if (account_count_number >= MAX_ACCOUNTS) {
        cout << "Maximum Account reached " << endl;
        return;
    }

  
    cout << "\n----------Search and Change Data----------";
    cout << "\nEnter Account ID to search: ";
    cin >> ID;
    cout << "\nEnter password to search: ";
    cin >> password;

    bool found = false;
    for (int i = 0; i < account_count_number; i++) {
        if (String_Equal(password_DB[i], password) && String_Equal(ID_DB[i], ID)) {
            cout << "\nUsername: " << username_DB[i];
            cout << "\nMobile Number: " << Mobile_number_DB[i];
            cout << "\nBalance: $" << Balance_DB[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Account not found!" << endl;
    }
}

void transfer_Balance(){
	int Amount;
    cout<<"Enter your ID: ";
    cin>>ID;
    cout<<"Enter password: ";
    cin>>password;
    bool found=false;

   for(int i=0;i<account_count_number;i++){
        if(String_Equal(ID_DB[i],ID)&&String_Equal(password_DB[i],password)){
   	    char Transfer_ID[20];
        cout<<"Enter ID which you want to transfer amount: ";
        cin>>Transfer_ID;
        if(String_Equal(Transfer_ID,ID)){
            cout<<"\nSame ID found. Cannot transfer to yourself.\n";
            return;
        } 
        for(int j=0;j<account_count_number;j++){
    	    if(String_Equal(Transfer_ID,ID_DB[j])){
                cout<<"Enter Ammount: $";
                cin>>Amount;
	            if(Balance_DB[i]>=Amount){
                Balance_DB[i]-=Amount;   
                Balance_DB[j]+=Amount;
            }
            else {
	            cout<<"Insuffient amount\n";
	            return;
            }
            found=true;
            break;
            }
        }
        if(!found){
            cout<<"\nIncorrect ID or password\n ";
            return;
        }
      }
    }
}

bool String_Equal(char S_C_1[], char S_C_2[]) {
	int i;
    for(i;S_C_1[i] != '\0' && S_C_2[i] != '\0';i++) {
        if (S_C_1[i] != S_C_2[i]) {
            return false;
        }
    }
    return (S_C_1[i] == '\0' && S_C_2[i] == '\0');
}
