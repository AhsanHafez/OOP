#include<iostream>
#include<string>
#include<math.h>
#include<cmath>
using namespace std;
void create_triangle();
int fib(int n);
class user{
    public:
    int id;
    static int next_id;  //must initialize static variable imediately after class defination
    static int next_user_id();
    int get_id();

    user();

};
int user::next_id=0;
class Point{
    public:
    int x;
    int y;
    void point_print();
};
class Shape{
    public:
    int number_of_points;
    Point *points;
    float get_area();

};
class Triangle : public  Shape{
public:
float get_area();
void set_point(Point *p);
void point_print();
 Triangle();
};
class Employee{
public:
//members or feeds
    string name;
    string adress;
    int salary;
    //methods
    void sighnin();
    void promote();  
        Employee();//constructor(called automtically when creating instance of this class)
        Employee(int salary);//function overloading
        ~Employee(); 
};
main(){
   Employee *e=new Employee;
  delete e;
  e=new Employee(70000);
   delete e;
   e=NULL;
  //e1.salary=9;
    Employee *eptr;
    //eptr=&e1;
    eptr=new Employee;
    (*eptr).name="as";
    eptr->sighnin();
    /*create_triangle();
    //  :: scope resolution operator
    // it tells in which scope we have to find variable
    user u;
    user v;
    cout<<u.get_id()<<endl;
    cout<<v.get_id()<<endl;
    cout<<"THE FBONACCI IS "<<fib(23)<<endl;
    cout<<fib(-1)<<endl;*/
    
    }
void Employee::sighnin(){
    cout<<"SIGHNING IN ....... "<<endl;
}
void Employee::promote(){
    cout<<"EMPLOY IS PROMOTED"<<endl;
}
Employee::Employee(){
    cout<<"CREATING AN INSTANCE OF CLASS EMPLOYEE"<<endl;
    salary=10000;  
    cout<<"THE SALARY OF THIS EMPLOYEE IS :"<<salary<<endl;
}
Employee::Employee(int salary){
    cout<<"CREATING AN INSTANT OF EMPLOYEE"<<endl;
this->salary=salary ;
cout<<"THE SALARY OF THIS EMPLOYEE IS :"<<salary<<endl;
}
Employee::~Employee(){
    cout<<"DELETING THE INSTANCE OF EMPLOYEE"<<endl;
}
void Point::point_print(){
cout<<'('<<x<<','<<y<<")\n";

}
float Shape::get_area(){

}
float Triangle::get_area(){ 
int x1,y1,x2,y2,x3,y3;
Point *tr=points;
x1=tr->x;     y1=tr->y;  tr++;
x2=tr->x;     y2=tr->y;  tr++;
x3=tr->x;     y3=tr->y;  
return abs(( (x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)) )/2);
}
void Triangle::set_point(Point *p){
    this->points=p;
}
void Triangle::point_print(){
    Point *temp=points;
    for(int i=0;i<number_of_points;i++){
        temp->point_print();
        temp++;
    }
    }
Triangle::Triangle(){
    cout<<"CREATING AN TRIANGLE \n";
    number_of_points=3;
}
void create_triangle(){

    Point p1,p2,p3;
    p1.x=0;
    p1.y=0;
    p2.x=10;
    p2.y=10;
    p3.x=25;
    p3.y=25;
    Point *point_of_triange;
    point_of_triange=new Point[3];
    point_of_triange[0]=p1;
    point_of_triange[1]=p3;
    point_of_triange[2]=p2;
    Triangle *t=new Triangle;
    t->set_point(point_of_triange);
    t->point_print();
   cout<<"THE AREA OF TRIANGLE IS "<<t->get_area()<<endl;
} 
user::user(){
    id=user::next_user_id();
}
int user::next_user_id(){
user::next_id++;
return user::next_id;
}
int user::get_id(){
    return id;
}
int fib(int n){
    static int count=0;
    count++;
    if(n<0){
        return count;
    }
    if(n==1||n==0){
        return  n;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
