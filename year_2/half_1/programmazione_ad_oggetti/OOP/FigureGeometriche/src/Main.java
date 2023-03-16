public class Main {
    public static void main(String[] args) {
        Figura figure[]=new Figura[10];


        figure[0]=new Quadrato(5);
        figure[1]=new Rettangolo(5, 2.5);
        figure[2]=new Cerchio(3);

        for(int i=0; i<3;i++) {
            System.out.println();
            figure[i].print();
            //Se avessi voluto esplicitare ancora di più il polimorfismo invece che la print,
            //in teoria uguale per ogni classe, occorreva fare calcola area e calcola perimetro
            //ad ogni iterazione --> così facendo il compilatore capisce runtime di che figura si tratta
            //e ne calcola area/perimetro in modo opportuno
        }

    }
}