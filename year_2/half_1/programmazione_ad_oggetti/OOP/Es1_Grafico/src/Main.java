import java.awt.*;
import javax.swing.*;
public class Main {
    public static void main(String[] args) {
        new Main();
    }

    public Main(){

        JFrame f = new JFrame();


        f.setSize(350, 500);
        
        f.setLocationRelativeTo(null);
        f.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        Omino panel = new Omino(100,50,50);
        f.add(panel);
        f.setVisible(true);
    }
}