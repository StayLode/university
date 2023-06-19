package Panels;
import DataTypes.autoSave;
import Menu.*;

import javax.swing.*;
import java.awt.*;

/**
 * Classe che definisce il pannello principale, dove vengono creati tutti i pannelli e il Menu
 */
public class mainPanel extends JPanel {
    private tablePanel pTable;
    private JPanel mainP;
    private filterPanel pFilter;
    private managePanel pManage;
    private searchPanel pSearch;
    private JPanel pF_S;
    private JMenuBar menuBar;
    private JMenu fileMenu, exportMenu;
    private JMenuItem saveItem, loadItem, printItem, csvItem, txtItem, odsItem;

    /**
     * Costruttore della classe mainPanel
     * @param frame oggetto JFrame nel quale verranno aggiunti i pannelli
     */
    public mainPanel(JFrame frame){
        super();
        /**
         * Definizione Pannelli
         */
        mainP = new JPanel();
        mainP.setLayout(new BorderLayout());

        this.setLayout(new BorderLayout());

        pTable = new tablePanel();
        pFilter = new filterPanel(pTable);
        pManage = new managePanel(pTable, pFilter);
        pSearch = new searchPanel(pTable);

        pF_S = new JPanel();
        pF_S.setLayout(new BorderLayout());
        pF_S.add(pFilter, BorderLayout.NORTH);
        pF_S.add(pSearch, BorderLayout.CENTER);

        mainP.add(pTable, BorderLayout.NORTH);
        mainP.add(pManage, BorderLayout.CENTER);
        mainP.add(pF_S, BorderLayout.SOUTH);

        /**
         * JMENU
         */
        menuBar = new JMenuBar();
        fileMenu = new JMenu("File");
        saveItem = new JMenuItem("Save...");
        saveItem.addActionListener(new saveActionListener(pTable));

        loadItem = new JMenuItem("Load...");
        loadItem.addActionListener(new loadActionListener(pTable, pManage));

        printItem = new JMenuItem("Print...");
        printItem.addActionListener(new printActionListener(pTable));

        fileMenu.add(saveItem);
        fileMenu.add(loadItem);
        fileMenu.add(printItem);

        exportMenu = new JMenu("Export");
        csvItem = new JMenuItem("CSV");
        csvItem.addActionListener(new exportActionListener(pTable));
        txtItem = new JMenuItem("TXT");
        txtItem.addActionListener(new exportActionListener(pTable));
        odsItem = new JMenuItem("ODS");
        odsItem.addActionListener(new exportActionListener(pTable));

        exportMenu.add(csvItem);
        exportMenu.add(txtItem);
        exportMenu.add(odsItem);

        menuBar.add(fileMenu);
        menuBar.add(exportMenu);
        frame.setJMenuBar(menuBar);

        autoSave saveFile = new autoSave(pTable.getDataModel());
        saveFile.start();

        add(mainP, BorderLayout.WEST);
    }
}
