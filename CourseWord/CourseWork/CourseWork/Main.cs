using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CourseWork
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Questions form = new Questions();
            form.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Results form = new Results();
            form.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            OwnResults form = new OwnResults();
            form.Show();
        }
    }
}
