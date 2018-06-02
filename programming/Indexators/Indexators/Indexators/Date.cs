using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Indexators
{
    class Date
    {
        public int[] date;
        public Date(int day, int month, int year)
        {
            date = new int[3] { day, month, year };
        }

        public int Day
        {
            get { return date[0]; }
            set { date[0] = value; }
        }

        public int Month
        {
            get { return date[1]; }
            set { date[1] = value; }
        }

        public int Year
        {
            get { return date[2]; }
            set { date[2] = value; }
        }

        public int this[int i]
        {
            get { return date[i]; }
            set { date[i] = value; }
        }
    }
}
