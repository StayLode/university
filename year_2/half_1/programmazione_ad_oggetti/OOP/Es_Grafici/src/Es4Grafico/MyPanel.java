package Es4Grafico;

import javax.swing.*;
import javax.swing.table.TableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class MyPanel extends JPanel implements ActionListener{

    private Contatto[] v = new Contatto[3];
    private JButton btnS;
    private JTextField txt, res;

    public MyPanel(){
        super();
        v[0]=new Contatto("Giacomo", "Cabri", "Via Vignolese", "12345");
        v[1]=new Contatto("Mario", "Rossi", "Via Campi", "543345");
        v[2]=new Contatto("Carlo", "Bianchi", "Via Araldi", "25844");

        TableModel dataModel = new MyTableModel(v);

        JPanel pn = new JPanel();
        JTable t=new JTable(dataModel);
        pn.add(t);

        JPanel pc = new JPanel();
        txt = new JTextField(20);
        btnS = new JButton("Cerca");
        pc.add(txt);
        pc.add(btnS);
        btnS.addActionListener(this);

        JPanel ps = new JPanel();
        res = new JTextField(20);
        res.setEditable(false);
        ps.add(res);

        setLayout(new BorderLayout());
        add(pn, BorderLayout.NORTH);
        add(pc, BorderLayout.CENTER);
        add(ps, BorderLayout.SOUTH);

    }
    public void actionPerformed(ActionEvent e){
        String occ=txt.getText();
        for(Contatto tmp: v)
            if(tmp.getNome().contains(occ) || tmp.getCognome().contains(occ)||tmp.getTelefono().contains(occ)||tmp.getIndirizzo().contains(occ))
                res.setText("Trovato "+tmp.getNome()+" "+tmp.getCognome());


    }
}