#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int judge(vector<int>& vec_yx, int width){
    int count_yx = 0;
    int length_yx = vec_yx.size();
    vector<bool> mark_yx(length_yx, false); //标记积木是否有被使用过
    for(int i = 0; i < length_yx; i++){
        if(mark_yx[i] == true){ // 已经使用
            continue;
        }
        if(i == length_yx - 1 && (vec_yx[i] != width)){//判断最后一块积木是否可以使用
            return -1;
        }
        int sum_yx = vec_yx[i];
        mark_yx[i] = true;
        if(sum_yx == width){//判断当前积木的长度是否都等于每层的长度
            count_yx++;
            continue;
        }
        //判断是否存在两块或者两块以上的积木可以拼接为长度等于每层的长度
        for(int j = i + 1; j < length_yx; j++){
            if(mark_yx[j] == true){
                continue;
            }
            if(j == length_yx - 1 && (vec_yx[j]+sum_yx != width)){
                return -1;
            }
            if(vec_yx[j] + sum_yx > width){
                continue;
            }else if(vec_yx[j] + sum_yx == width){
                mark_yx[j] = true;
                count_yx++;
                break;
            }else{
                sum_yx+=vec_yx[j];
                mark_yx[j] = true;
                continue;
            }
        }
    }
    return count_yx;
}

int main(){
    int temp = 0;
    int sum_yx = 0;
    vector<int> vec_yx;
    while(cin >> temp){
        sum_yx+=temp;
        vec_yx.push_back(temp);
    }
    sort(vec_yx.begin(), vec_yx.end(), greater<int>());
    int maxlength_yx = vec_yx[0];
    const int range = sum_yx / 2;
    int res = -1;
    for(int i = maxlength_yx; i <= range; i++){
        if(sum_yx % i == 0){
            res = judge(vec_yx,i);
            if(res != -1){
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}










