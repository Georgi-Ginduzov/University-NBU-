namespace CollidingBalls
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            button1 = new Button();
            button2 = new Button();
            pictureBox = new PictureBox();
            timer = new System.Windows.Forms.Timer(components);
            ((System.ComponentModel.ISupportInitialize)pictureBox).BeginInit();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Location = new Point(653, 407);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 0;
            button1.Text = "Stop";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button_Stop_Click;
            // 
            // button2
            // 
            button2.Location = new Point(110, 400);
            button2.Name = "button2";
            button2.Size = new Size(75, 23);
            button2.TabIndex = 1;
            button2.Text = "Start";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button_Start_Click;
            // 
            // pictureBox1
            // 
            pictureBox.BackColor = SystemColors.ControlLight;
            pictureBox.Location = new Point(51, 29);
            pictureBox.Name = "pictureBox1";
            pictureBox.Size = new Size(698, 350);
            pictureBox.TabIndex = 2;
            pictureBox.TabStop = false;
            pictureBox.Click += pictureBox1_Click;
            pictureBox.Paint += pictureBox_Paint;
            // 
            // timer
            // 
            timer.Tick += timer_Tick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(pictureBox);
            Controls.Add(button2);
            Controls.Add(button1);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)pictureBox).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private Button button1;
        private Button button2;
        private PictureBox pictureBox;
        private System.Windows.Forms.Timer timer;
    }
}
