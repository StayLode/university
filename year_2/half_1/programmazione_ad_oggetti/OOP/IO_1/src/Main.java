import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //esercizio1(args);
        esercizio2e3(args);
    }

    private static void esercizio1(String[] args){
        File f =new File(""); //Non creo un file, ma un oggetto di tipo file
        System.out.println("La directory corrente: "+f.getAbsolutePath());

        if(args.length <2){
            System.out.println("Non mi hai dato abbastanza parametri!");
            System.exit(-1);
        }
        File f_in = new File(f.getAbsolutePath()+File.separator+args[0]);
        File f_out = new File(f.getAbsolutePath()+File.separator+args[1]); //Se il file non esiste lo crea

        try{
            FileInputStream fin = new FileInputStream(f_in);
            FileOutputStream fout = new FileOutputStream(f_out);
            //Non serve usare classi filtro, lavoriamo solo con singoli byte

            int c;
            while((c=fin.read())!=-1){  //read() legge 1 byte alla volta
                fout.write(c);
            }
            fin.close(); //Senza il close, il programma potrebbe finire prima che venga flushato lo stream
            fout.close();
        }
        catch(IOException e){
            System.out.println("IOException: "+e);

        }
    }

    private static void esercizio2e3(String[] args){
        File f =new File(""); //Non creo un file, ma un oggetto di tipo file
        System.out.println("La directory corrente: "+f.getAbsolutePath());


        File f_io = new File(f.getAbsolutePath()+File.separator+args[0]); //Se il file non esiste lo crea
        try {
            Scanner scanner = new Scanner(System.in);
            DataOutputStream os = new DataOutputStream(new FileOutputStream(f_io));

            for (int i = 0; i < 4; i++) {
                String s = scanner.next();
                int n = Integer.parseInt(s);
                os.writeInt(n);
            }
            scanner.close();
            os.close();
        }catch(IOException e){
            e.printStackTrace();
        }
        catch(NumberFormatException e1) {
            System.out.println("NumberFormatException: "+e1);
            System.exit(-1);
        }

        //Esercizio 3
        DataInputStream is=null;
        try{
            is = new DataInputStream(new FileInputStream(f_io));
            int c;
            while (true){
                c=is.readInt();
                System.out.println(c);
            }
        }
        catch(EOFException e){
            System.out.println("Fine del file");
        }
        catch(IOException e){
            System.out.println("IOException: "+e);
        }

    }
}