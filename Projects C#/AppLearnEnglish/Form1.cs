using AppLearnEnglish.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppLearnEnglish
{
    public partial class Form1 : Form
    {
        int index = 0;
        string[][] arr = new string[][]
        {
            new string[] { "Rat", "Cat", "Dog" },
            new string[] { "Pen", "Fog", "Hen" },
            new string[] { "Bed", "Pet", "Huge" }
        };
        int[] correctAnswers = { 1, 2, 0 };
        void checkCorrectAnswered()
        {
            RadioButton[] answers = { Answer1, Answer2, Answer3 };

            if (answers[correctAnswers[index]].Checked)
            {
                button1.BackColor = Color.Green;
                button1.Enabled = true;
            }
            else
            {
                button1.BackColor = Color.Red;
                button1.Enabled = false;
            }
        }
        void    updateFram()
        {
            if (index == 0)
                pictureBox1.Image = Resources.cat;
            else if (index == 1)
                pictureBox1.Image = Resources.Hen;
            else if (index == 2)
                pictureBox1.Image = Resources.bed;
            button1.BackColor = Color.Red;
            button1.Enabled = false;
            Answer1.Text = arr[index][0];
            Answer2.Text = arr[index][1];
            Answer3.Text = arr[index][2];
        }
        public Form1()
        {
            InitializeComponent();
           // this.Size = new Size(991, 540);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            checkCorrectAnswered();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            index = (index + 1) % 3;
            updateFram();
        }

        private void Answer2_CheckedChanged(object sender, EventArgs e)
        {
            checkCorrectAnswered();
        }

        private void Answer3_CheckedChanged(object sender, EventArgs e)
        {
            checkCorrectAnswered();
        }

        private void button2_Click(object sender, EventArgs e)
        {
           index = (index - 1 + 3) % 3;
           updateFram();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
