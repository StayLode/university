import java.awt.*;
import javax.swing.*;
public class Omino extends JPanel {
    int x;
    int y;
    int dimT;
    public Omino(int x, int y, int dimT){
        this.x = x;
        this.y = y;
        this.dimT = dimT;
    }
    /*public void disegnaFaccia(Graphics g){
        int centroX=x+dimT/2,centroY=y+dimT/2;

        int raggio=dimT/2;
        g.drawOval(centroX,centroY, 5,5);
        g.drawOval((int)(centroX-raggio*0.25), (int)(centroY-raggio*0.25raggio*0.25), (int)(raggio*0.25),(int)(raggio*0.25));

        g.drawOval((int)(centroX+raggio*0.25), (int)(centroY-raggio*0.25), (int)(raggio*0.25),(int)(raggio*0.25));
    }*/
    public void disegnaOmino(Graphics g){
        int start_x=x+(dimT/2);
        int start_y=y+(dimT);
        int raggio=dimT/2;

        g.drawOval(x,y,dimT,dimT);
        g.drawLine(start_x,start_y, start_x,start_y+raggio*3);
        g.drawLine(start_x,start_y, (int)(start_x+raggio*0.7), (int)(start_y+raggio*1.5));
        g.drawLine(start_x,start_y, (int)(start_x-raggio*0.7), (int)(start_y+raggio*1.5));
        g.drawLine(start_x,start_y+raggio*3, (int)(start_x+raggio*0.7), (int)(start_y+raggio*4.5));
        g.drawLine(start_x,start_y+raggio*3, (int)(start_x-raggio*0.7), (int)(start_y+raggio*4.5));
        //disegnaFaccia(g);
    }


    @Override
    public void paint(Graphics g) {
        super.paint(g);   // chiamo il metodo paint di JPanel
        disegnaOmino(g);
    }
}