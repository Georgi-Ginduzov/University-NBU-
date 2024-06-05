package main.java.store.data.interfaces;

import main.java.store.data.observer.Observer;

public interface Client extends Entity, Observer {
    String getName();

    double getBalance();
}
