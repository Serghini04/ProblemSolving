using System;

namespace startLearn
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var me = new {id = 20, msg = "hi me"};
            dynamic a = "I'm dynamic a\n";
            Console.WriteLine("The output is : {0}", a.GetType());
            Console.ReadKey();
        }
    }
}
