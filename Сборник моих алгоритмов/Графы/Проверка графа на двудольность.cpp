//Проверка(и разбиение графа) на 2 доли.
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;
typedef long long ll;
//для списка рёбер
const ll maxn=100,maxm=10000;
ll ef[maxm],es[maxm],next[maxm],first[maxn],c=0;
ll i,j,n,m,x,y,z,h,v;
queue<ll> q;//очередь для обхода графа
bool used[maxn],ok=true;//массив посещений и флаг
char met[maxn];//массив меток

//добавление ребра

void init(ll v1,ll v2)
{
    next[++c]=first[v1];first[v1]=c;
    ef[c]=v1;es[c]=v2;
}

//инициализация графа

void input()
{
    cin>>n>>m;
    for(i=0;i<m;++i)
    {
        cin>>x>>y;
        init(x,y);
        init(y,x);
    }
}

//функция проверки на двудольность.Работает так: начинаем от любой вершины, ставим флаг, что она посещена, и присваиваем ей цвет(в данном случае 1 или 0).
//И запихиваем эту вершину в очередь.И тут уже обходим граф при помощи BFS(), попутно делая следующие проверки: если вершина не посещена, то присваиваем ей цвет,
//отличный от цвета вершины, из которой мы сюда пришли, и пихаем эту вершину в очередь.Если же вершина была уже ранее посещена, то проверяем: отличен ли её цвет от
//цвета текущей вершины.Если да - то всё нормально, если нет - то данный граф нельзя разбить на 2 доли - можно прерывать работу алгоритма.

bool prov(ll k)
{
    used[k]=true;
    met[k]='1';
    q.push(k);
    while(!q.empty())
    {
        v=q.front();q.pop();
        used[v]=true;
        for(h=first[v];h;h=next[h])
        {
            if(!used[es[h]])
            {
                met[v] == '1' ? met[es[h]]='0' : met[es[h]]='1';
                q.push(es[h]);
            }
            else
            {
                if(met[v] == met[es[h]])
                    return false;
            }
        }
    }
    return true;
}

//тут просто рассматривается случай - а вдруг у нас несколько компонент связностей

void sol()
{
    for(ll i=1;i<=n && ok;++i)
    {
        if(!used[i])
            ok=prov(i);
    }
}

//инициализируем граф, проверяем на двудольность, выводим метки вершин и флаг, удалось ли нам разбить граф на доли

int main()
{
    input();
    sol();
    for(i=1;i<=n;++i)
        cout<<met[i]<<' ';
    cout<<endl;
    cout<<ok<<endl;
    system("pause");
    return 0;
}
