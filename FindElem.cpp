#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n1, n2;
    cin>>n1;

    int array1[n1];
    if(n1 >= 0 && n1 <= 2000000)
        for(int i=0;i<n1;i++)
            cin>>array1[i];
    
    cin>>n2;
    int array2[n2];
    if(n2 >= 0 && n2<= 2000000)
        for(int i=0;i<n2;i++)
            cin>>array2[i];

    char exists;
    for(int i=0;i<n2;i++)
    {
        exists = 'N';
        for(int j=0;j<n1;j++)
        {
            if(array2[i] == array1[j])
            {
                exists = 'T';
                break;
            }
        }
        cout<<exists<<" ";
    }

    return 0;
}
