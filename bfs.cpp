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
 * @LastEditTime   : 2021-12-24 19:20:53
 * Copyright 2021 Christopher Liu, All Rights Reserved. 
 */

#include<bits/stdc++.h>
using namespace std;
#define SIZE_N 30
#define SIZE_C 6900000
int n,W,cnt;
clock_t t1, t2;
struct ITEM{
	int w, v, id;
	double d;
}item[SIZE_N];
bool cmp_d(const ITEM &a, const ITEM &b){ return a.d < b.d; }
struct STATUS{
	bitset<40>s;
	int tot_value, tot_weight, now;
	void Init(){
		s.reset();
		tot_value=0, tot_weight = 0, now = 0;
	}
	void PutIn(int now){
		s.set(item[now].id, true);
		tot_value += item[now].v;
		tot_weight += item[now].w;
	}
    STATUS(bitset<40>_s, int tot_v, int tot_w, int _now):s(_s), tot_value(tot_v), tot_weight(tot_w), now(_now){}
    STATUS(){}
};
STATUS ans;
queue<STATUS>Q;
void bfs(){
    bitset<40>s0;
    s0.reset();
    Q.push(STATUS(s0, 0, 0, 0));
    while(!Q.empty()){
        STATUS temp = Q.front();
        Q.pop();
        cnt++;
        temp.now++;
        // printf("%d %d %d \n" ,temp.now, temp.tot_value,temp.tot_weight);
        if(temp.now==n+1){
            if(temp.tot_value >= ans.tot_value){
                ans = temp;
            }
            continue;
        }
        Q.push(temp);
        if(temp.tot_weight + item[temp.now].w>W) continue;
        STATUS have_temp = temp;
        have_temp.PutIn(have_temp.now);
        Q.push(have_temp);
    }
}
void readDataIn(){
	cin>>n>>W;
	for(int i=1;i<=n;i++) scanf("%d" ,&item[i].w);
	for(int i=1;i<=n;i++) scanf("%d" ,&item[i].v);
	for(int i=1;i<=n;i++) item[i].d = (double)item[i].v / (double)item[i].w, item[i].id = i;
	sort(item+1, item+n+1, cmp_d);
}
void solutionBfs(){
    bfs();

}
void printDataOut(){
    printf("Solution Found: \nTotal Used Capacity: %d\nTotal Value: %d\nChoice of Item:\n",ans.tot_weight, ans.tot_value);
	for(int i=0;i<=n;i++){
		if(ans.s.test(i)) printf("%d ",i);
	}
    printf("\n");
    printf("Time Usage: %f mini-seconds in tot\n" ,1000*(double) (t2 - t1) / CLOCKS_PER_SEC);
	printf("tot_while: %d\n",cnt);
}
int main(){
	readDataIn();
    
    t1 = clock();
    solutionBfs();
    t2 = clock();
	
    printDataOut();
    return 0;
}
