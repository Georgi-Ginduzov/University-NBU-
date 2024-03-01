namespace Task1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var map = new Dictionary<int, int>();
            int randomNumber = int.Parse(Console.ReadLine());
            //random number
            for (int i = 0; i < n; i++)
            {
                int k = 0;
                map[i] = k++;
            }

            for (int i = 0; ; i++)
            {
                Console.WriteLine(map[i]);
            }

            
        }
    }
}
