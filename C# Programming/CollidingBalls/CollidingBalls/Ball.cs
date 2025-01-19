namespace CollidingBalls
{
    public class Ball
    {
        public int squareX;
        public int squareY;
        public Point position;
        public int dx;
        public int dy;
        public Color color;

        public Ball(int squareX, int squareY, Point position, int dx, int dy, Color color)
        {
            this.squareX = squareX;
            this.squareY = squareY;
            this.position = position;
            this.dx = dx;
            this.dy = dy;
            this.color = color;
        }

        public void MakeStep(int maxX, int maxY)
        {
            position.X += dx;
            position.Y += dy;

            if (position.X <= 0 || position.X + squareX >= maxX)
            {
                dx = -dx;
                position.X += dx;
            }
            if (position.Y <= 0 || position.Y + squareY >= maxY)
            {
                dy = -dy;
                position.Y += dy;
            }
        }
    }
}
