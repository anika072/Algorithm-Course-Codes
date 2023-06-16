#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define SIZE 7000
int data[SIZE];

void RandomDataWrite(char *FileName){
    FILE *fp;
    time_t t;
    int i;
    fp = fopen(FileName, "w");
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; i++){
        fprintf(fp, "%d\n", rand()%INT_MAX);
    }
    fclose(fp);
}

void ReadFromFile(char *FileName){
    FILE *fp;
    int i;
    fp = fopen(FileName, "r");
    for(i = 0; i < SIZE; i++){
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
}

void WriteToConsole(){
    for(int i = 0; i < SIZE; i++){
        printf("%10d", data[i]);
    }
}

int TestFunction(){
    int c = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(i > j){
                c++;
            }
        }
    }
    return c;
}
int insertionSort(int data[]){
   int c=0;
   for(int j=1; j<SIZE;j++){
    int key=data[j];
    int i= j-1;
    while(i>=0&&data[i]>key){
        data[i+1]=data[i];
        i--;
    }
    data[i+1]=key;
   }

}
int insertionSortDes(int data[]){
   int c=0;
   for(int j=1; j<SIZE;j++){
    int key=data[j];
    int i= j-1;
    while(i>=0&&data[i]<key){
        data[i+1]=data[i];
        i--;
    }
    data[i+1]=key;
   }

}
void selectionSort(int data[]){
  for (int j=0;j<SIZE-1;j++){
    int key=j;
    for(int i =j+1;i<SIZE;i++){
        if(data[i]<data[key])
            key=i;
    }
    int temp=data[key];
    data[key]=data[j];
    data[j]=temp;
  }

}
void selectionSortDes(int data[]){
  for (int j=0;j<SIZE-1;j++){
    int key=j;
    for(int i =j+1;i<SIZE;i++){
        if(data[i]>data[key])
            key=i;
    }
    int temp=data[key];
    data[key]=data[j];
    data[j]=temp;
  }

}
void bubbleSort(int data[]){
      int i = SIZE;
      for(int i =0;i<SIZE-1;i++){
        for(int j=0;j<SIZE-i-1;j++){
            if(data[j]>data[j+1]){
                int temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
      }

}
void bubbleSortDes(int data[]){
      int i = SIZE;
      for(int i =0;i<SIZE-1;i++){
        for(int j=0;j<SIZE-i-1;j++){
            if(data[j]<data[j+1]){
                int temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
      }

}

int main(){
    clock_t start, end;;
    int i, ans;
    RandomDataWrite("RandomIntegers.txt");
    ReadFromFile("RandomIntegers.txt");
    //WriteToConsole();


    start = clock();
    bubbleSort(data);
    end = clock();

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nBubble Sort took %f seconds toexecute\n\n", time_taken);

    ReadFromFile("RandomIntegers.txt");
    start=clock();
    insertionSort(data);
    end=clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nInsertion Sort took %f seconds toexecute\n\n", time_taken);




    ReadFromFile("RandomIntegers.txt");
    start=clock();
    selectionSort(data);
    end=clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nselection Sort took %f seconds toexecute\n\n", time_taken);


    start = clock();
    bubbleSort(data);
    end = clock();

     time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nBubble Sort took %f seconds to execute after sorting in asc \n\n", time_taken);

    start=clock();
    insertionSort(data);
    end=clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nInsertion Sort took %f seconds to execute after sorting in asc\n\n", time_taken);

    start=clock();
    selectionSort(data);
    end=clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nselection Sort took %f seconds to execute after sorting in asc\n\n", time_taken);


    start = clock();
    bubbleSortDes(data);
    end = clock();

     time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nBubble Sort took %f seconds to execute after sorting in dsc \n\n", time_taken);

    start=clock();
    insertionSortDes(data);
    end=clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nInsertion Sort took %f seconds to execute after sorting in dsc\n\n", time_taken);

    start=clock();
    selectionSortDes(data);
    end=clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nselection Sort took %f seconds to execute after sorting in dsc\n\n", time_taken);





}
