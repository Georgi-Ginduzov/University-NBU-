package main.java.store.service;

import main.java.store.data.builders.ProductBuilder;
import main.java.store.data.builders.StoreBuilder;
import main.java.store.data.entities.CartItem;
import main.java.store.data.entities.Customer;
import main.java.store.data.entities.Store;
import main.java.store.data.enums.GoodType;
import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;
import main.java.store.data.interfaces.Client;
import main.java.store.data.interfaces.ItemInCart;
import main.java.store.service.commands.AddClientCommand;
import main.java.store.service.commands.AddItemToCartCommand;
import main.java.store.service.commands.CommandInvoker;
import main.java.store.service.commands.PurchaseCommand;
import main.java.store.service.interfaces.Command;
import main.java.store.service.interfaces.Engine;
import main.java.store.utilities.SerializationImpl;

import java.io.File;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class CommandBasedEngine implements Engine {
    private Store store;
    private CommandInvoker invoker;
    private Scanner scanner;
    private Client currentClient;

    public CommandBasedEngine() {
        store = null;
        invoker = new CommandInvoker();
        scanner = new Scanner(System.in);
        currentClient = null;
    }

    @Override
    public void run() {
        System.out.println("Do you want to make a new store or generate one from the database?");
        String command = scanner.nextLine();

        switch (command.toLowerCase().replaceAll(" ", "")) {
            case "makenewstore":
                this.store = makeNewStore();
                try {
                    SerializationImpl.save(this.store, this.store.getName());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }

                System.out.println("Now that you've made a new store you need to add items to its stockroom.");
                addItemsToStore();
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
                break;
        }

        System.out.println("Now we shohuld add a customer to the store");
        addCustomer();

        System.out.println("Congrats! Enter how much items you'd like to add to the customer's cart");
        int itemsToAdd = scanner.nextInt();

        for (int i = 0; i < itemsToAdd; i++) {
            addItemToCart(currentClient.getName());
        }

        System.out.println("Now the customer enters the cashdesk and it's purchase is being processed.");
        try {
            if (makePurchase(currentClient.getName())){
                System.out.println("The customer successfully purchased these items.");
            }
            else{
                System.out.println("There was an error purchasing the items");
            }
        } catch (InsufficientBalanceException e) {
            throw new RuntimeException(e);
        } catch (InsufficientQuantityException e) {
            throw new RuntimeException(e);
        }
    }

    private boolean makePurchase(String clientName) throws InsufficientBalanceException, InsufficientQuantityException {
        Command purchaseCommand = new PurchaseCommand(store, store.getClientByName(clientName));
        return purchaseCommand.execute();
    }

    private void addCustomer(){
        System.out.println("Enter customer name: ");
        String name = scanner.nextLine();
        System.out.println("Enter customer balance: ");
        double balance = Double.parseDouble(scanner.nextLine());
        Client customer = new Customer(name, balance);

        Command addClientCommand = new AddClientCommand(store, customer);
        invoker.setCommand(addClientCommand);
        try {
            invoker.executeCommand();
        } catch (InsufficientBalanceException e) {
            throw new RuntimeException(e);
        } catch (InsufficientQuantityException e) {
            throw new RuntimeException(e);
        }

        currentClient = customer;

        try {
            SerializationImpl.save(this.store, this.store.getName());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public Store getStoreInstanceFromDatabase(String name) throws IOException, ClassNotFoundException {
        String directoryPath = "src/main/java/store/data/database/";
        File storePath = new File(directoryPath + name);

        if (!storePath.exists()) {
            throw new IllegalArgumentException("Store does not exist.");
        }

        return (Store)SerializationImpl.load(directoryPath +  name);
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

        int amountOfItems = scanner.nextInt();
        for (int i = 0; i < amountOfItems; i++) {
            System.out.println("Enter the name of the item you wish to add: ");
            String name = scanner.next();

            System.out.println("Enter the delivery price of a single unit: ");
            double deliveryPrice = scanner.nextDouble();

            System.out.println("Enter the product's type(edible/nonedible): ");
            String productType = scanner.next();

            GoodType type = null;
            if (productType.equalsIgnoreCase("edible")) {
                type = GoodType.EDIBLE;
            }
            else{
                type = GoodType.NONEDIBLE;
            }

            System.out.println("Enter the products expiry date(dd/mm/yyyy): ");
            String dateString = scanner.next();
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
            Date expirationDate = null;
            try {
                expirationDate = sdf.parse(dateString);
            } catch (ParseException e) {
                throw new RuntimeException(e);
            }

            System.out.println("Enter the amount of items you wish to add: ");
            int amount = scanner.nextInt();

            ProductBuilder builder = new ProductBuilder(name,deliveryPrice, type, expirationDate, amount);
            store.getInventoryManager().addProductInStockroom(builder.build());

            try {
                SerializationImpl.save(this.store, this.store.getName());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    private void addItemToCart(String customerName) {
        Client customer = store.getClientByName(customerName);
        if (customer == null) {
            System.out.println("Customer not found. Add customer first.");
            return;
        }
        System.out.println("Enter product name: ");
        String productName = scanner.nextLine();

        System.out.println("Enter product quantity: ");
        int quantity = scanner.nextInt();
        ItemInCart item = new CartItem(quantity, store.getSingleGoodPrice(productName), productName);

        Command addItemToCartCommand = new AddItemToCartCommand(store, item);
        invoker.setCommand(addItemToCartCommand);
        try {
            invoker.executeCommand();
        } catch (InsufficientBalanceException e) {
            throw new RuntimeException(e);
        } catch (InsufficientQuantityException e) {
            throw new RuntimeException(e);
        }

        try {
            SerializationImpl.save(this.store, this.store.getName());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


}
