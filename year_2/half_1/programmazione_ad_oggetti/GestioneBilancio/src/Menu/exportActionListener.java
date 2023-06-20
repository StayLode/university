package Menu;

import DataTypes.MyTableModel;
import ExportFile.Export;
import ExportFile.exportCSV;
import ExportFile.exportODS;
import ExportFile.exportTXT;
import Panels.tablePanel;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Classe per definire l'ActionListener degli export
 */
public class exportActionListener implements ActionListener {
    private final tablePanel tableP;
    public exportActionListener(tablePanel tableP){
        this.tableP=tableP;
    }

    /**
     * Ovverride dell'ActionPerformed, in cui viene eseguito l'export scelto dal Menu<br>
     * In base all'export scelto, viene istanziato un oggetto della rispettiva classe e richiamato il metodo astratto
     * @param e evento
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        MyTableModel dataModel = this.tableP.getDataModel();

        // Controllo se ci sono entries visualizzate da esportare
        if(!dataModel.getAllEntries(false).isEmpty()){

                // Generico oggetto Export che viene specializzato nel momento in cui si sceglie il formato di export
                Export export;

                String exportType = e.getActionCommand();
                String fileName;
                int returnValue;


                JFileChooser fileChooser = new JFileChooser();
                fileChooser.setAcceptAllFileFilterUsed(false);

                switch (exportType){
                    case "CSV":
                        fileChooser.setFileFilter(new FileNameExtensionFilter("*.csv", "csv"));
                        returnValue = fileChooser.showSaveDialog(null);
                        if (returnValue == JFileChooser.APPROVE_OPTION) {
                            fileName = fileChooser.getSelectedFile().getAbsolutePath();

                            if(!fileName.endsWith(".csv"))
                                fileName = fileName + ".csv";

                            export = new exportCSV(fileName);
                            export.exportTableModel(dataModel);
                            JOptionPane.showMessageDialog(null, "Visualised entries successfully exported!", "Gestione Bilancio", JOptionPane.PLAIN_MESSAGE);
                        }
                        break;

                    case "TXT":
                        fileChooser.setFileFilter(new FileNameExtensionFilter("*.txt", "txt"));
                        returnValue = fileChooser.showSaveDialog(null);
                        if (returnValue == JFileChooser.APPROVE_OPTION) {
                            fileName = fileChooser.getSelectedFile().getAbsolutePath();

                            if(!fileName.endsWith(".txt"))
                                fileName = fileName + ".txt";

                            export = new exportTXT(fileName);
                            export.exportTableModel(dataModel);
                            JOptionPane.showMessageDialog(null, "Visualised entries successfully exported!", "Gestione Bilancio", JOptionPane.PLAIN_MESSAGE);
                        }
                        break;

                    case "ODS":
                        fileChooser.setFileFilter(new FileNameExtensionFilter("*.ods", "ods"));
                        returnValue = fileChooser.showSaveDialog(null);
                        if (returnValue == JFileChooser.APPROVE_OPTION) {
                            fileName = fileChooser.getSelectedFile().getAbsolutePath();

                            if(!fileName.endsWith(".ods"))
                                fileName = fileName + ".ods";

                            export = new exportODS(fileName);
                            export.exportTableModel(dataModel);
                            JOptionPane.showMessageDialog(null, "Visualised entries successfully exported!", "Gestione Bilancio", JOptionPane.PLAIN_MESSAGE);
                        }
                        break;
                    default:
                        break;
                }
            }
            else{
                String errorMessage = "No entries to export!";
                JOptionPane.showMessageDialog(null, errorMessage,"Gestione Bilancio", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

