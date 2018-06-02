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
    public partial class Task3 : Form
    {
        public Task3()
        {
            InitializeComponent();
            textBox1.Enabled = textBox2.Enabled = false;
        }

        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Help.ShowHelp(this, helpProvider1.HelpNamespace);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Help.ShowHelp(this, helpProvider1.HelpNamespace);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Enabled)
            {
                textBox1.Enabled = textBox2.Enabled = false;//making textboxes unavailable
            }
            else
            {
                textBox1.Enabled = textBox2.Enabled = true;//making textboxes available
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Enabled)
            {
                //reading entered number, adding them and displaying them
                textBox3.Text = Convert.ToString(Convert.ToInt32(textBox1.Text) + Convert.ToInt32(textBox2.Text));
            }
            else
            {
                MessageBox.Show("First click \"Start Word\" button");
            }

        }
    }
}
