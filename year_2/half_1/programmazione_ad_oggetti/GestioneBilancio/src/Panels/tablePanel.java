package Panels;

import DataTypes.MyTableModel;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.TableModelEvent;
import javax.swing.event.TableModelListener;
import javax.swing.table.JTableHeader;
import java.awt.*;
/**
 * Classe che definisce il pannello per la creazione della tabella
 */
public class tablePanel extends JPanel {
    private final static MyTableModel dataModel = new MyTableModel();

    private JTextField txtSum;
    private JTable t;

    /**
     * Costruttore della classe tablePanel
     */
    public tablePanel(){
        t = new JTable(dataModel);
        txtSum = new JTextField(10);
        JScrollPane scrollPane;
        setLayout(new BorderLayout());

        JTableHeader header = t.getTableHeader();
        header.setBackground(Color.yellow);
        t.setSelectionBackground(new Color(249,249,173));

        scrollPane = new JScrollPane(t);
        scrollPane.setColumnHeaderView(t.getTableHeader());

        //Comunico al tablemodel la voce selezionata dall'utente tramite mouse
        t.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                dataModel.setSelectedRow(t.getSelectedRow());
            }
        });

        txtSum.setEditable(false);
        txtSum.setForeground(Color.black);
        txtSum.setText("Total: ");

        dataModel.addTableModelListener(new TableModelListener() {
            @Override
            public void tableChanged(TableModelEvent e) {
                float totalAmount = dataModel.getSum();
                if(totalAmount>0)
                    txtSum.setForeground(new Color(0,113,0));
                else if(dataModel.getSum()<0)
                    txtSum.setForeground(Color.red);
                else
                    txtSum.setForeground(Color.black);
                txtSum.setText("Total: " + totalAmount);
            }
        });


        add(scrollPane, BorderLayout.NORTH);
        add(txtSum, BorderLayout.CENTER);
    }

    /**
     * Funzione che restituisce il tableModel
     * @return l'istanza del tableModel
     */
    public static MyTableModel getDataModel() {
        return dataModel;
    }


    /**
     * Funzione che restituidce l'oggetto JTable
     * @return oggetto JTable
     */
    public JTable getTable() {
        return t;
    }
}
