#include <bits/stdc++.h>
using namespace std;


template <typename T> 
class myVector {
    T* array;
    int max_size;
    int current_size;

public:
    myVector() : max_size(10), current_size(0) 
    {
        array = new T[max_size];
    }
    ~myVector() {
        delete[] array;
    }

    T* begin() const {
        return array;
    }

    T* end() const {
        return array + current_size;
    }

    void push_back(T data) {
        if(current_size == max_size)
        {
            T* temp = new T[2 * max_size];

            for(int i=0;i<current_size;i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            max_size *= 2;
            array = temp;
        }

        array[current_size] = data;
        current_size++;
    }


    int size()
    {
        return current_size;
    }

    int capacity()
    {
        return max_size;
    }

    void print()
    {
        for(int i=0;i<current_size;i++)
        {
            cout<<array[i]<<" ";
        }
    }

    void reverse_print()
    {
        for(int i=current_size-1;i>=0;i--)
        {
            cout<<array[i]<<" ";
        }
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    
    myVector<unsigned int> v;
    int n;
    
    do
    {
        cin>>n;
        if(n!=0)
            v.push_back(n);
    } while(n!=0);

    // v.print();
    // cout<<"\n";
    // v.reverse_print();
    // cout<<"\n"<<v.size()<<" / "<<v.capacity();

    for(const auto& value: v)
    {
        cout<<value<<" ";
    }

    return 0;
}