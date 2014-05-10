//Обход в ширину(BFS).ДЛя списка рёбер
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//храним граф в списке рёбер:
const int maxe=100,maxv=100;// максимум рёбер и вершин
int ef[maxe],es[maxe],ev[maxe],next[maxe],first[maxv],last[maxv],i,x,y,z;
queue<int> s;//для работы BFS
vector<char> used(maxe);//массив был ли посещён

//функция добавления ребра

void add(int v1,int v2,int value,int &count)
{
    ++count;
    ef[count]=v1;es[count]=v2;ev[count]=value;
    if(!first[v1])  first[v1]=count;
    if(last[v1])    next[last[v1]]=count;
    last[v1]=count;
}
//инициализируем граф, ребра двунаправлены - вызываем функцию add() 2 раза
void init()
{
    int count=0;
    for(i=0;i<5;++i)
    {
        cin>>x>>y>>z;
        add(x,y,z,count);
        add(y,x,z,count);
    }
}

//Сама функция обхода.Работает слудющим образом:ложим в очередь вершину, с которой начинаем, ставим метку, что её посетили.
//И теперь пока очередь не пуста, делаем следующее:извлекаем вершину из очереди, смотри все ребра, выходящие из этой вершины.
//Если 2-ой конец ребра не был посещен, то ставим метку, что его посетили, и ложим данную вершину в очередь.И так повторяем до тех пор,
//пока у нас не будут посещены все вершины.Также этим алгоритмом можно искать компоненты связности.

void bfs()
{
    s.push(1);
    used[1]=true;
    while(!s.empty())
    {
        int from=s.front();
        s.pop();
        for(int h=first[from];h;h=next[h])
            if(!used[es[h]])
            {
                used[es[h]]=true;
                s.push(es[h]);
            }
    }
}

//ну а тут просто вызываем функцию bfs()

int main()
{
    init();
    bfs();
    system("pause");
}
