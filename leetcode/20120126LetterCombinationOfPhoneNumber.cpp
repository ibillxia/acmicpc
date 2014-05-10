#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	static char dict[][8] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	static int len[] = {0,0,3,3,3,3,3,4,3,4};
	vector<string>ans;
	vector<string> letterCombinations(string digits) {
		if(!digits.size())return ans;
		gen(&digits[0]);
		return ans;
	}

	void gen(char *d){
		int i,j;
		string str;
		for(i=0;i<strlen(d);i++){
			for(j=0;j<len[d[0]-'0'];j++){
				str+=dict[d[0]-'0'][j];
				gen(d+1);
			}
		}
		ans.push_back(str);
	}
};

int main()
{
	Solution sol;
	char str[] = "234";
	string digits(str);
	vector<string> ans = sol.letterCombinations(digits);
	FOR(i,ans.size()){
		cout<<ans[i]<<endl;
	}
	return 0;
}

