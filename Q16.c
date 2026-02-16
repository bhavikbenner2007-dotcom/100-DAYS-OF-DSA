#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    if(scanf("%d",&n)!=1) return 0;
    int *a = malloc(n * sizeof(int));
    int *vis = calloc(n, sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        int cnt=1;
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i]){
                cnt++;
                vis[j]=1;
            }
        }
        printf("%d %d\n", a[i], cnt);
    }
    free(a);
    free(vis);
    return 0;
}