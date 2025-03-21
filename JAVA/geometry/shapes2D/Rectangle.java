package geometry.shapes2D;
import geometry.interfaces.*;
public class implements calcArea,calcPerimeter{
    public double len,wid;
    public Rectangle(double l,double w){
        len=l;
        wid=w;
    }
    public double area(){
        return l*b;
    }
    public double perimeter(){
        return 2*(len+wid);
    }
}