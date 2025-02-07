class Animal {
    private String species;
    int age;
    int weight;
    protected String color;

    public Animal(String species, int age, int weight, String color) {
        this.species = species;
        this.age = age;
        this.weight = weight;
        this.color = color;
    }

    public void displayAnimal() {
        System.out.println(age + " Years & " + weight + " kg " + species + " in " + color + " color");
    }
}

class Dog extends Animal {
    private String name;
    private String owner;

    public Dog(String species, int age, int weight, String color, String name, String owner) {
        super(species, age, weight, color);
        this.name = name;
        this.owner = owner;
    }

    public void displayDog() {
        displayAnimal();  
        System.out.println(name + " owned by " + owner);
    }
}

public class AnimalDemo {
    public static void main(String[] args) {
        Dog d = new Dog("Mammal", 2, 10, "Brown", "Jimmy", "Surya");
        d.displayDog();
    }
}
