#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define endl '\n'

using namespace std;
#define MAX 131073
char res[MAX];

int custo(int L , int R , char ajuda);
int minimo(int L , int R , char ajuda);
void sol();



int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
		sol();
	}
}


int custo(int L , int R , char ajuda)
{
	int count = 0;
	for(int i=L;i<=R;i++)
	if(res[i] != ajuda) count++;
	
	return count;
}

int minimo(int L , int R , char ajuda)
{
	if(L == R)
	{
		if(res[L] == ajuda) return 0;
		else			return 1;
	}
	
	int mid = (L + R) / 2;
	
	return min(custo(L , mid , ajuda) + 
	minimo(mid + 1 , R , ajuda+1) ,
	custo(mid + 1 , R , ajuda) + 
	minimo(L , mid , ajuda+1));
}

void sol(){
    int n;
    cin>>n;
		for (int i = 1; i <= n; i++){
		    
		    cin>>res[i];
		}

		
		cout<<minimo(1 , n , 'a')<<endl;
}







