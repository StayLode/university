package Panels;

import DataTypes.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Calendar;
import java.util.Date;

import org.jdatepicker.ComponentColorDefaults;
import org.jdatepicker.JDatePicker;
import org.jdatepicker.UtilDateModel;

/**
 * Classe che definisce il pannello per la gestione del bilancio<br>
 * - Aggiunta voce;<br>
 * - Rimozione voce; <br>
 * - Modifica voce;<br>
 */
public class managePanel extends JPanel implements ActionListener {
    private JPanel p1 = new JPanel();
    private JPanel p2 = new JPanel();
    private JLabel lblDesc, lblAmount, lblDate;

    private JButton btnSubmit;
    private JTextField txtDesc, txtAmount;
    private JComboBox cbType;
    private JDatePicker datepicker;
    private tablePanel p;
    private filterPanel fp;
    private JOptionPane paneError;
    private float amount;
    private MyTableModel dataModel;

    /**
     * Costruttore della classe managePanel
     * @param p tablePanel
     * @param fp filterPanel
     */
    public managePanel(tablePanel p, filterPanel fp){
        this.p=p;
        this.fp=fp;

        dataModel = p.getDataModel();
        setLayout(new BorderLayout());

        lblDate = new JLabel("Date:");
        lblDesc = new JLabel("Description:");
        lblAmount = new JLabel("Amount:");

        ComponentColorDefaults colors = ComponentColorDefaults.getInstance();
        colors.setColor(ComponentColorDefaults.Key.FG_MONTH_SELECTOR, Color.WHITE);
        datepicker = new JDatePicker (new UtilDateModel(new Date()), "dd/MM/yyyy");

        txtDesc = new JTextField(18);
        txtAmount = new JTextField(10);
        txtAmount.setText(String.format("%.2f", 0.0));

        String []types = {"Add"};
        cbType = new JComboBox(types);

        btnSubmit = new JButton("Submit") ;
        btnSubmit.addActionListener(this);

        p1.add(lblDate);
        p1.add(datepicker);
        p1.add(lblAmount);
        p1.add(txtAmount);
        p1.add(lblDesc);
        p1.add(txtDesc);

        p2.add(cbType);
        p2.add(btnSubmit);

        add(p1, BorderLayout.NORTH);
        add(p2, BorderLayout.CENTER);
    }

    /**
     * Action Performed per la aggiunta, modifica ed eliminazione delle voci
     * @param e evento
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        String s_amount=txtAmount.getText().replace(',','.');
        String desc,date;
        MyEntry elem;
        int index;
        switch(cbType.getSelectedItem().toString()) {
            case "Add":
                if (!checkAmount(s_amount)) {
                    txtAmount.setText(String.format("%.2f", 0.0));
                    txtAmount.setBorder(new LineBorder(Color.RED, 2));
                } else if (!checkDefault(fp.bg)) {
                    paneError = new JOptionPane();
                    paneError.showMessageDialog(null, "Impostare visualizzazione default", "Error", JOptionPane.WARNING_MESSAGE);
                } else if (Float.parseFloat(s_amount) != 0.0f) {
                    desc = txtDesc.getText();
                    date = datepicker.getFormattedTextField().getText();
                    elem = new MyEntry(date, desc, amount);
                    if (dataModel.getRowCount() == 0) {
                        cbType.addItem("Modify");
                        cbType.addItem("Delete");
                    }
                    dataModel.addRow(elem);
                    resetField();

                }
                break;

            case "Modify":
                if (!checkAmount(s_amount)) {
                    txtAmount.setText(String.format("%.2f", 0.0));
                    txtAmount.setBorder(new LineBorder(Color.RED, 2));
                } else if (!checkDefault(fp.bg)) {
                    paneError = new JOptionPane();
                    paneError.showMessageDialog(null, "Impostare visualizzazione default", "Error", JOptionPane.WARNING_MESSAGE);
                } else if (Float.parseFloat(s_amount) != 0.0f) {
                    desc = txtDesc.getText();
                    date = datepicker.getFormattedTextField().getText();

                    index = dataModel.getSelectedRow();
                    if(index >= 0)
                        dataModel.modifyElem(index, date, desc, amount);
                    resetField();
                }
                break;

            case "Delete":
                if (checkDefault(fp.bg)) {
                    index = dataModel.getSelectedRow();
                    if(index >= 0)
                        dataModel.removeRow(index); //Rimozione elemento da tabella (vettore)

                    if (dataModel.getRowCount() == 0) {
                        cbType.removeItem("Modify");
                        cbType.removeItem("Delete");
                    }
                    resetField();
                } else {
                    paneError = new JOptionPane();
                    paneError.showMessageDialog(null, "Impostare visualizzazione default", "Error", JOptionPane.WARNING_MESSAGE);
                }
                break;
        }
    }

    /**
     * Metodo per controllare se il TextField contenente l'importo contiene un valore valido
     * @param s_amount importo nel TextField
     * @return true se valore è valido, false altrimenti
     */
    public boolean checkAmount(String s_amount){
        try {
            amount = Float.parseFloat(s_amount);
            return true;
        } catch (NumberFormatException exception) {
            return false;
        }
    }

    /**
     * Metodo per resettare i campi della data, descrizione e importo
     */
    public void resetField(){
        txtAmount.setText(String.format("%.2f", 0.0));
        txtDesc.setText("");
        txtAmount.setBorder(UIManager.getLookAndFeel().getDefaults().getBorder("TextField.border"));

        Calendar calendar = Calendar.getInstance();
        datepicker.getModel().setDate(calendar.get(Calendar.YEAR),calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH) );
        
    }

    /**
     * Metodo per controllare se si è nella visualizzazione di default
     * @param bg ButtonGroup per controllare il valore del RadioButton selezionato
     * @return true se si è nella visualizzazione di default, false altrimenti
     */
    public boolean checkDefault(ButtonGroup bg){
        if (bg.getSelection().getActionCommand() == "Def")
            return true;
        return false;
    }


    /**
     * Metodo usato per ottenere il ComboBox dei tipi di azioni disponibili
     * @return JComboBox dei tipi di azione
     */
    public JComboBox getCbType(){
        return this.cbType;
    }


}
