package main.java.store.service;

import main.java.store.data.entities.*;
import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;
import main.java.store.data.interfaces.Client;
import main.java.store.data.interfaces.Good;
import main.java.store.data.interfaces.Staff;
import main.java.store.utilities.SerializationImpl;

import java.io.IOException;
import java.util.Date;
import java.util.List;
import java.util.Set;

public class PurchaseCommand extends StoreCommandImpl {
    private Customer client;
    private Set<CartItem> products;

    public PurchaseCommand(Store store, Customer client, Set<CartItem> products) {
        super(store);
        this.client = client;
        this.products = products;
    }

    @Override
    public void execute() throws InsufficientQuantityException, InsufficientBalanceException {
        Cashier cashierToConsult = cashierToConsultClient();
        double totalAmount = 0;

        for (CartItem item : products) {
            validateProductQuantity(findGoodByName(item.getName()), item);

            double sellingPrice = getStore().getSingleGoodPrice(item.getName());
            if (sellingPrice > 0) {
                totalAmount +=  sellingPrice * item.getQuantity();
            }
            else {
                System.out.println(item.getName() + " is expired! It cannot be sold.");
            }
        }

        validatePurchase(client, totalAmount);

        try{
            saveReceipt(getStore().generateReceiptId(), cashierToConsult, (List<CartItem>) products);
        }catch(IOException exception){
            System.err.println(exception.getMessage());
        }

        updateInventory(products);
        client.decreaseBalance(totalAmount);
    }

    public Cashier cashierToConsultClient(){
        Cashier suitableCashier = null;

        for(Staff member : getStore().getStaffList()){
            if (member.getClass().getSimpleName() == "Cashier" && member.isOccupied()){
                suitableCashier =  (Cashier) member;
            }
        }

        return suitableCashier;
    }

    public boolean validateProductQuantity(Good product, CartItem item) throws InsufficientQuantityException, InsufficientBalanceException {
        if (product == null || product.getQuantity() < item.getQuantity()) {
            throw new InsufficientQuantityException(product, item.getQuantity());
        }
        return true;
    }

    public boolean validatePurchase(Client customer, double amount) throws InsufficientBalanceException {
        if (customer != null && customer.getBalance() < amount) {
            throw new InsufficientBalanceException(customer, amount);
        }
        return true;
    }

    public boolean saveReceipt(int receiptId, Cashier cashier, List<CartItem> items) throws IOException {
        Receipt receipt = new Receipt(getStore().generateReceiptId(), cashier , new Date(), (List<CartItem>) products);
        getStore().getReceipts().add(receipt);
        SerializationImpl.save(getStore(), "Store_" + getStore().getName());
        return true;
    }


}
