using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Indexators
{
    class Time
    {
        public int[] time { get; set; }  

        public Time(int hours, int minutes, int seconds)
        {
            time = new int[3] {hours,minutes,seconds};
        }

        public int Hours
        {
            get { return time[0]; }
            set { time[0] = value; }
        }

        public int Minutes
        {
            get { return time[1]; }
            set { time[1] = value; }
        }

        public int Seconds
        {
            get { return time[2]; }
            set { time[2] = value; }
        }

        public int this[int i]
        {
            get{return time[i];}
            set{time[i] = value;}
        }
    }
}
