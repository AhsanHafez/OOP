#include <iostream>
using namespace std;
int determinant(int arr[2][2]);
void add_matrices(int arr[3][3],int arr2[3][3]);
void cofactors(int arr[3][3],int n);
void multiply_matrix(int arr[3][3],int arr2[3][3]);
void transpose(int arr[3][3]);

int main() 
{
  int x[3][3]={{3,4,5},{7,8,9},{6,10,11}};
  int x2[3][3]={{1,2,3},{4,5,6},{9,8,7}};
  multiply_matrix(x,x2);
transpose(x);
  
  return 0;
}


int determinant(int arr[2][2])
{
int x1=arr[0][0]*arr[1][1];
int x2=arr[1][0]*arr[0][1];
return x1-x2;
}


void add_matrices(int arr[3][3],int arr2[3][3])
{
for(int i=0;i<3;i++)
{
  for(int j=0;j<3;j++)
  {
  arr[i][j]+=arr2[i][j];  
  }
}  
}


void cofactors(int arr1[3][3],int n)
{
int ans[3][3];
  int currentrow=0,currentcolum=0;
  int temp[2][2];
for(int f=0;f<9;f++)
{int x=0,y=0;
for(int i=0;i<3;i++)
{
  if(i==currentrow){continue;}
  else{
    for(int j=0;j<3;j++)
    {
      if(j==currentcolum){continue;}
    temp[x][y]=arr1[i][j];
    if(y==1){x+=1;y=0;}
    else{y+=1;}
    
    }
    
    
    }
  
}
ans[currentrow][currentcolum]=determinant(temp);
if(currentcolum==2&&currentrow<2){currentcolum=0;currentrow+=1;}
else if(currentcolum==2&&currentrow==2){currentcolum=0;currentrow=0;}
else{currentcolum++;}

}
}

void multiply_matrix(int arr[3][3],int arr2[3][3])
{
    int rows=3,colum=3;
    int rows2=3,colum2=3; 
    int value;
    int product[rows][colum2];
if(rows2!=colum)
{
    cout<<"FOR MULTIPLICATION ROWS OF 1ST MATRIX AND COLUM OF 2ND MATRIX MUST BE SAME"<<endl;
    return ;
}
for(int i=0;i<rows;i++)
    {
        for(int j=0;j<colum;j++)
        {value=0;
        for(int k=0;k<colum;k++)
        {
            value+=arr[i][k]*arr2[k][j];
        } 
        product[i][j]=value;
        }
           
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<colum2;j++)
        {
            cout<<product[i][j]<<"\t";
        }
        cout<<endl;
    }

}

void transpose(int arr[3][3])
{
    int l[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++){l[i][j]=arr[i][j];}
    }
    int x=0;
    for(int i=0;i<3;i++)
    {x=0;
        for(int j=0;j<3;j++)
        {
         arr[x][i]=l[i][j];  
         if(x<3){x++;} 
        }
        
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++){cout<<arr[i][j];cout<<"\t";}
    cout<<endl;
    }
}