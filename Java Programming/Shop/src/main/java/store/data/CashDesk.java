package main.java.store.data;

import java.util.UUID;

public class CashDesk {
    private final UUID id;
    private Cashier currentCashier;
    private boolean isOccupied;
    private boolean hasCashier;

    public CashDesk() {
        this.id = UUID.randomUUID();
        isOccupied = false;
        hasCashier = false;
    }

    public UUID getId() {
        return id;
    }

    public Cashier getCurrentCashier() {
        return currentCashier;
    }

    public void addCashier(Cashier cashier) {
        if (!isOccupied){
            currentCashier = cashier;
            isOccupied = true;
        }

        System.out.println("The cash desk is already occupied");
    }
}