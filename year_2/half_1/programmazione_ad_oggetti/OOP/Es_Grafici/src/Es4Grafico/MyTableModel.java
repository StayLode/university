package Es4Grafico;

import javax.swing.table.AbstractTableModel;

public class MyTableModel extends AbstractTableModel {
    private Contatto[] v;
    private int row, col;

    public MyTableModel(Contatto[] vett){
        this.v = vett;
        this.row = vett.length;
        this.col = vett[0].getClass().getDeclaredFields().length;
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
        Contatto elem = v[row];
        switch (col){
            case 0: return elem.getNome();
            case 1: return elem.getCognome();
            case 2: return elem.getIndirizzo();
            case 3: return elem.getTelefono();
            default: return "";
        }
    }
}

