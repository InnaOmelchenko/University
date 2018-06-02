using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Indexators
{
    class Program
    {
        static void Main(string[] args)
        {
            int day, month, year;
            int hour, minute, second;

            Console.WriteLine("Indexators, lab#2"
                                + "Inna Omelchenko"
                                + "IS-61");

            Console.WriteLine("Enter next information about TIME: ");
            Console.Write("Hours: ");
            hour = Convert.ToInt32(Console.ReadLine());
            while(hour > 23 || hour < 0)
            {
                Console.Write("Invalid value\nenter again\nHours: ");
                hour = Convert.ToInt32(Console.ReadLine());
            }

            Console.WriteLine("Minutes: ");
            Int32.TryParse(Console.ReadLine(), out minute);

            Console.WriteLine("Seconds: ");
            Int32.TryParse(Console.ReadLine(), out second);

            Time time = new Time(hour, minute, second);

            Console.WriteLine("TIME: ");
            Console.WriteLine("Hours: " + time.time[0] + "   Minutes: " + time.time[1] + "   Seconds: " + time.time[2]); // прямий доступ
            Console.WriteLine("Hours: " + time.Hours + "   Minutes: " + time.Minutes + "   Seconds: " + time.Seconds); // доступ через властивість
            Console.WriteLine("Hours: " + time[0] + "   Minutes: " + time[1] + "   Seconds: " + time[2]); // доступ через індексатор

            Console.ReadLine();

            Console.WriteLine("Enter next information about DATA: ");
            Console.WriteLine("Day: ");
            Int32.TryParse(Console.ReadLine(), out day);

            Console.WriteLine("Month: ");
            Int32.TryParse(Console.ReadLine(), out month);

            Console.WriteLine("Year: ");
            Int32.TryParse(Console.ReadLine(), out year);

            Date date = new Date(day, month, year);

            Console.WriteLine("\n\nDate:");
            Console.WriteLine("Day: " + date.date[0] + "   Month: " + date.date[1] + "   Year: " + date.date[2]); // прямий доступ
            Console.WriteLine("Day: " + date.Day + "   Month: " + date.Month + "   Year: " + date.Year);  // доступ через властивість
            Console.WriteLine("Day: " + date[0] + "   Month: " + date[1] + "   Year: " + date[2]); // доступ через індексатор

            Console.ReadLine();
        }
    }
}
