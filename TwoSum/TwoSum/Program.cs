namespace TwoSum
{
    internal class Program
    {
        static public int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, int> keyValuePairs = new Dictionary<int, int>();

            for (int i = 0; i < nums.Length; i++)
            {
                if (keyValuePairs.ContainsKey(target - nums[i]))
                {
                    return new int[] { keyValuePairs[target - nums[i]], i };
                }
                else
                {
                    keyValuePairs.TryAdd(nums[i], i);
                }
                
            }

            throw new ArgumentException("No solution");
        }
        static void Main(string[] args)
        {
            int[] input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int target = int.Parse(Console.ReadLine());

            TwoSum(input, target);
        }
    }
}
