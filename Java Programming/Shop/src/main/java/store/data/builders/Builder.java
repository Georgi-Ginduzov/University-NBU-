package main.java.store.data.builders;

import main.java.store.data.interfaces.Build;
import main.java.store.data.interfaces.Entity;

public abstract class Builder implements Build {
    @Override
    public abstract Entity build();
}
