package main.java.store.service;

import main.java.store.data.builders.ProductBuilder;
import main.java.store.data.builders.StoreBuilder;
import main.java.store.data.entities.Product;
import main.java.store.data.entities.Store;
import main.java.store.data.enums.GoodType;
import main.java.store.data.interfaces.Good;
import main.java.store.data.observer.InventoryManager;
import main.java.store.service.interfaces.Engine;
import main.java.store.utilities.SerializationImpl;

import java.io.File;
import java.io.IOException;
import java.util.Date;
import java.util.Scanner;

public class CommandBasedEngine implements Engine {
    private Store store;

    public CommandBasedEngine() {
        store = null;
    }

    @Override
    public void run() {
        // TODO: Make a store instance or create one
        System.out.println("Do you want to make a new store or generate one from the database?");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        switch (input.toLowerCase().replaceAll(" ", "")) {
            case "makenewstore":
                this.store = makeNewStore();
                break;
            case "getfromdatabase":
                System.out.println("Enter the name of the store you wish to work with");
                String storeName = scanner.nextLine();
                try {
                    this.store = getStoreInstanceFromDatabase(storeName);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                } catch (ClassNotFoundException e) {
                    throw new RuntimeException(e);
                }

                System.out.println("Now that you've made a new store you need to add items to its stockroom.");
                addItemsToStore();
                break;
        }





        // TODO: Make customers

        //TODO: Make some purchases

        //TODO: End workday
        // Order products
        // Shop is cleaned
        // Cashiers are not busy

    }

    public Store getStoreInstanceFromDatabase(String name) throws IOException, ClassNotFoundException {
        String directoryPath = "src/main/java/store/data/database";
        File storePath = new File(directoryPath + "/Store_" + name);

        if (!storePath.exists()) {
            throw new IllegalArgumentException("Store does not exist.");
        }

        return (Store)SerializationImpl.load(directoryPath + "/Store_" + name);
    }

    public Store makeNewStore() {
        System.out.println("The store generation begins... Please enter the store credentials as it follows:\n" +
                "Name: ");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        System.out.println("Foods turnover: ");
        double foodsTurnover = scanner.nextDouble();
        System.out.println("NonFoods turnover: ");
        double nonFoodsTurnover = scanner.nextDouble();
        System.out.println("Days before expirity date in which the product will be additionally discounted: ");
        int daysBeforeExpiryDate = scanner.nextInt();
        System.out.println("Amount of discount in %: ");
        double amountOfDiscount = scanner.nextDouble();

        StoreBuilder builder = new StoreBuilder(name, foodsTurnover, nonFoodsTurnover, amountOfDiscount, daysBeforeExpiryDate);

        return builder.build();
    }

    public void addItemsToStore() {
        System.out.println("Enter the amount of items to be added: ");
        Scanner input = new Scanner(System.in);

        int amountOfItems = input.nextInt();
        for (int i = 0; i < amountOfItems; i++) {
            System.out.println("Enter the name of the item you wish to add: ");
            String name = input.next();

            System.out.println("Enter the delivery price of a single unit: ");
            double deliveryPrice = input.nextDouble();

            System.out.println("Enter the product's type(edible/nonedible): ");
            String productType = input.next();

            GoodType type = null;
            if (productType.equalsIgnoreCase("edible")) {
                type = GoodType.EDIBLE;
            }
            else{
                type = GoodType.NONEDIBLE;
            }

            System.out.println("Enter the products expiry date: ");

            System.out.println("Enter the amount of this item you wish to add: ");
            double amount = input.nextDouble();

            Good newItem = ProductBuilder(String name, double unitDeliveryPrice, GoodType type, Date expirationDate, int quantity)
            store.getInventoryManager().addProductInStockroom();
        }
    }


}
