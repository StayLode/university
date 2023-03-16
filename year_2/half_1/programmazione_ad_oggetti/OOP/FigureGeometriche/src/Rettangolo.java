public class Rettangolo implements Figura{
    private double base;
    private double altezza;


    //Costruttore

    public Rettangolo(double base, double altezza) {
        this.base = base;
        this.altezza = altezza;
    }

    //Getter e Setter
    public double getBase() {
        return base;
    }

    public void setBase(double base) {
        this.base = base;
    }

    public double getAltezza() {
        return altezza;
    }

    public void setAltezza(double altezza) {
        this.altezza = altezza;
    }

    @Override
    public double area() {
        return (this.base*this.altezza);
    }
    @Override
    public double perimetro(){
        return (this.base+this.altezza)*2;
    }

    @Override
    public void print(){
        System.out.println("Rettangolo\nArea: "+area()+"\nPerimetro: "+perimetro());
    }
}
