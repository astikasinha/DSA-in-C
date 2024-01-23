// /*******sine series*********/
// #include<stdio.h>
// void main(){
//     int sign=1,f=1,i,n;
//     float x,sum,num;
//     printf("enter the value of x and enter the number of terms");
//     scanf("%f%d",&x,&n);
//     x=x*(3.14/180);
//     sum=x;
//     num=x;
//     for(i=1;i<=n-1;i++){
//         f=f*(2*i)*(2*i+1);
//         num=num*x*x;
//         sign=sign*(-1);
//         sum=sum+(num/f)*sign;
//     }
//     printf("%f",sum);

    
// }



// /******cosine series*******/
// #include<stdio.h>
// void main(){
//     int sign=1,f=1,i,n;
//     float x,sum,num;
//     printf("enter the value of x and enter the number of terms");
//     scanf("%f%d",&x,&n);
//     x=x*(3.14/180);
//     sum=1;
//     num=1;
//     for(i=1;i<=n-1;i++){
//         f=f*(2*i-1)*(2*i);
//         num=num*x*x;
//         sign=sign*(-1);
//         sum=sum+(num/f)*sign;
//     }
//     printf("%f",sum);

    
// }




// /*****merging of two sorted array********/
// #include<stdio.h>
// void traverse(int a[],int n)
// {
//     int i;
//     for(i=0;i<n;i++)
//         printf("%d ",a[i]);

// }
// void merge(int a[],int n,int b[],int m)
// {
//     int i=0,j=0,k=0,c[13];
//     while(i<n&&j<m)
//     {
//         if(a[i]<b[j])
//         c[k++]=a[i++];
//         else
//             c[k++]=b[j++];

//     }
//     while(i<n)
//      {

//       c[k++]=a[i++];
//      }

//     while(j<m)
//     {
//         c[k++]=b[j++];
//     }
//         printf("Mergedarray is =>  ");
//         traverse(c,k);


// }

// int main()
// {

//     int a[]={2,4,6,8,10,12};
//     int b[]={1,3,4,5,6,7,8};
//     int n=6;
//     int m=7;
//     traverse(a,n);
//     traverse(b,m);
//     merge(a,n,b,m);



// }





void traverse(int a[],int k){
    int i;
    for(i=0;i<k;i++){
        printf("%d",a[i]);
    }
}
void unionofarray(int a[],int m,int b[],int n){
    int i=0,j=0,k=0,c[m+n];
    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            if(b[j]<a[i]){
                c[k]=b[j];
                j++;
                k++;
            }
            else{
                c[k]=a[i];
                i++;
                j++;
                k++;
            }
        }
    }
    while(i<m){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m){
        c[k]=b[j];
        k++;
        j++;
    }
    printf("union of array is \n");
    traverse(c,k);
}

void intersectionofarray(int a[],int m,int b[],int n){
    int i=0,j=0,k=0,c[m+n];
    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
        }
        else{
            if(b[j]<a[i]){
                c[k]=b[j];
                j++;
            }
            else{
                c[k]=a[i];
                i++;
                j++;
                k++;
            }
        }
    }
    while(i<m){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m){
        c[k]=b[j];
        k++;
        j++;
    }
    printf("intersection of array is \n");
    traverse(c,k);
}

void differenceofarray(int a[],int m,int b[],int n){
    int i=0,j=0,k=0,c[m+n];
    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            if(b[j]<a[i]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
    }
    while(i<m){
        c[k]=a[i];
        i++;
        k++;
    }
    printf("difference of array A-B is \n");
    traverse(c,k);
}

void difference_ofarray(int a[],int m,int b[],int n){
    int i=0,j=0,k=0,c[m+n];
    while(i<m && j<n){
        if(a[i]<b[j]){
            i++;
        }
        else{
            if(b[j]<a[i]){
                c[k]=b[j];
                j++;
                k++;
            }
            else{
                i++;
                j++;
            }
        }
    }
    while(j<n){
        c[k]=b[j];
        j++;
        k++;
    }
    printf("difference of array B-A is \n");
    traverse(c,k);
}

void symmetricdifference(int a[],int m,int b[],int n){
    int i=0,j=0,k=0,c[m+n];
    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            if(b[j]<a[i]){
                c[k]=b[j];
                j++;
                k++;
            }
            else{
                i++;
                j++;
            }
        }
    }
    while(i<m){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m){
        c[k]=b[j];
        k++;
        j++;
    }
    printf("symmetric difference of array is \n");
    traverse(c,k);
}


{
    int a[]={1,2,4,5,8,6};
    int b[]={3,6,7,8,6};
    int m=6;
    int n=5;
    traverse(a,m);
    traverse(b,n);
    unionofarray(a,m,b,n);
    intersectionofarray(a,m,b,n);
    differenceofarray(a,m,b,n);
    difference_ofarray(a,m,b,n);
    symmetricdifference(a,m,b,n);
}



//problem solving day2 ques 7
#include<stdio.h>
void main(){
    int sign=1,i,n;
    float f=1,s=1;
    printf("enter the number of terms");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++){
        f=f*(2*i)*(2*i+1);
        sign=sign*(-1);
        s=s+1/f*sign;
    }
    printf("%f",s);

}

