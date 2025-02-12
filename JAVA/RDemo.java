import java.util.Scanner;

interface Printable {
    public void display();
    public void show();
}

interface Computable {
    public double area();
    public double perimeter();
    public double volume();
}

interface Drawable {
    public void draw();
}

class Rectangle implements Printable, Computable, Drawable {
    double length, width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public void display() {
        System.out.println("Length: " + length + " Width: " + width);
    }

    public void show() {}

    public double area() {
        return length * width;
    }

    public double perimeter() {
        return 2 * (length + width);
    }

    public double volume() {
        return -1; 
    }

    public void draw() {
        System.out.println("Drawing a rectangle");
    }
}

class Sphere implements Printable, Computable, Drawable {
    double radius;
    public static final double PI = 3.14159; 

    Sphere(double radius) {
        this.radius = radius;
    }

    @Override
    public void display() {
        System.out.println("Radius: " + radius);
    }

    public void show() {}

    public double area() {
        return 4 * PI * radius * radius; 
    }

    public double perimeter() {
        return 2 * PI * radius; 
    }

    public double volume() {
        return (4.0 / 3) * PI * radius * radius * radius; 
    }

    public void draw() {
        System.out.println("Drawing a sphere");
    }
}

public class RDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the length of rectangle:");
        double length = sc.nextDouble();
        System.out.println("Enter the width of rectangle:");
        double width = sc.nextDouble();
        Rectangle r = new Rectangle(length, width);

        r.display();
        r.show();
        System.out.println("Area: " + r.area());
        System.out.println("Perimeter: " + r.perimeter());
        System.out.println("Volume: " + r.volume());
        r.draw();

        System.out.println("\nEnter the radius of sphere:");
        double radius = sc.nextDouble();
        Sphere s = new Sphere(radius);

        s.display();
        s.show();
        System.out.println("Area: " + s.area());
        System.out.println("Perimeter: " + s.perimeter());
        System.out.println("Volume: " + s.volume());
        s.draw();

        sc.close();
    }
}
