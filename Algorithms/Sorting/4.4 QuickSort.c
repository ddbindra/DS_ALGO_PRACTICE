// ####limits.h  The limits.h header determines various properties of the various variable types. 
//These limits specify that a variable cannot store any value beyond these limits,
// EXAMPLE MACROS -> INT_MIN,INT_MAX,LONG_MIN,LONG_MAX,CHAR_MIN,CHAR_MAX,  UINT_MAX, ####

//Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. 
//There are many different versions of quickSort that pick pivot in different ways.

//Is QuickSort stable?
//The default implementation is not stable. However any sorting algorithm can
//be made stable by considering indexes as comparison parameter.

//Worst-case performance	O(n2)
//Best-case performance	    O(n log n) (simple partition) or O(n) (three-way partition and equal keys)
//Average performance	    O(n log n)

#include<limits.h>
#include<stdlib.h>
#include<stdio.h>

void swap(int *p,int *q){
    int tmp = *p; 
    *p = *q; 
    *q = tmp;
}

int Partition(int *a,int l,int h){ 
    int i,j;
    int pivot=a[l];
    i=l;
    j=h;

    do{
        do{
            i++;
        }while(a[i]<=pivot);

         do{
            j--;
        }while(a[j]>pivot);

        if(i<j)
            swap(&a[i],&a[j]);
    }while(i<j);

        swap(&a[l],&a[j]);
    return j;

}

int part(int *a,int l,int h){
   int p,i,j;
   j=l;
   p=a[l];

   for(i=l+1;i<=h;i++){
       if(a[i]<=p){
           j++;
           swap(&a[i],&a[j]);
       }
   }
   //a[l+1,l+2....j] has element <=p ,
   //a[j+1,j+2.....i] has element > p
   swap(&a[l],&a[j]);
   return j;
}

void QuickSort(int *a,int l,int h){
    int j;
    if(l<h){
        j=part(a,l,h);
        QuickSort(a,l,j-1);
        QuickSort(a,j+1,h);
    }
    //TAIL RECURSION - READ ABOUT IT
    /*
     while(l<h){
        j=part(a,l,h);
        if((j-l)<(h-j)){
            QucikSort(a,l,j-1);
            l=j+1;
        }
        else{
            QucikSort(a,j+1,h);
            h=j-1;
        }
    }
            
    */
}

void main(){
    int i,k,n,*a;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    a=(int *)malloc((n+1)*sizeof(int));
    printf("Enter the numbers to be Sorted\n");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    a[i]=INT_MAX;
    QuickSort(a,0,n-1);
    printf("SORTED ARRAY =  ");
    for(i=0;i<n;i++)
    printf("%d ",*(a+i));
    free(a);
}

//Read about INTRO SORT
