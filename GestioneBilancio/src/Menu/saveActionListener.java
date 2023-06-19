package Menu;

import DataTypes.MyEntry;
import DataTypes.MyTableModel;
import Panels.tablePanel;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

/**
 * Classe per definire l'ActionListener per la gestione del salvataggio su file dell'intero bilancio
 */
public class saveActionListener implements ActionListener {
    private final tablePanel tableP;
    public saveActionListener(tablePanel tableP){
        this.tableP=tableP;
    }

    /**
     * Override dell'Action Performed che dispone un file chooser e salva le varie voci serializzandole<br>
     * In caso di file già presente verrà chiesto se sovrascriverlo
     * @param e evento
     */
    @Override
    public void actionPerformed(ActionEvent e){
        MyTableModel dataModel = tableP.getDataModel();

        //Controllo se ci sono voci da salvare, solo in questo caso proseguo nel salvataggio
        if (!dataModel.getAllEntries(true).isEmpty()) {
            JFileChooser fileChooser = new JFileChooser();

            int returnValue = fileChooser.showSaveDialog(null);
            if (returnValue == JFileChooser.APPROVE_OPTION) {
                try {
                    File file = fileChooser.getSelectedFile();
                    if (file.exists()) {
                        returnValue = JOptionPane.showConfirmDialog(null, "Do you want to overwrite the file?", "Gestione Bilancio", JOptionPane.YES_NO_OPTION);
                        if(returnValue == JOptionPane.YES_OPTION) {
                            FileOutputStream fileOut = new FileOutputStream(file.getAbsolutePath());
                            ObjectOutputStream outputStream = new ObjectOutputStream(fileOut);

                            for (MyEntry entry : dataModel.getAllEntries(true))
                                outputStream.writeObject(entry);

                            outputStream.close();
                            fileOut.close();

                            JOptionPane.showMessageDialog(null, "Successfully Saved!", "Gestione Bilancio", JOptionPane.INFORMATION_MESSAGE);
                        }
                    }
                    else{
                        FileOutputStream fileOut = new FileOutputStream(file.getAbsolutePath());
                        ObjectOutputStream outputStream = new ObjectOutputStream(fileOut);

                        for (MyEntry entry : dataModel.getAllEntries(true))
                            outputStream.writeObject(entry);

                        outputStream.close();
                        fileOut.close();
                        JOptionPane.showMessageDialog(null, "Successfully Saved!", "Gestione Bilancio", JOptionPane.INFORMATION_MESSAGE);

                    }
                } catch (FileNotFoundException fileNotFoundException) {
                    JOptionPane.showMessageDialog(null, "File Not Found exception!", "Gestione Bilancio", JOptionPane.ERROR_MESSAGE);
                }
                catch (IOException IOexception) {
                    JOptionPane.showMessageDialog(null, "IO exception!", "Gestione Bilancio", JOptionPane.ERROR_MESSAGE);
                }
            }
        }
        else{
            String errorMsg = "No entries to save!";
            JOptionPane.showMessageDialog(null, errorMsg, "Gestione Bilancio", JOptionPane.ERROR_MESSAGE);
        }

    }
}