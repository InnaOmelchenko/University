using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2
{
    public partial class Individual2 : Form
    {
        private double distance = 0;

        public Individual2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "" && comboBox1.Text != "" && textBox3.Text != "" && comboBox2.Text != "" && textBox4.Text != "" && textBox5.Text != "")
            {
                Ticket form = new Ticket(textBox1.Text, comboBox1.Text, textBox3.Text, comboBox2.Text, textBox4.Text, textBox5.Text);
                form.Show();
            }
            else
            {
                MessageBox.Show("Спершу введіть всі необхідні дані та підрахуйте загальну вартість");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void monthCalendar1_DateSelected(object sender, DateRangeEventArgs e)
        {
            textBox4.Text = e.Start.ToShortDateString();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch(comboBox1.Text)
            {
                case "Купе":
                    textBox2.Text = "1";
                    break;
                case "Плацкарт":
                    textBox2.Text = "0.5";
                    break;
                case "СВ":
                    textBox2.Text = "5";
                    break;
            }
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBox2.Text)
            {
                case "Львів":
                    distance = 541;
                    break;
                case "Одеса":
                    distance = 484;
                    break;
                case "Луцьк":
                    distance = 400;
                    break;
                case "Івано-Франківськ":
                    distance = 604;
                    break;
                case "Запоріжжя":
                    distance = 516;
                    break;
                case "Дніпро":
                    distance = 453;
                    break;
                case "Харків":
                    distance = 480;
                    break;
                case "Суми":
                    distance = 333;
                    break;
                case "Чернігів":
                    distance = 142;
                    break;
                case "Тернопіль":
                    distance = 420;
                    break;
                case "Хмельницький":
                    distance = 323;
                    break;
                case "Біла церква":
                    distance = 87;
                    break;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                textBox5.Text = Convert.ToString(Convert.ToDouble(textBox2.Text) * distance * Convert.ToDouble(textBox3.Text));
            }
            catch(Exception ex)
            {
                MessageBox.Show("Спершу введіть всі необхідні дані");
            }
        }

        private void textBox3_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
                MessageBox.Show("Тут має бути лише число");
            }

        }
    }
}
