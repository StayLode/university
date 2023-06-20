package Menu;

import Panels.tablePanel;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.print.PrinterException;

/**
 * Classe per definire l'ActionListener per la stampa della tabella
 */
public class printActionListener implements ActionListener {

    private final tablePanel tableP;
    public printActionListener(tablePanel tableP) {
        this.tableP=tableP;
    }

    /**
     * Ovverride dell'ActionPerformed, in cui viene richiamato il metodo per effettuare la stampa
     * @param e evento
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        try{
            tableP.getTable().print();
        } catch (PrinterException ex) {
            JOptionPane.showMessageDialog(null, "Printer not found! ", "Gestione Bilancio", JOptionPane.ERROR_MESSAGE);
        }
    }
}
