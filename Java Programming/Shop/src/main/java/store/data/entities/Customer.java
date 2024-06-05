package main.java.store.data.entities;

import main.java.store.data.interfaces.Client;

public class Customer implements Client {
    private final String name;
    private double balance;

    public Customer(String name) {
        this.name = name;
        this.balance = 0;
    }

    public Customer(String name, double balance) {
        this.name = name;
        this.balance = balance;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public double getBalance() {
        return balance;
    }

    public void increaseBalance(double amount) {
        this.balance += amount;
    }

    public void decreaseBalance(double amount) {
        this.balance -= amount;
    }

    @Override
    public void update(String message) {
        System.out.println(getName() + " received update: " + message);
    }
}
