// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    int left = 4;
    int right = 6;
    int len = right-left+1;
    vector <int> op;
    vector<int> vec;
    int count=left;
    vec.insert(vec.begin(),len, 0);
    op.insert(op.begin(),len, 0);

    bool flag = 0;
    int np=0;
    int r=0;
    
    // cout<<sqrt(10);
    for(int i =0; i<vec.size();i++){
        vec[i]=count++;
        for(int j =2;j<=ceil(sqrt(vec[i]));j++){
            if(vec[i]%j==0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            // cout<<vec[i]<<"is not prime"<<endl;
            flag=0;
        }
        else{
            // cout<<vec[i]<<"FOUND"<<endl;
            op[r]=vec[i];
            // cout<<op[r]<<endl;
            np++;
            r++;
        }
    }
    // cout<<np;
    vector<int>nes;
    nes.insert(nes.begin(),2,0);
    int distance=right;
    if(np>1){
        for(int k = 0; k<np-1;k++){
            // cout<<op[k]<<endl;
            if(op[k+1]-op[k]<distance){
                distance=op[k+1]-op[k];
                nes[0]=op[k];
                nes[1]=op[k+1];
            }
        }
    }
    else{
        nes[0]=nes[1]=-1;
    }
    for(int m=0;m<2;m++){
        cout<<nes[m]<<endl;
    }
    return 0;
}
// 1.Iterate through the given range of array, check how many of them are prime numbers
// 2. insert these numbers in seperate array
// 3. Look for base condition if there are less than 2 prime numbers in the range
// 4. now for this new array make a variable count and iterate through it for each consecutive numbers, upadate count variable if new is less than the previous one
