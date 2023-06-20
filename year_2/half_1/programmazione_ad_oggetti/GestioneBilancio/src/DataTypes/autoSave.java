package DataTypes;

import java.io.*;

/**
 * Classe autoSave che estende Thread per salvare i dati della tabella in background in un file denominato "backup"
 */
public class autoSave extends Thread{
    private final MyTableModel dataModel;
    private File file = new File("backup");
    private static final int SECONDS = 10;

    /**
     * Costruttore della classe AutoSave
     * @param dataModel informazioni da salvare
     */
    public autoSave(MyTableModel dataModel) {
        super("AutoSave Thread");
        setDaemon(true);
        this.dataModel = dataModel;
    }

    /**
     * Metodo run del thread che salva il file in background ogni 10 secondi
     */
    public void run() {
        while (true) {
            try {
                sleep(SECONDS*1000);
            } catch (InterruptedException e) {}
            if (!dataModel.getAllEntries(true).isEmpty()) {
                FileOutputStream fileOut;
                try {
                    fileOut = new FileOutputStream(file.getAbsolutePath());
                    ObjectOutputStream outputStream = new ObjectOutputStream(fileOut);
                    for (MyEntry entry : dataModel.getAllEntries(true)) {
                        outputStream.writeObject(entry);
                    }
                    outputStream.close();
                    fileOut.close();
                }
                catch (FileNotFoundException e) {
                    System.out.println("AutoSave - File not Found!");
                }
                catch (IOException e) {
                    System.out.println("AutoSave - IO exception!");
                }
            }
        }
    }
}
