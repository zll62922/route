#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
const int NN = 50004;
using namespace std;
struct Cow {
	int a, b, no;
	bool operator<(const Cow &c) const {
		return a < c.a;
	}
}C[NN];
struct Stall {
	int ed, no;
	bool operator<(const Stall &s) const {
		return ed > s.ed;
	}
};
int Pos[NN];
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
	 int a,b;
	 cin>>a>>b;
	 C[i]={a,b,i};
	}
	
	sort(C, C + n);
	priority_queue<Stall> q;//∂—≈≈–Ú ”≈ªØ∞Ê 
	for (int i = 0; i < n; i++) {
		const Cow &c = C[i];
		if (q.empty() || q.top().ed >= c.a)
	    {
			q.push({c.b, ++cnt}), Pos[c.no] = cnt;
		} 
		else 
		{
			Stall s = q.top();
			q.pop(), q.push({c.b, s.no});
			 Pos[c.no] = s.no;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) cout << Pos[i] << endl;
	cout<<"&&"<<endl;
	while(q.size())
	cout<<q.top().ed<<" "<<q.top().no<<endl,q.pop();
	return 0;
}
