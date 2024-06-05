package main.java.store.data.exceptions;

import main.java.store.data.interfaces.Good;

public class InsufficientQuantityException extends Exception {
    public InsufficientQuantityException(Good good, int requiredQuantity) {
        super("Insufficient quantity for goods: " + good.getName() + ". Required: " + requiredQuantity + ", Available: " + good.getQuantity());
    }
}