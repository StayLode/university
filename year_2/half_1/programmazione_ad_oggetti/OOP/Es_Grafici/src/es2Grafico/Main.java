package es2Grafico;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Esercizio 2");
        MyPanel p = new MyPanel();

        frame.add(p);
        frame.pack();
        frame.setSize(300,150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

    }
}