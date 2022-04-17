/*
Date: 4-17-2022
Author: nanorex / nanorex07
*/

#include <bits/stdc++.h>
using namespace std;


class RadixSort {
private:
	vector<vector<int>> buckets;
	void reset_buckets(){
		buckets.clear();
		for(int i = 0; i < 10; i++)
			buckets.push_back({});
	}
	int get_max_length(vector<int> &arr){
		int m = *max_element(arr.begin(),arr.end());
		int k = ceil(log10(m));
		return k;
	}
	void flatten(vector<int> &arr){
		int cnt = 0;
		for(auto bucket: buckets)
			for(auto item: bucket)
				arr[cnt++] = item;
	}
public:
	void radix_sort(vector<int> &arr){
		reset_buckets();
		int len = get_max_length(arr);
		for(int i = 0; i < len; i++){
			for(int k: arr){
				int n = (k/pow(10,i));
				n %= 10;
				buckets[n].push_back(k);
			}
			flatten(arr);
			reset_buckets();
		}
	}
};


int main(){

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	RadixSort* sorter = new RadixSort();

    clock_t t1,t2;
    t1=clock();

	sorter->radix_sort(a);

    t2=clock();
    float diff = ((float)t2-(float)t1)/CLOCKS_PER_SEC;

    cout<< "Radix Sort: " <<diff << "s" <<endl;

}