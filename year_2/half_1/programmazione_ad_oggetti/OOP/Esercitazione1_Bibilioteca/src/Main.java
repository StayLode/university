public class Main {
    public static void main(String[] args) {
        Libro l1= new Libro("Dave", 3, "Viva Linux");
        System.out.println(l1);
        l1.Prestito();
        l1.Prestito();
        System.out.println(l1);
        l1.Restituzione();
        System.out.println(l1);
    }
}
