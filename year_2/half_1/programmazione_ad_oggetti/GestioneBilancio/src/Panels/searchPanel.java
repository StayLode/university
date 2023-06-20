package Panels;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Classe che definisce la creazione del pannello per la ricerca delle voci
 */
public class searchPanel extends JPanel implements ActionListener {
    private JTextField txtSearch ;

    private JButton btnSearch;
    private JButton btnStop;
    private tablePanel t;

    /**
     * Costruttore della classe searchPanel
     * @param t tablePanel
     */
    public searchPanel(tablePanel t) {
        super();
        this.t=t;

        btnStop = new JButton("X");
        btnStop.setEnabled(false);

        txtSearch = new JTextField(20);
        btnSearch = new JButton("Search");

        this.add(txtSearch);
        this.add(btnSearch);
        this.add(btnStop);

        btnSearch.addActionListener(this);
        btnStop.addActionListener(this);

    }

    /**
     * ActionPerformed per la gestione dei pulsanti "cerca" e "x" nella ricerca<br>
     * @param e evento
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource()==btnStop){
            t.getTable().clearSelection();
            txtSearch.setText("");
            t.getDataModel().setLast(-1);
            btnStop.setEnabled(false);
        }
        else if(e.getSource()==btnSearch){
            btnStop.setEnabled(true);
            String occ=txtSearch.getText();
            int v = t.getDataModel().getXY(occ);
            if (v!=-1)
                t.getTable().setRowSelectionInterval(v, v);
        }

    }
}



