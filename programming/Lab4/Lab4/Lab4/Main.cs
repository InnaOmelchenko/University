using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab4
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Task1 form = new Task1();
            form.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Task2 form = new Task2();
            form.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Task3 form = new Task3();
            form.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            IndividualTask form = new IndividualTask();
            form.Show();
        }
    }
}
