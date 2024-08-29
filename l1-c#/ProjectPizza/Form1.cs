using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProjectPizza
{
    public partial class Form1 : Form
    {
        int Size = 10;
        int CrustType = 1;
        int Topping = 0;
        void UpdateTopping()
        {
            string strTopping = "";
            int Price = 0;
            if (checkBox1.Checked)
            {
                Price = 2;
                strTopping = "Extra Cheese";
            }
            if (checkBox2.Checked)
            {
                Price += 1;
                strTopping += (strTopping == "") ? "Mushrooms" : ", Mushrooms\n";
            }
            if (checkBox3.Checked)
            {
                Price += 2;
                strTopping += (strTopping == "") ? "Tomatoes" : ", Tomatoes";
            }
            if (checkBox4.Checked)
            {
                Price += 1;
                strTopping += (strTopping == "") ? "Onion" : ", Onion\n";
            }
            if (checkBox5.Checked)
            {
                Price += 2;
                strTopping += (strTopping == "") ? "Olives" : ", Olives";
            }
            if (checkBox6.Checked)
            {
                Price += 3;
                strTopping += (strTopping == "") ? "Green Peppers" : ", Green Peppers";
            }
            if (strTopping == "")
            {
                Topping = 0;
                strTopping = "No Toppings";
            }
            Topping = Price;
            label8.Text = strTopping;
            printPrice();
        }
        public Form1()
        {
            InitializeComponent();
        }
        void printPrice()
        {
            int res = Size + CrustType + Topping;
             label11.Text = "$" + res.ToString();
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
             label7.Text = "Larg";
             Size = 20;
            printPrice();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
             label7.Text = "Small";
             Size = 10;
            printPrice();
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            label7.Text = "Meduim";
            Size = 15;
            printPrice();
        }

        private void radioButton9_CheckedChanged(object sender, EventArgs e)
        {
            label9.Text = "Thin Crust";
            CrustType = 1;
            printPrice();
        }

        private void radioButton8_CheckedChanged(object sender, EventArgs e)
        {
            label9.Text = "Think Crust";
            CrustType = 2;
            printPrice();
        }

        private void radioButton5_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = "Eat In";
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            label10.Text = "Take out";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Enjoy ...", "Take you Pizza :) ", MessageBoxButtons.OKCancel, MessageBoxIcon.Information, MessageBoxDefaultButton.Button1) == DialogResult.OK)
            {
                gbSize.Enabled = false;
                gbToppings.Enabled = false;
                gbType.Enabled = false;
                gbWhereToEat.Enabled = false;
                bOrder.Enabled = false;
            }       
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Size = 10;
            CrustType = 1;
            Topping = 0;
            checkBox1.Checked = false;
            checkBox2.Checked = false;
            checkBox3.Checked = false;
            checkBox4.Checked = false;
            checkBox5.Checked = false;
            checkBox6.Checked = false;
            gbSize.Enabled = true;
            gbToppings.Enabled = true;
            gbType.Enabled = true;
            gbWhereToEat.Enabled = true;
            bOrder.Enabled = true;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTopping();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void groupBox4_Enter(object sender, EventArgs e)
        {

        }

        private void groupBox3_Enter(object sender, EventArgs e)
        {

        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void groupBox5_Enter(object sender, EventArgs e)
        {

        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTopping();
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTopping();
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTopping();
        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTopping();
        }

        private void checkBox6_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTopping();
        }
    }
}
