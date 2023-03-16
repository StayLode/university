import javax.swing.*;

public class MainTester {

    public int maxSleep=0;
    private int sleepCounter;



    public int getSleepCounter() {
        return sleepCounter;
    }

    public void setSleepCounter(int sleepCounter) {
        this.sleepCounter = sleepCounter;
    }

    public static void main(String[] args) {
        new MainTester(250);
    }
    public MainTester(int n) {
        Thread[] t=new Thread[n];

        for(int i=0;i<n;i++)
            t[i]=new MioThread(i,this);

        for(int i=0; i<n;i++)
            t[i].start();

        for(int i=0;i<n;i++) {
            try {
                t[i].join();
            } catch (InterruptedException e) {
                System.out.println(e.getStackTrace());
            }
        }

        System.out.println("Quanti hanno dormito: "+sleepCounter);
        if(sleepCounter==n)
            System.out.print("Tutto Ok");
        else
            System.out.print("Errore");

        System.out.println("Durata massima di sleep di un thread: "+maxSleep);
    }

    public synchronized void incCounter(){
        sleepCounter++;
    }
}