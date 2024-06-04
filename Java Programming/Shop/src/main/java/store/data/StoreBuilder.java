package main.java.store.data;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class StoreBuilder {
    private Set<Product> inventory;
    private List<Cashier> cashiers;
    private List<CashDesk> cashDesks;
    private final double foodTurnover;
    private final  double nonFoodTurnover;
    private List<Receipt> receipts;
    private double stockDeliverySpendings;

    public StoreBuilder(double foodTurnover, double nonFoodTurnover) {
        this.inventory = new HashSet<>();
        this.cashiers = new ArrayList<>();
        this.cashDesks = new ArrayList<>();
        this.foodTurnover = foodTurnover;
        this.nonFoodTurnover = nonFoodTurnover;
        this.receipts = new ArrayList<>();
        stockDeliverySpendings = 0;
    }


}
