import java.awt.*;
import javax.swing.*;
public class MyPanel extends JPanel {
    public void paint(Graphics g) {
        super.paint(g);   // chiamo il metodo paint di JPanel
        g.setColor(Color.gray);   // imposto il colore
        // white, gray, lightGray, darkGray, red, green,etc.
        g.fillRect(20, 20, 100, 80); // un rettangolo pieno
        // in posizione 20,20 e dimensioni 100,80
        g.setColor(Color.GREEN);  // cambio colore
        g.drawRect(30, 30, 80, 60);// un rettangolo vuoto
        g.setColor(Color.yellow);
        g.drawString("ciao", 50, 60); // disegno una stringa
    }
}