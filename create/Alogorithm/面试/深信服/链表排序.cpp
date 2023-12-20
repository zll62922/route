#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1000010;

typedef long long ll;
typedef pair<int,int>P;
int a[N],n;

struct node {
    int val;
    struct node *next;
};

void bubble(node* h)
{
	node *p=h;
	for(int i=0;i<n-1;i++)
	{
		node *p=h;
		while(p!=NULL)
		{
			node* ne=p->next;
			if(ne==NULL)break;
			if(p->val>ne->val)
			{
				int t=p->val;
				p->val=ne->val;
				ne->val=t;
			}
			p=p->next;	
		}
	}
}

void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	
	node *last=NULL;
	for(int i=n-1;i>=0;i--)
	{
		node* now=(node*)malloc(sizeof(node));
		now->val=a[i];
		now->next=last;
		last=now;
	}
	node *head=last;
	bubble(head);
	node *p=head;
	while(p!=NULL)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
	p=head;
	while(p!=NULL)
	{
		node*ne=p->next;
		free(p);
		p=ne;
	}
}

int main()
{
	io;
	int t=1;
//	cin>>t;
    while(t--)solve();
	return 0;
}

