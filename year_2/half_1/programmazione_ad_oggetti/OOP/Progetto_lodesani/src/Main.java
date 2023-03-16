
import My.MyPanel;

import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Progetto Lodesani");
        MyPanel p = new MyPanel();
        frame.setLayout(new BorderLayout());
        frame.add(p, BorderLayout.CENTER);

        frame.pack();
        frame.setResizable(false);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}