using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace delegates_Inna_
{
    class Program
    {
        static void Main(string[] args)
        {
            MyEvent myevent = new MyEvent();
            myevent.cardStuck += new MyEventHandler(cardStuckHandler);
            myevent.cardLost += new MyEventHandler(cardLostHandler);

            myevent.callService();

            Console.ReadLine();
        }

        static void cardStuckHandler()
        {
            Console.WriteLine("you will get your new card in the next 10 days");
        }

        static void cardLostHandler()
        {
            Console.WriteLine("you will get your new card in the next 3 weeks\n" + 
                "and there is no more money on your card)))");
        }
    }
}
