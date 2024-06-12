import main.java.store.data.entities.Store;
import main.java.store.service.CommandBasedEngine;
import main.java.store.service.commands.CommandInvoker;
import main.java.store.utilities.SerializationImpl;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        CommandBasedEngine engine = new CommandBasedEngine();
        engine.run();
    }
}