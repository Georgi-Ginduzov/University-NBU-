namespace Demo
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] goatsAndCourses = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int goats = goatsAndCourses[0];
            int goatsWeightSum = 0;
            int courses = goatsAndCourses[1];

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
            int courses = 1, currentWeight = 0;
            foreach (int weight in weights)
            {
                if (currentWeight + weight > capacity)
                {
                    currentWeight = weight;
                    courses++;
                    if (courses > maxCourses)
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
