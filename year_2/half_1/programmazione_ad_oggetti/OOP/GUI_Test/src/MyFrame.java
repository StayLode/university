import java.awt.*;
import javax.swing.*;
public class MyFrame extends JFrame{
    public MyFrame(){
        this("");
    }
    public MyFrame(String titolo){
        super(titolo);
        setBounds(200,100, 300,150);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}