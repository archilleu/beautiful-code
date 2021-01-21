#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

int x[] = {6,1,11,10,12,90,5,8,9,4,7};
void swap(int left, int right)
{
    int tmp = x[left];
    x[left] = x[right];
    x[right] = tmp;
}

void quitsort(int l, int u)
{
    // 遍历到头了
    if(l > u)
        return;

    // 比较变量，选取第一个（那个都无所谓，参照而已)
    int m = l;
    for(int i=l+1; i<u; i++)
    {
        if(x[i] < x[l])
            swap(++m, i);
    }
    swap(l, m);

    quitsort(l, m-1);
    quitsort(m+1, u);

}

void checksort(int a[], int l, int u)
{
    for(int i=l+1; i<u; i++)
    {
        assert(a[i-1] <= a[i]);
    }
    return;
}

// 重复元素升级
void quicksort(int* a, int l, int u)
{
    if(l >= u)  return;

    int i = l;
    int j = u;

    {
    //防止顺序的序列影响排序性能，退化成冒泡
    int random = rand()%(u-l) + l;
    std::swap(a[l], a[random]);
    }

    int pivot = a[l];

    while(i < j)
    {
        /*
            要从j遍历开始，因为们先从在边开始时，那么i所停留的那个位置肯定是大于pivot的
            j为了满足 i<j, 于是j也停留在上面i的位置
        */
        while((i<j) && (pivot<=a[j])){j--;}
        while((i<j) && (pivot>=a[i])){i++;}
        std::swap(a[i], a[j]);
    }
    std::swap(a[l], a[i]);

    quicksort(a, l, j-1);
    quicksort(a, j+1, u);
}

// 分析
int comps = 0;
void quitsort_analyze(int l, int u)
{
    if(l > u)
        return;

    int m = l;
    comps += u - 1;
    for(int i=l+1; i<u; i++)
    {
        if(x[i] < x[l])
            swap(++m, i);
    }
    swap(l, m);

    quitsort_analyze(l, m-1);
    quitsort_analyze(m+1, u);

}

int* random(int length)
{
    int count = length;
    int* a = new int[length];
    while(count--)
    {
        a[count] = rand()%length;
    }
    return a;
}

void print(int* a, int l, int u)
{
    for(int i=l; i<u; i++)
    {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}

int main(int, char**)
{
    for(int i=0; i<1000; i++)
    {
        int len = 100;
        int* a = random(len);
        quicksort(a, 0, len-1);
        checksort(a, 0, len-1);
        print(a, 0, len-1);
        free(a);
    }

}
