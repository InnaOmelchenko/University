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
    public partial class Results : Form
    {
        public Results()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("../../1q.png");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("../../2q.png");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("../../3q.png");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("../../4q.png");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("../../5q.png");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("../../6q.png");
        }

        private void button7_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("../../7q.png");
        }

        private void button8_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("../../8q.png");
        }

        private void button9_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("../../9q.png");
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("https://goo.gl/forms/a4aonEB9zjGMB6iv1");
            linkLabel1.LinkVisited = true;
        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("https://docs.google.com/forms/d/1AF9g_-C15Kio6VBh2QL5t89-28bDbqL2HVYZR1pvdW0/edit#responses");
            linkLabel2.LinkVisited = true;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("../../answ.png");
        }

    }
}
