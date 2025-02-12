import java.util.Scanner;

interface Computable {
    double area();
    double perimeter();
}

class Circle implements Computable {
    double r;

    public Circle(double r) {
        this.r = r;
    }

    public double area() {
        return 3.14 * r * r;
    }

    public double perimeter() {
        return 2 * 3.14 * r;
    }
}

class Rectangle implements Computable {
    double l, b;

    public Rectangle(double l, double b) {
        this.l = l;
        this.b = b;
    }

    public double area() {
        return l * b;
    }

    public double perimeter() {
        return 2 * (l + b);
    }
}

public class ShapeDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        while (true) {
            System.out.println("1. Area of Circle");
            System.out.println("2. Area of Rectangle");
            System.out.println("3. Exit");
            System.out.print("Enter the choice: ");
            int ch = sc.nextInt();
            
            switch (ch) {
                case 1:
                    System.out.print("Enter the radius: ");
                    double r = sc.nextDouble();
                    Circle c = new Circle(r);
                    System.out.println("Area of Circle: " + c.area());
                    System.out.println("Perimeter of Circle: " + c.perimeter());
                    break;
                    
                case 2:
                    System.out.print("Enter the length: ");
                    double l = sc.nextDouble();
                    System.out.print("Enter the breadth: ");
                    double b = sc.nextDouble();
                    Rectangle rect = new Rectangle(l, b);
                    System.out.println("Area of Rectangle: " + rect.area());
                    System.out.println("Perimeter of Rectangle: " + rect.perimeter());
                    break;
                    
                case 3:
                    System.out.println("Exiting...");
                    System.exit(0);
                    break;
                    
                default:
                    System.out.println("Invalid choice, please try again.");
            }
        }
    }
}
