using System;
using System.Linq;

namespace Fibonacci
{
    /**
     * Make some Fibonacci
     */
    class Fibonacci
    {
        static void Main(string[] args)
        {
            Console.WriteLine(DoFibonacci(20));
        }

        /**
         * Fibonacci algorithm based on formula: f(x) = f(x-1) + f(x-2) for x >= 3
         *
         * Prints out the result of the fibonacci number for 'x'
         */
        private static int DoFibonacci(int x)
        {
            return (x == 1 || x == 2) ? 1 : DoFibonacci(x - 1) + DoFibonacci(x - 2);
        }
    }
}