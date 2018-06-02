using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab3
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Task form = new Task();
            form.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            IndividualTask form = new IndividualTask();
            form.Show();
        }
    }
}
