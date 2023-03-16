import com.sun.tools.javac.Main;

import java.util.Random;

public class MioThread extends Thread{
    private int id;
    private MainTester o;
    private Random rand;

    public MioThread(int id, MainTester obj){
        this.id=id;
        this.o=obj;
        rand = new Random(id);
    }

    @Override
    public void run(){
        int n_cas=100+rand.nextInt(51);
        System.out.println("Thread id["+this.id+"], dorme per "+n_cas+" millisecondi");
        try {
            Thread.sleep(n_cas);
        }catch(InterruptedException e){
            System.out.print(e.getStackTrace());
        }

        o.incCounter();

        synchronized (o){
            if(o.maxSleep<n_cas)
                o.maxSleep=n_cas;
        }
    }
}
