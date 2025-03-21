package geometry.shapes2D;
import geometry.interfaces.*;
public class implements calcArea,calcPerimeter{
    public double radius;
    public Circle(double r){
        radius=r;
    }
    public double area(){
        return math.PI*radius*radius;
    }
    public double perimeter(){
        return math.PI*2*radius;
    }
}