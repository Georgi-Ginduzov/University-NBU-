package shapes;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TriangleTest {

    Triangle triangle;

    @BeforeEach
    void init(){
        this.triangle = new Triangle(4, 5, 6);
    }

    @Test
    void perimeter(){
        // when
        int actual = triangle.perimeter();

        // then
        int expected = 12;
        assertEquals(expected, actual);
    }

    @Test
    void isTriangle() {
        assertTrue(triangle.isTriangle());
    }

    @Test
    void increaseSide1(){
        //assertEquals();
    }
}