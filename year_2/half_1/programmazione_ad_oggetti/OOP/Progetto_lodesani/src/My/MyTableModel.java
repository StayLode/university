package My;

import DataTypes.MyEntry;

import javax.swing.table.AbstractTableModel;
import java.util.Vector;

public class MyTableModel extends AbstractTableModel{
    private Vector<MyEntry> voci ;
    private int row, col;
    private String[] columnName= {"Date", "Description", "Amount"};
    private static int n = 0;
    public MyTableModel(){
        this.col = columnName.length;
        this.row = 0;
        this.voci = new Vector<MyEntry>();
    }

    @Override
    public String getColumnName(int column)
    {
        return columnName[column];
    }
    @Override
    public int getColumnCount(){
        return this.col;
    }
    @Override
    public int getRowCount(){
        return this.row;
    }


    @Override
    public Object getValueAt(int row, int col) {

        MyEntry elem = voci.get(row);
        switch (col) {
            case 0:
                return elem.getDate();
            case 1:
                return elem.getDescription();
            case 2:
                return elem.getAmount();
            default:
                return "";

        }

    }
    public Vector<MyEntry> getVoci(){
        return this.voci;
    }
    public void addRow(MyEntry v){
        System.out.println(voci);
        this.voci.add(v);
        this.row++;
        this.fireTableDataChanged();
    }
    public int[] getXY(String occ){
        int clicked=0;
        int[] coor = new int [2];
        for(int i=0;i<this.row;i++)
            for(int j=0;j<this.col;j++){
                if(getValueAt(i,j).toString().contains(occ)){
                    if(clicked==n){
                        coor[0]=i;
                        coor[1]=j;
                        n++;
                        return coor;
                    }
                    else{
                        clicked++;
                    }
                }
            }
        if(n==0) {
            coor[0] = -1;
            coor[1] = -1;
            return coor;
        }
        else{
            n=0;
            return getXY(occ);
        }

    }
    public void removeRow(int i){
        this.voci.remove(voci.elementAt(i));
        this.row--;
        this.fireTableDataChanged();
    }

    public void modifyElem(int index, String date, String desc, String amount){
        voci.get(index).setDate(date);
        voci.get(index).setAmount(amount);
        voci.get(index).setDescription(desc);
    }

    public double getSum(){
        double sum=0;
        for(int i=0;i<this.row;i++){
            sum+=Double.parseDouble(getValueAt(i,2).toString());
        }
        return sum;
    }
    public int get_index(String entry){
        String[] splitted = entry.split(";");
        String date = splitted[0].trim();
        String desc = splitted[1].trim();
        String amount = splitted[2].trim();

        for(int i=0;i<this.row;i++) {
            if (date.equals(voci.get(i).getDate()) && amount.equals(voci.get(i).getAmount()) && desc.equals(voci.get(i).getDescription()))
                return i;
        }
        return -1;
    }

}

