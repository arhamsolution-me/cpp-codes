/*
	Huzaifa Mushtaq
	Arham Abdul Qayyum 
*/
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
template<typename T>
class StudentRecord{
protected:
    string studentName;
    string studentId;
    string courseCode;
    string courseName;
    T midMarks;
    T finalMarks;
public:
    StudentRecord(string name,string id,string code,string title,T mid=0,T final=0):studentName(name),
	studentId(id),courseCode(code),courseName(title),midMarks(mid),finalMarks(final){
	}
    virtual void collectDetails()=0;
    virtual string calculateGrade()=0;
    virtual ~StudentRecord(){
	}
	friend ostream& operator<<(ostream& out,const StudentRecord<T>& S){
		out<<"Student ID : "<<S.studentId<<endl
		<<"Student Name : "<<S.studentName<<endl
		<<"Course Code : "<<S.courseCode<<endl
		<<"Course Name : "<<S.courseName<<endl
		<<"Mid Marks : "<<S.midMarks<<endl
		<<"Final Marks : "<<S.finalMarks<<endl;
		return out;
	}
	bool operator==(StudentRecord<T>& other){
		return (studentId==other.studentId);
	}
    friend class ReportGenerator;
};
template<typename T>
class CalculateGrade:public StudentRecord<T>{
public:
    CalculateGrade(string name,string id,string code,string title):StudentRecord<T>(name,id,code,title,0,0){
	}
    void collectDetails(){
		reenter:cout<<"Enter Mid Marks (0-100): ";
        cin>>midMarks;
        cout<<"Enter Final Marks (0-100): ";
        cin>>this->finalMarks;
        if(this->midMarks<0||this->midMarks>100||this->finalMarks<0||this->finalMarks>100){
            cout<<"Invalid marks entered"<<endl;
            goto reenter;
    }
}
    string calculateGrade(){
        T average=(this->midMarks+this->finalMarks)/2;
        string grade;
        if(average>=80){
			grade="A";
		}
        else if(average>=70){
		 	grade="B";
		}
        else if(average>=60){
			grade="C";
		}
        else{
			grade="F";
		}
       	return grade;
    }
};
class ReportGenerator{
public:
	template<typename T>
    void saveReport(StudentRecord<T>* record,const string& result){
        ofstream Report((record->studentId+"_report.txt").c_str());
        Report<<*record;
        Report<<"Grade: "<<result<<endl;
        Report.close();
	}
};
int main(){
    int num;
    renum:cout<<"Enter number of students: ";
    cin>>num;
    if(num<0){
    	goto renum;
	}
    vector<StudentRecord<float>*>records;
    ReportGenerator report;
    for (int i=0;i<num;++i){
        cout<<"\nStudent "<<i+1<<":"<<endl;
        string name,id,code,title;
        cout<<"Enter Name: ";
        cin>>ws;
        getline(cin, name);
        cout<<"Enter ID: ";
        cin>>id;
        if(i>0){
        	CalculateGrade<float> temp("",id,"","");
        	bool found;
        	for(int j=0;j<records.size();++j){
        	if(*(records[j])==temp){
        		found=true;
        		--i;
			}
			else{
				found=false;
			}
		}
		if(found){
			cout<<"ID Already Existed ! "<<endl;
			continue;
		}
	}
        cout<<"Enter Course Code: ";
        cin>>code;
        cout<<"Enter Course Name: ";
        cin>>ws;
        getline(cin,title);
        StudentRecord<float>* record= new CalculateGrade<float>(name,id,code,title);
        record->collectDetails();
        string result=record->calculateGrade();
        report.saveReport(record,result);
        records.push_back(record);
    }
    for(int i=0;i<records.size();++i){
        delete records[i];
	}
    return 0;
}
