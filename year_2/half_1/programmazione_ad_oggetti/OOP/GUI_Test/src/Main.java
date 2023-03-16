import java.awt.*;
import javax.swing.*;
public class Main {
    public static void main(String[] args) {
        MyFrame f = new MyFrame("Demo");
        MyPanel panel = new MyPanel();
        f.add(panel);
        f.setVisible(true);
    }
}