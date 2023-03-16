package Panels;

import My.*;

import javax.swing.*;
import javax.swing.table.TableRowSorter;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FilterPanel extends JPanel{
    protected ButtonGroup bg = new ButtonGroup();
    protected JRadioButton rbtnDef = new JRadioButton("Default", true);
    protected JRadioButton rbtnDay = new JRadioButton("Day");
    protected JRadioButton rbtnWeek = new JRadioButton("Week");
    protected JRadioButton rbtnYear = new JRadioButton("Year");
    protected JRadioButton rbtnMonth = new JRadioButton("Month");
    private tablePanel p;
    public FilterPanel(tablePanel p) {
        JPanel panel = new JPanel();

        this.p=p;
        MyTableModel dataModel = p.getDataModel();
        TableRowSorter myTableRowSorter= p.getMyTableRowSorter();
        JTextField txtSum = p.getTxtSum();
        rbtnDef.setHorizontalTextPosition(SwingConstants.LEFT);
        rbtnDay.setHorizontalTextPosition(SwingConstants.LEFT);
        rbtnWeek.setHorizontalTextPosition(SwingConstants.LEFT);
        rbtnYear.setHorizontalTextPosition(SwingConstants.LEFT);
        rbtnMonth.setHorizontalTextPosition(SwingConstants.LEFT);
        bg.add(rbtnDef);
        bg.add(rbtnDay);
        bg.add(rbtnWeek);
        bg.add(rbtnMonth);
        bg.add(rbtnYear);

        ActionListener rbtnActionListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                AbstractButton a = (AbstractButton) e.getSource();
                myTableRowSorter.setRowFilter(new MyRowFilter(a.getText()));
                txtSum.setText("Total: " + dataModel.getSum());
            }
        };
        rbtnDay.addActionListener(rbtnActionListener);
        rbtnWeek.addActionListener(rbtnActionListener);
        rbtnMonth.addActionListener(rbtnActionListener);
        rbtnYear.addActionListener(rbtnActionListener);
        rbtnDef.addActionListener(rbtnActionListener);

        panel.add(rbtnDef);
        panel.add(rbtnDay);
        panel.add(rbtnWeek);
        panel.add(rbtnMonth);
        panel.add(rbtnYear);


       add(panel);
    }
}
