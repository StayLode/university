package ExportFile;

import DataTypes.MyTableModel;
import org.jopendocument.dom.spreadsheet.SpreadSheet;

import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;
import java.io.File;
import java.io.IOException;

/**
 * Classe che estende Export per esportare il bilancio come file OpenDocument (.ods)
 */
public class exportODS extends Export{
    /**
     * Costruttore che crea un oggetto File a partire dal nome
     *
     * @param fileName nome del file da salvare
     */
    public exportODS(String fileName) {
        super(fileName);
    }
    /**
     * Ovveride della funzione di Export, per esportare il bilancio come file OpenDocument
     * @param tableModel table model da esportare su file
     */
    @Override
    public void exportTableModel(MyTableModel tableModel) {
        try{
            TableModel exportModel = new DefaultTableModel(tableModel.getEntriesAsObject(), tableModel.getHeaders());
            SpreadSheet.createEmpty(exportModel).saveAs(this.file);
        }catch (IOException e){}

    }
}
