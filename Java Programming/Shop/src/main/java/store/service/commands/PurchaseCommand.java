package main.java.store.service.commands;

import main.java.store.data.entities.CartItem;
import main.java.store.data.entities.Cashier;
import main.java.store.data.entities.Receipt;
import main.java.store.data.entities.Store;
import main.java.store.data.exceptions.InsufficientBalanceException;
import main.java.store.data.exceptions.InsufficientQuantityException;
import main.java.store.data.interfaces.Client;
import main.java.store.data.interfaces.Good;
import main.java.store.data.interfaces.ItemInCart;
import main.java.store.data.interfaces.Staff;
import main.java.store.utilities.SerializationImpl;

import java.io.IOException;
import java.util.Date;
import java.util.List;
import java.util.Set;

public class PurchaseCommand extends StoreCommand {
    private Client client;

    public PurchaseCommand(Store store, Client client) {
        super(store);
        this.client = client;
    }

    @Override
    public boolean execute() throws InsufficientBalanceException, InsufficientQuantityException {
        Cashier cashierToConsult = cashierToConsultClient();
        double totalAmount = 0;

        for (ItemInCart item : store.getInventoryManager().getCart()) {

            validateProductQuantity(store.getInventoryManager().findGoodByName(item.getName()), (CartItem) item);

            double sellingPrice = store.getSingleGoodPrice(item.getName());
            if (sellingPrice > 0) {
                totalAmount +=  sellingPrice * item.getQuantity();
            }
            else {
                System.out.println(item.getName() + " is expired! It cannot be sold.");
            }
        }

        validatePurchase(client, totalAmount);

        Receipt receipt = null;
        try{
            receipt = saveReceipt(store.generateReceiptId(), cashierToConsult, (List<ItemInCart>) store.getInventoryManager().getCart());
        }catch(IOException exception){
            System.err.println(exception.getMessage());
        }

        updateInventory(store.getInventoryManager().getCart());
        client.decreaseBalance(totalAmount);

        System.out.println("Purchase completed for client: " + client.getName());
        System.out.println("Receipt: " + receipt);
        return false;
    }

    public Cashier cashierToConsultClient(){
        Cashier suitableCashier = null;

        for(Staff member : store.getStaffList()){
            if (member.getClass().getSimpleName() == "Cashier" && member.isOccupied()){
                suitableCashier =  (Cashier) member;
            }
        }

        return suitableCashier;
    }

    public boolean validateProductQuantity(Good product, CartItem item) throws InsufficientQuantityException{
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

    public Receipt saveReceipt(int receiptId, Cashier cashier, List<ItemInCart> items) throws IOException {
        Receipt receipt = new Receipt(store.generateReceiptId(), cashier , new Date(), (List<ItemInCart>) items);
        store.getReceipts().add(receipt);
        SerializationImpl.save(store, "Store_" + store.getName());
        return receipt;
    }

    public void updateInventory(Set<ItemInCart> purchaseItems) {
        for (ItemInCart item : purchaseItems) {
            Good good = store.getInventoryManager().findGoodByName(item.getName());
            if (good != null) {
                good.decreaseQuantity(item.getQuantity());
            }
        }
    }

}
