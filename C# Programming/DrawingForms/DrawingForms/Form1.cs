using System.Drawing.Drawing2D;

namespace DrawingForms
{
    public partial class Form1 : Form
    {
        Graphics gr;
        public Form1()
        {
            InitializeComponent();
            gr = panel.CreateGraphics();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            gr.SmoothingMode = SmoothingMode.AntiAlias;
        }
        private void btnClear_Click(object sender, EventArgs e)
        {
            gr.Clear(panel.BackColor);
            pictureBoxGif.Image = null;
        }

        private void btnFigureGif_Click(object sender, EventArgs e)
        {
            pictureBoxGif.Image = Image.FromFile(@"..\..\..\animatedCircle.gif");
            pictureBoxGif.SizeMode = PictureBoxSizeMode.CenterImage;
        }

        private void btnDrawArcs_Click(object sender, EventArgs e)
        {
            using (var bluePen = new Pen(Color.Blue, 10f))
            {
                using (var redPen = new Pen(Color.Red, 10f))
                {
                    gr.DrawArc(bluePen, 40, 100, 180, 230, 180, 180);
                    gr.DrawArc(redPen, 60, 110, 140, 230, 180, 180);
                    
                    gr.DrawArc(bluePen, 80, 120, 100, 230, 180, 180);
                    gr.DrawArc(redPen, 100, 130, 60, 230, 180, 180);
                    
                    gr.DrawArc(bluePen, 115, 140, 30, 230, 180, 180);
                }
            }

        }

        private void pictureBoxGif_Click(object sender, EventArgs e) { }
    }
}
