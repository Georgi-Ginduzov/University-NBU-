package main.java.store.data;

public class Cashier extends StoreStaff {
    private final double baseSalary = 1800;

    public Cashier(String name) {
        super(name);
        this.salary = baseSalary;
    }
}
