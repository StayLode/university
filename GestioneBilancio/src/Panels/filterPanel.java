package Panels;

import DataTypes.MyTableModel;
import org.jdatepicker.ComponentColorDefaults;
import org.jdatepicker.JDatePicker;
import org.jdatepicker.UtilDateModel;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Classe che definisce il pannello per visualizzare le voci in base a giorno/settimana/mese/anno
 */
public class filterPanel extends JPanel implements ActionListener {
    protected ButtonGroup bg;
    private JRadioButton rbtnDef,rbtnDay, rbtnWeek, rbtnYear, rbtnMonth;
    private JDatePicker datePicker;
    private tablePanel p;
    private JPanel p1= new JPanel();
    private JPanel p2= new JPanel();
    private MyTableModel dataModel;

    /**
     * Costruttore della classe filterPanel
     * @param p tablePanel
     */
    public filterPanel(tablePanel p) {

        setLayout(new BorderLayout());
        this.p=p;
        dataModel = p.getDataModel();

        // Radio buttons
        bg = new ButtonGroup();
        rbtnDef = new JRadioButton("Default", true);
        rbtnDef.setActionCommand("Def");

        rbtnDay = new JRadioButton("Day");
        rbtnDay.setActionCommand("Day");

        rbtnWeek = new JRadioButton("Week");
        rbtnWeek.setActionCommand("Week");

        rbtnMonth = new JRadioButton("Month");
        rbtnMonth.setActionCommand("Month");

        rbtnYear = new JRadioButton("Year");
        rbtnYear.setActionCommand("Year");

        //DatePicker configuration
        ComponentColorDefaults colors = ComponentColorDefaults.getInstance();
        colors.setColor(ComponentColorDefaults.Key.FG_MONTH_SELECTOR, Color.WHITE);
        datePicker = new JDatePicker (new UtilDateModel(new Date()), "dd/MM/yyyy");
        datePicker.setEnabled(false);

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
                if (a.getText().equals("Default")) {
                    datePicker.setEnabled(false);
                    dataModel.defaultView();
                }
                else
                    datePicker.setEnabled(true);
            }
        };

        rbtnDay.addActionListener(rbtnActionListener);
        rbtnWeek.addActionListener(rbtnActionListener);
        rbtnMonth.addActionListener(rbtnActionListener);
        rbtnYear.addActionListener(rbtnActionListener);
        rbtnDef.addActionListener(rbtnActionListener);
        datePicker.addActionListener(this);
        p1.add(rbtnDef);
        p2.add(rbtnDay);
        p2.add(rbtnWeek);
        p2.add(rbtnMonth);
        p2.add(rbtnYear);
        p2.add(datePicker);

        add(p1, BorderLayout.NORTH);
        add(p2, BorderLayout.CENTER);
    }

    /**
     * ActionPerformed per filtrare la visualizzazione della tabella in base a giorno/settimana/mese/anno
     * @param e the event to be processed
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        Date filterDate;
        String btnCommand = bg.getSelection().getActionCommand();
        SimpleDateFormat dateFormatter = new SimpleDateFormat("dd/MM/yyyy");
        switch(btnCommand){
            case "Day":
                try {
                    filterDate = dateFormatter.parse(datePicker.getFormattedTextField().getText());
                    dataModel.dayView(filterDate);
                } catch (ParseException ex) {}
                break;
            case "Week":
                try {
                    filterDate = dateFormatter.parse(datePicker.getFormattedTextField().getText());
                    dataModel.weekView(filterDate);
                } catch (ParseException ex) {}
                break;
            case "Month":
                try {
                    filterDate = dateFormatter.parse(datePicker.getFormattedTextField().getText());
                    System.out.println("filterPanel.actionPerformed");
                    dataModel.monthView(filterDate);
                } catch (ParseException ex) {}
                break;
            case "Year":
                try {
                    filterDate = dateFormatter.parse(datePicker.getFormattedTextField().getText());
                    dataModel.yearView(filterDate);
                } catch (ParseException ex) {}
                break;
        }
    }

}
