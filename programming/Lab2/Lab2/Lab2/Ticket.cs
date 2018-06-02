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
    public partial class Ticket : Form
    {
        public Ticket(string name, string type, string num, string destination, string date, string price)
        {
            InitializeComponent();
            label1.Text = "---Інформація про квиток---" +
                "\nЗамовник: " + name +
                "\nТип вагону: " + type + 
                "\nКількість місць: " + num + 
                "\nПункт призначення: " + destination + 
                "\nДата: " + date + 
                "\nЦіна: " + price;
        }
    }
}
