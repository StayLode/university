package DataTypes;

import java.io.Serializable;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.Date;
import java.util.Locale;
/**
 * Classe che identifica una voce di bilancio
 */
public class MyEntry implements Serializable {
    private String description;
    private float amount;
    private Date date;

    /**
     * Oggetto "formatter" per uniformare le date in "dd/MM/yyyy"
     */
    private static final SimpleDateFormat dateFormatter = new SimpleDateFormat("dd/MM/yyyy");

    /**
     * Costruttore
     * @param date campo data di tipo "java.util.Date"
     * @param description campo descrizione della voce di bilancio
     * @param amount campo importo della voce di bilancio
     */
    public MyEntry(Date date, String description, float amount){
        this.date=date;
        this.description=description;
        this.amount=amount;
    }

    /**
     * Costruttore
     * @param date campo data di tipo stringa
     * @param description campo descrizione della voce di bilancio
     * @param amount campo importo della voce di bilancio
     */
    public MyEntry(String date, String description, float amount){
        this.setDate(date);
        this.description=description;
        this.amount=amount;
    }

    /**
     * Metodo getter per la data
     * @return parametro data come stringa formattata "dd/MM/yyyy"
     */
    public String getStringDate(){
        return dateFormatter.format(this.date);
    }
    /**
     * Metodo getter per la data
     * @return data come oggetto "java.util.Date"
     */
    public Date getDate() {
        return this.date;
    }

    /**
     * Metodo setter per la data
     * @param date data sotto forma di stringa
     *
     * Viene controllato il formato della data
     */
    public void setDate(String date) {
        try {
            this.date = dateFormatter.parse(date);
        }catch(ParseException e){}
    }

    /**
     * Metodo getter per la descrizione
     * @return descrizione come stringa
     */
    public String getDescription() {
        return description;
    }

    /**
     * Metodo setter per la descrizione
     * @param description descrizione come stringa
     */
    public void setDescription(String description) {
        this.description = description;
    }

    /**
     * Metodo getter per l'importo
     * @return importo come float
     */
    public float getAmount() {
        return this.amount;
    }

    /**
     * Metodo setter per l'importo
     * @param amount importo passato come float
     */
    public void setAmount(float amount) {
        this.amount = amount;
    }

    /**
     * Metodo per trasformare una voce di bilancio in un oggetto generico
     * @return Object[] con i tre attributi della classe come elementi
     */
    public Object[] toObject(){
        return new Object[]{this.getStringDate(), this.description, this.amount};
    }
}
