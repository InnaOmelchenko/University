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

namespace Lab4
{
    public partial class IndividualTask : Form
    {
        public IndividualTask()
        {
            InitializeComponent();
        }

        private void exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            New_Click(sender, e);
        }

        private void New_Click(object sender, EventArgs e)
        {
            ArrayForm form = new ArrayForm();
            DialogResult result = form.ShowDialog();//start form as dialog
            if (result == DialogResult.OK)//if OK button was pressed
            {
                //set info entered on the dialog as text of the richTextBox 
                richTextBox1.Text =form.getArray;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Count form = new Count(richTextBox1.Text);
            form.Show();
        }

        private void Open_Click(object sender, EventArgs e)
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

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Open_Click(sender, e);
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveAs_Click(sender, e);
        }

        private void saveAs_Click(object sender, EventArgs e)
        {
            saveFileDialog1.Filter = "txt file(*.txt)|*.txt";//setting appropriate extensions 
            if (saveFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK &&
                saveFileDialog1.FileName.Length > 0)//if file name was created and OK button pressed
            {
                //save text in richTextBox to this file
                richTextBox1.SaveFile(saveFileDialog1.FileName, RichTextBoxStreamType.PlainText);
            }
        }

        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Help.ShowHelp(this, helpProvider1.HelpNamespace);
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            Help.ShowHelp(this, helpProvider1.HelpNamespace);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Help.ShowHelp(this, helpProvider1.HelpNamespace);
        }
    }
}
