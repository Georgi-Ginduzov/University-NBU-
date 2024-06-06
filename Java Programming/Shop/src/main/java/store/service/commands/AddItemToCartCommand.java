package main.java.store.service.commands;

import main.java.store.data.entities.Store;
import main.java.store.data.interfaces.ItemInCart;

public class AddItemToCartCommand extends StoreCommand {
    private ItemInCart itemInCart;

    public AddItemToCartCommand(Store store, ItemInCart item) {
        super(store);
        this.itemInCart = item;
    }

    @Override
    public void execute() {
        store.getInventoryManager().addProductToCart(itemInCart);
        System.out.println("Item added to cart." + itemInCart.getName());
    }
}
