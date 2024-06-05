package main.java.store.data.interfaces;

import main.java.store.data.Equipment;
import main.java.store.data.Receipt;

import java.io.Serializable;
import java.util.List;
import java.util.Set;

public interface StoreEntity extends Serializable, Entity {
    Set<Good> getInventory();

    List<Staff> getCashiers();

    List<StoreEquipment> getCashDesks();

    List<Receipt> getReceipts();

    double getStockDeliverySpendings();
    double getTotalSalaries();
    double getCustomerTotalPurchases();
    double getTotalEarnings();
}
