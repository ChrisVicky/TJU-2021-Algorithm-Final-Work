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
 * @LastEditTime   : 2021-12-24 19:34:41
 * Copyright 2021 Christopher Liu, All Rights Reserved. 
 */

#include<bits/stdc++.h>
using namespace std;
#define SIZE_C 6404181
#define SIZE_N 40
int n,c;
int w[SIZE_N], p[SIZE_N];
int f[SIZE_C];
int main(){
	cin>>n>>c;
	for(int i=0;i<=c;i++) f[i] = 0;
	for(int i=1;i<=n;i++) scanf("%d" ,&w[i]);
	for(int i=1;i<=n;i++) scanf("%d" ,&p[i]);

    clock_t t1 = clock();
	for(int i=1;i<=n;i++){
		for(int j=c;j>=w[i];j--){
            f[j] = max(f[j-w[i]]+p[i], f[j]);
		}
	}
	printf("Solution Found: \nTotal Value: %d\n",f[c]);
    clock_t t2 = clock();
    printf("Time Usage: %f min-seconds in tot\n" ,1000*(double) (t2 - t1) / CLOCKS_PER_SEC);
	return 0;
}
