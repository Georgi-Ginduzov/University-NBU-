package main.java.store.service.interfaces;

import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;

public interface Command {
    boolean execute() throws InsufficientBalanceException, InsufficientQuantityException;
}
