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
            Console.WriteLine(CanPartitionKSubsets(weights, courses)); // Check how to get each partition's elements




            /*while (low < high)
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
            Console.WriteLine(low);*/
        }

        static bool CanPartitionEqually(int[] nums) 
        {
            int sum = 0;
            for (int i = 0; i < nums.Length; i++) sum += nums[i];
            if (sum % 2 == 1) return false; //if sum is odd we cant split array into two equal halves

            int[] array = new int[(sum / 2) + 1];
            array[0] = 1;
            for (int i = 0; i < nums.Length; i++)
                for (int weight = sum / 2; weight >= 0; weight--)
                {
                    if (weight - nums[i] < 0) break;
                    if (array[weight - nums[i]] == 1) array[weight] = 1;
                }
            if (array[sum / 2] == 1) return true;
            return false;
        }

        static bool CanPartitionKSubsets(int[] nums, int k)
        {
            if (nums.Length == 0 || k == 0)
            {
                return false;
            }

            if (k == 1)
            {
                return true;
            }

            var sum = nums.Sum();

            if (sum % k != 0)
            {
                return false;
            }

            var visited = new bool[nums.Length];

            return Search(nums, k, sum / k, 0, 0, visited);
        }

        static bool Search(int[] nums, int k, int target, int start, int sum, bool[] visited)
        {
            if (k == 1)
            {
                return true;
            }

            if (sum == target)
            {
                return Search(nums, k - 1, target, 0, 0, visited);
            }

            for (var i = start; i < nums.Length; i++)
            {
                var localSum = nums[i] + sum;
                if (localSum > target || visited[i])
                {
                    continue;
                }
                visited[i] = true;
                if (Search(nums, k, target, i, localSum, visited))
                {
                    return true;
                }
                visited[i] = false;
            }

            return false;
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
