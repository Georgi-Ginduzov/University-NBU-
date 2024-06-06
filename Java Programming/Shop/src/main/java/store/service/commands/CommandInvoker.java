package main.java.store.service.commands;

import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;
import main.java.store.service.interfaces.Command;

public class CommandInvoker {
    private Command command;

    public void setCommand(Command command) {
        this.command = command;
    }

    public void executeCommand() throws InsufficientBalanceException, InsufficientQuantityException {
        command.execute();
    }
}
