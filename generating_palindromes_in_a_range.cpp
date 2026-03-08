#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double


int  a,b;

vector<int> primePalindromes;


bool isPrime(int x)
{
	for(int i=2; i*i<=(x); i++)
	{
		if(x%i == 0)
			return 0;
	}
	return 1;
}


// method to generate palindrome of length n
// time - O(10^half-1) * (sqrt(1e5))
void generatePalindromesForLengthN(int length)
{
	// for length 3 half will be 2 so we need to generate between 10 to 100 for left and same for right by popping 1
	// for length 4 half will be 4 so we need to generate between 10 to 100 for left and same for right without popping
	int half = (length+1)/2;
	// start will be 10
	int start = pow(10, half-1);
	// end will be 100
	int end = pow(10, half);

    // 10 to 99
	for(int i=start; i<end; i++)
	{
		string left = to_string(i);
		string right = left;
		
		// pop when length is odd
		if(length % 2 != 0)
			right.pop_back();

        // reverse right and add to make palindrome
		reverse(right.begin(), right.end());

		string full = left+right;
		auto num = stoll(full);
		// check if it is a potential answer
		if(num >= a and num <= b and isPrime(num))
			primePalindromes.push_back(stoll(full));
	}
}

void solve()
{
	cin>>a>>b;
	auto minLength = to_string(a).length();
	auto maxLength = to_string(b).length();

	// for all possible length
	// 9*(O(10^(half-1) * (sqrt(1e5))))
	for(int i=minLength; i<=maxLength; i++)
	{
		generatePalindromesForLengthN(i);
	}
	cout<<primePalindromes.size()<<endl;

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
