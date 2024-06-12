package main.java.store.data.interfaces;

import main.java.store.data.observer.Observer;

import java.io.Serializable;

public interface Client extends Entity, Observer, Serializable {
    String getName();
    double getBalance();
    void decreaseBalance(double amount);
    void increaseBalance(double amount);
}
