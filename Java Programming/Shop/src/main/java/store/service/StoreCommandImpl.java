package main.java.store.service;

import main.java.store.data.entities.CartItem;
import main.java.store.data.entities.Product;
import main.java.store.data.entities.Store;
import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;
import main.java.store.data.interfaces.*;
import main.java.store.service.commands.AddClientCommand;
import main.java.store.service.commands.AddItemToCartCommand;
import main.java.store.service.commands.CommandInvoker;
import main.java.store.service.interfaces.Command;

import java.util.Scanner;

public class StoreCommandImpl implements Command {
    @Override
    public void execute() throws InsufficientBalanceException, InsufficientQuantityException {

    }
    /*private Store store;
    private Command command;

    public StoreCommandImpl(Store store) {
        this.store = store;
    }

    @Override
    public void execute() throws InsufficientQuantityException, InsufficientBalanceException {
        System.out.println("Choose what do you want to do. Operations: " +
                "\n(1) Open the store" +
                "\n(2) Add a client" +
                "\n(3) Add an item to the cart" +
                "\n(4) Buy items" +
                "\n(5) Close the store");

        switch (operation.toLowerCase().replaceAll(" ", "")){
            case "openstore":
                openStore();
                System.out.println("Store opened.");
                break;
            case "closestore":
                closeStore();
                System.out.println("Store closed.");
                break;
            case "customerenters":
                System.out.println("Client enters");
                System.out.println("Enter the client credentials: \nName: ");

                Scanner input = new Scanner(System.in);
                String customerName = input.nextLine();
                System.out.println("Balance: ");
                double customerBalance = Double.parseDouble(input.nextLine());

                Client newCustomer = new Customer(customerName, customerBalance);

                command = new ShoppingCommand(getStore(), newCustomer);
                command.execute();
                break;
            /*case "clientisatcashdesk":
                System.out.println("Client enters Cash Desk");
                break;
            case "clientgetsout":
                System.out.println("Client gets out");
                break;
        }
    }

    public Store getStore(){
        return this.store;
    }

    public void updateInventory(Set<CartItem> purchaseItems) {
        for (CartItem item : purchaseItems) {
            Good good = findGoodByName(item.getName());
            if (good != null) {
                good.decreaseQuantity(item.getQuantity());
            }
        }
    }

    public Good findGoodByName(String name) {
        return store.getInventoryManager().findGoodByName(name);
    }

    public void openStore(){
        for(StoreEquipment cashDesk : store.getEquipments()){
            Staff suitableCashier = findCashierForCashdesk();
            cashDesk.setCurrentStaff(suitableCashier);
        }
    }

    public Staff findCashierForCashdesk() {
        Staff desiredCashier = null;
        for (Staff cashier : store.getStaffList()) {
            if (cashier.isOccupied()) {
                continue;
            }
            desiredCashier = cashier;
        }
        return desiredCashier;
    }

    public void closeStore(){
        for(StoreEquipment cashDesk : store.getEquipments()){
            cashDesk.setCurrentStaff(null);
        }

        System.out.println("Store cleaned.");
    }*/

    /*private Store store;
    private CommandInvoker invoker;

    public StoreServiceImpl(Store store) {
        this.store = store;
        this.invoker = new CommandInvoker();
    }

    public void perform(String operation) {
        Scanner input = new Scanner(System.in);

        switch (operation.toLowerCase().replaceAll(" ", "")){
            case "addclient":
                System.out.println("Enter client name: ");
                String clientName = input.nextLine();
                System.out.println("Enter client balance: ");
                double balance = input.nextDouble();
                Client client = new Client(clientName, balance);

                Command addClientCommand = new AddClientCommand(store, client);
                invoker.setCommand(addClientCommand);
                invoker.executeCommand();
                break;

            case "additemtocart":
                System.out.println("Enter product details: ");
                // Assuming we have a method to create a product from input
                ItemInCart product = createProductFromInput(input);

                // Assuming we have a cart associated with the client
                Command addItemToCartCommand = new AddItemToCartCommand(store, product);
                invoker.setCommand(addItemToCartCommand);
                invoker.executeCommand();
                break;

            case "purchase":
                Command purchaseCommand = new PurchaseCommand(store, client);
                invoker.setCommand(purchaseCommand);
                invoker.executeCommand();
                break;

            default:
                System.out.println("Invalid operation");
                break;
        }
    }

    private ItemInCart createProductFromInput(Scanner input) {
        Scanner inputProduct = new Scanner(System.in);
        System.out.println("Enter product name: ");
        String name = inputProduct.next();
        System.out.println("Enter product quantity: ");
        int quantity = inputProduct.nextInt();

        return new CartItem(quantity, store.getSingleGoodPrice(name), name);
    }*/
}
