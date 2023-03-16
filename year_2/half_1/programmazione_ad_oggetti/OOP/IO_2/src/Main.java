import java.io.*;


public class Main{
    public static void main(String[] args) {
        esercizio1(args);
        //esercizio2e3(args);
    }

    private static void esercizio1(String[] args) {
        File f=new File("");
        File f_o = new File(f.getAbsolutePath()+File.separator+args[0]);

        try {
            FileWriter w = new FileWriter(f_o); //Classe di output notevole
            InputStreamReader line = new InputStreamReader(System.in); //Classe di Input notevole a cui passiamo system.in che è lo standard input
            BufferedReader l = new BufferedReader(line); //Permette di leggere una riga
            String s="";
            System.out.println("Scrivere del testo, termina con N");
            s=l.readLine();
            while(s.equals("N")!=true){
                w.write(s);
                w.write("\n");
                s=l.readLine();
            }
            System.out.println("Scrittura terminata con successo!");
            w.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    private static void esercizio2e3(String[] args) {
        File f=new File("");
        File f_o = new File(f.getAbsolutePath()+File.separator+args[0]);
        Libro libri[] = new Libro[3];
        libri[0]= new Libro("Prova1", 2, "Lode");
        libri[1]= new Libro("Prova2", 3, "Lode");
        libri[2]= new Libro("Prova3", 4, "Lode");

        System.out.print("Serializzazione...");
        try{
            FileOutputStream fout = new FileOutputStream(f_o);
            ObjectOutputStream os = new ObjectOutputStream(fout);
            os.writeObject(libri);
            os.close();
            System.out.println("effettuata!");
        }
        catch(IOException e){
            e.printStackTrace();
            System.exit(-1);
        }
        System.out.println("Deserializzazione: ");
        try{

            FileInputStream fin = new FileInputStream(f_o);
            ObjectInputStream is = new ObjectInputStream(fin);
            Libro l1[];

            l1=(Libro[])is.readObject();
            for(int i=0;i<l1.length;i++)
                System.out.println(l1[i].toString());

            is.close();
        }
        catch(EOFException e){}
        catch(IOException e){
            e.printStackTrace();
            System.out.println(e);
        }
        catch(ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}