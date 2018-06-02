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
    public partial class OwnResults : Form
    {
        public OwnResults()
        {
            InitializeComponent();

            System.Globalization.CultureInfo customCulture = (System.Globalization.CultureInfo)System.Threading.Thread.CurrentThread.CurrentCulture.Clone();
            customCulture.NumberFormat.NumberDecimalSeparator = ".";

            System.Threading.Thread.CurrentThread.CurrentCulture = customCulture;
        }

        private void validation(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != '.' && e.KeyChar != ' ' && !char.IsControl(e.KeyChar))
            {
                e.Handled = true;
                MessageBox.Show("Вводьте лише числа, розділені пробілами");
            }
        }

        private void richTextBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            validation(sender, e);
        }

        private double[] getArray(RichTextBox rtb)
        {
            if(rtb.Text == "")
            {
                return null;
            }
            string[] stringArr = rtb.Text.Split(' ');
            double[] arr = new double[stringArr.Length];
            for (int i = 0; i < stringArr.Length; i++)
            {
                arr[i] = Convert.ToDouble(stringArr[i]);
            }
            return arr;
        }

        private double badSum(double[] arr)
        {
            return arr[0] + arr[1];
        }

        private double goodSum(double[] arr)
        {
            return arr[3] + arr[4];
        }

        private bool checkData(double[] arr, double num, TextBox tb)//num - number of values needed, 
                                                              //tb - text box with an error message
        {
            string err = "";
            if(arr == null || Convert.ToInt32(arr.Sum()) != 100)
            {
                err += "сума чисел має бути 100; ";
            }
            if(arr == null || arr.Length != num)
            {
                err += "кількість числе має бути " + num + ";";
            }

            if (err != "")
            {
                tb.Text = err;
                return false;
            }

            return true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //first text box
            double[] arr = getArray(richTextBox1);
            if(checkData(arr, 5, textBox1))
            {
                double sum1 = badSum(arr);
                double sum2 = goodSum(arr);
                if (sum1 > sum2)
                {
                    textBox1.Text = "Більшість студентів вважають, що навчальний план потребує змін";
                }
                else
                {
                    textBox1.Text = "Студенти задоволені навчальним планом за яким вони навчаються";
                }
            }

            //second text box
            arr = getArray(richTextBox2);
            if(checkData(arr, 5, textBox2))
            {
                double sum1 = badSum(arr);
                double sum2 = goodSum(arr);
                if (sum1 > sum2)
                {
                    textBox2.Text = "В університеті не вистачає сучасного обладнання для комфортного навчання";
                }
                else
                {
                    textBox2.Text = "Студенти достатньо технічно забепечені";
                }
            }

            //3 textBox
            arr = getArray(richTextBox3);
            if(arr != null && arr.Length == 6)
            {
                int max = 0;
                for (int i = 1; i < arr.Length;i++)
                {
                    if(arr[i] > arr[max])
                    {
                        max = i;
                    }
                }
                switch (max+1)
                {
                    case 1:
                        textBox3.Text = "Більшість студентів відвідують заняття бо це їх обов'язок";
                        break;
                    case 2:
                        textBox3.Text = "Більшість студентів відвідують заняття через прагнення отримати нові знання";
                        break;
                    case 3:
                        textBox3.Text = "Більшість студентів відвідують заняття через пошану до викладача";
                        break;
                    case 4:
                        textBox3.Text = "Більшість студентів відвідують заняття через високу якість навчання";
                        break;
                    case 5:
                        textBox3.Text = "Більшість студентів відвідують заняття через строгий контроль";
                        break;
                    case 6:
                        textBox3.Text = "Більшість студентів відвідують заняття через живу і творчу атмосферу на заняттях";
                        break;
                }
            }
            else
            {
                textBox3.Text = "кількість чисел має бути 6;";
            }

            //4 text box
            arr = getArray(richTextBox4);
            if(checkData(arr, 5, textBox4))
            {
                double sum1 = badSum(arr);
                double sum2 = goodSum(arr);
                if (sum1 > sum2)
                {
                    textBox4.Text = "На думку студентів, вони не отримують достатньо прикладних знань у ВНЗ";
                }
                else
                {
                    textBox4.Text = "Студенти отримують достатню кількість прикладних знань у ВНЗ";
                }
            }

            //5 textBox
            arr = getArray(richTextBox5);
            if (checkData(arr, 5, textBox5))
            {
                double sum1 = badSum(arr);
                double sum2 = goodSum(arr);
                if (sum1 > sum2)
                {
                    textBox5.Text = "Стан аудиторій незадовільний. Рівень комфорту низький";
                }
                else
                {
                    textBox5.Text = "Аудиторії достатньо комфортні для навчання";
                }
            }

            //6 textBox
            arr = getArray(richTextBox6);
            if (checkData(arr, 5, textBox6))
            {
                double sum1 = badSum(arr);
                double sum2 = goodSum(arr);
                if (sum1 > sum2)
                {
                    textBox6.Text = "Студенти не отримують той обсяг знань на який розраховували при вступі";
                }
                else
                {
                    textBox6.Text = "Студенти отримують обсяг знань на який розраховували при вступі";
                }
            }

            //7 textBox
            arr = getArray(richTextBox7);
            if (checkData(arr, 2, textBox7))
            {
                int max = (arr[0] > arr[1]) ? 1 : 2;
                switch (max)
                {
                    case 1:
                        textBox7.Text = "Викладачі дотримуються авторитарного стилю спілккування";
                        break;
                    case 2:
                        textBox7.Text = "Викладачі дотримуються демократичного стилю спілккування";
                        break;
                }
            }

            //8 textBox
            arr = getArray(richTextBox8);
            if (checkData(arr, 6, textBox8))
            {
                int max = 0;
                for (int i = 1; i < arr.Length;i++)
                {
                    if(arr[i]> arr[max])
                    {
                        max = i;
                    }
                }
                switch (max+1)
                {
                    case 1:
                        textBox8.Text = "Викладачі постійно використовують технічні засоби, студенти вважають, що це важливо";
                        break;
                    case 2:
                        textBox8.Text = "Викладачі інколи використовують технічні засоби, студенти вважають, що це важливо";
                        break;
                    case 3:
                        textBox8.Text = "Викладачі ніколи не використовують технічні засоби, студенти вважають, що це важливо";
                        break;
                    case 4:
                        textBox8.Text = "Викладачі постійно використовують технічні засоби, студенти вважають, що це не важливо";
                        break;
                    case 5:
                        textBox8.Text = "Викладачі інколи використовують технічні засоби, студенти вважають, що це не важливо";
                        break;
                    case 6:
                        textBox8.Text = "Викладачі ніколи не використовують технічні засоби, студенти вважають, що це не важливо";
                        break;
                }
            }

            //9 textBox
            arr = getArray(richTextBox9);
            if (checkData(arr, 5, textBox9))
            {
                double sum1 = badSum(arr);
                double sum2 = goodSum(arr);
                if (sum1 > sum2)
                {
                    textBox9.Text = "Студенти не задоволені обраною спеціальністю";
                }
                else
                {
                    textBox9.Text = "Студенти задоволені обраною спеціальністю";
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
