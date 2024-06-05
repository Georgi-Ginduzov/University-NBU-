package main.java.store.data.entities;

import main.java.store.data.builders.StoreBuilder;
import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;
import main.java.store.data.interfaces.*;
import main.java.store.data.observer.InventoryManager;

import java.util.*;

public class Store implements StoreEntity {
    private UUID id;
    private List<Staff> cashiers;
    private List<StoreEquipment> cashDesks;
    private final double foodTurnover;
    private final  double nonFoodTurnover;
    private List<Receipt> receipts;
    private double stockDeliverySpendings;
    private InventoryManager inventoryManager;

    public Store(StoreBuilder builder) // TODO: StoreBuilder
    {
        this.id = builder.getId();
        this.cashiers = builder.getCashiers();
        this.cashDesks = builder.getCashDesks();
        this.foodTurnover = builder.getFoodTurnover();
        this.nonFoodTurnover = builder.getNonFoodTurnover();
        this.receipts = new ArrayList<>();
        this.inventoryManager = builder.getInventoryManager();
        stockDeliverySpendings = 0;
    }

    @Override
    public InventoryManager getInventoryManager() {
        return inventoryManager;
    }

    @Override
    public List<Staff> getCashiers() {
        return cashiers;
    }

    @Override
    public List<StoreEquipment> getCashDesks() {
        return cashDesks;
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

    public double getFoodTurnover() {
        return foodTurnover;
    }

    public double getNonFoodTurnover() {
        return nonFoodTurnover;
    }

    public void addGoods(List<Good> products) {
        for (Good item : products) {
            Good itemFromInventory = findGoodByName(item.getName());
            updateSpendings(item.getUnitDeliveryPrice(), item.getQuantity());

            if(itemFromInventory != null) {
                int itemQuantity = item.getQuantity();
                itemFromInventory.increaseQuantity(itemQuantity);
            }
            else {
                this.inventoryManager.addProduct(item);
            }
        }
    }

    public void updateSpendings(double newStockDeliverySpendings, int quantity) {
        this.stockDeliverySpendings += newStockDeliverySpendings * quantity;
    }

    public void addCashier(Staff cashier) {

        this.cashiers.add(cashier);
    }

    public void addCashDesk(CashDesk cashDesk) {
        this.cashDesks.add(cashDesk);
    }

    public Receipt processPurchase(Customer customer, List<CartItem> purchaseItems) throws InsufficientQuantityException, InsufficientBalanceException {
        double totalAmount = 0;

        for (CartItem item : purchaseItems) {
            Good product = findGoodByName(item.getName());
            if (product == null || product.getQuantity() < item.getQuantity()) {
                throw new InsufficientQuantityException(product, item.getQuantity());
            }
            double sellingPrice = product.getSellingPrice(5, 0.3, 3);
            if (sellingPrice > 0) {
                totalAmount +=  sellingPrice * item.getQuantity();
            }
            else {
                System.out.println(product.getName() + " is expired! It cannot be sold.");
            }
        }

        if (customer.getBalance() < totalAmount) {
            throw new InsufficientBalanceException(customer, totalAmount);
        }

        Receipt receipt = new Receipt(generateReceiptId(), new Cashier("Not implemented well") , new Date(), purchaseItems);
        // TODO: implementation of purchasing items
        this.receipts.add(receipt);
        updateInventory(purchaseItems);
        customer.decreaseBalance(totalAmount);
        return receipt;
    }

    private void updateInventory(List<CartItem> purchaseItems) {
        for (CartItem item : purchaseItems) {
            Good good = findGoodByName(item.getName());
            if (good != null) {
                good.decreaseQuantity(item.getQuantity());
            }
        }
    }

    private Good findGoodByName(String name) {
        for (Good product : inventoryManager.getProducts()) {
            if (product.getName().equals(name)) {
                return product;
            }
        }

        return null;
    }

    private int generateReceiptId() {
        return receipts.size();
    }


    @Override
    public double getTotalEarnings() {
        return getCustomerTotalPurchases() - (this.stockDeliverySpendings + getTotalSalaries());
    }

    @Override
    public double getTotalSalaries() {
        double totalSalaries = 0;
        for (Staff cashier : cashiers) {
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
