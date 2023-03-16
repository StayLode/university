package My;

import DataTypes.MyEntry;

import javax.swing.*;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class MyRowFilter extends RowFilter {
    private String type;

    public MyRowFilter(String type) {
        this.type = type;
    }

    @Override
    public boolean include(Entry entry) {
        LocalDate ld = MyEntry.toLocalDate(entry.getStringValue(0));
        System.out.println(ld.getYear()+ " "+ ld.getMonth()+" "+ld.getDayOfMonth());
        switch (type) {
            case "Default":
                return true;
            case "Day":
                return entry.getStringValue(0).equals(MyEntry.getLocalDate().toString());
            case "Week":
                return ld.isAfter(MyEntry.getLocalDate().minus(7, ChronoUnit.DAYS));
            case "Month":
                return ld.getMonth() == MyEntry.getLocalDate().getMonth() && ld.getYear() == MyEntry.getLocalDate().getYear();
            case "Year":
                return ld.getYear() == MyEntry.getLocalDate().getYear();
        }
        return true;
    }

}
