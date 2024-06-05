package main.java.store.data.interfaces;

import java.io.Serializable;

public interface Staff extends Serializable, Entity {
    String getName();
    double getSalary();
    boolean isOccupied();
    void changeOccupation();
}
