package main.java.store.data.exceptions;

import main.java.store.data.Good;

public class InsufficientQuantityException extends Exception {
    public InsufficientQuantityException(Good goods, int requiredQuantity) {
        super("Insufficient quantity for goods: " + goods.getName() + ". Required: " + requiredQuantity + ", Available: " + goods.getQuantity());
    }
}