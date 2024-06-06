package main.java.store.service.command;

import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;
import main.java.store.service.interfaces.Command;

public class AddClientCommand implements Command {


    @Override
    public void execute() throws InsufficientQuantityException, InsufficientBalanceException {

    }
}
