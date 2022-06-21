#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int judge(vector<int>& nums, int width){
    int count = 0;
    int len = nums.size();
    vector<bool> mark(len, false); //标记积木是否有被使用过
    for(int i = 0; i < len; i++){
        if(mark[i] == true){ // 已经使用
            continue;
        }
        if(i == len - 1 && (nums[i] != width)){//判断最后一块积木是否可以使用
            return -1;
        }
        int sum = nums[i];
        mark[i] = true;
        if(sum == width){//判断当前积木的长度是否都等于每层的长度
            count++;
            continue;
        }
        //判断是否存在两块或者两块以上的积木可以拼接为长度等于每层的长度
        for(int j = i + 1; j < len; j++){
            if(mark[j] == true){
                continue;
            }
            if(j == len - 1 && (nums[j]+sum != width)){
                return -1;
            }
            if(nums[j] + sum > width){
                continue;
            }else if(nums[j] + sum == width){
                mark[j] = true;
                count++;
                break;
            }else{
                sum+=nums[j];
                mark[j] = true;
                continue;
            }
        }
    }
    return count;
}

int main(){
    int temp = 0;
    int sum = 0;
    vector<int> nums;
    while(cin >> temp){
        sum+=temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end(), greater<int>());
    int maxLen = nums[0];
    const int range = sum / 2;
    int res = -1;
    for(int i = maxLen; i <= range; i++){
        if(sum % i == 0){
            res = judge(nums,i);
            if(res != -1){
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}










