class CPU
  {
    int price;
    public CPU(int a){
        price=a;

    }
    public void display()
     {
        System.out.println("Price:"+price);
     }

     class Processor
      {
        int cores;
        String manufactures;
        public Processor(int c,String m)
         {
            cores=c;
            manufactures=m;

         }

          public void show()
     {
        System.out.println("Cores:"+cores+" "+"Manufactures:"+manufactures);
     }

      }

      static class RAM
  {
    String memory;
    String manufacture;
    public RAM(String m,String k){
        memory=m;
        manufacture=k;
    }
    void dis()
    {
        System.out.println("Memory:"+ memory +" "+"manufacture:"+ manufacture);
    }
  }
  }

class CpuDemo{
    public static void main(String[] arg){
        CPU c=new CPU(120000);
        CPU.Processor p=c.new Processor(4,"ASUS");
        CPU.RAM r=new CPU.RAM("8","ASUS");
        c.display();
        p.show();
        r.dis();
    }
}