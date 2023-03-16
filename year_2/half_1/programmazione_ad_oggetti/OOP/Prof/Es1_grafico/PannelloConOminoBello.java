package es1omino;

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.Timer;

import javax.imageio.ImageIO;

public class PannelloConOminoBello extends PannelloConOmino
{

	private static final long serialVersionUID = 1L;
	
	private final static int DELTA = 1;
	
	protected BufferedImage img;
	
	
	public PannelloConOminoBello(){
		this(false);
	}
	
	public PannelloConOminoBello(boolean conURL){
		

		Animatore animatore = new Animatore(this); 	 //questo estende TimerTask
		Timer timer = new Timer();			   	 //Oggetto timer
		timer.scheduleAtFixedRate(animatore, 0, 10); //Usando il timer scheduliamo il TimerTask
		
		try {
			
			if(conURL)
				img = ImageIO.read(new URL("https://i1.wp.com/noiradiomobile.org/wp-content/uploads/2016/07/sfondo-astratto-colori-macchie-172628.jpg?ssl=1"));
			else img = ImageIO.read(new File("sfondo.jpg"));
			
		} catch (Exception e) {
			
			e.printStackTrace();
		}
		
	
	}
	
	@Override
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		g.drawImage(img, 0, 0, null);
		disegnaOmino(g);
	}
	
	public BufferedImage getImg(){
		return img;
	}
	
	public void anima()
	{
		centroTestaX += DELTA;
		repaint();
		
		if(centroTestaX>this.getWidth()) centroTestaX=0;
	
	}
	
	
	

}
