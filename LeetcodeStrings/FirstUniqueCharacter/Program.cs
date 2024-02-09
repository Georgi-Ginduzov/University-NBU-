namespace FirstUniqueCharacter
{
    internal class Program
    {
        static public int FirstUniqChar(string s)
        {
            for (int i = 0; i < s.Length; i++)
            {
                for (int j = 0; j < s.Length; j++)
                {
                    if (s[i] == s[j])
                    {
                        break;
                    }
                    else
                    {
                        if (j == s.Length - 1)
                        {
                            return i;
                        }
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");

            string input = Console.ReadLine();
            FirstUniqChar(input);
        }
    }
}
