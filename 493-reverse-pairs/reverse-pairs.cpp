class Solution {
public:
    int count = 0;
    void merge(int low, int mid, int high, vector<int>&array, vector<int>&aux){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && array[i] > 2*(long long)array[j]){
                j++;
            }
            count += j-(mid+1);
        }
        int curr = low, first = low, second = mid+1;
        while(first<=mid && second<=high){
            if(array[first]<=array[second]){
                aux[curr++] = array[first++];
            }else{
                aux[curr++] = array[second++];
            }
        }
        while(first<=mid){
            aux[curr++] = array[first++];
        }
        while(second<=high){
            aux[curr++] = array[second++];
        }

        for(int value = low; value<=high; value++){
            array[value] = aux[value];
        }
    }

    void mergeSort(int low, int high, vector<int>&array, vector<int>&aux){
        if(high<=low) return;
        
        int mid = low + (high - low)/2;
        mergeSort(low, mid, array, aux);
        mergeSort(mid+1, high, array, aux);
        merge(low, mid, high, array, aux);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int>aux(n);
        mergeSort(0, n-1, nums, aux);
        return count;
    }
};