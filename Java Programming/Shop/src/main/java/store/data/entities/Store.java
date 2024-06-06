package main.java.store.data.entities;

import main.java.store.data.builders.StoreBuilder;
import main.java.store.data.enums.GoodType;
import main.java.store.data.interfaces.*;
import main.java.store.data.observer.InventoryManager;

import java.util.*;

public class Store implements StoreEntity {
    private UUID id;
    private String name;
    private List<Staff> staffList;
    private List<StoreEquipment> equipments;
    private final double foodTurnover;
    private final  double nonFoodTurnover;
    private List<Receipt> receipts;
    private double stockDeliverySpendings;
    private InventoryManager inventoryManager;
    private double expirityDateDiscount;
    private long minimalDaysForDiscountForExpirationDate;

    public Store(StoreBuilder builder) // TODO: StoreBuilder
    {
        this.id = builder.getId();
        this.name = builder.getStoreName();
        this.staffList = builder.getCashiers();
        this.equipments = builder.getCashDesks();
        this.foodTurnover = builder.getFoodTurnover();
        this.nonFoodTurnover = builder.getNonFoodTurnover();
        this.receipts = new ArrayList<>();
        this.inventoryManager = builder.getInventoryManager();
        this.expirityDateDiscount = builder.getExpirateionDateDiscount();
        this.minimalDaysForDiscountForExpirationDate = builder.getMinimalDaysForDiscountForExpirationDate();
        stockDeliverySpendings = 0;
    }

    public String getName() {
        return name;
    }

    @Override
    public InventoryManager getInventoryManager() {
        return inventoryManager;
    }

    @Override
    public List<Staff> getStaffList() {
        return staffList;
    }

    @Override
    public List<StoreEquipment> getEquipments() {
        return equipments;
    }

    @Override
    public List<Receipt> getReceipts() {
        return receipts;
    }

    @Override
    public double getStockDeliverySpendings() {
        return stockDeliverySpendings;
    }

    public UUID getId() {
        return id;
    }

    public void addGoods(List<Good> products) {
        for (Good item : products) {
            inventoryManager.addProduct(item);
            updateSpendings(item.getUnitDeliveryPrice(), item.getQuantity());
        }
    }

    public double getSingleGoodPrice(String unitName){
        Good good = findGoodByName(unitName);

        double sellingPrice = good.getUnitDeliveryPrice();

        if(good.getCategory() == GoodType.EDIBLE){
            sellingPrice *= foodTurnover;
        }
        else {
            sellingPrice *= nonFoodTurnover;
        }

        long daysToExpirationDate = ((new Date().getTime() - good.getExpirationDate().getTime()) / (1000 * 60 * 60 * 24));

        if (daysToExpirationDate < minimalDaysForDiscountForExpirationDate && daysToExpirationDate >= 0) {
            // Transform discount
            while(expirityDateDiscount > 1) {
                expirityDateDiscount /= 10;
            }

            sellingPrice *= expirityDateDiscount;
        } else if (daysToExpirationDate < 0) {
            sellingPrice *= -1;
        }


        return sellingPrice;
    }

    public void updateSpendings(double newStockDeliverySpendings, int quantity) {
        this.stockDeliverySpendings += newStockDeliverySpendings * quantity;
    }

    public void addCashier(Staff cashier) {

        this.staffList.add(cashier);
    }

    public void addCashDesk(CashDesk cashDesk) {
        this.equipments.add(cashDesk);
    }

    public Good findGoodByName(String name) {
        return inventoryManager.findGoodByName(name);
    }

    public int generateReceiptId() {
        return receipts.size();
    }


    @Override
    public double getTotalEarnings() {
        return getCustomerTotalPurchases() - (this.stockDeliverySpendings + getTotalSalaries());
    }

    @Override
    public double getTotalSalaries() {
        double totalSalaries = 0;
        for (Staff cashier : staffList) {
            totalSalaries += cashier.getSalary();
        }
        return totalSalaries;
    }

    public double getCustomerTotalPurchases() {
        double totalPurchases = 0;
        for (Receipt receipt : this.receipts) {
            totalPurchases += receipt.getTotal();
        }
        return totalPurchases;
    }

    private double getProfit() {
        double total = 0;
        for (Receipt receipt : receipts) {
            total += receipt.getTotal();
        }
        return total;
    }



}
