namespace DrawingForms
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
            panel = new Panel();
            pictureBoxGif = new PictureBox();
            btnBitMap = new Button();
            btnDrawArcs = new Button();
            button3 = new Button();
            panel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBoxGif).BeginInit();
            SuspendLayout();
            // 
            // panel
            // 
            panel.Controls.Add(pictureBoxGif);
            panel.Location = new Point(8, 8);
            panel.Name = "panel";
            panel.Size = new Size(710, 356);
            panel.TabIndex = 5;
            // 
            // pictureBoxGif
            // 
            pictureBoxGif.Location = new Point(345, 19);
            pictureBoxGif.Name = "pictureBoxGif";
            pictureBoxGif.Size = new Size(346, 314);
            pictureBoxGif.TabIndex = 0;
            pictureBoxGif.TabStop = false;
            pictureBoxGif.Click += pictureBoxGif_Click;
            // 
            // btnBitMap
            // 
            btnBitMap.Location = new Point(101, 388);
            btnBitMap.Name = "btnBitMap";
            btnBitMap.Size = new Size(75, 23);
            btnBitMap.TabIndex = 6;
            btnBitMap.Text = "Media";
            btnBitMap.UseVisualStyleBackColor = true;
            btnBitMap.Click += btnFigureGif_Click;
            // 
            // btnDrawArcs
            // 
            btnDrawArcs.Location = new Point(353, 388);
            btnDrawArcs.Name = "btnDrawArcs";
            btnDrawArcs.Size = new Size(75, 23);
            btnDrawArcs.TabIndex = 8;
            btnDrawArcs.Text = "Figure";
            btnDrawArcs.UseVisualStyleBackColor = true;
            btnDrawArcs.Click += btnDrawArcs_Click;
            // 
            // button3
            // 
            button3.Location = new Point(605, 388);
            button3.Name = "button3";
            button3.Size = new Size(75, 23);
            button3.TabIndex = 3;
            button3.Tag = "btnClear_Click";
            button3.Text = "Clear";
            button3.UseVisualStyleBackColor = true;
            button3.Click += btnClear_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(732, 418);
            Controls.Add(btnDrawArcs);
            Controls.Add(btnBitMap);
            Controls.Add(panel);
            Controls.Add(button3);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            panel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)pictureBoxGif).EndInit();
            ResumeLayout(false);
        }

        #endregion
        private Panel panel;
        private Button btnBitMap;
        private Button btnDrawArcs;
        private Button button3;
        private PictureBox pictureBoxGif;
    }
}
