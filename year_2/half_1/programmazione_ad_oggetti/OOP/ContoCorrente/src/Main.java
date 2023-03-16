public class Main {
    public static void main(String[] args) {
        Conto cc[]=new Conto[3];
        cc[0] = new Conto(1,0);
        cc[1] = new Conto(2,0);
        cc[2] = new Conto(3,0);

        //Versamenti
        cc[0].versamento(10);
        cc[0].versamento(100);
        cc[1].versamento(100);
        cc[1].versamento(100);
        cc[2].versamento(80);
        cc[2].versamento(60);
        //Prelievi
        cc[0].prelievo(4);
        cc[0].prelievo(100);
        cc[1].prelievo(100);
        cc[1].prelievo(700);
        cc[2].prelievo(10);
        cc[2].prelievo(20);
        //Saldi
        cc[0].resituzioneSaldo();
        cc[1].resituzioneSaldo();
        cc[2].resituzioneSaldo();
        //Movimenti
        cc[0].stampa();
        cc[1].stampa();
        cc[2].stampa();
    }
}