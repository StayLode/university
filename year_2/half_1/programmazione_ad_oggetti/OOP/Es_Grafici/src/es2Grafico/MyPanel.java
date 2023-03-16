package es2Grafico;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class MyPanel extends JPanel implements ActionListener {
    private JTextField txtMain, txtVecchio, txtNuovo, txtRes;
    private JLabel lblOld, lblNew;
    private JButton butSos;

    public MyPanel(){
        super();

        txtMain=new JTextField(25);
        add(txtMain);

        lblOld=new JLabel("Vecchio Carattere");
        add(lblOld);

        txtVecchio=new JTextField(1);
        add(txtVecchio);

        lblNew=new JLabel("Nuovo Carattere");
        add(lblNew);

        txtNuovo=new JTextField(1);
        add(txtNuovo);

        txtRes=new JTextField(25);
        txtRes.setEditable(false);
        add(txtRes);

        butSos=new JButton("Sostituisci");
        butSos.addActionListener(this);
        add(butSos);

    }
    public void actionPerformed(ActionEvent e){
        char oldChar = txtVecchio.getText().charAt(0);
        char newChar = txtNuovo.getText().charAt(0);
        String oldText = txtMain.getText();

        String newText;

        newText = oldText.replace(oldChar,newChar);
        txtRes.setText(newText);
    }
}