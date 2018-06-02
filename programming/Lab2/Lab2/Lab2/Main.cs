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
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form form = new Task1();
            form.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form form = new TestList();
            form.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Task3 form = new Task3();
            form.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Завдання 4 - доповнене 3. Дивитись у Task 3 - status strip");
            Task3 form = new Task3();
            form.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Task5 form = new Task5();
            form.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Task6 form = new Task6();
            form.Show();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Завдання 7 - доповнене 6. Дивитись у Task 6 - елементи з підтримкою редагування тексту: adress and phone number");
            Task6 form = new Task6();
            form.Show();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Task8 form = new Task8();
            form.Show();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Завдання 9 - доповнене 8. Дивитись у Task 8 - Події KeyPress і Validating. Елемент управління ErrorProvider ");
            Task8 form = new Task8();
            form.Show();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            Individual1 form = new Individual1();
            form.Show();
        }

    }
}
