import java.io.Serializable;

public class Libro  implements Serializable {
    String titolo;
    int nrCopie;
    String autore;
    private static final long serialVersionUID=1;

    public Libro(String titolo, int nrCopie, String autore) {
        this.titolo = titolo;
        this.nrCopie = nrCopie;
        this.autore = autore;
    }

    public void Prestito(){
        this.nrCopie--;
    }
    public void Restituzione(){
        this.nrCopie++;
    }

    @Override
    public String toString() {
        return "Titolo: " + titolo + ", Numero di copie : " + nrCopie + ", Autore : " + autore;
    }
}