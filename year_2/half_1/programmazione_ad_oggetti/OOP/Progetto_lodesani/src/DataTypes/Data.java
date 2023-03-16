package DataTypes;

public class Data {
    private String description;
    private String amount;
    public Data(){
        this.description = null;
        this.amount = null;
    }

    public Data(String description, String amount){
        this.description = description;
        this.amount = amount;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getAmount() {
        return amount;
    }

    public void setAmount(String amount) {
        this.amount = amount;
    }

    public boolean check(){
        if (this.description.isEmpty() || this.amount.isEmpty())
            return false;
        try{
            double tmp = Double.parseDouble(this.amount);
        }catch(NumberFormatException e){
            return false;
        }
        return true;
    }
}
