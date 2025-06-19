#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string rollno,name,fname,address,search;
    fstream file;
    public:
    void addStudent();
    void viewStudent();
    void searchStudent();

}obj;


int main() {
    int choice;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"1 - Add Student Record"<<endl;
    cout<<"2 - View All Students Record"<<endl;
    cout<<"3 - Search Student Record"<<endl;
    cout<<"4 - Exit"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cin>>choice;

    switch (choice)
    {
    case 1:
    cin.ignore();
     obj.addStudent();
        break;
    case 2: 
    cin.ignore();
    obj.viewStudent();
        break;
    case 3: 
    cin.ignore();
    obj.searchStudent();
        break;
    case 4: return 0;
        break;
    
    default: cout<<"Invalid Choice.";
        break;
    }

}

void temp :: addStudent(){
    cout<<"Enter the Student Roll Number : "<<endl;
    getline(cin,rollno);
    cout<<"Enter the Student Name : "<<endl;
    getline(cin,name);
    cout<<"Enter the Student Father's Name : "<<endl;
    getline(cin,fname);
    cout<<"Enter the Student Address : "<<endl;
    getline(cin,address);

    file.open("Stdata.txt", ios :: out | ios :: app);
    file<<rollno<<"*"<<endl;
    file<<name<<"*"<<endl;
    file<<fname<<"*"<<endl;
    file<<address<<endl;
    file.close();
    
}

void temp :: viewStudent(){
    file.open("Stdata.txt",ios::in);
    getline(file,rollno,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');

    while(!file.eof()){
        cout<<'\n';
        cout<<"Student Roll No : "<<rollno<<endl;
        cout<<"Student Name : "<<name<<endl;
        cout<<"Student Father's Name : "<<fname<<endl;
        cout<<"Student Address : "<<address<<endl;

        getline(file,rollno,'*');
        getline(file,name,'*');
        getline(file,fname,'*');
        getline(file,address,'\n');
    }
    file.close();

}

void temp :: searchStudent(){

    cout<<"Enter Student Roll No : ";
    getline(cin,search);

    file.open("Stdata.txt", ios :: in);
    getline(file,rollno,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');

    while(!file.eof()){
        if(rollno == search){
            cout<<endl;
            cout<<"Student Roll No : "<<rollno<<endl;
            cout<<"Student Name : "<<name<<endl;
            cout<<"Student Father's Name : "<<fname<<endl;
            cout<<"Student Address : "<<address<<endl;

        }
        getline(file,rollno,'*');
        getline(file,name,'*');
        getline(file,fname,'*');
        getline(file,address,'\n'); 
        }
        file.close();
               
}