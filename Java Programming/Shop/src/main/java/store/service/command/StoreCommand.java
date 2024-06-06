package main.java.store.service.command;

import main.java.store.data.entities.Store;
import main.java.store.data.interfaces.Staff;
import main.java.store.data.interfaces.StoreEquipment;
import main.java.store.service.interfaces.Command;

public abstract class StoreCommand implements Command {
    protected Store store;

    public StoreCommand(Store store) {
        this.store = store;
    }

    /*@Override
    public void execute() {

    }*/

    /*public abstract void perform(String operation);

    public abstract boolean validateOperation(String operation);

    protected void openStore() {
        for (StoreEquipment equipment : store.getEquipments()) {
            Staff suitableCashier = findCashierForCashdesk();
            equipment.setCurrentStaff(suitableCashier);
        }
    }

    protected void closeStore() {
        for (StoreEquipment equipment : store.getEquipments()) {
            equipment.setCurrentStaff(null);
        }
        System.out.println("Store closed.");
    }

    private Staff findCashierForCashdesk() {
        for (Staff cashier : store.getStaffList()) {
            if (!cashier.isOccupied() && cashier.getClass().getSimpleName() == "Cashier") { // Can add an interface for staff which can sell products
                return cashier;
            }
        }
        return null;
    }*/
}
