package main.java.store.data.exceptions;

import main.java.store.data.interfaces.Client;

public class InsufficientBalanceException extends Exception {
    public InsufficientBalanceException(Client customer, double requiredAmount) {
        super("Insufficient balance for customer: " + customer.getName() + ". Required: " + requiredAmount + ", Available: " + customer.getBalance());
    }
}