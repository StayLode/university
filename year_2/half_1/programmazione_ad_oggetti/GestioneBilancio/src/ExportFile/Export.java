package ExportFile;

import DataTypes.MyTableModel;
import java.io.File;

/**
 * Classe astratta per la "predisposizione" all'esportazione in un determinato formato di file
 */
public abstract class Export {
    protected String fileName;
    protected File file;

    /**
     * Costruttore che crea un oggetto File a partire dal nome
     * @param fileName nome del file da salvare
     */
    public Export(String fileName)  {
        this.fileName = fileName;
        this.file = new File(this.fileName);
    }

    /**
     * Metodo da sovrascrivere per definire come eseguire l'esportazione
     * @param tableModel table model da esportare su file
     */
    public abstract void exportTableModel(MyTableModel tableModel);

}
