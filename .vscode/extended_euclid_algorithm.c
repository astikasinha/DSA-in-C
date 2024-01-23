#include<stdio.h>
struct triplet{
    int x,y,gcd;
};
typedef struct triplet triplet;
triplet extendedeuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.gcd=a;
        ans.y=0;
        return ans;
    }
    triplet reduced=extendedeuclid(b,a%b);
    triplet fans;
    fans.gcd=reduced.gcd;
    fans.x=reduced.y;
    fans.y=reduced.x-(a/b)*reduced.y;
    return fans;
}
int multiplicativemoduloinverse(int a,int m){
    triplet ans=extendedeuclid(a,m);
    return ans.x;
}

void main(){
    triplet ans;
    ans=extendedeuclid(4,8);
    printf("%d " "%d " " %d",ans.gcd,ans.x,ans.y);


}