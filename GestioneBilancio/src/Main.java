
import Panels.mainPanel;

import javax.swing.*;
import java.awt.*;

/**
 * Classe Main nella quale viene creato il JFrame e il mainPanel, aggiunto in seguito al frame<br>
 * Vengono inoltre definite le specifiche del frame
 */
public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Progetto Lodesani");
        mainPanel p = new mainPanel(frame);
        frame.setLayout(new BorderLayout());
        frame.add(p, BorderLayout.CENTER);


        frame.pack();
        frame.setResizable(false);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.setVisible(true);

    }
}