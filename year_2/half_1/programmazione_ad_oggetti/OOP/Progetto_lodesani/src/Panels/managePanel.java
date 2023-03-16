package Panels;

import My.*;
import DataTypes.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class managePanel extends JPanel{


    private JPanel pc1 = new JPanel();
    private JPanel pc2 = new JPanel();
    private JPanel pc3 = new JPanel();
    private JLabel lblDesc, lblAmount, lblDate;

    private JButton btnSubmit;
    private JTextField txtDesc, txtAmount, txtDate;
    private JComboBox cbType, cbList;
    private JRadioButton rbtnDay, rbtnWeek, rbtnMonth, rbtnYear;
    private tablePanel p;
    public managePanel(tablePanel p){
        this.p=p;
        MyTableModel dataModel = p.getDataModel();
        JTextField txtSum = p.getTxtSum();
        setLayout(new BorderLayout());
        lblDate = new JLabel("Date:");
        lblDesc = new JLabel("Description:");
        lblAmount = new JLabel("Amount:");
        txtDate = new JTextField(10);
        txtDate.setText(MyEntry.getLocalDate().toString());
        txtDesc = new JTextField(18);
        txtAmount = new JTextField(10);

        String []types = {"Add"};
        cbType = new JComboBox(types);


        cbList = new JComboBox();
        cbList.setPreferredSize(new Dimension(300,25));
        /**
         * ActionListener per il ComboBox contenente le tipologie di azione sul conto
         * In questo modo, se selezionata la tipologia "Modify" e la voce della tabella,
         * verranno mostrati i valori nei rispettivi JTextField pronti ad essere modificati
         */
        cbList.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (cbType.getSelectedItem().toString().equals("Modify") && cbList.getSelectedItem()!=null){
                    String[] splitted = cbList.getSelectedItem().toString().split(";");
                    String date = splitted[0].trim();
                    String desc = splitted[1].trim();
                    String amount = splitted[2].trim();
                    txtDate.setText(date);
                    txtDesc.setText(desc);
                    txtAmount.setText(amount);
                }

            }
        });
        btnSubmit = new JButton("Submit") ;
        btnSubmit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e){
                String amount;
                String desc;
                String date;
                switch(cbType.getSelectedItem().toString()) {
                    case "Add":
                        amount = txtAmount.getText();
                        desc = txtDesc.getText();
                        Data elem = new Data(desc, amount);
                        if (!elem.check()) {
                            txtDesc.setBorder(new LineBorder(Color.RED, 2));
                            txtAmount.setBorder(new LineBorder(Color.RED, 2));
                        } else {
                            date = txtDate.getText();
                            elem = new MyEntry(date, desc, amount);
                            if (!elem.check()) {
                                txtDate.setBorder(new LineBorder(Color.YELLOW, 2));
                                txtDate.setText(MyEntry.getLocalDate().toString());
                            } else {
                                if (dataModel.getRowCount()==0){
                                    cbType.addItem("Modify");
                                    cbType.addItem("Delete");
                                }
                                dataModel.addRow((MyEntry) elem);
                                String entryBox = txtDate.getText() + "; " + txtDesc.getText() + "; " + txtAmount.getText();
                                cbList.addItem(entryBox);
                                p.editTextSum();
                                resetTextField();
                            }
                        }break;
                    case "Modify":
                        amount = txtAmount.getText();
                        desc = txtDesc.getText();

                        String entry = cbList.getSelectedItem().toString();

                        int index = dataModel.get_index(entry);

                        elem = new Data(desc, amount);
                        if (!elem.check()) {
                            txtDesc.setBorder(new LineBorder(Color.RED, 2));
                            txtAmount.setBorder(new LineBorder(Color.RED, 2));
                        } else {
                            date = txtDate.getText();
                            elem = new MyEntry(date, desc, amount);
                            if (!elem.check()) {
                                txtDate.setBorder(new LineBorder(Color.YELLOW, 2));
                                txtDate.setText(MyEntry.getLocalDate().toString());
                            } else {
                                cbList.removeItem(entry); //Rimozione item da ComboBox
                                dataModel.modifyElem(index, date, desc, amount);
                                cbList.addItem(date + "; " + desc + "; " + amount); //Inserimento nuovo elemento nel ComboBox
                                resetTextField();
                                txtSum.setText("Total: " + dataModel.getSum());
                                dataModel.fireTableDataChanged();
                            }
                        }
                        break;
                    case "Delete":
                        entry = cbList.getSelectedItem().toString();
                        cbList.removeItem(entry);   //Rimozione item da Combobox
                        index = dataModel.get_index(entry);
                        dataModel.removeRow(index); //Rimozione elemento da tabella (vettore)

                        if(dataModel.getRowCount()==0){
                            cbType.removeItem("Modify");
                            cbType.removeItem("Delete");
                        }
                        txtSum.setText("Total: " + dataModel.getSum());
                        resetTextField();
                        dataModel.fireTableDataChanged();
                        break;
                }

            }
        });



        pc1.add(lblDate);
        pc1.add(txtDate);
        pc1.add(lblAmount);
        pc1.add(txtAmount);
        pc1.add(lblDesc);
        pc1.add(txtDesc);

        pc2.add(cbType);
        pc2.add(cbList);
        pc2.add(btnSubmit);

        add(pc1, BorderLayout.NORTH);
        add(pc2, BorderLayout.CENTER);
    }

    public void resetTextField(){
        txtAmount.setText("");
        txtDate.setText(MyEntry.getLocalDate().toString());
        txtDesc.setText("");
        txtDate.setBorder(UIManager.getLookAndFeel().getDefaults().getBorder("TextField.border"));
        txtDesc.setBorder(UIManager.getLookAndFeel().getDefaults().getBorder("TextField.border"));
        txtAmount.setBorder(UIManager.getLookAndFeel().getDefaults().getBorder("TextField.border"));
    }

}
