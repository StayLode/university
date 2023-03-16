package es1omino;

import java.util.TimerTask;

public class Animatore extends TimerTask //estendere TimerTask ci obbliga a fare override del metodo "run"
{
	private PannelloConOminoBello pannelloRiferimento;

	public Animatore(PannelloConOminoBello pannelloRiferimento) //passiamo un riferimento al pannello da cambiare
	{
		this.setPannelloRiferimento(pannelloRiferimento);
	}
	
	@Override
	public void run() {
		
		pannelloRiferimento.anima();
		
	}

	public PannelloConOminoBello getPannelloRiferimento() {
		return pannelloRiferimento;
	}

	public void setPannelloRiferimento(PannelloConOminoBello pannelloRiferimento) {
		this.pannelloRiferimento = pannelloRiferimento;
	}

}
