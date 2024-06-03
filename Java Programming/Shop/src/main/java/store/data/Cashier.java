package main.java.store.data;

import java.util.UUID;

public class Cashier {
    private UUID id;
    private String name;
    private double salary;

    public Cashier(String name, double salary) {
        this.id = UUID.randomUUID();
        this.name = name;
        this.salary = salary;
    }

    public UUID getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }
}
