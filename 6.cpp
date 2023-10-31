#include<iostream>
#include<fstream>
#include<string>
using namespace  std;
class Plugin{
	public:
	virtual void apply_filter(int img[5][5])=0;//=0 makes it pure virtual function
	//pure virtual function can't be called bcz they dont have defination or body
	//virtual function is not called if it is overridden
	//pure virtual function are called abstract function in other languages
	//if class has even one abstract function the whole class would be called abstract
};
class Made_black: public Plugin {
	public:
	void apply_filter(int img[5][5]) ;
};
class Made_white:public Plugin{
	public:
	void apply_filter(int img[5][5]) ;

};
void int_array(int a[5][5]);
void show_array(int a[5][5]);
Plugin* get_filter();
 main()
{
 int a[5][5];
 int_array(a);
 cout<<"INITIALIZING ARRAY"<<endl;
 show_array(a);
 /*
 made_black mib;
 made_white miw;
 mib.apply_filter(a);
 show_array(a);
 miw.apply_filter(a);
 show_array(a);
 */
  
Plugin *p;
p=get_filter();
p->apply_filter(a);
cout<<"AFTER APPLICATION OF PLUGIN"<<endl;

show_array(a);

 }
 void Made_black::apply_filter(int img[5][5]){
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		img[i][j]=0;
		}
 void Made_white::apply_filter(int img[5][5]){
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		img[i][j]=255;
 
 }
 void int_array(int a[5][5]){
	int val=0;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++){
		a[i][j]=val;
		val++;}	
 }
 void show_array(int a[5][5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
		{
		cout<<a[i][j]<<'\t';}
		cout<<endl;
	}
 }
 Plugin* get_filter(){
Plugin *p;
string plugin_name="miw";

if(plugin_name == "miw"){
	p=new Made_black ;
}
else{
	p=new Made_white;
}
return p;
 }