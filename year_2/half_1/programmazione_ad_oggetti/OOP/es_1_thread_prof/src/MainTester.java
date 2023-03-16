import com.sun.tools.javac.Main;

public class MainTester {
    public int maxSleep;
    private int sleepCounter;
    private int n;

    public MainTester(int n){
        this.n=n;
    }

    public synchronized int getSleepCounter(){
        return sleepCounter;
    }

    public synchronized void setSleepCounter(int sleepCounter){
        this.sleepCounter=sleepCounter;
    }

    public synchronized void incSleepCounter(){
        sleepCounter++;
    }

    public static void main(String[] args) {
        MainTester mt = new MainTester(10);
        MioThread[] threads=new MioThread[mt.n];
        for(int i =0;i<mt.n;i++){
            threads[i] = new MioThread(i,mt);
            threads[i].start();
        }
        for(int i =0;i<mt.n;i++){
            threads[i].join();
        }
    }
}