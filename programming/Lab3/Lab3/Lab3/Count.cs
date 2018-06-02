using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab3
{
    public partial class Count : Form
    {
        public Count(string str)
        {
            InitializeComponent();
            richTextBox1.Text = str;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string str = richTextBox1.Text;
            int sum = 0;
            int mult = 1;
            string temp = "";
            for(int i =0;i<str.Length;i++)
            {
                if (Char.IsDigit(str[i]))
                {
                    temp += str[i];
                    if (i == str.Length - 1)
                    {
                        sum += Convert.ToInt32(temp);
                        mult *= Convert.ToInt32(temp);
                    }
                }
                else
                {
                    if (temp != "")
                    {
                        sum += Convert.ToInt32(temp);
                        mult *= Convert.ToInt32(temp);
                        temp = "";
                    }
                }
            }
            textBox1.Text = Convert.ToString(sum);
            textBox2.Text = Convert.ToString(mult);
        }

        private void saveAsToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            saveFileDialog1.Filter = "txt file(*.txt)|*.txt";//setting appropriate extensions 
            if (saveFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK &&
                saveFileDialog1.FileName.Length > 0)//if file name was created and OK button pressed
            {
                //save text in richTextBox to this file
                richTextBox1.SaveFile(saveFileDialog1.FileName, RichTextBoxStreamType.PlainText);
            }
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();//create dialog
            openFileDialog1.InitialDirectory = @"C:\";//set initial directory
            openFileDialog1.Filter = "txt files(*.txt)|*.txt|All files (*.*)|*.*";//filter appropriate extensions
            openFileDialog1.FilterIndex = 2;//set filter index

            if (openFileDialog1.ShowDialog() == DialogResult.OK)//if OK button was pressed
            {
                try
                {
                    if ((myStream = openFileDialog1.OpenFile()) != null)
                    {
                        using (myStream)
                        {
                            //read from file and write to the richTextBox
                            richTextBox1.LoadFile(openFileDialog1.FileName, RichTextBoxStreamType.PlainText);
                        }
                    }
                }
                catch (Exception ex)//if file was not found 
                {
                    //show error message
                    MessageBox.Show("Error: could not read file from disk: " + ex.Message);
                }
            }
        }

        private void exitToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            Close();
        }
    }
}
