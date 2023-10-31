 public abstract class Polygon{
    int numSides;
    Polygon(){
        numSides=0;
        System.out.println("Creating polygon of side" + numSides);
    }
    Polygon(int num){
        this.numSides=num;
        System.out.println("Creating polygon of side" + numSides);
    }
    abstract double getArea();
    public static void main(String args[]){
        // Polygon p=new Polygon();
        Rectangle r=new Rectangle();
        r.setSides(4, 04);
        System.out.println(r.getArea());
    }
    
 }

 class Rectangle extends Polygon{
    int length,width;
    Rectangle(){super(4);}
    double getArea(){
        return this.length*this.width;
    }
    public  void setSides(int len,int wid){
        this.length=len;
        this.width=wid;
    }
 }
