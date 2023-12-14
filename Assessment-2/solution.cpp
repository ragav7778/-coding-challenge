#include <bits/stdc++.h>
using namespace std;
 
//It is the function used to verify the probability of the newly rised spots of the dices
bool ispossible(vector<int>temp,vector<int>temp2,map<int,int>mp){
    map<int,int>mp_check;
     for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            mp_check[temp[i]+temp2[j]]+=1;
            
        }
    }
    
    if(mp==mp_check){
        
        return true;
    }
  return false;
}

//Function to generate all the combinations

void makeCombination(vector<vector<int>>& ans, vector<int>& tmp, const vector<int>& elements, int k)
{
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }

    for (int i = 0; i < elements.size(); ++i) {
        tmp.push_back(elements[i]);
        makeCombination(ans, tmp, elements, k - 1);
        tmp.pop_back();
    }
}

vector<vector<int>> make_Comb(const vector<int>& elements, int k)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    makeCombination(ans, tmp, elements, k);
    return ans;
}

//The function that undoom the dice
void undoom_dice(vector<int>dice1,vector<int>dice2){
     
     bool flag=false;
    //The acceptable repeated elements for diceA because the ocuurence of 12 can be only one such that it is 6+6 before the loki magic and after the occurance of magic the largest element present in the first dice 
    //is 4 and  it can be made as 12 by fixing 4 in the first dice and 8 in the second dice,You may think that 3+9=12 why don't we take that pair and fix 3 in the first dice but the presence of 9 in the second dice with 4 in the first dice can rise to the arise of 13 which lead to the new probability creation so that we are 
    //picking the pair {8,4} and fixing 4 in first dice and 8 in the second dice .So that 4 in the first Dice cannot be repeated more than once.The same scenario is for 1+1=2  where 1 is also fixed in the dice 1 and dice 1 which cannot be repeated
    vector<int> elements1 = { 2, 3 };
    int k = 4;
    map<int,int>mp;
    vector<int>elements2={ 2,3,4,5,6,7};
    //Generating all the Combinations of length 4 with repeated elements of dice1
    vector<vector<int>> ans = make_Comb(elements1, k);
     //Generating all the Combinations of length 4 with repeated elements of dice2
     vector<vector<int>> ans1 = make_Comb(elements2, k);
     
     
     for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            mp[dice1[i]+dice2[j]]+=1;
            
        }
    }
     
    int count=0;
    vector<int>answer1;
    vector<int>answer2;
    
    //Trying all the combinations

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans1.size();j++){
            vector<int>v1=ans[i];
            //Appending the fixed elements for dice 1
            v1.push_back(1);
            v1.push_back(4);
            vector<int>v2=ans1[j];
            //Appending the fixed elements for dice2
            v2.push_back(1);
            v2.push_back(8);
            count++;
             if(ispossible(v1,v2,mp)){
                 flag=true;
                 answer1=v1;
                 answer2=v2;
                 break;
             }
             count++;
        }
        if(flag){
            break;
        }
        count++;
    }
 cout<<"The dice1 spots after loki's magic"<<"\n";
for(int e1:answer1){
    cout<<e1<<",";
}
cout<<"\n";
cout<<"The dice2 spots after loki's magic"<<"\n";
for(int e2:answer2){
    cout<<e2<<",";
}
cout<<endl;


}

int main()
{
    //Given Norrmal Dice Inputs
    vector<int>dice1={1,2,3,4,5,6};
      vector<int>dice2={1,2,3,4,5,6};
      undoom_dice(dice1,dice2);
     
    
    return 0;
}