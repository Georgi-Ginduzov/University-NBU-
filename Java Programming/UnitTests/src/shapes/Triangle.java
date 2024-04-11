package shapes;

import java.util.Objects;

public class Triangle {
    private int side1;
    private int side2;
    private int side3;

    public Triangle(int side1, int side2, int side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public int getSide1() {
        return side1;
    }

    public void setSide1(int side1) {
        this.side1 = side1;
    }

    public int getSide2() {
        return side2;
    }

    public void setSide2(int side2) {
        this.side2 = side2;
    }

    public int getSide3() {
        return side3;
    }

    public void setSide3(int side3) {
        this.side3 = side3;
    }

    public int perimeter(){
        if (isTriangle()){
            return getSide1() + getSide2() + getSide3();
        }
        return 0;
    }

    public boolean isTriangle(){
        return this.side1 + this.side2 > this.side3
                && this.side2 + this.side3 > this.side1
                && this.side3 + this.side1 > this.side2;
    }

    public int increaseSide1(int increaseValue){
        if (increaseValue > 0 && isTriangle()){
            return this.side1 + increaseValue;
        }
        return this.side1;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Triangle triangle = (Triangle) o;
        return side1 == triangle.side1 && side2 == triangle.side2 && side3 == triangle.side3;
    }

    @Override
    public int hashCode() {
        return Objects.hash(side1, side2, side3);
    }

    @Override
    public String toString() {
        return "Triangle{" +
                "side1=" + side1 +
                ", side2=" + side2 +
                ", side3=" + side3 +
                '}';
    }
}
