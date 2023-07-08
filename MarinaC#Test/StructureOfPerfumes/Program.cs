struct Perfume
{
    private string brand;
    private double price;
   
    public Perfume(string brand, double price)
    {
        this.brand = brand;
        this.price = price;
    }

    public string Brand
    {
        get
        {
            return brand;
        }
        set 
        { brand = value; }
    }
    public double Price
    {
        get
        {
            return price;
        }
        set 
        { price = value; }
    }
    public Perfume AddPerfume(string brand, double price)
    {
        Perfume newPerfume = new Perfume(brand, price);
        return newPerfume;
    }
    public override string ToString()
    {
        return $"Perfume: Brand - {Brand}, Price - {Price:F2}";
    }

}
class Perfumery
{
    public string Name { get; }
    public List<Perfume> Perfumes { get; }

    public Perfumery(string name)
    {
        Name = name;
        Perfumes = new List<Perfume>();
    }

    public void AddPerfume(Perfume perfume)
    {
        Perfumes.Add(perfume);
    }

    public override string ToString()
    {
        if (Perfumes.Count > 0)
        {
            string perfumesInfo = string.Join(Environment.NewLine, Perfumes);
            return $"Perfumery {Name} has the following perfumes:{Environment.NewLine}{perfumesInfo}";
        }
        else
        {
            return $"Perfumery {Name} has no available perfumes.";
        }
    }
}

class Program
{
    static Dictionary<string, Perfumery> perfumeries = new Dictionary<string, Perfumery>();

    static void CreatePerfumery(string name)
    {
        Perfumery perfumery = new Perfumery(name);
        perfumeries.Add(name, perfumery);
    }

    static void PerfumeryInfo(string name)
    {
        if (perfumeries.ContainsKey(name))
        {
            Perfumery perfumery = perfumeries[name];
            Console.WriteLine(perfumery);
        }
        else
        {
            Console.WriteLine($"Perfumery {name} does not exist.");
        }
    }

    static void Main(string[] args)
    {
        // Example usage
        CreatePerfumery("MyPerfumery");
        Perfume perfume1 = new Perfume("Brand1", 49.99);
        Perfume perfume2 = new Perfume("Brand2", 59.99);
        perfumeries["MyPerfumery"].AddPerfume(perfume1);
        perfumeries["MyPerfumery"].AddPerfume(perfume2);

        PerfumeryInfo("MyPerfumery");
    }
}