package Panels;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SearchPanel extends JPanel implements ActionListener {
    protected JTextField txtSearch = new JTextField(20);

    protected JButton btnSearch = new JButton("Search");
    protected JButton btnNext = new JButton("Next");
    private tablePanel t;

    public SearchPanel(tablePanel t) {
        super();
        this.t=t;
        btnNext.setVisible(false);
        btnSearch.addActionListener(this);
        this.add(txtSearch);
        this.add(btnSearch);
        this.add(btnNext);
    }
        public void actionPerformed(ActionEvent e) {
        //rbtnDef.doClick();
        String occ=txtSearch.getText();
        int[] v= t.getDataModel().getXY(occ);
        System.out.println(v[0]+" "+v[1]);
        if (v[0]!=-1 || v[1]!=-1) {
            t.getTable().setColumnSelectionInterval(v[1], v[1]);
            t.getTable().setRowSelectionInterval(v[0], v[0]);
        }

    }
}



