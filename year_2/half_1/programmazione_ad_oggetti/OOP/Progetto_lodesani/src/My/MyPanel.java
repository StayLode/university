package My;

import Panels.FilterPanel;
import Panels.SearchPanel;
import Panels.managePanel;
import Panels.tablePanel;

import javax.swing.*;
import java.awt.*;


public class MyPanel extends JPanel {

    private JLabel lblDesc, lblAmount, lblDate;

    private JButton btnSearch, btnSubmit;
    private JTextField txtSearch, txtResSearch, txtDesc, txtAmount, txtDate;
    private JComboBox cbType, cbList;

    private int entries=0;
    public MyPanel(){
        super();
        /**
         * Definizione Pannelli
         */
        JPanel mainP = new JPanel();

        JPanel ps = new JPanel();
        ps.setLayout(new BorderLayout());
        JPanel psSearch = new JPanel();
        JPanel psResult = new JPanel();
        mainP.setLayout(new BorderLayout());
        setLayout(new BorderLayout());


        tablePanel pTable = new tablePanel();
        managePanel pManage = new managePanel(pTable);
        mainP.add(pTable, BorderLayout.NORTH);
        mainP.add(pManage, BorderLayout.CENTER);

/*
        JPanel pEdit = new JPanel();
        GroupLayout layout = new GroupLayout(pEdit);
        pEdit.setLayout(layout);
        layout.setAutoCreateGaps(true);
        layout.setAutoCreateContainerGaps(true);
        layout.setHorizontalGroup(
                layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING))
                            .addComponent(lblDesc)
                            .addComponent(lblAmount)
                        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING))
                            .addComponent(txtDesc)
                            .addComponent(txtAmount)
                        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING))
                            .addComponent(lblDate)
                            .addComponent(btnSubmit)
                        .addComponent(txtDate)
        );
        layout.setHorizontalGroup(
                layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.BASELINE))
                            .addComponent(lblDesc)
                            .addComponent(txtDesc)
                            .addComponent(lblDate)
                            .addComponent(txtDate)

                        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.BASELINE))
                            .addComponent(lblAmount)
                            .addComponent(txtAmount)
                            .addComponent(btnSubmit)
        );
*/
        FilterPanel pFilter = new FilterPanel(pTable);

        SearchPanel pSearch = new SearchPanel(pTable);

        JPanel pc = new JPanel();
        pc.setLayout(new BorderLayout());
        pc.add(pFilter, BorderLayout.NORTH);
        pc.add(pSearch, BorderLayout.CENTER);
        mainP.add(pc, BorderLayout.SOUTH);



        add(mainP, BorderLayout.WEST);
    }






}
