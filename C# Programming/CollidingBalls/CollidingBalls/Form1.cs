using System.Drawing.Drawing2D;

namespace CollidingBalls
{
    public partial class Form1 : Form
    {
        List<Ball> balls;
        private List<(Ball Ball1, Ball Ball2, DateTime CollisionTime)> collidedBalls = new();


        public Form1()
        {
            InitializeComponent();
            balls = new List<Ball>();
            this.DoubleBuffered = true;
            SetStyle(ControlStyles.AllPaintingInWmPaint | ControlStyles.OptimizedDoubleBuffer | ControlStyles.ResizeRedraw | ControlStyles.UserPaint, true);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            balls.Add(new Ball(20, 20, new Point(0, 0), 1, 1, Color.Red));
            balls.Add(new Ball(20, 20, new Point(pictureBox.ClientSize.Width - 50, 78), 1, 1, Color.Blue));
            balls.Add(new Ball(20, 20, new Point(pictureBox.ClientSize.Height - 60, 60), 1, 1, Color.Green));
            balls.Add(new Ball(20, 20, new Point(0, 90), 1, 1, Color.Yellow));
            balls.Add(new Ball(20, 20, new Point(0, 120), 1, 1, Color.Purple));

            timer.Interval = 1;

        }

        private void button_Start_Click(object sender, EventArgs e)
        {
            timer.Start();
        }

        private void button_Stop_Click(object sender, EventArgs e)
        {
            timer.Stop();
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            int maxX = pictureBox.ClientSize.Width;
            int maxY = pictureBox.ClientSize.Height;

            foreach (var ball in balls)
            {
                ball.MakeStep(maxX, maxY);
            }

            int displayTime = 500; 
            collidedBalls = collidedBalls.Where(c => (DateTime.Now - c.CollisionTime).TotalMilliseconds <= displayTime).ToList();

            for (int i = 0; i < balls.Count; i++)
            {
                for (int j = i + 1; j < balls.Count; j++)
                {
                    if (AreBallsColliding(balls[i], balls[j]))
                    {
                        HandleCollision(balls[i], balls[j]);

                        collidedBalls.Add((balls[i], balls[j], DateTime.Now));

                        timer.Stop();
                    }
                }
            }

            pictureBox.Invalidate();
        }

        private void pictureBox_Paint(object sender, PaintEventArgs e)
        {
            Graphics gr = e.Graphics;
            gr.SmoothingMode = SmoothingMode.HighQuality;

            foreach (var ball in balls)
            {
                using (SolidBrush brush = new SolidBrush(ball.color))
                {
                    gr.FillEllipse(brush, ball.position.X, ball.position.Y, ball.squareX, ball.squareY);
                }
            }

            foreach (var collision in collidedBalls)
            {
                DrawTextAboveBall(gr, collision.Ball1, "Collision!");
                DrawTextAboveBall(gr, collision.Ball2, "Collision!");
            }
        }

        private void HandleCollision(Ball ball1, Ball ball2)
        {
            int tempDx = ball1.dx;
            int tempDy = ball1.dy;
            ball1.dx = ball2.dx;
            ball1.dy = ball2.dy;
            ball2.dx = tempDx;
            ball2.dy = tempDy;
        }

        private bool AreBallsColliding(Ball ball1, Ball ball2)
        {
            int deltaX = (ball1.position.X + ball1.squareX / 2) - (ball2.position.X + ball2.squareX / 2);
            int deltaY = (ball1.position.Y + ball1.squareY / 2) - (ball2.position.Y + ball2.squareY / 2);
            double distance = Math.Sqrt(deltaX * deltaX + deltaY * deltaY);

            double radiusSum = (ball1.squareX + ball2.squareX) / 2.0;

            return distance <= radiusSum;
        }

        private void DrawTextAboveBall(Graphics gr, Ball ball, string text)
        {
            using (Font font = new Font("Arial", 12, FontStyle.Bold))
            {
                using (SolidBrush textBrush = new SolidBrush(Color.Black))
                {
                    SizeF textSize = gr.MeasureString(text, font);
                    float textX = ball.position.X + (ball.squareX / 2) - (textSize.Width / 2);
                    float textY = ball.position.Y - textSize.Height - 5;
                    if (textY < 0) textY = 0;
                    gr.DrawString(text, font, textBrush, textX, textY);
                }
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        
    }
}
