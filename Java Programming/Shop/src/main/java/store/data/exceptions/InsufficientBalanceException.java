package main.java.store.data.exceptions;

import main.java.store.data.entities.Customer;

public class InsufficientBalanceException extends Exception {
    public InsufficientBalanceException(Customer customer, double requiredAmount) {
        super("Insufficient balance for customer: " + customer.getName() + ". Required: " + requiredAmount + ", Available: " + customer.getBalance());
    }
}