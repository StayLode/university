package Menu;

import DataTypes.MyEntry;
import DataTypes.MyTableModel;
import Panels.managePanel;
import Panels.tablePanel;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

/**
 * Classe per definire l'ActionListener del caricamento di una gestione da file
 */
public class loadActionListener implements ActionListener {
    private final tablePanel tableP;
    private final managePanel manageP;
    public loadActionListener(tablePanel tableP, managePanel manageP){
        this.tableP=tableP;
        this.manageP=manageP;
    }

    /**
     * Override dell'Action Performed che dispone un JFileChooser e carica le voci de-serializzandole<br>
     * Viene comunicato che le voci non salvate vengono eliminate prima di caricare le nuove voci dal file
     * @param e evento
     */
    @Override
    public void actionPerformed(ActionEvent e){
        MyTableModel dataModel = tableP.getDataModel();

        String warningMsg = "Entries will be deleted, continue?";
        int response = JOptionPane.OK_OPTION;
        if (!dataModel.getAllEntries(true).isEmpty())
             response = JOptionPane.showConfirmDialog(null, warningMsg, "Gestione Bilancio", JOptionPane.YES_NO_OPTION);

        if (response == JOptionPane.OK_OPTION){
            if (manageP.getCbType().getItemCount()!=1) {
                manageP.getCbType().removeItem("Modify");
                manageP.getCbType().removeItem("Delete");
            }
            dataModel.removeAllEntries();

            JFileChooser fileChooser = new JFileChooser();
            int returnValue = fileChooser.showOpenDialog(null);
            if(returnValue == JFileChooser.APPROVE_OPTION){
                try{
                    FileInputStream fileIn = new FileInputStream(fileChooser.getSelectedFile().getAbsolutePath());
                    ObjectInputStream inputStream = new ObjectInputStream(fileIn);
                    if (manageP.getCbType().getItemCount()==1) {
                        manageP.getCbType().addItem("Modify");
                        manageP.getCbType().addItem("Delete");
                    }
                    try{
                        while(true) {
                            MyEntry entry =(MyEntry) inputStream.readObject();
                            dataModel.addRow(entry);
                        }
                    } catch (ClassNotFoundException ex) {}
                    catch(EOFException ex){
                        //Viene aggiornato il valore del JTextField del totale
                        inputStream.close();
                        fileIn.close();
                    }
                }
                catch (FileNotFoundException ex) {
                    JOptionPane.showMessageDialog(null, "File not found!", "Gestione Bilancio", JOptionPane.ERROR_MESSAGE);
                }
                catch (IOException ex) {
                    JOptionPane.showMessageDialog(null, "File not supported!", "Gestione Bilancio", JOptionPane.ERROR_MESSAGE);
                }
            }
        }
    }
}
