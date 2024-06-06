package main.java.store.data.builders;

import main.java.store.data.entities.Receipt;
import main.java.store.data.entities.Store;
import main.java.store.data.interfaces.*;
import main.java.store.data.observer.InventoryManager;

import java.util.*;

public class StoreBuilder extends Builder {
    private UUID id;
    private String storeName;
    private Set<Good> inventory;
    private List<Staff> cashiers;
    private List<StoreEquipment> cashDesks;
    private final double foodTurnover;
    private final  double nonFoodTurnover;
    private List<Receipt> receipts;
    private List<Client> clients;
    private double stockDeliverySpendings;
    private InventoryManager inventoryManager;
    private double expirateionDateDiscount;
    private long minimalDaysForDiscountForExpirationDate;

    public StoreBuilder(String storeName, double foodTurnover, double nonFoodTurnover, double expirateionDateDiscount, long minimalDaysForDiscountForExpirationDate) {
        this.id = UUID.randomUUID();
        this.storeName = storeName;
        this.inventory = new HashSet<>();
        this.cashiers = new ArrayList<>();
        this.cashDesks = new ArrayList<>();
        this.foodTurnover = foodTurnover;
        this.nonFoodTurnover = nonFoodTurnover;
        this.receipts = new ArrayList<>();
        this.clients = new ArrayList<>();
        this.inventoryManager = new InventoryManager();
        this.expirateionDateDiscount = expirateionDateDiscount;
        this.minimalDaysForDiscountForExpirationDate = minimalDaysForDiscountForExpirationDate;
        stockDeliverySpendings = 0;
    }

    public UUID getId() {
        return id;
    }

    public String getStoreName() {
        return storeName;
    }

    public Set<Good> getInventory() {
        return inventory;
    }

    public List<Staff> getCashiers() {
        return cashiers;
    }

    public List<StoreEquipment> getCashDesks() {
        return cashDesks;
    }

    public double getFoodTurnover() {
        return foodTurnover;
    }

    public double getNonFoodTurnover() {
        return nonFoodTurnover;
    }

    public List<Receipt> getReceipts() {
        return receipts;
    }

    public List<Client> getClients() {
        return clients;
    }

    public double getStockDeliverySpendings() {
        return stockDeliverySpendings;
    }

    public InventoryManager getInventoryManager() {
        return inventoryManager;
    }

    public double getExpirateionDateDiscount() {
        return expirateionDateDiscount;
    }

    public long getMinimalDaysForDiscountForExpirationDate() {
        return minimalDaysForDiscountForExpirationDate;
    }

    public Store build() {
        return new Store(this);
    }

}
