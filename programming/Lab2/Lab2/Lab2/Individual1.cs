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
    public partial class Individual1 : Form
    {
        public Individual1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Individual2 form = new Individual2();
            form.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Author: Inna Omelchenko. IS-61"
            +"\n Task: "
            +" \n16. Створити головне вікно застосування, меню якого містить команди виклику форм" 
            + " Про програму і Купівля квитків на потяги, який працює за таким сценарієм: увести прізвище замовника,"
            +" з комбінованого списку вибрати тип вагону (купейний, плацкартний, СВ), відобразити ціну за один кілометр,"
            +" яка вибирається автоматично з файлу, з управляючого елемента Календар вибрати дату, задати кількість місць"
            +" та кінцевий пункт призначення, розрахувати вартість квитка відповідно до довжини маршруту, відобразити загальну"
            +" суму згідно з кількістю місць. Після закриття форми кнопкою <OK> відобразити квиток у новій формі.");
        }
    }
}
