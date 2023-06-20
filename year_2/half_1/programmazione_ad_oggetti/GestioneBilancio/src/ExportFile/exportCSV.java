package ExportFile;

import DataTypes.MyEntry;
import DataTypes.MyTableModel;

import java.io.FileWriter;
import java.io.IOException;
/**
 * Classe che estende Export per esportare il bilancio come file CSV (.csv)
 */
public class exportCSV extends Export{
    /**
     * Costruttore che crea un oggetto File a partire dal nome
     *
     * @param fileName nome del file da salvare
     */
    public exportCSV(String fileName) {
        super(fileName);
    }

    /**
     * Ovveride della funzione di Export, per esportare il bilancio come file CSV
     * @param tableModel table model da esportare su file
     */
    @Override
    public void exportTableModel(MyTableModel tableModel) {
        try {
            FileWriter fileWriter = new FileWriter(this.file);

            for (MyEntry entry : tableModel.getAllEntries(false)) {
                String toWrite = entry.getStringDate() + ", " + entry.getDescription() + ", " + entry.getAmount() + "\n";
                fileWriter.write(toWrite);
            }
            fileWriter.close();
        }
        catch(IOException e){}
    }
}
