#include <iostream>
using namespace std;
int n, q;
long long *p;
int nnum = 0;
struct node{
	long long sum;
	int nr, nl;
	node * lc = NULL;
	node *rc = NULL;
	int flag = 0;
};
node * root;
long long buildtree(node * now, int l, int r){
	now->nr = r; now->nl = l;
	if(r == l) {
		now->sum = p[nnum];
		nnum ++;
		return now->sum;
	}
	int tp = (r + l)/2;
	now-> lc = new node;
	now-> rc = new node;
	int x = buildtree(now->lc, l, tp);
	int y = buildtree(now->rc, tp + 1, r);
	now-> sum = x + y;
	return now-> sum;	
}
int nodenum = 0;
int qury(node * nod, int ql, int qr){
	if(nod->nr < ql || nod->nl >qr) return 0;
	int tp = nod->flag;
	if(tp != 0 ){
		if(nod->lc != NULL) nod->lc->flag += tp;
		if(nod->rc != NULL) nod->rc->flag += tp;
		nod->flag = 0;
		nod->sum += (nod->nr - nod->nl + 1) * tp;
	}
	if(nod->nr <= qr && nod->nl >=ql){
		return nod->sum;
	}
	int x = qury(nod->lc, ql,qr);
	int y = qury(nod->rc, ql, qr);
	return x + y;
}

int adding(node * nod, int ql, int qr, int c){
	if(nod->nr < ql || nod->nl > qr) return 0;
	if(nod -> nr <= qr && nod -> nl >= ql ){
		int tp =  (nod->nr - nod->nl + 1) * c;
		nod->flag += c;
		return tp;
	}
	int tp  = 0;
	tp += adding(nod-> lc, ql, qr, c);
	tp += adding(nod-> rc, ql, qr, c);
	nod->sum += tp;
	return tp;
}
int main(){
	cin >>n>> q;
	p = new long long [n];
	for(int i = 0; i < n; i ++) cin >> p[i];
	root = new node;
	buildtree(root, 1, n);
	char ch;
	int a, b, c;
	for(int i = 0; i < q; i ++) {
		cin >> ch;
		if(ch == 'Q') {
			cin >> a >> b;
			cout <<qury(root, a, b)<< endl;
		}
		if(ch == 'C'){
			cin >> a >> b >> c;
			adding(root, a, b, c);
		}	
	}
}
