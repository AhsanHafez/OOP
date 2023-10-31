import java.util.*;
public class vectr {
    
    public static void main(String args[]){
        Vector v=new Vector<>();
        v.add(23);
        v.add("ahsan");
        print(v);
    }
    public static void print(Vector v){
        System.out.print("[");
        for(int i=0;i<v.size();i++){
        System.out.print(v.get(i));
        System.out.print (",");}
        System.out.println("]");
    }
}
