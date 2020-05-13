#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <bitset>
#include <climits>
#include <set>
using namespace std;


int fib(int n){


	if(n==0 or n==1){

		return n;
	}

	int fib1=fib(n-1);
	int fib2=fib(n-2);

	return fib1+fib2;
}

int fibMemo(int n,int dp[]){


	if(n==0 or n==1){

		return n;
	}
	if(dp[n] != -1){

		return dp[n];
	}

	int fib1=fibMemo(n-1 , dp);
	int fib2=fibMemo(n-2 , dp);

	dp[n]=fib1+fib2;

	return fib1+fib2;

}

int fibPuredp(int n){

	int dp[n+1];

	dp[0]=0;
	dp[1]=1;

	for(int i=2;i<=n;i++){

		dp[i]=dp[i-1]+dp[i-2];

	}

	return dp[n];
}

int reducetoOne(int n){

	if(n==1 or n<1){

		return 0;
	}

	int count1=INT_MAX , count2=INT_MAX , count3=INT_MAX;

	if(n%2==0){

		count2 = reducetoOne(n/2) +1;
	}
	if(n%3==0){

		count3 = reducetoOne(n/3) +1;
	}

	count1 = reducetoOne(n-1)+1;


	int minCount= min(count1 , min(count2 , count3));

	return minCount;



}

int reducetoOneMemo(int n, int dp[]){


	if(n==1 or n<1){

		dp[n]=0;
		return 0;
	}

	if(dp[n] != -1){

		return dp[n];
	}

	int count1=INT_MAX , count2=INT_MAX , count3=INT_MAX;

	if(n%2==0){

		count2 = reducetoOneMemo(n/2 , dp) +1;
	}
	if(n%3==0){

		count3 = reducetoOneMemo(n/3 , dp) +1;
	}

	count1 = reducetoOneMemo(n-1 , dp)+1;


	int minCount= min(count1 , min(count2 , count3));


	dp[n]=minCount;


	return minCount;

}

int reducetoOnePureDp(int n){

	int dp[n+1];

	memset(dp , -1, sizeof(dp));

	dp[1]=0;
	dp[2]=1;  // we can skip this
	dp[3]=1;	// and this  and can start the loop with 2 it wil work

	for(int i=4;  i<=n ; i++){

		int count1=INT_MAX , count2=INT_MAX , count3=INT_MAX;


		if(i%3==0){

			count3= dp[i/3] + 1;


		}

		if(i%2==0){

			count2 = dp[i/2]+1;
		}

		count1 = dp[i-1]+1;

		dp[i] = min(count1 , min(count2,count3));
	}

	return dp[n];


}

int countBoardPath(int start , int end){

	if(start==end){

		return 1;
	}

	if(start > end){

		return 0;
	}


	int count=0;

	for(int dice=1;dice<=6;dice++){

		count += countBoardPath(start + dice , end);
	}

	return count;
}

int countBoardPathMemo(int start , int end , int dp[]){

	if(start==end){

		dp[start] = 1;
		return 1;
	}

	if(start > end){

		return 0;
	}

	if(dp[start] != -1){

		return dp[start];
	}


	int count=0;

	for(int dice=1;dice<=6;dice++){

		count += countBoardPathMemo(start + dice , end , dp);
	}

	dp[start] = count;

	return count;
}

int countBoardPathPureDP(int start ,int end){

	int dp[end+1];

	dp[end]=1;

	for(int i=end-1;i>=0;i--){

		int count=0;
		for(int dice=1; dice<=6; dice++){

			if(i+dice > end){

				break;
			}

			count += dp[i+dice];
		}

		dp[i]=count;
	}

	return dp[0];
}

int numsqures(int n){

	if(n<=0){

		return 0;
	}
	int minsquares=INT_MAX;

	for(int i=1; i*i <= n; i++){

		int abhitakkaans = numsqures(n-i*i) + 1;
		minsquares = min(minsquares , abhitakkaans);

	}

	return minsquares;




}

int numsquresMemo(int n , int dp[]){  //leet code 279 perfect squres without dp krne p tle ayega

	if(n<=0){

		return 0;
	}

	if(dp[n] != -1){

		return dp[n];
	}

	int minsquares=INT_MAX;

	for(int i=1; i*i <= n; i++){

		int abhitakkaans = numsquresMemo(n-i*i,dp) + 1;
		minsquares = min(minsquares , abhitakkaans);

	}

	dp[n]=minsquares;

	return minsquares;
}

int numsquresPureDP(int n){

	int dp[n+1];

	dp[0]=0;
	dp[1]=1;

	for(int i=2; i<=n; i++){

		int minsquares=INT_MAX;

		for(int j=1; j*j<=i; j++){

			minsquares= min(minsquares , dp[i-j*j]+1);
		}

		dp[i]=minsquares;
	}

	

	return dp[n];
}


int climbStairs(int n) {  //leetcode 70
        
        if(n==0){
            
            return 1;
        }
        if(n<0){
            
            return 0;
        }
        
        int count1=climbStairs(n-1);
        int count2=climbStairs(n-2);
        
        return count1+count2;
        
}

int climbStairsMemo(int n , int dp[]) {
        
        if(n==0){
            
            return 1;
        }
        if(n<0){
            
            return 0;
        }

        if(dp[n] != -1){

        	return dp[n];
        }
        
        int count1=climbStairsMemo(n-1 , dp);
        int count2=climbStairsMemo(n-2 , dp);

        dp[n]= count1+count2;
        
        return count1+count2;
       
}

int climbStairsPureDP(int n){


	int dp[n+1];

	dp[0]=1;
	dp[1]=1;

	for(int i=2;i<=n; i++){

		int count1=dp[i-1];
		int count2=dp[i-2];

		dp[i]=count1+count2;


	} 

	return dp[n];
}


int helperRobber(vector<int> &nums , int i){
        
        if(i>=nums.size()){
            
            return 0;
        }
        
        int yekrtahu = nums[i]+ helperRobber(nums ,i+2);
        int yenikrtahu = helperRobber(nums , i+1);
        
        
        
        return max(yekrtahu , yenikrtahu);
}
    

int helperRobberMemo(vector<int> &nums , int i , int dp[]){
        
        if(i>=nums.size()){
            
            return 0;
        }
        
        if(dp[i] != -1){
            
            return dp[i];
        }
        
        int yekrtahu = nums[i]+ helperRobberMemo(nums ,i+2,dp);
        int yenikrtahu = helperRobberMemo(nums , i+1 ,dp);
        
        dp[i]=max(yekrtahu , yenikrtahu);
        
        return max(yekrtahu , yenikrtahu);
}

int rob(vector<int>& nums) {
        
       // return helperRobber(nums ,0); //normal recursion --- it gives tle on leetcode198
        
        int dp[nums.size()];			// memoization
        memset(dp , -1 , sizeof(dp));
        return helperRobberMemo(nums , 0 , dp);



}

int main(int argc, char const *argv[])
{
	
	// int n=5;
	// cout<<fib(n)<<endl;;  //normal recursion calling


	// int dp[n+1];
	// memset(dp,-1,sizeof(dp));
	// cout<<fibMemo(n,dp)<<endl; // with memoization


	// cout<<fibPuredp(5)<<endl;  //pure dp



	// int n=5;

	// int dp[n+1];

	// memset(dp , -1 , sizeof(dp));

	// cout<<reducetoOne(n)<<endl;

	// cout<<reducetoOneMemo(n,dp)<<endl;

	// cout<<reducetoOnePureDp(n)<<endl;


	// int start=0 , end=10;
	// int dp[end+1];

	// memset(dp , -1 , sizeof(dp));

	// cout<<countBoardPath(start, end)<<endl;
	// cout<<countBoardPathMemo(start , end , dp)<<endl;
	// cout<<countBoardPathPureDP(start ,end)<<endl;




	// int n=12;
	// int dp[n+1];
	// memset(dp , -1, sizeof(dp));

	// cout<<numsqures(n)<<endl;
	// cout<<numsquresMemo(n, dp)<<endl;
	// cout<<numsquresPureDP(n)<<endl;


	// int n=2;
	// int dp[n+1];
	// memset(dp , -1, sizeof(dp));

	// cout<<climbStairs(n)<<endl;
	// cout<<climbStairsMemo(n , dp)<<endl;
	// cout<<climbStairsPureDP(n)<<endl;


	return 0;
}