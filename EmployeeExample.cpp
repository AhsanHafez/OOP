#include<iostream>
#include <string>
using namespace std;
class Employee{
    protected: // aceess modifier or access specifiier
    int pay_rate; // data hiding or encapsulation
    public:
    friend void acess_pay_rate_directly(Employee e);
    void set_pay_rate(int rate);
    int get_pay_rate();
    Employee();
};
class FacultyMember:public Employee{
    public:
    void set_pay_rate(int rate);
    FacultyMember();
};
main(){
   Employee a;
   a.set_pay_rate(15);
   cout<<a.get_pay_rate()<<endl;
   a.set_pay_rate(11);
   cout<<a.get_pay_rate()<<endl;

 FacultyMember f;
 f.set_pay_rate(25);
 cout<<f.get_pay_rate()<<endl;
 f.set_pay_rate(22);
 cout<<f.get_pay_rate()<<endl;
}
void  Employee::set_pay_rate(int rate){//setters
    if(rate>=14){
        this->pay_rate=rate;
    }
    else{
        cout<<"CANNOT SET PAY RATE "<<rate<<"  BCZ ITS BELOW 14 NOT SETTING......"<<endl;
    }
}
int Employee::get_pay_rate(){//getter
    return pay_rate;
}
Employee::Employee(){
    //cout<<"CREATING AN EMPLOYEE INSTANCE AND SETTING DEFAULT VALUES " <<endl;
    pay_rate=14;
}
void FacultyMember::set_pay_rate(int rate){
    if(rate>=25){
        this->pay_rate=rate;
    }
    else{
        cout<<"CANNOT SET PAY RATE AT "<<rate<<" IT SHOULD BE OVER 25 FOR FACULTY"<<endl;
    }
}
FacultyMember::FacultyMember(){
    this->pay_rate=25;
}
void acess_pay_rate_directly(Employee e){//friend function
cout<<e.pay_rate<<endl;
}