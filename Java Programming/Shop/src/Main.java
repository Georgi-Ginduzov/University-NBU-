import main.java.store.data.*;
import main.java.store.data.enums.GoodType;
import main.java.store.data.CartItem;
import main.java.store.service.SerializationImpl;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        SerializationImpl serialization = new SerializationImpl();
        Store lidl = (Store)serialization.load("src/main/java/store/data/database/Store_Lidl");

        System.out.println(lidl.getId());
        //lidl.beginWorkDay();


        // TODO: Make customers

        //TODO: Make some purchases

        //TODO: End workday
            // Order products
            // Shop is cleaned
            // Cashiers are not busy



    }

    public static Store makeStore() {
        // Initialize the store with food and non-food turnover percentages
        Store store = new Store(1.2, 1.5); // Example turnover percentages

        // Add cashiers to the store
        Cashier cashier1 = new Cashier("John Doe");
        Cashier cashier2 = new Cashier("Jane Smith");
        store.addCashier(cashier1);
        store.addCashier(cashier2);

        // Add cash desks to the store
        CashDesk cashDesk1 = new CashDesk();
        CashDesk cashDesk2 = new CashDesk();
        store.addCashDesk(cashDesk1);
        store.addCashDesk(cashDesk2);

        // Add goods to the store inventory
        List<Product> products = new ArrayList<>();
        products.add(new Food( "Milk", 1.0, GoodType.EDIBLE, new Date(System.currentTimeMillis() + 86400000 * 10), 100)); // Expires in 10 days
        products.add(new Food("Bread", 0.5, GoodType.EDIBLE, new Date(System.currentTimeMillis() + 86400000 * 5), 50));  // Expires in 5 days
        products.add(new Food( "Soap", 2.0, GoodType.NONEDIBLE, new Date(System.currentTimeMillis() + 86400000 * 30), 30)); // Expires in 30 days
        store.addGoods(products);

        // Create a customer
        Customer customer = new Customer("Alice", 50.0);

        // Create a list of purchase items
        List<CartItem> purchaseItems = new ArrayList<>();
        purchaseItems.add(new CartItem(1, 2, "Milk"));
        purchaseItems.add(new CartItem(2, 2, "Bread"));

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
        System.out.println("Store profit: " + store.getTotalEarnings());

        return store;
    }
}