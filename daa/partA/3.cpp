#include <utilties.h>

void merge(string& s, int start, int end) {
    /*string left = s.substr(start, mid - start + 1);
    string right = s.substr(mid + 1, end - mid);

    int left_iterator = 0, right_iterator = 0;
    int k = start;

    while (left_iterator < left.length() && right_iterator < right.length()) {
        if (left[left_iterator] <= right[right_iterator]) {
            s[k++] = left[left_iterator++];
        } else {
            s[k++] = right[right_iterator++];
        }
    }

    while (left_iterator < left.length()) {
        s[k++] = left[left_iterator++];
    }

    while (right_iterator < right.length()) {
        s[k++] = right[right_iterator++];
    }*/

   int count0=0;
   FORN(i,start,end)
        if(s[i]=='0')
            count0++;
   FORN(i,start,end){
        if(count0){
            s[i]='0';
            count0--;
        }else
            s[i]='1';
   }

}

void mergesort(string& s, int start, int end) {
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    mergesort(s, start, mid);
    mergesort(s, mid + 1, end);
    merge(s, start, end);
}

void dutchNationalFlag(string&s)
{
    int l0=0,r1=s.length()-1;
    while(l0<r1)
    {
        while(s[l0]=='0' and l0<r1)
        l0++;

        while(s[r1]=='1' and l0<r1)
        r1--;
        if(l0<r1){
            swap(s[l0],s[r1]);
            l0++,r1--;
        }

    }
}

void result() {
    string s;
    cin >> s;
    // mergesort(s, 0, s.length() - 1);
    dutchNationalFlag(s);
    cout << s << endl;
}

int main() {
    int tc;
    cin >> tc;
    TC(tc) {
        result();
    }
    return 0;
}