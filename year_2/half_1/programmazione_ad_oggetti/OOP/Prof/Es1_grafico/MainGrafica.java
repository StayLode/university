package es1omino;

import javax.swing.JFrame;

public class MainGrafica {

	public static void main(String[] args) {
			new MainGrafica();
	}
	
	
	public MainGrafica(){
		
		JFrame frame = new JFrame("Pannello Con Omino");
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(800,600);
	
		
		//PannelloConOmino pannello = new PannelloConOmino();
		PannelloConOmino pannello = new PannelloConOminoBello();
		
		frame.add(pannello);
	
		
		frame.setLocationRelativeTo(null); //centra il frame
		
		if(pannello instanceof PannelloConOminoBello){
			frame.setTitle(frame.getTitle() + " Bello");
		}
		
		frame.setVisible(true);
		
	}
	
	
	

}
