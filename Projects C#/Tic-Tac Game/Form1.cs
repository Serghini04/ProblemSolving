using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.NetworkInformation;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tic_Tac_Game.Properties;

namespace Tic_Tac_Game
{
    public partial class Form1 : Form
    {
        int[][] block = new int[][]
        {
             new int[] { -1, -1, -1 },
             new int[] { -1, -1, -1 },
             new int[] { -1, -1, -1 }
        };
        int choose = 1;
        int i = 0;
        void    printMessage(int win)
        {
            if (win == 1)
            {
                MessageBox.Show("Player 1 Win :)", "Tic-Tac-Toe");
                Winner.Text = " Player 1 ";
            }
            else
            {
                MessageBox.Show("Player 2 Win :)", "Tic-Tac-Toe");
                Winner.Text = " Player 2 ";
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    string buttonName = "b" + i.ToString() + j.ToString();
                    Button btn = this.Controls.Find(buttonName, true).FirstOrDefault() as Button;
                    if (btn != null && btn.Enabled)
                        btn.Enabled = false;
                }
            }
        }
        void checkWiner()
        {
            int win = -1;
            i++;
            // first check col
            for (int i = 0; i < 3; i++)
            {
                if (block[i][0] == block[i][1] && block[i][1] == block[i][2] && block[i][0] != -1)
                {
                    win = block[i][0];
                    SetButtonColor("b" + i.ToString() + "0", Color.Green);
                    SetButtonColor("b" + i.ToString() + "1", Color.Green);
                    SetButtonColor("b" + i.ToString() + "2", Color.Green);
                    break;
                }
            }
            // check row
            for (int i = 0; i < 3; i++)
            {
                if (block[0][i] == block[1][i] && block[1][i] == block[2][i] && block[0][i] != -1)
                {
                    Console.WriteLine("fuck\n");
                    win = block[0][i];
                    SetButtonColor("b0" + i.ToString(), Color.Green);
                    SetButtonColor("b1" + i.ToString(), Color.Green);
                    SetButtonColor("b2" + i.ToString(), Color.Green);
                    break;
                }
            }
            // check cross
            if (win == -1 && block[0][0] == block[1][1] && block[1][1] == block[2][2] && block[0][0] != -1)
            {
                win = block[0][0];
                SetButtonColor("b00", Color.Green);
                SetButtonColor("b11", Color.Green);
                SetButtonColor("b22", Color.Green);
            }
            else if (win == -1 && block[0][2] == block[1][1] && block[1][1] == block[2][0] && block[2][0] != -1)
            {
                win = block[2][0];
                SetButtonColor("b20", Color.Green);
                SetButtonColor("b11", Color.Green);
                SetButtonColor("b02", Color.Green);
            }
            if (win != -1)
            {
                printMessage(win);
                return ;
            }
            // draw :
            if (i == 9)
            {
                MessageBox.Show("Draw");
                Winner.Text = "Draw";
            }
        }
        private void SetButtonColor(string buttonName, Color color)
        {
            Button btn = this.Controls.Find(buttonName, true).FirstOrDefault() as Button;
            if (btn != null)
            {
                btn.BackColor = color;
            }
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox9_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox8_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox10_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (choose == 1)
            {
                block[0][0] = 1;
                b00.Image = Resources.X;
                choose = 0;
                Player.Text = "Player 2";
            }
            else
            {
                block[0][0] = 0;
                b00.Image = Resources.O;
                Player.Text = "Player 1";
                choose = 1;
            }
            b00.Enabled = false;
            checkWiner();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (choose == 1)
            {
                block[2][1] = 1;
                b21.Image = Resources.X;
                choose = 0;
                Player.Text = "Player 2";
            }
            else
            {
                block[2][1] = 0;
                b21.Image = Resources.O;
                choose = 1;
                Player.Text = "Player 1";
            }
            b21.Enabled = false;
            checkWiner();
        }

        private void b3_Click(object sender, EventArgs e)
        {
            if (choose == 1)
            {
                block[0][1] = 1;
                b01.Image = Resources.X;
                choose = 0;
                Player.Text = "Player 2";
            }
            else
            {
                block[0][1] = 0;
                b01.Image = Resources.O;
                choose = 1;
                Player.Text = "Player 1";
            }
            b01.Enabled = false;
            checkWiner();
        }

        private void b4_Click(object sender, EventArgs e)
        {
            if (choose == 1)
            {
                block[0][2] = 1;
                b02.Image = Resources.X;
                choose = 0;
                Player.Text = "Player 2";
            }
            else
            {
                block[0][2] = 0;
                b02.Image = Resources.O;
                choose = 1;
                Player.Text = "Player 1";
            }
            b02.Enabled = false;
            checkWiner();
        }

        private void b5_Click(object sender, EventArgs e)
        {
            if (choose == 1)
            {
                block[1][0] = 1;
                b10.Image = Resources.X;
                choose = 0;
                Player.Text = "Player 2";
            }
            else
            {
                block[1][0] = 0;
                b10.Image = Resources.O;
                choose = 1;
                Player.Text = "Player 1";
            }
            b10.Enabled = false;
            checkWiner();
        }

        private void b6_Click(object sender, EventArgs e)
        {
            if (choose == 1)
            {
                block[1][1] = 1;
                b11.Image = Resources.X;
                choose = 0;
                Player.Text = "Player 2";
            }
            else
            {
                block[1][1] = 0;
                b11.Image = Resources.O;
                choose = 1;
                Player.Text = "Player 1";
            }
            b11.Enabled = false;
            checkWiner();
        }

        private void b7_Click(object sender, EventArgs e)
        {
            if (choose == 1)
            {
                block[1][2] = 1;
                b12.Image = Resources.X;
                choose = 0;
                Player.Text = "Player 2";
            }
            else
            {
                block[1][2] = 0;
                b12.Image = Resources.O;
                choose = 1;
                Player.Text = "Player 1";
            }
            b12.Enabled = false;
            checkWiner();
        }

        private void b8_Click(object sender, EventArgs e)
        {
            if (choose == 1)
            {
                block[2][0] = 1;
                b20.Image = Resources.X;
                choose = 0;
                Player.Text = "Player 2";
            }
            else
            {
                block[2][0] = 0;
                b20.Image = Resources.O;
                choose = 1;
                Player.Text = "Player 1";
            }
            b20.Enabled = false;
            checkWiner();
        }

        private void b10_Click(object sender, EventArgs e)
        {
            if (choose == 1)
            {
                block[2][2] = 1;
                b22.Image = Resources.X;
                choose = 0;
                Player.Text = "Player 2";
            }
            else
            {
                block[2][2] = 0;
                b22.Image = Resources.O;
                choose = 1;
                Player.Text = "Player 1";
            }
            b22.Enabled = false;
            checkWiner();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    block[i][j] = -1;
                    string buttonName = "b" + i.ToString() + j.ToString();
                    Button btn = this.Controls.Find(buttonName, true).FirstOrDefault() as Button;
                    if (btn != null && !btn.Enabled)
                    {
                        btn.Enabled = true;
                        btn.Image = Resources.question_mark_96;
                        btn.BackColor = Color.DarkGray;
                    }
                    }
            }
            choose = 1;
            Player.Text = "Player 1";
        }
    }
}
