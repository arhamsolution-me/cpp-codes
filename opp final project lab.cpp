//	f2024266796
	#include<iostream>
	#include<string>
	#include<fstream>
	#include<conio.h>
	using namespace std;
        
	//functions name
	bool MAIL(string,string);
	void AdminDashboard();
	void Employee_R_L();
	bool CAPTCHA();
	void Add_Employee_data(string);
	float BONUS(float);
	void MailToAdmin();
	
	string username;
	string password;
	int account_count_number = 0;

	float BONUS(float  salery){
		if(salery>=10000&&salery <=50000){
			return salery*0.1;
		}
		else if(salery>20000&&salery<=100000){
			return salery*0.2;
		}
		else{
			return 0.0;
		}
		
	}
	void deleteEmployeeByUsername(const string& Username) {
	    ifstream IFile("Employee.txt");
	    ofstream TFile("Employee_t.txt");
	
	    bool found = false;
	    string fUsername, fPassword;
	
	    if (IFile.is_open() && TFile.is_open()) {
	        while (IFile >> fUsername >> fPassword) {
	            if (fUsername == Username) {
	                found = true; 
	            } 
				else {
	                TFile<<fUsername<<" "<<fPassword<<endl;
	            }
	        }
	
	        IFile.close();
	        TFile.close();
	
	        remove("Employee.txt");
	        rename("Employee_t.txt", "Employee.txt");
	
	        if (found) {
	            cout << "Employee with username '" << Username << "' deleted successfully." << endl;
	        } else {
	            cout<<"Username '"<<Username<<"' not found."<<endl;
	        }
	    } 
		else {
	        cout << "Error opening file." << endl;
	    }
	}
	
	bool is_password_valid(string password){
	    char special_symbols[] = {'@', '$', '%', '&', '*'};
	    int length = password.length();
	
	    if (length < 7 || length > 15) {
	        cout<<"Password must be between 7 and 15 characters."<<endl;
	        return false;
	    }
	
	    for (int i = 0; i < 5; i++) {
	        if (password[0] == special_symbols[i]) {
	            cout << "Password should not start with a special character." << endl;
	            return false;
	        }
	    }
	
	    int has_upper = 0;
	    for (int i = 0; i < length; i++) {
	        if (isupper(password[i])) {
	            has_upper = 1;
	            break;
	        }
	    }
	    if (!has_upper) {
	        cout << "Password must contain at least one uppercase letter." << endl;
	        return false;
	    }
	
	    int has_special = 0;
	    for (int i = 0; i < length; i++) {
	        for (int j = 0; j < 5; j++) {
	            if (password[i] == special_symbols[j]) {
	                has_special = 1;
	                break;
	            }
	        }
	        if (has_special) break;
	    }
	
	    if (!has_special) {
	        cout << "Password must include at least one special symbol: @ $ % & *" << endl;
	        return false;
	    }
	
	    return true;
	}
	
	class person{
		public: 
		virtual void ShowRole()=0;
		
	};
		class ADMIN: public person{
		private:
			string Mail;
			string recieveMAil[100];
			int iteration=0;
		public:
			ADMIN(){
				Mail="";
			    
			}
			ADMIN(string m):Mail(m){
			}
			void setRecieveMail(const string& ma){	
				recieveMAil[iteration]=ma;
				iteration++;
			}
		
			string getRecieveMail(){
				for(int i=0;i<iteration;i++){
					return recieveMAil[i];
				}
			}
		    void ShowRole()override{
			    cout<<"Admin";
		    }
		    void SendMessageToEmployee(){
				string name,fname,fpass;
				cout<<"\n\nEnter username to send message: ";
				cin>>name;
				ifstream checkfile("Employee.txt");
					bool check = false;
					if(checkfile.is_open()){
						while(checkfile >>fname >> fpass){
							if(name == fname ){
								check = true;
								break;
							}
						}
						checkfile.close();
						if(check){
							cout<<"\nMail to "<<name<<endl;
							cout<<"\nEnter Mail: ";
							cin.ignore();
							getline(cin,Mail);
							
							if(MAIL(name,Mail)){
								cout<<"\nMail successfully"<<endl;
							}
							else{
								cout<<"Error,Employee cannot complete his Details."<<endl;
							}
							
						}
						else{
							cout<<"No name found"<<endl;
						}
					}
			}
	};
	class Employee:public person{
	private:
	    string employee_name;
	    string employee_id;
	    string Experience;
	    string position;
	    string department_name;
	    string department_code;
	     string Mail[100];
	    long long   basic_salary;
	    float bonus;
	    int iteration =0;
	
	public:
	    Employee()
	    {
	        employee_name = "";
	        employee_id = "0";
	        Experience = "None";
	        position =  "";
	        department_name =  "";
	        department_code =  "";
	        
	        basic_salary = 0.0;
	        bonus = 0.0;
	    }
	    Employee(string e_n, string e_i, string Exp,string con, string d_n, string d_c,  long long  b_s, float b) {
	        employee_name = e_n;
	        employee_id = e_i;
	        Experience = Exp;
	        position =  con;
	        department_name =  d_n;
	        department_code =  d_c;
	        basic_salary = b_s;
	        bonus = b;
	    }
	    Employee(const Employee &copy){
	    	employee_name = copy.employee_name;
	        position = copy.position;
	        Experience = copy.Experience;
	        department_name = copy.department_name;
	        department_code = copy.department_code;
	        basic_salary = copy.basic_salary;
	        bonus = copy.bonus;
		}
		void ShowRole()override{
			cout<<"Employee";
		}
		void EmployeeSlip() {
			system("cls");
	    cout<<"\n\n==============================Employee Salary Slip ================================\n\n";
	    cout<<"         Employee Name     : " <<  employee_name <<"           Employee ID   : " << employee_id << endl;
	     cout<<"----------------------------------------------------------------------------------\n";
	    cout<<"         Position          : " << position <<     "                Experience    : " << Experience << endl;
	    
	     cout<<"----------------------------------------------------------------------------------\n";
	    cout<<"           Department Name   : " << department_name<<"               Department Code: " << department_code << endl;
	    cout<<"-----------------------------------------------------------------------------------\n";
	
	    cout<<"         Basic Salary      : " << basic_salary << endl;
	    cout<<"         Bonus             : " << bonus << endl;
	    cout<<"---------------------------------------------------------------\n";
	    cout<<"         Total Salary      : " << getTotalSalary() << endl;
	    cout<<"=============================================================\n\n";
	}
	
	    void setEmployeeName(string e_n)
	    {
	       employee_name = e_n;  
	
	    }
	    void setEmployeeID(int e_i)
	    {
	        employee_id = e_i;
	    }
	    void setPosition(string con)
	    {
	        position = con;
	    }
	    void setDepartmentName(string d_n)
	    {
	        department_name = d_n;
	    }
	    void setDepartmentCode(string d_c)
	    {
	        department_code = d_c;
	    }
	    void setBasicSalary(float  b_s)
	    {
	        basic_salary = b_s;
	    }
	    void setBonus(float b)
	    {
	        bonus = b;
	    }
	    
	    string getMail(){
	    		cout<<"\nMail";
	    	for(int i=0;Mail[i]!="\0";i++){
		    	cout<< endl<<i+1<<". "<<Mail[i]<<endl;
	        }
		}
		void setMail(const string& ma){	
				Mail[iteration]=ma;
				iteration++;
			}
	  
	    string getEmployeeID()
	    {
	        return employee_id;
	    }
	    string getEmployeeName()
	    {
	        return employee_name;
	    }
	    string getPosition()
	    {
	        return position;
	    }
	    string getDepartmentName()
	    {
	        return department_name;
	    }
	    string getDepartmentCode()
	    {
	        return department_code;
	    }
	    float getBasicSalary()
	    {
	        return basic_salary;
	    }
	    float getBonus()
	    {
	        return bonus;
	    }
	    float getTotalSalary()
	    {
	        return basic_salary + bonus;
	    }
	
	    void displayinformation()
	    {
					system("cls");	
	        cout << "\n\nEmployee Name:" << employee_name << endl
	             << "Employee ID:" << employee_id << endl
	             << "position:" << position << endl
	             << "Department Name:" << department_name << endl
	             << "Department Code:" << department_code << endl
	             << "Total Salary:" << getTotalSalary() << endl;
	       
	    }
	    ~Employee(){
	       
	    }
	
	
	    
	};
	const int max_students =100;
	
	Employee Employees[max_students];

	
	
	bool CAPTCHA(){
		static int number = 1;
		
		float cap,captcha;
		
		cap = number*2+number;
		
		cout<< "\nVerify CAPTCHA: ";
		cout<<number<<"*2+"<<number;
		number+=1;
		cout<<"\nEnter CAPTCHA: ";
		cin>>captcha;
		if(captcha == cap){
			
			return true;
		}
		else{
			return false;
		}
	}
	bool MAIL(string name,string mail){
		for (int i = 0; i < account_count_number; i++) {
	        if (name == Employees[i].getEmployeeName()) {
	            Employees[i].setMail(mail);
	            return true;
	        }
	    }
	    return false;
	    	
	}
	ADMIN a;
	void Admin(){
		
		a.ShowRole();
		system("cls");
		cout<<"\n-----Admin-----"<<endl;
		while(true){
		    
			string name, pass;
			cout<<"\nEnter Name: ";
			cin>>name;
			cout<<"Enter password: ";
			cin>>pass;
			if(name == "Admin"&&pass =="admin"){
				cout<<"Admin login successfully"<<endl;
				system("cls");
				AdminDashboard();
				break;
		    }
		    else{
		    	cout<<"Wrong Login"<<endl;
		    	continue;
			}
	    }
	
	}

void AdminDashboard(){
	char choice;
	while(true){
	cout<<"\n1. show All Employee"<<endl
	    <<"2. delete Employee"<<endl
	    <<"3. Send Mail"<<endl
	    <<"4. Exit"<<endl;
	    cout<<"Enter your choice: ";
	    choice=getch();
	    switch(choice){
	    	case '1':{
	    		system("cls");
	    		cout<<"\nShow all Employee Details"<<endl;
	    		cout<<"\nThere are "<<account_count_number<<" Employees"<<endl;
	    		bool found = false;
			    for (int i = 0; i < account_count_number; i++) {
			        if (username == Employees[i].getEmployeeName()) {
			            Employees[i].displayinformation();
			            cout<<endl;
			            found = true;
			            break;
			        }
			    }
			    if (!found) {
			        cout << "\nEmployee data not inserted.\n";
			    }
				break;
			}
			case '2':{
				system("cls");
				string name;
				cout<<"\nEnter Username to remove: ";
				cin>>name;
				deleteEmployeeByUsername(name);
			    continue;
				break;
			}
			case '3':{
				system("cls");
				 
				 a.SendMessageToEmployee();
				break;
			}
		
			case '4':{
				return ;
				break;
			}
		}
	    
	}
}
Employee Emp;
void Add_Employee_data(string name){
system("cls");
Emp.ShowRole();
    while (true){
        char choice;
        cout << "\n\nEnter 1 to Add Details";
        cout << "\nEnter 2 to Display Information";
        cout<<"\nEnter 3 to More services";
        cout << "\nEnter 4 to Exit";

        cout << "\nEnter your choice:";
         choice=getch();
        switch (choice){
        case '1':{
            cout << "Add Detaisl";
            if (!(account_count_number < max_students)){
                cout << "Max account reached";
                return;
            }
            
            string Id, Experience,position, department_name, department_code;

            float basic_salary, bouns;

            
            cin.ignore();
        
            cout<<"\nBe carefull after submit your data cannot change"<<endl;
            while (true){
                cout << "\nEnter employee ID: ";
                getline(cin,Id);
                bool found = false;
              
                for (int i = 0; i < account_count_number; i++){
                    if (Id == Employees[i].getEmployeeID()){
                        found = true;
                        break;
                    }
                }
                if(Id == "0"){
                	cout<<"ID is not 0";
                   continue;               	
				}
                if (!found){
                    break;
                }
                cout << "Employee ID already exists\n";
            }
            cout << "\nEnter your Experience: ";
            getline(cin, Experience);
     			     
            cout << "\nEnter your Position: ";
            getline(cin, position);
        

            cout << "\nEnter Department Name which you want to enter: ";
            getline(cin, department_name);
        

        
            cout << "\nEnter Department Code (like CS123,..): ";
            getline(cin, department_code);
            
            while(true){
	            cout << "\nEnter Basic Salary: ";
	            cin >> basic_salary;
	            if(basic_salary>200000){
	            	cout<<"\nYou are Employee and your salery is less then 200000"<<endl;
	            	continue;
				}
				break;
            }
            bouns = BONUS(basic_salary);

            Employees[account_count_number] = Employee(name, Id,Experience, position, department_name, department_code, basic_salary, bouns);
            account_count_number++;
            cout<<"Your data has been saved. now, go to servics and generate your slip.";
            break;
        }
		case '2': {
		    bool found = false;
		    for (int i = 0; i < account_count_number; i++) {
		        if (username == Employees[i].getEmployeeName()) {
		            Employees[i].displayinformation();
		            found = true;
		            break;
		        }
		    }
		
		    if (!found) {
		        cout << "\nEmployee data not inserted.\n";
		    }
		    break;
		    }
		

		case '3': {
            char service_choice;
            cout << "\n\n1. Generate Slip"
                 << "\n2. Check Mail"
                 << "\nEnter your choice: ";
            service_choice = getch();
            switch (service_choice) {
                case '1': {
                    bool found = false;
                    for (int i = 0; i < account_count_number; i++) {
                        if (username == Employees[i].getEmployeeName()) {
                            Employees[i].EmployeeSlip();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Employee data not found. Please add your details first.\n";
                    }
                    break;
                }
                case '2': {
                    bool found = false;
                    for (int i = 0; i < account_count_number; i++) {
                        if (username == Employees[i].getEmployeeName()) {
                            string mail = Employees[i].getMail();
                            
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "\nEmployee data not found.\n";
                    }
                    break;
                }
                default:
                    cout << "\nInvalid choice in more services.\n";
            }
            break;
        }

        case '4':
            return;

        default:
            cout << "\nInvalid choice. Try again.\n";
        }
    }
}

void Employee_R_L(){
	system("cls");
	char choice;
	cout<<"\n1. Register"<<endl
	    <<"2. Login"<<endl
	    <<"3. Information"<<endl;
	cout<<"Enter your choice: ";
	choice = getch();
	switch(choice){
		case '1':{
			system("cls");
			string E_username;
			string E_password;
            while(true){
				cout<<"\n-----Register-----";
			    
				cout<<"\nEnter username: ";
				cin>>username;
				cout<<"Enter your password: ";
				cin>>password;
				if(!is_password_valid(password)){

					cout<<"\nPassword incorrect.All information are in Information section."<<endl;
					continue;
			    }
				ifstream checkfile("Employee.txt");
				bool check = false;
				if(checkfile.is_open()){
					while(checkfile >>E_username >> E_password){
						if(username == E_username ){
							check = true;
							break;
						}
					}
					checkfile.close();
					if(check){
						cout<<"Username already Exist"<<endl;
						continue;
					}
				}
				if(CAPTCHA()){
					cout<<"\nverified You are human.\nResistration successfully."<<endl;
				    ofstream inputfile("Employee.txt",ios::app);
					if(inputfile.is_open()){
						inputfile<<username<<" "<<password<<endl;
						inputfile.close();
						
			         
						break;
					}
					else{
						cout<<"file cannot open";
					}
			    }
			    else{
			    	cout<<"\nWrong CAPTCHA! Again try."<<endl;
				}
		    }
			break;
		}
		case '2':{
			system("cls");
				string E_username;
				string E_password;
				
				cout<<"\n-----Login-----";
				cout<<"\nEnter Username: ";
				cin>>username;
				cout<<"Enter password: ";
				cin>>password;
				ifstream outputfile("Employee.txt");
				bool check = false;
				if(outputfile.is_open()){
					while(outputfile >>E_username >> E_password){
						if(username == E_username && password == E_password){
							check = true;
							break;
						}
					}
					outputfile.close();
					if(check){
						cout<<"Login successfull";
						Add_Employee_data(username);
					}
					else{
						cout<<"login failed";
					}
				}
				else{
					cout<<"file cannot open";
				}
			break;
		}
		case '3':{
			system("cls");
			cout << "\n========================= Information Services =========================\n";
		    cout << "\n--- How this software works ---\n";
		    cout << "1. First, the user must register with a unique username and a valid password.\n";
		    cout << "2. Password Rules:\n";
		    cout << "    .Length must be between 7 and 15 characters.\n";
		    cout << "    .Must contain at least one uppercase letter.\n";
		    cout << "    .Must contain at least one special symbol: @ $ % & *\n";
		    cout << "    .Should NOT start with a special symbol.\n";
		    cout << "3. After registration, a CAPTCHA will be shown. You must solve it correctly to complete registration.\n";
		    cout << "4. If your username already exists, you will be asked to choose another.\n";
		    cout << "5. Mail can be use for Employee and admin.\n";
		    cout << "6. On successful login, you can:\n";
		    cout << "    .Add your Employee details (Once only. Cannot be changed later).\n";
		    cout << "   . Generate a Salary Slip.\n";
		    cout << "\nNOTE: This system uses dynamic memory for employee names, department info, etc.\n";
		    cout << "      Please be careful while entering your data. Once submitted, it cannot be edited.\n";
		    cout << "=========================================================================\n\n";
			break;
		}
	}
	
}
int main(){
	

    cout<<"     ======================================================" << endl<<endl;
    cout<<"     |        WELCOME TO EMPLOYEE MANAGEMENT SYSTEM       |" << endl<<endl;
    cout<<"     ======================================================" << endl;
    cout<<endl;

    cout<<"     |                Developed by: Muhammad Arham         |  " << endl;
    cout<<"     |                Institute: UMT                       |   " << endl<<endl;
    cout<<"     ======================================================" << endl;
    cout<<endl;

    cout<<"     Press Enter to continue......";
    
    cin.get(); 
	char choice='y',c;
	
    while(choice == 'y'|| choice == 'Y'){
    	system("cls");
    	cout<<"\nYou are Admin OR Emlpoyee  (a/e): ";
    	c=getch();
    	if(c=='a'){
	
    		Admin();
		}
		else if(c=='e'){
			Employee_R_L();
		}
		else{
			cout<<"Wrong Input!"<<endl;
			continue;
		}
	    
//	    cout<<"\nDo you want to go main page. press y, otherwise code terminate.: ";
//	    choice = getch();
//	    cin.ignore();
	}
}
