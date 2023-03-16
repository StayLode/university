
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

public class Rubrica {
    private List<Contatto> l;

    public Rubrica() {
        //l = new ArrayList<Contatto>();
        l = new Vector<Contatto>();
    }

    public void addContact(Contatto c){
        l.add(c);
    }
    public void remContact(Contatto c){
        l.remove(c);
        /*
        Se ci sono più occorrenze dello stesso contatto le rimuove tutte e ritorna il numero di contattti rimossi
        int rimossi=0;
        while (l.remove(c))
            rimossi++;
        return rimossi
         */
    }

    public void remAll(){
        l.removeAll(l);
    }

    public Contatto SearchContact(String sur){
        for(Contatto c: l)
            if(c.getCognome().equals(sur)) {
                System.out.println("Contatto trovato:" +c.getTelefono());
                return c;
            }
        System.out.println("Contatto non trovato!");
        return null;
    }

    @Override
    public String toString() {
        return "Rubrica{" +
                "l=" + l +
                '}';
    }
}
