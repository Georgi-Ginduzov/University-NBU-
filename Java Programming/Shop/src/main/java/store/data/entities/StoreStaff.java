package main.java.store.data;

import main.java.store.data.interfaces.Staff;

import java.util.UUID;

public abstract class StoreStaff implements Staff {
    private final UUID id;
    private final String name;
    protected double salary;
    private boolean isOccupied;

    public StoreStaff(String name) {
        this.id = UUID.randomUUID();
        this.name = name;
    }

    public UUID getId() {
        return id;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public double getSalary() {
        return salary;
    }

    @Override
    public boolean isOccupied() {
        return isOccupied;
    }

    @Override
    public void changeOccupation() {
        isOccupied = !isOccupied;
    }
}
