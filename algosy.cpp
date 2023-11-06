#include <iostream>
using namespace std;

int main()
{
    
    // 1<=n<=3000000
    // 0<=p<=k<=1000000 
    
    int size, value, option;
    // int points_min, points_max;
    cout<<"Podaj rozmiar";
    cin>>size;
    cout<<"Podaj opcje";
    cin>>option;
    int tab[size][2];

    for(int j=0;j<size;j++)
    {
        cin>>value;
        tab[j][0] = value;
        cin>>value;
        tab[j][1] = value;
    }


    if(option == 0)
        for(int k=0;k<size;k++)
        {
            cout<<tab[k][0]<<endl;
        }
    else if(option == 1)
        for(int k=0;k<size;k++)
        {
            cout<<tab[k][1]<<" ";
        }






        // for(int k=0;k<size;k++)
        // {
        //     cout<<tab[k][0]<<" "<<tab[k][1]<<endl;
        // }








    
    return 0;
}