package main.java.store.data;

import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;

import java.util.*;

public class Store {
    private Set<Product> inventory;
    private List<Cashier> cashiers;
    private List<CashDesk> cashDesks;
    private final double foodTurnover;
    private final  double nonFoodTurnover;
    private List<Receipt> receipts;
    private double stockDeliverySpendings;

    public Store(double foodTurnover, double nonFoodTurnover) // StoreBuilder
    {
        this.inventory = new HashSet<>();
        this.cashiers = new ArrayList<>();
        this.cashDesks = new ArrayList<>();
        this.foodTurnover = foodTurnover;
        this.nonFoodTurnover = nonFoodTurnover;
        this.receipts = new ArrayList<>();
        stockDeliverySpendings = 0;
    }

    public void beginWorkDay(){
        int i = 0;

        for(CashDesk cashDesk : cashDesks){
            Cashier suitableCashier = findCashierForCashdesk();
            cashDesk.setCurrentStaff(suitableCashier);
        }
    }

    public void addGoods(List<Product> products) {
        for (Product item : products) {
            Product itemFromInventory = findGoodByName(item.getName());

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
            Product product = findGoodByName(item.getName());
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

        Receipt receipt = new Receipt(generateReceiptId(), cashiers.getFirst() , new Date(), purchaseItems);
        // TODO: implementation of purchasing items
        this.receipts.add(receipt);
        updateInventory(purchaseItems);
        customer.decreaseBalance(totalAmount);
        return receipt;
    }

    private void updateInventory(List<CartItem> purchaseItems) {
        for (CartItem item : purchaseItems) {
            Product goods = findGoodByName(item.getName());
            if (goods != null) {
                goods.decreaseQuantity(item.getQuantity());
            }
        }
    }

    private Product findGoodByName(String name) {
        for (Product product : inventory) {
            if (product.getName().equals(name)) {
                return product;
            }
        }

        return null;
    }

    private int generateReceiptId() {
        return receipts.size();
    }

    public Cashier findCashierForCashdesk() {
        Cashier desiredCashier = null;
        for (Cashier cashier : cashiers) {
            if (cashier.isOccupied()) {
                continue;
            }
            desiredCashier = cashier;
        }
        return desiredCashier;
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
