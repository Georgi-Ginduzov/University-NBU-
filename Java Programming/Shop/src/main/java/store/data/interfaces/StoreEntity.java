package main.java.store.data.interfaces;

import main.java.store.data.entities.Receipt;
import main.java.store.data.observer.InventoryManager;

import java.io.Serializable;
import java.util.List;
import java.util.Set;

public interface StoreEntity extends Serializable, Entity {
    InventoryManager getInventoryManager();
    List<Staff> getStaffList();
    List<StoreEquipment> getEquipments();
    List<Receipt> getReceipts();
    double getStockDeliverySpendings();
    double getTotalSalaries();
    double getCustomerTotalPurchases();
    double getTotalEarnings();
}
