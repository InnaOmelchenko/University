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
    public partial class Task1 : Form
    {
        private static int counter = 0;
        public Task1()
        {
            InitializeComponent();
        }

        private void btnyes_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Mи і не сумнівалися, що Ви так думаєте!");
        }

        private void btnno_MouseMove(object sender, MouseEventArgs e)
        {
            if (counter < 10)
            {
                btnno.Top -= e.Y; btnno.Left += e.X;
                if (btnno.Top < -10 || btnno.Top > 100) btnno.Top = 60;
                if (btnno.Left < -80 || btnno.Left > 250) btnno.Left = 120;
                counter++;
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnno_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Варто щось змінювати у своєму житті");
        }
    }
}
