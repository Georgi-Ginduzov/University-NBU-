package shop;

public abstract class RegisteredProvider implements Provider{
    private String regNumber;

    public RegisteredProvider(String regNumber) {
        this.regNumber = regNumber;
    }


    @Override
    public String toString() {
        return "RegisteredProvider{" +
                "regNumber='" + regNumber + '\'' +
                '}';
    }
}
