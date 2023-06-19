package ExportFile;

import DataTypes.MyEntry;
import DataTypes.MyTableModel;

import java.io.FileWriter;
import java.io.IOException;
/**
 * Classe che estende Export per esportare il bilancio come file di testo (.txt)
 */
public class exportTXT extends Export{
    /**
     * Costruttore che crea un oggetto File a partire dal nome
     *
     * @param fileName nome del file da salvare
     */
    public exportTXT(String fileName) {
        super(fileName);
    }
    /**
     * Ovveride della funzione di Export, per esportare il bilancio come file di testo
     * @param tableModel table model da esportare su file
     */
    @Override
    public void exportTableModel(MyTableModel tableModel) {
        try {
            FileWriter fileWriter = new FileWriter(this.file);

            for (MyEntry entry : tableModel.getAllEntries(false)) {
                String toWrite = entry.getStringDate() + "\t" + entry.getDescription() + "\t" + entry.getAmount() + "\n";
                fileWriter.write(toWrite);
            }
            fileWriter.close();
        }
        catch(IOException e){}
    }

}
