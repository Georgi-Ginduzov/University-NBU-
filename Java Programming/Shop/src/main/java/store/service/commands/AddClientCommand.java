package main.java.store.service.commands;

import main.java.store.data.entities.Store;
import main.java.store.data.interfaces.Client;
import main.java.store.service.interfaces.Command;

public class AddClientCommand implements Command {
    private Store store;
    private Client client;

    public AddClientCommand(Store store, Client client) {
        this.store = store;
        this.client = client;
    }

    @Override
    public void execute() {
        store.addClient(client);
        System.out.println("Client added: " + client.getName());
    }
}
