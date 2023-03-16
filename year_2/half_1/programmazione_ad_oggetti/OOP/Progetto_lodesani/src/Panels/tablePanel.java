package Panels;

import My.*;
import javax.swing.*;
import javax.swing.table.JTableHeader;
import javax.swing.table.TableRowSorter;
import java.awt.*;
import java.awt.event.MouseEvent;

public class tablePanel extends JPanel {
    protected static MyTableModel dataModel = new MyTableModel();

    protected JTextField txtSum = new JTextField(10);
    protected JTable t;
    protected TableRowSorter myTableRowSorter;

    public tablePanel(){
         t = new JTable(dataModel){
            public String getToolTipText( MouseEvent e )
            {
                int row = rowAtPoint( e.getPoint() );
                int column = columnAtPoint( e.getPoint() );

                Object value = getValueAt(row, column);
                return value == null ? null : value.toString();
            }
        };
        JScrollPane scrollPane;
        setLayout(new BorderLayout());

        JTableHeader header = t.getTableHeader();
        header.setBackground(Color.yellow);
        myTableRowSorter = new TableRowSorter(dataModel);
        t.setRowSorter(myTableRowSorter);
        t.setCellSelectionEnabled(true);
        scrollPane = new JScrollPane(t);

        scrollPane.setColumnHeaderView(t.getTableHeader());

        txtSum.setEditable(false);
        txtSum.setText("Total: ");

        add(scrollPane, BorderLayout.NORTH);
        add(txtSum, BorderLayout.CENTER);
    }

    public TableRowSorter getMyTableRowSorter() {
        return myTableRowSorter;
    }

    public void editTextSum(){
        System.out.println(dataModel.getSum());
        txtSum.setText("Total: " + dataModel.getSum());
    }
    public static MyTableModel getDataModel() {
        return dataModel;
    }

    public JTextField getTxtSum() {
        return txtSum;
    }
    public JTable getTable() {
        return t;
    }
}
