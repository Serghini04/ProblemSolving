namespace Tic_Tac_Game
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.Player = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.Winner = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.b22 = new System.Windows.Forms.Button();
            this.b21 = new System.Windows.Forms.Button();
            this.b12 = new System.Windows.Forms.Button();
            this.b02 = new System.Windows.Forms.Button();
            this.b11 = new System.Windows.Forms.Button();
            this.b01 = new System.Windows.Forms.Button();
            this.b20 = new System.Windows.Forms.Button();
            this.b10 = new System.Windows.Forms.Button();
            this.b00 = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 28.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label1.Location = new System.Drawing.Point(347, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(464, 59);
            this.label1.TabIndex = 1;
            this.label1.Text = "Tic-Tac-Toe Game";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label4.Location = new System.Drawing.Point(380, 186);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(382, 16);
            this.label4.TabIndex = 4;
            this.label4.Text = "***************************************************************************";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label2.Location = new System.Drawing.Point(494, 93);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(14, 324);
            this.label2.TabIndex = 5;
            this.label2.Text = "*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n\r\n\r\n\r\n\r\n";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.Transparent;
            this.label6.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label6.Location = new System.Drawing.Point(118, 95);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(119, 35);
            this.label6.TabIndex = 8;
            this.label6.Text = " Turn :";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // Player
            // 
            this.Player.AutoSize = true;
            this.Player.BackColor = System.Drawing.Color.Transparent;
            this.Player.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Player.ForeColor = System.Drawing.SystemColors.Highlight;
            this.Player.Location = new System.Drawing.Point(92, 156);
            this.Player.Name = "Player";
            this.Player.Size = new System.Drawing.Size(160, 35);
            this.Player.TabIndex = 9;
            this.Player.Text = " Player  1";
            this.Player.Click += new System.EventHandler(this.label7_Click);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.Color.Transparent;
            this.label8.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label8.Location = new System.Drawing.Point(100, 225);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(160, 35);
            this.label8.TabIndex = 10;
            this.label8.Text = " Winner :";
            this.label8.Click += new System.EventHandler(this.label8_Click);
            // 
            // Winner
            // 
            this.Winner.AutoSize = true;
            this.Winner.BackColor = System.Drawing.Color.Transparent;
            this.Winner.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Winner.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.Winner.Location = new System.Drawing.Point(80, 284);
            this.Winner.Name = "Winner";
            this.Winner.Size = new System.Drawing.Size(216, 35);
            this.Winner.TabIndex = 11;
            this.Winner.Text = " In Progress ";
            this.Winner.Click += new System.EventHandler(this.label9_Click);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.LightCyan;
            this.button1.Font = new System.Drawing.Font("Showcard Gothic", 13.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.Color.Crimson;
            this.button1.Location = new System.Drawing.Point(106, 345);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(146, 49);
            this.button1.TabIndex = 12;
            this.button1.Text = "Restart";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // b22
            // 
            this.b22.BackColor = System.Drawing.Color.DarkGray;
            this.b22.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b22.Image = global::Tic_Tac_Game.Properties.Resources.question_mark_96;
            this.b22.Location = new System.Drawing.Point(659, 322);
            this.b22.Name = "b22";
            this.b22.Size = new System.Drawing.Size(102, 86);
            this.b22.TabIndex = 21;
            this.b22.Tag = "-1";
            this.b22.UseVisualStyleBackColor = false;
            this.b22.Click += new System.EventHandler(this.b10_Click);
            // 
            // b21
            // 
            this.b21.BackColor = System.Drawing.Color.DarkGray;
            this.b21.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b21.Image = global::Tic_Tac_Game.Properties.Resources.question_mark_96;
            this.b21.Location = new System.Drawing.Point(522, 322);
            this.b21.Name = "b21";
            this.b21.Size = new System.Drawing.Size(102, 86);
            this.b21.TabIndex = 20;
            this.b21.Tag = "-1";
            this.b21.UseVisualStyleBackColor = false;
            this.b21.Click += new System.EventHandler(this.button9_Click);
            // 
            // b12
            // 
            this.b12.BackColor = System.Drawing.Color.DarkGray;
            this.b12.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b12.Image = global::Tic_Tac_Game.Properties.Resources.question_mark_96;
            this.b12.Location = new System.Drawing.Point(659, 205);
            this.b12.Name = "b12";
            this.b12.Size = new System.Drawing.Size(102, 86);
            this.b12.TabIndex = 19;
            this.b12.Tag = "-1";
            this.b12.UseVisualStyleBackColor = false;
            this.b12.Click += new System.EventHandler(this.b7_Click);
            // 
            // b02
            // 
            this.b02.BackColor = System.Drawing.Color.DarkGray;
            this.b02.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b02.Image = global::Tic_Tac_Game.Properties.Resources.question_mark_96;
            this.b02.Location = new System.Drawing.Point(659, 93);
            this.b02.Name = "b02";
            this.b02.Size = new System.Drawing.Size(102, 86);
            this.b02.TabIndex = 18;
            this.b02.UseVisualStyleBackColor = false;
            this.b02.Click += new System.EventHandler(this.b4_Click);
            // 
            // b11
            // 
            this.b11.BackColor = System.Drawing.Color.DarkGray;
            this.b11.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b11.Image = global::Tic_Tac_Game.Properties.Resources.question_mark_96;
            this.b11.Location = new System.Drawing.Point(522, 205);
            this.b11.Name = "b11";
            this.b11.Size = new System.Drawing.Size(102, 86);
            this.b11.TabIndex = 17;
            this.b11.Tag = "-1";
            this.b11.UseVisualStyleBackColor = false;
            this.b11.Click += new System.EventHandler(this.b6_Click);
            // 
            // b01
            // 
            this.b01.BackColor = System.Drawing.Color.DarkGray;
            this.b01.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b01.Image = global::Tic_Tac_Game.Properties.Resources.question_mark_96;
            this.b01.Location = new System.Drawing.Point(522, 93);
            this.b01.Name = "b01";
            this.b01.Size = new System.Drawing.Size(102, 86);
            this.b01.TabIndex = 16;
            this.b01.Tag = "-1";
            this.b01.UseVisualStyleBackColor = false;
            this.b01.Click += new System.EventHandler(this.b3_Click);
            // 
            // b20
            // 
            this.b20.BackColor = System.Drawing.Color.DarkGray;
            this.b20.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b20.Image = global::Tic_Tac_Game.Properties.Resources.question_mark_96;
            this.b20.Location = new System.Drawing.Point(383, 322);
            this.b20.Name = "b20";
            this.b20.Size = new System.Drawing.Size(102, 86);
            this.b20.TabIndex = 15;
            this.b20.Tag = "-1";
            this.b20.UseVisualStyleBackColor = false;
            this.b20.Click += new System.EventHandler(this.b8_Click);
            // 
            // b10
            // 
            this.b10.BackColor = System.Drawing.Color.DarkGray;
            this.b10.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b10.Image = global::Tic_Tac_Game.Properties.Resources.question_mark_96;
            this.b10.Location = new System.Drawing.Point(383, 205);
            this.b10.Name = "b10";
            this.b10.Size = new System.Drawing.Size(102, 86);
            this.b10.TabIndex = 14;
            this.b10.Tag = "-1";
            this.b10.UseVisualStyleBackColor = false;
            this.b10.Click += new System.EventHandler(this.b5_Click);
            // 
            // b00
            // 
            this.b00.BackColor = System.Drawing.Color.DarkGray;
            this.b00.Cursor = System.Windows.Forms.Cursors.Hand;
            this.b00.Image = global::Tic_Tac_Game.Properties.Resources.question_mark_96;
            this.b00.Location = new System.Drawing.Point(383, 93);
            this.b00.Name = "b00";
            this.b00.Size = new System.Drawing.Size(102, 86);
            this.b00.TabIndex = 13;
            this.b00.Tag = "-1";
            this.b00.UseVisualStyleBackColor = false;
            this.b00.Click += new System.EventHandler(this.button2_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::Tic_Tac_Game.Properties.Resources.Green;
            this.pictureBox1.Location = new System.Drawing.Point(-4, 0);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(913, 519);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            this.pictureBox1.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBox1_Paint);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label3.Location = new System.Drawing.Point(384, 299);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(377, 16);
            this.label3.TabIndex = 22;
            this.label3.Text = "**************************************************************************";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label5.Location = new System.Drawing.Point(635, 95);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(14, 324);
            this.label5.TabIndex = 23;
            this.label5.Text = "*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n*\r\n\r\n\r\n\r\n\r\n";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(894, 496);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.b22);
            this.Controls.Add(this.b21);
            this.Controls.Add(this.b12);
            this.Controls.Add(this.b02);
            this.Controls.Add(this.b11);
            this.Controls.Add(this.b01);
            this.Controls.Add(this.b20);
            this.Controls.Add(this.b10);
            this.Controls.Add(this.b00);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Winner);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.Player);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = " Tic-Tak-Toe";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label Player;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label Winner;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button b00;
        private System.Windows.Forms.Button b10;
        private System.Windows.Forms.Button b20;
        private System.Windows.Forms.Button b01;
        private System.Windows.Forms.Button b11;
        private System.Windows.Forms.Button b02;
        private System.Windows.Forms.Button b12;
        private System.Windows.Forms.Button b21;
        private System.Windows.Forms.Button b22;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label5;
    }
}

