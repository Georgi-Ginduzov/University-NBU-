package main.java.store.data;

import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;

import java.util.*;

public class Store {
    private Set<Good> inventory;
    private List<Cashier> cashiers;
    private List<CashDesk> cashDesks;
    private final double foodTurnover;
    private final  double nonFoodTurnover;
    private List<Receipt> receipts;
    private double stockDeliverySpendings;

    public Store(double foodTurnover, double nonFoodTurnover) {
        this.inventory = new HashSet<>();
        this.cashiers = new ArrayList<>();
        this.cashDesks = new ArrayList<>();
        this.foodTurnover = foodTurnover;
        this.nonFoodTurnover = nonFoodTurnover;
        this.receipts = new ArrayList<>();
        stockDeliverySpendings = 0;
    }

    public void addGoods(List<Good> goods) {
        for (Good item : goods) {
            Good itemFromInventory = findGoodByName(item.getName());

            if(itemFromInventory != null) {
                int itemQuantity = item.getQuantity();
                this.stockDeliverySpendings += item.getUnitDeliveryPrice() * itemQuantity;
                itemFromInventory.increaseQuantity(itemQuantity);
            }
            else {
                stockDeliverySpendings += item.getUnitDeliveryPrice();
                this.inventory.add(item);
            }
        }
    }

    public void addCashier(Cashier cashier) {
        this.cashiers.add(cashier);
    }

    public void addCashDesk(CashDesk cashDesk) {
        this.cashDesks.add(cashDesk);
    }

    public Receipt processPurchase(Customer customer, List<PurchaseItem> purchaseItems) throws InsufficientQuantityException, InsufficientBalanceException {
        double totalAmount = 0;

        for (PurchaseItem item : purchaseItems) {
            Good good = findGoodByName(item.getName());
            if (good == null || good.getQuantity() < item.getQuantity()) {
                throw new InsufficientQuantityException(good, item.getQuantity());
            }
            double sellingPrice = good.getSellingPrice(5, 0.3, 3);
            if (sellingPrice > 0) {
                totalAmount +=  sellingPrice * item.getQuantity();
            }
            else {
                System.out.println(good.getName() + " is expired! It cannot be sold.");
            }
        }

        if (customer.getBalance() < totalAmount) {
            throw new InsufficientBalanceException(customer, totalAmount);
        }

        Receipt receipt = new Receipt(generateReceiptId(), findCashierByCustomer(customer), new Date(), purchaseItems);
        this.receipts.add(receipt);
        updateInventory(purchaseItems);
        customer.decreaseBalance(totalAmount);
        return receipt;
    }

    private void updateInventory(List<PurchaseItem> purchaseItems) {
        for (PurchaseItem item : purchaseItems) {
            Good goods = findGoodByName(item.getName());
            if (goods != null) {
                goods.decreaseQuantity(item.getQuantity());
            }
        }
    }

    private Good findGoodByName(String name) {
        for (Good good : inventory) {
            if (good.getName().equals(name)) {
                return good;
            }
        }

        return null;
    }

    private int generateReceiptId() {
        return receipts.size();
    }

    private Cashier findCashierByCustomer(Customer customer) {
        return this.cashiers.get(0);
    }

    public double calculateProfit() {
        return calculateTotalPurchases() - (this.stockDeliverySpendings + calculateTotalSalaries());
    }

    public double calculateTotalSalaries() {
        double totalSalaries = 0;
        for (Cashier cashier : cashiers) {
            totalSalaries += cashier.getSalary();
        }
        return totalSalaries;
    }

    public double calculateTotalPurchases() {
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

    public int getReceiptCount() {
        return receipts.size();
    }

    public double getFoodTurnover() {
        return foodTurnover;
    }

    public double getNonFoodTurnover() {
        return nonFoodTurnover;
    }
}
