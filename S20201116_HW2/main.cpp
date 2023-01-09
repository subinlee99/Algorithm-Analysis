/*
 S20201116 이수빈 homework 2

 */

#include <iostream>
#include <fstream> //open file
#include <vector>
using namespace::std;

int get_min(int a, int b){ //get min num
    return (a<b) ? a:b;
}

int get_max(int a, int b){ //get max num
    return (a>b) ? a:b;
}

int LCS(vector<char> arr1, vector<char> arr2)
{
    int m = arr1.size(), n = arr2.size();
    int MAX= get_max(m, n);
    int MIN = get_min(m, n);

    if(MAX != m) arr1.swap(arr2); //set arr1 as longer sequence

    vector<int> c(MIN+1,0); //space complexity:O(min{len1,len2})
    int curr, tmp;
    
    for (int i=0; i<=MAX; i++)
    {
        curr = 0;
        for (int j=0; j<=MIN; tmp=c[++j])
        {
            if (i==0 or j==0) c[j] = 0;
            else if (arr1[i-1]==arr2[j-1]) c[j]=curr+1;//if letter match lcs+1
            else c[j] = get_max(c[j-1], c[j]); 
            curr = tmp;
        }
    }
    return c.back();
}

int main(int argc, const char * argv[]) {
    
    if (argc < 2) { //no argument passed -> exit
        cout << "Enter File Name. Exiting...";
        return -1;
    }
    ifstream fp(argv[1]); //open file
    
    string num[2]; //save input
    string line = " ";
    
    if (fp.is_open() && fp.good()) for(int i=0;i<2;i++) fp >> num[i];
    else cout << "Failed to open file..";
    
    vector<char> arr1, arr2; //get each digit in vecotr
 
    for(int i=0;i<num[0].size();i++) arr1.push_back(num[0][i]);
    for(int i=0;i<num[1].size();i++) arr2.push_back(num[1][i]);
    
    cout << "Length of LCS: " << LCS(arr1, arr2)<<endl;
    
    return 0;
}

