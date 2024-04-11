package Files;

import informatics.Box;

import java.io.Serializable;

public class BoxWithWeight extends Box implements Serializable {
    private double weight;

    public BoxWithWeight(int dim1, int dim2, int dim3, double weight) {
        super(dim1, dim2, dim3);
        this.weight = weight;
    }


    @Override
    public String toString() {
        return "BoxWithWeight{" +
                "weight=" + weight +
                "} " + super.toString();
    }
}
