#include <iostream>

#include <stdlib.h>     /* srand, rand */

using namespace std;

struct Legitymacje
{
    int l; //   id
    int w; //   punkty
};


int main()
{   
    int n, p, k, c;
    // n - rozmiar tablicy
    // p - dolna granica w
    // k - górna granica w
    // c - opcja
    cin>>n>>p>>k>>c;
    if (n >= 1 && n <= 3000000 )
    {
        if(p >= 0 && p <= k && k <= 1000000)
        {
            {
                Legitymacje Legitymacja[n]; 
                for(int i=0;i<n;i++)
                {
                    Legitymacja[i].l =  rand() % 2000 + 1000;
                    Legitymacja[i].w =  rand() % k + p;
                }

                for(int j=0;j<n;j++)
                {
                    if(c == 0)
                    {
                        cout<<Legitymacja[j].l<<" ";
                    }
                    else if(c == 1)
                    {
                        cout<<Legitymacja[j].w<<" ";
                    }
                }
            }
        }
    }
    return 0;
}
