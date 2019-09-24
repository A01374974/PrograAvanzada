#include <stdio.h>
int countOnes(int n){
    int ones=0;
    while(n!=0){
        n &= (n -1);
        ones ++;
    }
    return ones;
}
int compareBits(int a,int b){
    int aBits = countOnes(a),bBits=countOnes(b);
    if(aBits<bBits){
        return -1;
    }else if(aBits>bBits){
        return 1;
    }else{
        return 0;
    }
}
void main(){
    int a,b;
    scanf("%d\n%d",&a,&b);
    printf("%d",compareBits(a,b));
}