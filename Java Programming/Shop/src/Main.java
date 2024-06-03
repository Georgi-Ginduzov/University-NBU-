import main.java.store.data.*;
import main.java.store.data.enums.GoodType;
import main.java.store.data.PurchaseItem;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Initialize the store with food and non-food turnover percentages
        Store store = new Store(1.2, 1.5); // Example turnover percentages

        // Add cashiers to the store
        Cashier cashier1 = new Cashier("John Doe", 1000);
        Cashier cashier2 = new Cashier("Jane Smith", 1000);
        store.addCashier(cashier1);
        store.addCashier(cashier2);

        // Add cash desks to the store
        CashDesk cashDesk1 = new CashDesk();
        CashDesk cashDesk2 = new CashDesk();
        store.addCashDesk(cashDesk1);
        store.addCashDesk(cashDesk2);

        // Add goods to the store inventory
        List<Good> goods = new ArrayList<>();
        goods.add(new Good( "Milk", 1.0, GoodType.EDIBLE, new Date(System.currentTimeMillis() + 86400000 * 10), 100)); // Expires in 10 days
        goods.add(new Good("Bread", 0.5, GoodType.EDIBLE, new Date(System.currentTimeMillis() + 86400000 * 5), 50));  // Expires in 5 days
        goods.add(new Good( "Soap", 2.0, GoodType.NONEDIBLE, new Date(System.currentTimeMillis() + 86400000 * 30), 30)); // Expires in 30 days
        store.addGoods(goods);

        // Create a customer
        Customer customer = new Customer("Alice", 50.0);

        // Create a list of purchase items
        List<PurchaseItem> purchaseItems = new ArrayList<>();
        purchaseItems.add(new PurchaseItem(1, 2, "Milk"));
        purchaseItems.add(new PurchaseItem(2, 2, "Bread"));

        // Process the purchase and generate a receipt
        try {
            Receipt receipt = store.processPurchase(customer, purchaseItems);
            System.out.println("Receipt generated successfully with serial number: " + receipt.getSerialNumber());

            // Read the receipt file
            String fileName = "receipts/receipt_" + receipt.getSerialNumber() + ".txt";
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Display the store's profit
        System.out.println("Store profit: " + store.calculateProfit());


    }
}