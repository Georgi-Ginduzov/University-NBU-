package main.java.store.data;

import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;
import main.java.store.data.interfaces.Good;
import main.java.store.data.interfaces.Staff;
import main.java.store.data.interfaces.StoreEntity;

import java.util.*;

public class Store implements StoreEntity {
    private UUID id;
    private Set<Good> inventory;
    private List<Staff> cashiers;
    private List<Equipment> cashDesks;
    private final double foodTurnover;
    private final  double nonFoodTurnover;
    private List<Receipt> receipts;
    private double stockDeliverySpendings;

    public Store(double foodTurnover, double nonFoodTurnover) // TODO: StoreBuilder
    {
        this.id = UUID.randomUUID();
        this.inventory = new HashSet<>();
        this.cashiers = new ArrayList<>();
        this.cashDesks = new ArrayList<>();
        this.foodTurnover = foodTurnover;
        this.nonFoodTurnover = nonFoodTurnover;
        this.receipts = new ArrayList<>();
        stockDeliverySpendings = 0;
    }

    @Override
    public Set<Good> getInventory() {
        return inventory;
    }

    @Override
    public List<Staff> getCashiers() {
        return cashiers;
    }

    @Override
    public List<Equipment> getCashDesks() {
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

    public void beginWorkDay(){
        int i = 0;

        for(Equipment cashDesk : cashDesks){
            Staff suitableCashier = findCashierForCashdesk();
            cashDesk.setCurrentStaff(suitableCashier);
        }
    }

    public void addGoods(List<Product> products) {
        for (Product item : products) {
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
        for (Good product : inventory) {
            if (product.getName().equals(name)) {
                return product;
            }
        }

        return null;
    }

    private int generateReceiptId() {
        return receipts.size();
    }

    public Staff findCashierForCashdesk() {
        Staff desiredCashier = null;
        for (Staff cashier : cashiers) {
            if (cashier.isOccupied()) {
                continue;
            }
            desiredCashier = cashier;
        }
        return desiredCashier;
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


    public double getFoodTurnover() {
        return foodTurnover;
    }

    public double getNonFoodTurnover() {
        return nonFoodTurnover;
    }
}
