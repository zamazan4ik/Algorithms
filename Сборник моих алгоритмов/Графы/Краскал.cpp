//Минимальное остовное дерево за O(NlogN) методом Краскала через DSU(систему непересекающихся множеств)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll maxn=100,maxm=200;//максимум вершин и максимум рёбер
vector<ll> d(maxn,-1);//массив для DSU
vector<pair<ll,pair<ll,ll> > > a(maxm),p;//тут будем хранить рёбра.Первый элемент - вес ребра, 2-ой и 3-ий - начало и конец ребра
ll i,j,k,z=0,temp,r,n,m;

//функция для получения корня данного множества.Подробное описание в описании самого DSU

ll findroot(ll v)
{
    return d[v]==-1 ? v : d[v]=findroot(d[v]);
}

//функция обьединения двух множеств.Подробное описание в описании самого DSU

bool union_set(ll a,ll b)
{
    ll q1,q2;
    q1=findroot(a);
    q2=findroot(b);
    if(q1 != q2)
    {
        r=rand() % 2;
        r==0 ? d[q1]=q2 : d[q2]=q1;
        return true;
    }
    return false;
}

//Задаем граф по кторому будем искать минимальный остов

void input()
{
    scanf("%I64d %I64d",&n,&m);
    for(i=0;i<m;++i)
    {
        scanf("%I64d %I64d %I64d",&a[i].second.first,&a[i].second.second,&a[i].first);
    }
}

//Главная функция алгоритма.Работает следующим образом: мы сортируем в порядке возрастания ребра по весу.Потом берем первые n-1 рёбер
//(так как дерево будет состоять из n-1 ребра по теореме о деревьях) и если концы не принадлежат одному множеству(то есть не соединены), то берем это ребро
//добавлем вес к минимальной стоимости дерева, и обьединяем концы ребра в одно множество.И так до тех пор, пока не запишем в ответ N-1 раз ребра.
//В данной реализации мы не минимальный вес получаем, а сами ребра, из которых будет состоять мимнимальное остовное дерево

void sol()
{
    sort(a.begin(),a.begin()+m);
    temp=n-1;
    for(i=0;i<m && z<temp;++i)
    {
        if(union_set(a[i].second.first,a[i].second.second))
        {
            ++z;
            p.push_back(a[i]);
        }
    }
}

//Вывод полученного дерева

void output()
{
    for(i=0;i<p.size();++i)
        printf("%I64d -> %I64d = %I64d\n",p[i].second.first,p[i].second.second,p[i].first);
}

//Ну а тут сначала обнуляем rand(), затем вводим граф, считаем min_ost и выводим его

int main()
{
    srand(time(0));
    input();
    sol();  
    output();  
    system("pause");
    return 0;
}
