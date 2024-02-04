using System.Reflection.Metadata.Ecma335;

namespace Demo
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] goatsAndCourses = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int goats = goatsAndCourses[0];
            int courses = goatsAndCourses[1];
            int goatsWeightSum = 0;// 30 10 5 7 4 15 

            int[] weights = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            for (int i = 0; i < goats; i++)
            {
                goatsWeightSum += weights[i];
            }

            int raft = (goatsWeightSum + weights[goats - 1]) / 2;
            int low = weights.Max(), high = goatsWeightSum;

            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (CanTransportAllGoats(weights, mid, courses))
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            Console.WriteLine(low);
        }
        static bool CanTransportAllGoats(int[] weights, int capacity, int maxCourses)
        {
            int courses = 0, currentWeight = 0;
            foreach (int weight in weights)
            {
                if (currentWeight + weight > capacity)
                {
                    currentWeight = weight;
                    courses++;
                    if (courses > maxCourses)// when I courses = maxcourses it continuous but when there are more sheeps left it continuous
                        return false;
                    if (courses == maxCourses && currentWeight == weights.Last())
                        return false;
                    
                }
                else
                {
                    currentWeight += weight;
                }
            }
            return true;
        }
    }
}
