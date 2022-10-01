using System;

namespace Palindromes
{
    public static class Palindrome
    {
        /// <summary>
        /// Checks if word is palindrome
        /// </summary>
        /// <param name="word"></param>
        /// <returns></returns>
        public static bool IsPalindrome(string word) {
            return string.Equals(word, Reverse(word), StringComparison.InvariantCultureIgnoreCase);
        }

        /// <summary>
        /// Reverses given string
        /// </summary>
        /// <param name="word"></param>
        /// <returns></returns>
        private static string Reverse(string word)
        {
            var stringArr = word.ToCharArray();
            Array.Reverse(stringArr);
            return stringArr.ToString();
        }
    }
}