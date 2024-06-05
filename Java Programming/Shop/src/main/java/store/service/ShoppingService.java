package main.java.store.service;

import main.java.store.data.*;
import main.java.store.service.interfaces.Service;

public class PurchaseService implements Service {
    private Store store;

    public PurchaseService(Store store) {
        this.store = store;
    }

    @Override
    public void Perform(String operation) {

    }

    @Override
    public boolean validateOperation() {
        return false;
    }
}
