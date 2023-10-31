public abstract class Plugin {
    public abstract void draw();
    public abstract void save();
    
    public static void main(String args[]){
        Plugin p= new pdf();
        p.draw();
    }


    
}

class pdf extends Plugin{
    public  void draw(){System.out.println("drawing pdf");}
    public void save(){System.out.println("saving pdf");}
}