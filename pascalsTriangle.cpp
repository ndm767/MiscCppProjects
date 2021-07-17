//generates Pascal's Triangle up to a certain number of rows

#include <iostream>
#include <string>
#include <vector>

typedef unsigned long long ull;

ull factorial(ull n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

ull nChoosek(ull n, ull k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main(int argc, char *argv[])
{
    int limit = 5;
    if (argc > 1)
    {
        limit = std::stoi(std::string(argv[1]));
    }

    std::vector<std::string> rows;
    std::string maxnck = std::to_string(nChoosek(limit - 1, (limit - 1) / 2));
    int maxlen = maxnck.length();

    for (int n = 0; n < limit; n++)
    {
        std::string r = "";
        for (int k = 0; k <= n; k++)
        {
            std::string nck = std::to_string(nChoosek(n, k));
            int diff = maxlen - nck.length();
            if (diff > 0)
            {
                for (int i = 0; i < diff; i++)
                {
                    nck = i % 2 != 0 ? " " + nck : nck + " ";
                }
            }

            r += nck + " ";
        }
        rows.push_back(r);
    }

    int lastLen = rows.at(rows.size() - 1).length();

    for (auto s : rows)
    {
        int diff = lastLen - s.length();
        for (int i = 0; i < diff / 2; i++)
        {
            s = " " + s + " ";
        }
        std::cout << s << "\n";
    }
    std::cout << std::flush;

    return 0;
}