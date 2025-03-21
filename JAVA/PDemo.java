class MultiplicationTable implements Runnable{
    public void run(){

    System.out.println("multiplication table");
    for(int i=1;i<=10;i++){
        System.out.println("5*"+i+"="+(5*i));
        try{
            Thread.sleep(200);
        }catch(InterruptedException e){
            e.printStackTrace();
        }
        }
    }
}
class Factorfinder implements Runnable{
    public void run(){
    int number=36;  
       System.out.println("Factor"+number+":");
        for(int i=1;i<=number;i++){
            if(number%i==0){
                System.out.println("factor"+i);
            }
            try{
                Thread.sleep(300);
            }catch(InterruptedException e){
                e.printStackTrace();
            }
    }
}
}
public class PDemo{
    public static void main(String[] args) {
        MultiplicationTable tableTask=new MultiplicationTable();
        Factorfinder factorTask=new Factorfinder();

        Thread tableThread=new Thread(tableTask);
        Thread factorThread=new Thread(factorTask);

        tableThread.start();
        factorThread.start();

        System.out.println("main thread continues..");
        try{
            tableThread.join();
            factorThread.join();
        }
        catch(InterruptedException e){
            e.printStackTrace();
        }
        System.out.println("Both threads are finished");
}
}

