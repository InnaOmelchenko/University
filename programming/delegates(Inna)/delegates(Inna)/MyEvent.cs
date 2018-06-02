using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace delegates_Inna_
{
    delegate void MyEventHandler();
    class MyEvent
    {
        public event MyEventHandler cardStuck;
        public event MyEventHandler cardLost;

        public void callService()
        {
            Console.WriteLine("What is your problem?\n" + 
                "1 - I forgot my credit card in ATM\n" + 
                "2 - I lost my credit card\n");

            int ans = Convert.ToInt32(Console.ReadLine());
            if (ans == 1) cardStuck();
            else if (ans == 2) cardLost();
            else Console.WriteLine("invalid answer");
        }
    }
}
