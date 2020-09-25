#include<stdio.h>
#include<stdlib.h>

void print_matrix(float *matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%.2f\t", *(matrix+i*n+j));
        }
        printf("\n");
    }
    printf("\n\n");
}

void gauss_jordan(float *matrix,float *result, int n){
    float aux, value;
    for(int i=0; i<n; i++){
        if (*(matrix+i*n+i)==0){
            for(int j=i+1;j<=n+1;j++){
                if (*(matrix+j*n+i)!=0){
                    aux = *(matrix+i*n+(j-1));
                    *(matrix+i*n+(j-1)) = *(matrix+(i+1)*n+(j-1));
                    *(matrix+(i+1)*n+(j-1)) = aux;
                    aux=result[i];
                    result[i]=result[i+1];
                    result[i+1]=aux;
                }
            }
        }
        value=*(matrix+i*n+i);
        for(int j=0;j<n;j++){
            *(matrix+i*n+j) /= value;
        }
        result[i]=result[i]/value;
        for(int j=i+1;j<n;j++){
            value = *(matrix+j*n+i);
            for(int k=0;k<n;k++){
                *(matrix+j*n+k)=*(matrix+j*n+k) - value * *(matrix+i*n+k);
            }
            result[j]=result[j]-value*result[i];
        }
    }

    for(int i=n;i>=1;i--){
        for(int j=i-1;j>=0;j--){
            value = *(matrix+j*n+i);
            *(matrix+j*n+i) = *(matrix+j*n+i) - value * *(matrix+i*n+i);
            result[j]=result[j]-value*result[i];
        }
    }
}

int main(){
    float matrix[] = {1,1,1,2,3,5,1,-5,6};
    float result[] = {2,11,29};
    int n = 3;
    char variables[] = {'X', 'Y', 'Z'};

    printf("Matriz Inicial\n\n");
    print_matrix(matrix, n, n);

    gauss_jordan(matrix, result, n);
    printf("Matriz Final\n\n");
    print_matrix(matrix,n,n);

    printf("Resultados\n\n");
    for(int i=0;i<n;i++){
        printf("%c = %.2f\t", variables[i],result[i]);
    }
    printf("\n\n");
    return 0;
}
