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

            int[] weights = Console.ReadLine().Split(' ').Select(int.Parse).OrderByDescending(x => x).ToArray();

            int raft = (goatsWeightSum + weights[goats - 1]) / 2;
            int low = weights.Max(), high = weights.Sum();
            Console.WriteLine(high);

            while (low < high)
            {
                int mid = (low + high) / 2;
                Console.WriteLine(mid);
                if (CanTransportAllGoats(weights, mid, courses)) // mid = 40 or 39? in low=mid+1                 
                {
                    high = mid;
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
                    currentWeight = 0;
                    courses++;
                    if (courses > maxCourses)
                        return false;
                    
                }
                currentWeight += weight;

                if (weight == weights.Last() && currentWeight > weight && courses == maxCourses)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
