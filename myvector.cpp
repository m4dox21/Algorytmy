#include <iostream>
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

    void push_back(T value) {
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

        array[current_size] = value;
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

    T* begin(){
        return array;    
    }
    
    T* end(){
        return array + current_size;
    }
    
    T& operator[](T index)
    {
        if(index >= current_size)
        {
            throw("Index poza tablica");
        }
        return array[index];
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
    unsigned int n;

    do
    {
        cin>>n;
        if(n>0)
            v.push_back(n);
    } while(n!=0);
    
    v.reverse_print();
    
    // for(auto i = v.end()-1; i > v.begin()-1; i--)
    // {
    //     cout<<*i<<" ";
    // }
    
    // cout<<v[1];
    // cout<<"\n"<<v.size()<<" / "<<v.capacity();
    
    return 0;
}
