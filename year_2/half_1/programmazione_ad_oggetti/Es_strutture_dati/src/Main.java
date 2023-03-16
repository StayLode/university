public class Main {
    public static void main(String[] args) {
        Rubrica r= new Rubrica();
        Contatto c1=new Contatto("Luca", "Lodesani", "Modena", "1234");
        Contatto c2=new Contatto("Giuseppe", "Catillo", "Modena", "5555");
        Contatto c3=new Contatto("Alberto", "Nuzzaci", "Bomporto", "1111");

        r.addContact(c1);
        r.addContact(c2);
        r.addContact(c3);
        System.out.println(r);

        r.remContact(c2);
        System.out.println(r);

        r.SearchContact("Nuzzaci");

        r.remAll();
        System.out.println(r);

    }
}