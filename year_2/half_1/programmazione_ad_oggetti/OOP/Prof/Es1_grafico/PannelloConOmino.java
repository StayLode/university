package es1omino;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;

public class PannelloConOmino extends JPanel{

	private static final long serialVersionUID = 1L;
	
	protected int centroTestaX;
	protected int centroTestaY;
	
	private final static int LUNGHEZZA_CORPO = 180;
	private final static int LUNGHEZZA_GAMBA = 160;
	private final static int LUNGHEZZA_BRACCIO = LUNGHEZZA_GAMBA;

	public PannelloConOmino()
	{
		this.setBackground(Color.WHITE);
		centroTestaX = 200;
		centroTestaY = 200;
	}
	
	protected void disegnaOmino(Graphics g)
	{
		g.setColor(Color.BLACK);
		Graphics2D g2 = (Graphics2D) g;
		g2.setStroke(new BasicStroke(10));
		g2.fillOval(centroTestaX-50, centroTestaY-50, 100,100); //testa
		g2.drawLine(centroTestaX, centroTestaY+50, centroTestaX, centroTestaY+50+LUNGHEZZA_CORPO); //corpo
		g2.drawLine(centroTestaX, centroTestaY+50+LUNGHEZZA_CORPO, centroTestaX-50, centroTestaY+LUNGHEZZA_CORPO+LUNGHEZZA_GAMBA); //gamba sx
		g2.drawLine(centroTestaX, centroTestaY+50+LUNGHEZZA_CORPO, centroTestaX+50, centroTestaY+LUNGHEZZA_CORPO+LUNGHEZZA_GAMBA); //gamba dx
		g2.drawLine(centroTestaX, centroTestaY+50, centroTestaX-50, centroTestaY+LUNGHEZZA_BRACCIO); //braccio sx
		g2.drawLine(centroTestaX, centroTestaY+50, centroTestaX+50, centroTestaY+LUNGHEZZA_BRACCIO); //braccio dx
	}
	

	@Override
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		disegnaOmino(g);

	}
	
	
}
