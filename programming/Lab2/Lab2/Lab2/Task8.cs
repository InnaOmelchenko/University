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
    public partial class Task8 : Form
    {
        public Task8()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)//if checkbox is checked
            {
                Label lbl = new Label();//creating label
                lbl.Location = new System.Drawing.Point(16, 23);//setting its location
                lbl.Size = new System.Drawing.Size(42, 32);//setting its size
                lbl.Name = "label01";//setting its name
                lbl.TabIndex = 2;//setting its tab index
                lbl.Text = "PIN 2";//setting its text
                groupBox1.Controls.Add(lbl);//adding label to the form

                //doing the same process with text box
                TextBox txt = new TextBox();
                txt.Location = new System.Drawing.Point(90, 23);
                txt.Size = new System.Drawing.Size(90, 20);
                txt.Name = "textbox";
                txt.TabIndex = 1;
                txt.Text = "";
                groupBox1.Controls.Add(txt);

                ////adding action to the text box
                txt.KeyPress += new System.Windows.Forms.KeyPressEventHandler(textBox2_KeyPress);
            }
            else
            {
                groupBox1.Controls.Clear();//remove all controls
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Ви успішно зареєстровані!");
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
                errorProvider1.SetError(textBox1, "Must be letter");
                //MessageBox.Show("Поле Name не може містити цифри");
            }
        }



        //to use this type of validating: 
        //copy the name of this function to the KeyPress event of the textBox2 events
        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
                MessageBox.Show("Поле PIN не може містити букви");
            }
        }


        //to use this type of validating: 
        //copy the name of this function to the Validating event of the textBox2 events
        private void textBox2_Validating(object sender, CancelEventArgs e)
        {
            if (textBox2.Text == "")
            {
                e.Cancel = false;
            }
            else
            {
                try
                {
                    double.Parse(textBox2.Text); 
                    e.Cancel = false;
                }
                catch
                {
                    e.Cancel = true;
                    MessageBox.Show("Поле PIN не може мати букви");
                }
            }

        }
    }
}
