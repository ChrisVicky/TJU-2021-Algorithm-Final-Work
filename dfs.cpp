/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑       永不宕机     永无BUG
 * 
 *        佛曰:  
 *                写字楼里写字间，写字间里程序员；  
 *                程序人员写程序，又拿程序换酒钱。  
 *                酒醒只在网上坐，酒醉还来网下眠；  
 *                酒醉酒醒日复日，网上网下年复年。  
 *                但愿老死电脑间，不愿鞠躬老板前；  
 *                奔驰宝马贵者趣，公交自行程序员。  
 *                别人笑我忒疯癫，我笑自己命太贱；  
 *                不见满街漂亮妹，哪个归得程序员？
 * 
 * @Description    : 
 * @Auther         : Christopher Liu
 * @LastEditors    : Do note edit
 * @Date           : 2021-12-06 16:32:52
 * @LastEditTime   : 2021-12-25 18:58:14
 * Copyright 2021 Christopher Liu, All Rights Reserved. 
 */

#include<bits/stdc++.h>
using namespace std;
#define SIZE_N 30
#define SIZE_C 6900000
int n,W,bound;
clock_t t1, t2;
int dfs_cnt;
struct ITEM{
	int w, v, id;
	double d;
}item[SIZE_N];
bool cmp_d(const ITEM &a, const ITEM &b){ return a.d < b.d; }
struct STATUS{
	bitset<40>s;
	int tot_value, tot_weight;
	void Init(){
		s.reset();
		tot_value=0, tot_weight = 0;
	}
	void PutIn(int now){
		s.set(now, true);
		tot_value += item[now].v;
		tot_weight += item[now].w;
	}
	void PutOut(int now){
		s.set(now, false);
		tot_value -= item[now].v;
		tot_weight -= item[now].w;
	}
};
STATUS ans;
void dfs(int now, STATUS temp){
	dfs_cnt ++;
	/* Reach to the end */
	if(now == n+1){
		if(ans.tot_value < temp.tot_value || (ans.tot_value == temp.tot_value && ans.tot_weight > temp.tot_value)){
			ans = temp;
		}
		return ;
	}
	/* Choose now_th item */
	if(temp.tot_weight + item[now].w <= W){
		temp.PutIn(now);
		dfs(now + 1, temp);
		temp.PutOut(now);
	}
	/* Don't choose now_th item */
	dfs(now+1, temp);
}
void readDataIn(){
	cin>>n>>W;
	for(int i=1;i<=n;i++) scanf("%d" ,&item[i].w);
	for(int i=1;i<=n;i++) scanf("%d" ,&item[i].v);
}
void solutionDfs(){
	STATUS init;
	init.Init();
	dfs(1, init);
}
void printDataOut(){
	printf("Solution Found: \nTotal Used Capacity: %d\nTotal Value: %d\nChoice of Item:\n",ans.tot_weight, ans.tot_value);
	for(int i=0;i<=n;i++){
		if(ans.s.test(i)) cout<<i<<" ";
	}
	cout<<endl;
	printf("Time Usage: %f min-seconds in tot\n" ,1000*(double) (t2 - t1) / CLOCKS_PER_SEC);
	printf("dfs_while: %d\n" ,dfs_cnt);
	printf("Should: %lld\n" ,(1LL<<(long long)(n+1))-1LL);
}
int main(){
	readDataIn();
	
    t1 = clock();
	solutionDfs();
    t2 = clock();
	
	printDataOut();
	return 0;
}
