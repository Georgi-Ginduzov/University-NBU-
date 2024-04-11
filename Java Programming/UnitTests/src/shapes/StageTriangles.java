package shapes;

import java.util.ArrayList;
import java.util.List;

public class StageTriangles {
    private List<Triangle> triangles;

    public StageTriangles() {
        this.triangles = new ArrayList<Triangle>();
    }

    public boolean addTriangle(Triangle triangle) {
        return this.triangles.add(triangle);
    }

    public int totalPerimeter(){
        int total = 0;
        for (Triangle triangle : this.triangles) {
            total += triangle.perimeter();
        }

        return total;
    }

    public List<Triangle> TrianglesWithPerimeterGreaterThan(int value) {
        List<Triangle> triangleList = new ArrayList<>();
        for (Triangle triangle : this.triangles) {
            if (triangle.perimeter() > value) {
                triangleList.add(triangle);
            }
        }

        return triangleList;
    }
}
