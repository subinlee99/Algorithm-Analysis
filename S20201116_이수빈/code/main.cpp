 //S20201116 이수빈
#include "header.hpp"

//set flag to 0 for big integar array (to deactivate couting sort)
//int countingsort_flag=0;
int countingsort_flag=1; //for small integar array sort
int quicksort_compare=0; //number of comparsion for quicksort

//insertion sort
int insertion_sort(vector<long double>& arr, int size)
{
    int count=0; //number of comparsion
    for(int i=1;i<size;i++){
        int key = arr[i]; int j=i-1; //array sorted until index i-1
        while(j>=0 and key<arr[j]){ //move key until it is sorted
            arr[j+1]=arr[j];
            j--;
            count ++;
        }
        arr[j+1]=key;
    }
    return count;
}

//merge sort
int merge(vector<long double> &arr, int start, int mid, int end)
{
    int count=0; //number of comparsion
    int i = start; int j=mid+1;
    vector<long double> new_arr;
    while(i<mid+1 and j<end+1) {
        count++;
        if(arr[i]<arr[j]+1)new_arr.push_back(arr[i++]);
        else new_arr.push_back(arr[j++]);
    }
    while(i<mid+1)new_arr.push_back(arr[i++]);
    while(j<end+1)new_arr.push_back(arr[j++]);
    copy(new_arr.begin(), new_arr.end(), arr.begin()+start);
    return count;
}

int merge_sort(vector<long double> &arr, int start, int end){
    int count=0;
    if(start<end) {
        int mid=(start+end)/2; //divide array into 2 subarray
        merge_sort(arr, start, mid); //iterative function
        merge_sort(arr, mid+1, end);
        count+=merge(arr, start, mid, end);
    }
 //init: merge_sort(arr, 0, size - 1);
    return count;
}

//quick sort
int partition(vector<long double> &arr, int left, int right){
    int pivot = right;
    int j = left;
    for(int i=left;i<right;++i) {
        if(arr[i]<arr[pivot]) {
            swap(arr[i],arr[j++]); //move element smaller than pivot to the left side
            quicksort_compare++;
        }
    }
    swap(arr[j],arr[pivot]);
    return j;
}
void quick_sort(vector<long double> &arr, int left, int right){
    
    if(left < right){
        int q = partition(arr, left, right);
        quick_sort(arr, left, q-1);
        quick_sort(arr, q+1, right);
    }
    //init : quick_sort(new_arr,0,new_arr.size()-1);

}

//counting sort
int get_max(vector<long double> arr){
    return *max_element(arr.begin(), arr.end());
}
void counting_sort(vector<long double> &arr, int arr_size){
    long double max=get_max(arr); //get maximun number for the bucket
    vector<long double> new_arr(arr_size,0); //initialize new sorted array
    vector<long double> C(max+1,0); //initialize array to save count
    int i=0;
    while(i<arr_size)C[arr[i++]]++; //frequency of each number
    i=2;
    while(i<=max){//Calculate the cumulative of each freqs
        C[i]+=C[i-1];
        i++;
    }
    for(int j=arr_size-1; j>-1; j--){
        int temp = C[arr[j]];
        new_arr[temp]=arr[j];
        C[arr[j]]--;
    }
    arr.clear();
    arr.assign(new_arr.begin(), new_arr.end());
}

 //radix sort
int get_digit(int num, int digit, int base) {
    int N = (num/pow(base,digit));
    N%=base;
    return N; //get the digit of the number according to its base
}

void counting_radix(vector<long double> &arr, int digit, int base){
    int size = (int)arr.size();
    vector<long long> tmp(size,0); //initialize new sorted array
    vector<long long> C(base,0); //initialize array to save count (0~base-1)
    
    int i=0;
    while(i<size) C[get_digit(arr[i++],digit,base)]++; //frequency of each number
 
    for(i=1;i<base;i++) C[i]+=C[i-1]; //Calculate the cumulative of each freqs

    for(i=size-1; i>=0; i--) tmp[--C[get_digit(arr[i],digit,base)]] = arr[i];
 
    arr.clear();
    arr.assign(tmp.begin(), tmp.end());
    tmp.clear(); C.clear();
}

void radix_sort(vector<long double> &arr, int base){
    //base -  ex) binary:2, hexadecimal:16
    int max=get_max(arr);
    int digit_N=0;
    while(max>0){ //get the nuber of digit
        digit_N++;
        max/=base;
    }
    for(int i=0;i<digit_N;i++) counting_radix(arr, i, base);  //for every digit do the counting sort
}

void calculate_time(vector<long double> &temp){
/*
 1) insertion sort, 2) merge sort, 3) quicksort, 4) counting sort, and 5) radix sort
 */
    vector<long double> arr;  int size = (int)temp.size();
    vector<pair<double, string > > rank_time;
    vector<pair<int, string > > rank_count;
    
    for(int i=0; i<5;i++){ //sort for all algorithms
        arr.clear();
        arr.assign(temp.begin(), temp.end());
        int count =0;
        double time1=wall_time();
    
        switch (i) {
            case 0:
                count = insertion_sort(arr, size);
                break;
            case 1:
                count = merge_sort(arr,0,size-1);
                break;
            case 2:
                quick_sort(arr,0,size-1);
                count = quicksort_compare;
                break;
            case 3:
                if(countingsort_flag==1)counting_sort(arr, size);
                break;
            case 4:
                radix_sort(arr, 8);
                break;
        }
        double time2=wall_time();
        double total_time = time2-time1;

        rank_time.push_back(make_pair(total_time, sort_type[i]));
        rank_count.push_back(make_pair(count,sort_type[i]));
        
    }
    //output
    //Q1
    sort(rank_time.begin(), rank_time.end());
    cout << "Ql: Ranking based on runtime (ascending order)" <<"\n\n";
    for(int i=0; i<5;i++){
        cout << i+1 << ": " << rank_time[i].second <<endl;
        cout << "\trun time: " << rank_time[i].first <<endl;
        //cout << "\tnumber of comparsion: " << rank_time[i].second.second << "\n\n";
    }
    cout << "\n***************************************************************\n\n";
    //Q2
    sort(rank_count.begin(), rank_count.end());
    cout << "Q2: Ranking based on number of comparsions (ascending order)" <<"\n\n";
    cout <<"(used counting sort for radix sort -> comparsion =0 )\n";
    for(int i=0; i<5;i++){
        cout << i+1 << ": " << rank_count[i].second<<endl;
        cout << "\tnumber of comparsion: " << rank_count[i].first << "\n";
    }
    //

}
//Q3 change base of the radix sort
void radix_base(vector<long double> &arr){
    int size = sizeof(r);
    vector<pair<double, int> > save_time; //time,r
    cout << "\n***************************************************************\n\n";
    cout << "Q3: Comparing different r"  <<"\n";
    double time1, time2;
    for(int i=0;i<size;i++){
        time1=wall_time();
        radix_sort(arr, r[i]);
        time2=wall_time();
        save_time.push_back(pair<double, int>(time2-time1,r[i]));
    }
    
    cout <<endl;
    sort(save_time.begin(), save_time.end());
    for(int i=0;i<size;i++){
        cout << i+1 << ". r = " << save_time[i].second <<endl;
        cout << "\trun time: " << save_time[i].first <<endl;
    }
}

int main(int argc, char *argv[]){
    //get file name
    if (argc < 2) { //no argument passed -> exit
        cout << "Enter File Name. Exiting...";
        return -1;
    }
    ifstream fp(argv[1]); //open file
    vector<long double> arr; long double data;
    
    if (fp.is_open() && fp.good()) {//if opened, get data
            string line = "";
            while (getline(fp, line) >> data) arr.push_back(data);
    }
    else cout << "Failed to open file..";
    //Q1, Q2
    calculate_time(arr);
    //Q3
    if(countingsort_flag==0) radix_base(arr); //change radix for big integar
    return 0;
}


