package DataTypes;

import java.time.LocalDate;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.Locale;

public class MyEntry extends Data {
    private String date;

    public MyEntry(String date, String description, String amount){
        super(description, amount);
        this.date=date;
    }

    public String getDate() {
        return this.date;
    }

    public void setDate(String date) {
        this.date=date;
    }
    public int compare(LocalDate d1, LocalDate d2){
        return d1.compareTo(d2);
    }

    @Override
    public boolean check() {
        try {
            LocalDate tmp = LocalDate.parse(this.date);
            if (compare(tmp, getLocalDate()) > 0)
                return false;
            return true;
        }catch(DateTimeParseException e){
            return false;
        }

    }

    public static LocalDate getLocalDate(){
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy.MM.dd", Locale.ITALY).withZone(ZoneId.of("Europe/Rome"));
        LocalDate date = LocalDate.now();
        String text = date.format(formatter);

        LocalDate parsedDate = LocalDate.parse(text, formatter);
        return parsedDate;
    }
    public static LocalDate toLocalDate(String date){
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd", Locale.ITALY).withZone(ZoneId.of("Europe/Rome"));


        LocalDate parsedDate = LocalDate.parse(date, formatter);
        return parsedDate;
    }
}
