// See https://aka.ms/new-console-template for more information
string inputString = Console.ReadLine();
string onlyDigits = string.Empty;

for (int i = 0; i < inputString.Length; i++) {
    if (char.IsDigit(inputString[i]))
    {
        onlyDigits += inputString[i];
        inputString = inputString.Remove(i, 1);
        i--;
    }    
}
Console.WriteLine(onlyDigits);

string onlyLetters = string.Empty;

for (int i = 0; i < inputString.Length; i++)
{
    if ((int)inputString[i] > (char)64 && (int)inputString[i] < (char)91 || (int)inputString[i] > (char)96 && (int)inputString[i] < (char)124)
    {
        onlyLetters += inputString[i];
        inputString = inputString.Remove(i, 1);
        i--;
    }
}
Console.WriteLine(onlyLetters);
Console.Write(inputString);