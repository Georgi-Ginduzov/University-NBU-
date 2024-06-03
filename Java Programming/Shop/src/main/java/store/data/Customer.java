package main.java.store.data;

import java.util.UUID;

public class Customer {
    private final UUID id;
    private final String name;
    private double balance;

    public Customer(String name, double balance) {
        this.id = UUID.randomUUID();
        this.name = name;
        this.balance = balance;
    }

    public UUID getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getBalance() {
        return balance;
    }

    public void decreaseBalance(double amount) {
        this.balance -= amount;
    }
}
