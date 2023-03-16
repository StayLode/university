public class Conto {
    private int nr_conto;
    private int saldo;
    private int nr_movimenti;
    private int movimenti[];

    public Conto(int nr_conto, int saldo) {
        this.nr_conto = nr_conto;
        this.saldo = saldo;
        this.movimenti = new int[20];
    }

    public void prelievo(int importo){
        if(nr_movimenti<movimenti.length) {
            this.saldo -= importo;
            this.movimenti[nr_movimenti] = -importo;
            this.nr_movimenti++;
            System.out.println("Prelievo effettuato");
        }
        else
            System.out.println("Prelievo non possibile, numero di movimenti possibile superato!");
    }
    public void versamento(int importo){
        if(nr_movimenti<movimenti.length){
            this.saldo+=importo;
            this.movimenti[nr_movimenti]=importo;
            this.nr_movimenti++;
            System.out.println("Versamento effettuato");
        }
        else
            System.out.println("Versamento non possibile, numero di movimenti possibile superato!");
    }
    public void resituzioneSaldo(){
       System.out.println("Saldo del conto "+this.nr_conto+": " + this.saldo);
    }

    public void stampa(){
        System.out.print("Nr conto corrente: "+nr_conto+"\nMovimenti: ");
        for(int i=0;i<nr_movimenti;i++){
            System.out.print(movimenti[i]+", ");
        }
        System.out.println();
    }
}
