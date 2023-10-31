import java.util.*;

public class Animal {
    
  int legs=4;    
int getlegs(){
return this.legs;
}
public static void main(String args[]){
    Animal a=new Animal();
    System.out.println(a.legs);    
}
}
class Try{
    int x(){
        Animal y=new Animal();
        return y.legs;

    }
}