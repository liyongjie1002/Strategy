#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <stdio.h>
#include <chrono>

// 抽象策略类
class Strategy
{
public:
	Strategy(){}
	virtual ~Strategy(){}
	virtual void sort(int arr[], int N) = 0;
};

// 具体策略：冒泡排序
class BubbleSort :public Strategy
{
public:
	BubbleSort(){
		printf("冒泡排序\n");
	}
	void sort(int arr[], int N){
        clock_t start, end;
        double cpu_time_used;

        start = clock();  // 开始计时

        
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<N - i - 1; j++)
			{
				if (arr[j]>arr[j + 1]){
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
        
        
        end = clock();  // 结束计时

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  // 计算时间
        printf("程序执行时间为: %lf seconds\n", cpu_time_used);
	}
};

// 具体策略：选择排序
class SelectionSort :public Strategy
{
public:
	SelectionSort(){
		printf("选择排序\n");
	}
	void sort(int arr[], int N){
        clock_t start, end;
        double cpu_time_used;

        start = clock();  // 开始计时
        
        int i, j, k;
        for (i = 0; i<N; i++)
        {
            k = i;
            for (j = i + 1; j<N; j++)
            {
                if (arr[j] < arr[k]){
                    k = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
        
        
        
        end = clock();  // 结束计时

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  // 计算时间
        printf("程序执行时间为: %lf seconds\n", cpu_time_used);
		
	}
};

// 具体策略：插入排序
class InsertSort :public Strategy
{
public:
	InsertSort(){
		printf("插入排序\n");
	}
	void sort(int arr[], int N){
        clock_t start, end;
        double cpu_time_used;

        start = clock();  // 开始计时
        
        int i, j;
        for (i = 1; i<N; i++)
        {
            for (j = i - 1; j >= 0; j--)
            {
                if (arr[i]>arr[j]){
                    break;
                }
            }
            int temp = arr[i];
            for (int k = i - 1; k > j; k--){
                arr[k + 1] = arr[k];
            }
            arr[j + 1] = temp;
        }
        
        end = clock();  // 结束计时

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  // 计算时间
        printf("程序执行时间为: %lf seconds\n", cpu_time_used);
	}
};

#endif
