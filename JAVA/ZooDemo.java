class Zoo{
    String name;
    String [] encl;

    public Zoo(String name, String[] encl){
        this.name = name;
        this.encl = encl;
    }
    public void displayZoo(){
        System.out.println("Name: " + name);
        for(String x: encl)
            System.out.println(x);
    }

    public class Enclosure{
        String name, type, animals[];

        public Enclosure(String n, String t, String[] a){
            name = n;
            type = t;
            animals = a;
        }
        public void displayEnclosure(){
            System.out.println("Name: " + name + " Type: " + type);
            for(String x: animals)
                System.out.println(x);
        }
    }

    static class ZooInfo{
        String addr, phno;

        public ZooInfo(String a, String p){
            addr = a;
            phno = p;
        }
        public void displayZooInfo(){
            System.out.println("Address: " + addr + " Phone Number: " + phno);
        }
    }
}

public class ZooDemo{
    public static void main(String[] args) {
        String enclosures[] = {"Area-1", "Area-2", "Area-3"};
        String an[] = {"Zebra","Giraffe"};

        Zoo z = new Zoo("TVM Zoo", enclosures);
        Zoo.Enclosure en = z.new Enclosure("Grassland", "Outdoor", an);
        Zoo.ZooInfo info = new Zoo.ZooInfo("ABC Lane, TVM", "1234567890");
        z.displayZoo();
        en.displayEnclosure();
        info.displayZooInfo();
    }
}