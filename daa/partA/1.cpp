#include <utilties.h>
class number{
    private:
        int n,m;
        int helper(int num1,int num2)
        {
            if(num2%num1==0)
            return num1;

            return helper(num2%num1,num1);
        }   
    public:
    int hcf;
    number(int n=1,int m=1)
    {
        this->m = min(n,m);
        this->n = max(n,m);
        this->hcf = 1;
    }
    void middle_school()
    {
        int temp1 =m,temp2 = n;

        for(int i =2;i*i<=m or i*i<=n;++i)
        {
            if(isPrime(i))
            {
                while(temp1%i==0 and temp2%i==0)
                {
                    hcf*=i;
                    temp1/=i;
                    temp2/=i;
                }
                while(temp1%i==0)
                {
                    temp1/=i;
                }
                while(temp2%i==0)
                {
                    temp2/=i;
                }
            }
        }
    }

    
    void Euclid()
    {
        hcf = helper(m,n);
    }

    void consecutive_integer_checking()
    {
        FORD(i,m,1){
            if(n%i==0 and m%i==0){
                hcf = i;
                break;
            }
        }
    }

};

void result() {
    int n,m;
    cout<<"ENter the values for the two numbers\t";
    cin>>n>>m;nl
    number *num = new number(n,m);

    int i;
    cout<<"perform one of the following";nl
    cout<<"1.Euclid\n2.Middle School\n3.Consecutive integer\n";
    cin>>i;
    switch (i)
    {
    case 1:
        num->Euclid();
        cout<<"\nHCF = "<<num->hcf;
        break;
    case 2:
        num->middle_school();
        cout<<"\nHCF = "<<num->hcf;
        break;
    case 3:
        num->consecutive_integer_checking();
        cout<<"\nHCF = "<<num->hcf;
        break;

    default:
        cout<<"error";
        break;
    }
}

int main() {
    int tc;
    cin >> tc;
    TC(tc){
        result();
    }
    return 0;
}
