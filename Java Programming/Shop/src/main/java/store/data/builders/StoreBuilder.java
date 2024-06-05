package main.java.store.data.builders;

import main.java.store.data.Receipt;
import main.java.store.data.Store;
import main.java.store.data.interfaces.Entity;
import main.java.store.data.interfaces.Good;
import main.java.store.data.interfaces.Staff;
import main.java.store.data.interfaces.StoreEquipment;

import java.util.*;

public class StoreBuilder extends Builder {
    private UUID id;
    private Set<Good> inventory;
    private List<Staff> cashiers;
    private List<StoreEquipment> cashDesks;
    private final double foodTurnover;
    private final  double nonFoodTurnover;
    private List<Receipt> receipts;
    private double stockDeliverySpendings;

    public StoreBuilder(double foodTurnover, double nonFoodTurnover) {
        this.id = UUID.randomUUID();
        this.inventory = new HashSet<>();
        this.cashiers = new ArrayList<>();
        this.cashDesks = new ArrayList<>();
        this.foodTurnover = foodTurnover;
        this.nonFoodTurnover = nonFoodTurnover;
        this.receipts = new ArrayList<>();
        stockDeliverySpendings = 0;
    }

    public UUID getId() {
        return id;
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

    public double getStockDeliverySpendings() {
        return stockDeliverySpendings;
    }

    public Entity build() {
        return new Store(this);
    }

}
