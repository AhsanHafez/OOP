#include<iostream>
#include<fstream>
using namespace std;
void init_matrix(int pixel[5][5]);
void print_pixel(int pixel[5][5]);
main()
{
ifstream fin;
ofstream fout;
fout.open("sample.txt");
fout<<"READING THE FILE........."<<endl;
fout.close();
string line;
fin.open("sample.txt");
while(fin)
{
getline(fin,line);
cout<<line<<endl;
}
fin.close();
int pixel[5][5];
cout<<"INITIALIZING MATRIX"<<endl;
 for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            pixel[i][j]=1+(i*j);
        }
    }
print_pixel(pixel);
fout.open("data.bin");
for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
    {
        fout.write((char*)&pixel[i][j],sizeof(int));
    }
}
fout.close();
cout<<"SETTING PIXELS TO 0 AGAIN"<<endl;
 init_matrix(pixel);
 print_pixel(pixel);

fin.open("data.bin");
for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
    {
        fin.read((char*)&pixel[i][j],sizeof(int) );
    }
}
fin.close();

cout<<"READING FROM FILE"<<endl;
print_pixel(pixel);
}





void init_matrix(int pixel[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            pixel[i][j]=0;
        }
    }
}
void print_pixel(int pixel[5][5]){

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<pixel[i][j]<<"\t";
        }
        cout<<endl;
    }
}