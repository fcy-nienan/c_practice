//
// Created by 80771 on 2021/7/22.
//
#include <stdlib.h>
#include <time.h>
#include "using_cout.h"

namespace sort_test{
    static const int default_generate_size = 1;
    static const int default_generate_length = 15;
    void init_rand_seed(){
        srand(time(NULL));
    }
    int random(int limit){
        return rand()%limit;
    }
    int** generate_unsorted_array(int size=default_generate_size,int length=default_generate_length,int limit=1000){
        int** result = new int*[size];
        for (int i = 0; i < size; ++i) {
            result[i]=new int[length];
            for (int j = 0; j < length; ++j) {
                result[i][j]= random(limit);
            }
        }
        return result;
    }
    void output_array_one(int *p,int length){
        for (int i = 0; i < length; ++i) {
            cout<<p[i]<<',';
        }
        cout<<endl;
    }
    void output_array(int** p,int size=default_generate_size,int length=default_generate_length){
        for(int i=0;i<default_generate_size;i++){
            output_array_one(p[i],length);
        }
    }

    void swap(int x[],int left,int right){
        if(left==right){
            return;
        }
        x[left]=x[left]+x[right];
        x[right]=x[left]-x[right];
        x[left]=x[left]-x[right];
    }
    void bubble_sort(int *x,int length){
        for(int i=0;i<length;i++){
            for (int j = i+1; j < length; ++j) {
                if (x[j]>x[i]){
                    swap(x,i,j);
                }
            }
        }
    }
    void select_sort(int *x,int length){
        for (int i = 0; i < length-1; ++i) {
            int min_index = i;
            for(int j=i+1;j<length;j++){
                if (x[j]<x[min_index]){
                    min_index=j;
                }
            }
            swap(x,i,min_index);
        }
    }
    void insert_sort(int *x,int length){
        for(int i=1;i<length;i++){
            int wait_insert=x[i];
            int j=i;
            while(j>0 && wait_insert<x[j-1]){
                x[j]=x[j-1];
                j--;
            }
            x[j]=wait_insert;
        }
    }

    void merge_count(int *x,int left,int mid,int right,int *result){

    }
    void merge_sort_recursive(int *x,int left,int right,int *result){
        int mid = (right-left)/2;
        if (mid>0){
            merge_sort_recursive(x,0,mid,result);
            merge_sort_recursive(x,mid+1,right,result);
            merge_count(x,left,mid+1,right,result);
        }
    }
    void merge_sort(int *x,int length){
        int* result=new int[length];
        merge_sort_recursive(x,0,length-1,result);
    }
    void quick_sort(int *x,int length){

    }
    void test(){
        int** result = sort_test::generate_unsorted_array();
        sort_test::output_array(result);
        sort_test::bubble_sort(result[0], sort_test::default_generate_length);
        sort_test::select_sort(result[0],sort_test::default_generate_length);
        sort_test::insert_sort(result[0],sort_test::default_generate_length);
        sort_test::output_array(result);

    }
}