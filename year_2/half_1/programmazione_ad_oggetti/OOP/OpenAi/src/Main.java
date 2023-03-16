import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main extends JFrame implements ActionListener {
    // Inizializza il bilancio totale a 0
    private double totalBudget = 0;
    private double totalTaxes = 0;

    // Crea i componenti dell'interfaccia grafica
    private JLabel budgetItemLabel = new JLabel("Voce di bilancio:");
    private JTextField budgetItemField = new JTextField(20);
    private JLabel budgetAmountLabel = new JLabel("Importo:");
    private JTextField budgetAmountField = new JTextField(20);
    private JCheckBox isTaxableCheckBox = new JCheckBox("Soggetto a tasse?");
    private JLabel taxRateLabel = new JLabel("Aliquota fiscale:");
    private JTextField taxRateField = new JTextField(20);
    private JButton submitButton = new JButton("Invia");
    private JButton finishButton = new JButton("Fine");

    public Main() {
        // Imposta il titolo della finestra
        super("Gestione del bilancio");

        // Imposta il layout della finestra
        setLayout(new FlowLayout());

        // Aggiungi i componenti alla finestra
        add(budgetItemLabel);
        add(budgetItemField);
        add(budgetAmountLabel);
        add(budgetAmountField);
        add(isTaxableCheckBox);
        add(taxRateLabel);
        add(taxRateField);
        add(submitButton);
        add(finishButton);
        // Imposta il comportamento dei pulsanti al click
        submitButton.addActionListener(this);
        finishButton.addActionListener(this);

// Imposta le dimensioni della finestra e rendila visibile
        setSize(400, 200);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
// Se viene cliccato il pulsante "Invia", ottiene i valori degli input e li utilizza per aggiornare il bilancio
        if (e.getSource() == submitButton) {
            String budgetItem = budgetItemField.getText();
            double budgetAmount = Double.parseDouble(budgetAmountField.getText());
            boolean isTaxable = isTaxableCheckBox.isSelected();
            double taxRate = Double.parseDouble(taxRateField.getText());
            // Calcola l'importo delle tasse per questa voce di bilancio
            double taxAmount = budgetAmount * taxRate;
            totalTaxes += taxAmount;

            // Aggiunge l'importo all'entrata o sottrae dall'uscita, a seconda del tipo di voce di bilancio
            if (budgetItem.equalsIgnoreCase("entrata")) {
                totalBudget += budgetAmount;
            } else if (budgetItem.equalsIgnoreCase("uscita")) {
                totalBudget -= budgetAmount;
            } else {
                JOptionPane.showMessageDialog(null, "Tipo di voce di bilancio non riconosciuto. Inserire 'entrata' o 'uscita'.", "Errore", JOptionPane.ERROR_MESSAGE);
            }
        }
// Se viene cliccato il pulsante "Fine", calcola il bilancio finale e mostra un messaggio con il risultato
        else if (e.getSource() == finishButton) {
            // Calcola il bilancio finale, tenendo conto delle tasse
            double finalBudget = totalBudget - totalTaxes;
            JOptionPane.showMessageDialog(null, "Bilancio finale: " + finalBudget + " EUR\nTasse totali: " + totalTaxes + " EUR", "Risultato", JOptionPane.INFORMATION_MESSAGE);
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        new Main();
    }
}




