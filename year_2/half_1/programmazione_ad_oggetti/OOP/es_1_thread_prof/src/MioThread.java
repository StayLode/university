import java.util.Random;

public class MioThread extends Thread{
    private MainTester mt;
    private int id;
    public MioThread(int id,MainTester mt){
        super();
        this.id=id;
        this.mt=mt;
    }
    public void run(){
        Random rnd = new Random(id);
        int numCasuale = rnd.nextInt(50)+100;

        try {
            Thread.sleep(numCasuale);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        synchronized (mt) {
            int sc = mt.getSleepCounter();
            sc++;
            mt.setSleepCounter(sc);
        }
        if(numCasuale>mt.maxSleep)
            mt.maxSleep=numCasuale;

    }
}
