package DataTypes;

import DataTypes.MyEntry;

import javax.swing.table.AbstractTableModel;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
/**
 * Classe per definire il TableModel
 */
public class MyTableModel extends AbstractTableModel{
    private List<MyEntry> entries;
    private List<MyEntry> displayed;
    private int row, col;
    private String[] columnName= {"Date", "Description", "Amount"};
    private int last = -1;
    private int selectedRow;

    /**
     * Costruttore che setta il numero di righe e colonne, oltre a creare due ArrayList
     */
    public MyTableModel(){
        this.col = columnName.length;
        this.row = 0;
        this.entries = new ArrayList<>();
        this.displayed = new ArrayList<>();
        this.selectedRow = -1;
    }

    /**
     * (Override) Metodo che restituisce il nome delle colonne
     * @param column indice di colonna della quale si vuole ottenere il nome
     * @return nome della colonna
     */
    @Override
    public String getColumnName(int column)
    {
        return columnName[column];
    }

    /**
     * (Override) Metodo che restituisce il numero di colonne
     * @return intero, numero di colonne
     */
    @Override
    public int getColumnCount(){
        return this.col;
    }

    /**
     * (Override) Metodo che restituisce il numero di righe
     * @return intero, numero di righe
     */
    @Override
    public int getRowCount(){
        return displayed.size();
    }

    /**
     * (Override) Metodo che restistuisce l'elemento, dati indici di riga e colonna, utilizzato per creare la tabella
     * @param row  indice di riga
     * @param col  indice di colonna
     * @return oggetto in corrispondenza degli indici
     */
    @Override
    public Object getValueAt(int row, int col) {
        MyEntry elem = displayed.get(row);

        switch (col) {
            case 0:
                return elem.getStringDate();
            case 1:
                return elem.getDescription();
            case 2:
                return elem.getAmount();
            default:
                return "";

        }

    }

    /**
     * Metodo getter per ottenere l'indice della linea selezionata
     * @return l'indice della linea selezionata
     */
    public int getSelectedRow() {
        return selectedRow;
    }

    /**
     * Metodo setter per l'indice di linea selezionata.<br>Utilizzato per evidenziare una linea specifica
     * selezionata col mouse dall'utente
     * @param selectedRow indice della linea da evidenziare
     */
    public void setSelectedRow(int selectedRow) {
        this.selectedRow = selectedRow;
    }

    /**
     * Metodo setter per l'ultimo indice di riga corrispondente all'ultimo elemento trovato nella ricerca<br>
     * Utilizzato per resettare la ricerca impostando il valore a -1
     * @param last indice di riga
     */
    public void setLast(int last) {
        this.last = last;
    }
    /**
     * Metodo per aggiungere una voce (una riga) nella tabella
     * @param v voce che si vuole aggiungere
     */
    public void addRow(MyEntry v){
        this.entries.add(v);
        this.displayed.add(v);
        this.row++;
        this.fireTableDataChanged();
    }

    /**
     * Metodo per la rimozione di una riga dalla tabella, dato un indice di riga
     * @param i indice di riga da eliminare
     */
    public void removeRow(int i){
        this.entries.remove(i);
        this.displayed.remove(i);
        this.row--;
        this.fireTableDataChanged();
    }

    /**
     * Metodo per la modifica di un elemento della tabella
     * @param index indice di riga che si vuole modificare
     * @param date nuovo valore di data
     * @param desc nuovo valore di descrizione
     * @param amount nuovo valore di importo
     */
    public void modifyElem(int index, String date, String desc, float amount){
        entries.get(index).setDate(date);
        entries.get(index).setAmount(amount);
        entries.get(index).setDescription(desc);

        displayed.get(index).setDate(date);
        displayed.get(index).setAmount(amount);
        displayed.get(index).setDescription(desc);
        this.fireTableDataChanged();
    }

    /**
     * Metodo ricorsivo utilizzato per ricercare un elemento nella tabella, in qualsiasi campo
     * @param occ valore da ricercare
     * @return indice di riga dell'occorenza trovata
     */
    public int getXY(String occ){
        int coor;
        //Scorro ogni elemento della tabella
        for(int i=0;i<displayed.size();i++) {
            if (i > last)
                for (int j = 0; j < this.col; j++)
                    //Se l'elemento contiene la stringa cercata
                    if (getValueAt(i, j).toString().contains(occ)) {
                        coor = i;
                        last = i;
                        return coor;
                    }
        }
        if(last==-1) {
            coor = -1;
            return coor;
        }
        //Quando arrivo alla fine della tabella rincomincio
        else{
            last=-1;
            return getXY(occ);
        }

    }

    /**
     * Metodo che calcola la somma degli importi delle voci visualizzate
     * @return la somma come float
     */
    public float getSum(){
        float sum=0;
        for(int i=0;i<displayed.size();i++)
            sum+=Float.parseFloat(getValueAt(i,2).toString());

        return sum;
    }

    /**
     * Visualizzazione di default, senza filtri, della tabella
     */
    public void defaultView(){
        displayed=new ArrayList<>(entries);
        fireTableDataChanged();
    }

    /**
     * Visualizzazione dei dati, di un singolo giorno, della tabella
     * @param day giorno con cui si filtrano i dati
     */
    public void dayView(Date day){
        displayed.clear();
        for(MyEntry entry: entries)
            if(entry.getDate().equals(day))
                displayed.add(entry);
        fireTableDataChanged();
    }

    /**
     * Visualizzazione dei dati, di una singola settimana, della tabella
     * @param day giorno dal quale si otterrà la settimana desiderata
     */
    public void weekView(Date day){
        displayed.clear();
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(day);
        int week = calendar.get(Calendar.WEEK_OF_YEAR);
        int year = calendar.get(Calendar.YEAR);

        for(MyEntry entry: entries) {
            calendar.setTime(entry.getDate());
            if (calendar.get(Calendar.WEEK_OF_YEAR) == week && calendar.get(Calendar.YEAR) == year)
                displayed.add(entry);
        }

        fireTableDataChanged();
    }

    /**
     * Visualizzazione dei dati, di un singolo mese, della tabella
     * @param day giorno dal quale si otterrà il mese desiderato
     */
    public void monthView(Date day){
        displayed.clear();
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(day);
        int month = calendar.get(Calendar.MONTH);
        int year = calendar.get(Calendar.YEAR);

        for(MyEntry entry: entries) {
            calendar.setTime(entry.getDate());
            if (calendar.get(Calendar.MONTH) == month && calendar.get(Calendar.YEAR) == year)
                displayed.add(entry);

        }

        fireTableDataChanged();
    }

    /**
     * Visualizzazione dei dati, di un singolo anno, della tabella
     * @param day giorno dal quale si otterrà l'anno desiderato
     *
     */
    public void yearView(Date day){
        displayed.clear();
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(day);
        int year = calendar.get(Calendar.YEAR);

        for(MyEntry entry: entries) {
            calendar.setTime(entry.getDate());
            if (calendar.get(Calendar.YEAR) == year)
                displayed.add(entry);
        }

        fireTableDataChanged();
    }

    /**
     * Metodo utilizzata per ottenere una delle due diverse liste
     * @param all valore booleano per scegliere la lista
     *            true resituisce la lista completa<br>
     *            false restituisce la lista dei soli elementi visualizzati
     * @return oggetto List (MyEntry) che corrisponde ad una delle due liste<br><br>
     * Utilizzato :<br>
     *  - Nel salvataggio per salvare tutte le voci del bilancio <br>
     *  - Nell'esportazione per esportare solo quelle visualizzate
     */

    public List<MyEntry> getAllEntries(boolean all){
        if (all)
            return this.entries;
        else
            return this.displayed;
    }

    /**
     * Metodo che svuota le due liste, utilizzata nel caricamento, da file, di un bilancio per svuotare la tabella corrente
     */
    public void removeAllEntries(){
        this.entries.clear();
        this.displayed.clear();
        fireTableDataChanged();
    }
    /**
     * Metodo per trasformare la lista di voci in un array di oggetti <br>
     * Chiama il metodo toObject della classe DataTypes.MyEntry sulle voci di bilancio
     * @return array di voci sottoforma di oggetti generici
     */
    public Object[][] getEntriesAsObject(){
        Object[][] objects = new Object[this.getRowCount()][this.getColumnCount()];
        for(int i=0;i<this.getRowCount();i++)
            objects[i] = this.displayed.get(i).toObject();
        return objects;
    }

    /**
     * Metodo getter dell'array di headers della tabella
     * @return array di String
     */
    public String[] getHeaders(){
        return columnName;
    }

}

