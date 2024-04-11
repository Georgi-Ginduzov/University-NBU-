package informatics;

import exceptions.IllegalIncreaseValueException;

public class Box {
    private int dim1;
    private int dim2;
    private int dim3;

    public Box(int dim1, int dim2, int dim3) {
        this.dim1 = dim1;
        this.dim2 = dim2;
        this.dim3 = dim3;
    }

    public int getDim1() {
        return dim1;
    }

    public int getDim2() {
        return dim2;
    }

    public int getDim3() {
        return dim3;
    }

    // 2, 3, 4
    public void increaseDimentions(int increaseValue) throws IllegalIncreaseValueException {
        if (increaseValue > 0){
            dim1 += increaseValue;
            dim2 += increaseValue;
            dim3 += increaseValue;
        }
        else throw new IllegalIncreaseValueException("Illegal value", increaseValue);

    }


    @Override
    public String toString() {
        return "Box{" +
                "dim1=" + dim1 +
                ", dim2=" + dim2 +
                ", dim3=" + dim3 +
                '}';
    }
}
