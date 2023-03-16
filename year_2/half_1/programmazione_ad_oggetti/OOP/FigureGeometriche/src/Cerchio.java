public class Cerchio implements Figura{
    private double raggio;

    public Cerchio(double raggio) {
        this.raggio = raggio;
    }

    public double getRaggio() {
        return raggio;
    }

    public void setRaggio(double raggio) {
        this.raggio = raggio;
    }

    @Override
    public double area() {
        return (raggio*raggio*Math.PI);
    }
    @Override
    public double perimetro() {
        return (raggio*2*Math.PI);
    }

    @Override
    public void print(){
        System.out.println("Cerchio\nArea: "+area()+"\nPerimetro: "+perimetro());
    }
}

