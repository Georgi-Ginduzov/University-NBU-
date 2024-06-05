package main.java.store.data.interfaces;

import main.java.store.data.observer.Observer;

import java.io.Serializable;

public interface Staff extends Serializable, Entity {
    String getName();
    double getSalary();
    boolean isOccupied();
    void changeOccupation();
}
