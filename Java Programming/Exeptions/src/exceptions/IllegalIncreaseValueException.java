package exceptions;

public class IllegalIncreaseValueException extends Exception {
    private int increaseValue;

    public IllegalIncreaseValueException(String message, int increaseValue) {
        super(message);
        this.increaseValue = increaseValue;
    }
}
