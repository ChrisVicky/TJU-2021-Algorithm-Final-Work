/*
 *                                |~~~~~~~|
 *                                |       |
 *                                |       |
 *                                |       |
 *                                |       |
 *                                |       |
 *     |~.\\\_\~~~~~~~~~~~~~~xx~~~         ~~~~~~~~~~~~~~~~~~~~~/_//;~|
 *     |  \  o \_         ,XXXXX),                         _..-~ o /  |
 *     |    ~~\  ~-.     XXXXX`)))),                 _.--~~   .-~~~   |
 *      ~~~~~~~`\   ~\~~~XXX' _/ ';))     |~~~~~~..-~     _.-~ ~~~~~~~
 *               `\   ~~--`_\~\, ;;;\)__.---.~~~      _.-~
 *                 ~-.       `:;;/;; \          _..-~~
 *                    ~-._      `''        /-~-~
 *                        `\              /  /
 *                          |         ,   | |
 *                           |  '        /  |
 *                            \/;          |
 *                             ;;          |
 *                             `;   .       |
 *                             |~~~-----.....|
 *                            | \             \
 *                           | /\~~--...__    |
 *                           (|  `\       __-\|
 *                           ||    \_   /~    |
 *                           |)     \~-'      |
 *                            |      | \      '
 *                            |      |  \    :
 *                             \     |  |    |
 *                              |    )  (    )
 *                               \  /;  /\  |
 *                               |    |/   |
 *                               |    |   |
 *                                \  .'  ||
 *                                |  |  | |
 *                                (  | |  |
 *                                |   \ \ |
 *                                || o `.)|
 *                                |`\\) |
 *                                |       |
 *                                |       |
 * 
 * @Description    : 
 * @Auther         : Christopher Liu
 * @LastEditors    : Do note edit
 * @Date           : 2021-12-13 10:47:53
 * @LastEditTime   : 2021-12-24 19:52:25
 * Copyright 2021 Christopher Liu, All Rights Reserved. 
 */

#include<bits/stdc++.h>
using namespace std;
#define SIZE_N 30
#define SIZE_C 6404181
int n,W;
int f[SIZE_N][SIZE_C];
struct ITEM{
	int w, v, id;
	double d;
}item[SIZE_N];
bool cmp_d(const ITEM &a, const ITEM &b){ return a.d > b.d; }
clock_t t1,t2;
vector<int>ans;
int tot_w = 0;
void readDataIn(){
	cin>>n>>W;
	for(int i=1;i<=n;i++) scanf("%d" ,&item[i].w);
	for(int i=1;i<=n;i++) scanf("%d" ,&item[i].v);
}
void solutionDp(){
	for(int i=1;i<=n;i++){
		for(int j=item[i].w;j<=W;j++){
            f[i][j] = max(f[i-1][j-item[i].w]+item[i].v, f[i-1][j]);
		}
	}
    int cc = W;
    for(int i=n;i>=1;i--){
        if(f[i][cc]==f[i-1][cc]) continue;
		ans.push_back(i);
		tot_w += item[i].w;
        cc -= item[i].w;
    }
}
void printDataOut(){
	printf("Solution Found: \nTotal Used Capacity: %d\nTotal Value: %d\nChoice of Item:\n",tot_w,f[n][W]);
	for(int i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
    printf("\n");
    printf("Time Usage: %f mini-seconds in tot\n" ,1000*(double) (t2 - t1) / CLOCKS_PER_SEC);
}
int main(){
	readDataIn();
    
	t1 = clock();
	solutionDp();
    t2 = clock();
	
	printDataOut();
	return 0;
}
