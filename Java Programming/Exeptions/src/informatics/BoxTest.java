package informatics;

import exceptions.IllegalIncreaseValueException;

import static org.junit.jupiter.api.Assertions.*;

class BoxTest {

    @org.junit.jupiter.api.Test
    void increaseDimentions_NegativeIncreaseValue_ThrowsIllegalIncreaseValue() {
        Box box = new Box(2, 3,4);

        assertThrows(IllegalIncreaseValueException.class, () -> box.increaseDimentions(-10));
    }
}