#include <iostream>
#include <stdio.h>

// Для теста
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

// Как обычно, максимальное количество вершин
#define N 111111
struct cell {
    // Ключ, приоритет
    int key,prior;
    
    // Номера левого и правого сына. 0 - ссылка в никуда
    int ls,rs;
} tree[N];

// Количество действующих вершин, номер корня дерева
int kv,root;

// Процедура, которая делит дерево с корнем в вершине x
// На два дерева, при чём записывает номер корня левого дерева
// в переменную left_tree, а правого в right_tree
// В левом дереве все ключи < key
void split(int x, int key, int& left_tree, int& right_tree) {
    // Если мы пришли в 0, т.е там, где дерева не существует
    if (!x) {
	// Тогда оба дерева - фиктивные
	left_tree = right_tree = 0;
	return;
    }
    if (key < tree[x].key) {
	// Если мы попали сюда, то значит ситуация следующая -
	// Всё правое поддерево должно уйти в right_tree, ведь
	// Все ключи в нём заведомо больше key.
	// А вот в левом поддереве могут лежать вершины, которые
	// в будущем могут принадлежать разным поддеревьям
	
	
	// Поэтому поступаем следующим образом. Сплитим левое поддерево
	// относительно нашего же ключа
	// Результат этого вызова - два поддерева
	// Левое дерево результата - именно то, что нам нужно, Поэтому тут ничего не меняем
	// А вот с правым поддеревов сложнее, ведь оно состоит и из вершин этого вызова и из вершин
	// правого сына поддерева x. Но так как изначальное дерево уже удовлетворяло свойствам трипа
	// то мы провернём такой фокус: корнем right_tree сделаем x. Его левым сыном - поддерево, которое
	// вернёт наш вызов split. Получается, что все свойства дерамиды выполнены
	split(tree[x].ls, key, left_tree, tree[x].ls); 
	right_tree = x;
    } else {
	// Симметричный случай
	
	split(tree[x].rs, key, tree[x].rs, right_tree);
	left_tree = x;
    }
}

// Процедура объединяет два дерева с корням left_tree и right_tree
// В одно, корнем которого будет значение переменной x
void merge(int& x, int left_tree, int right_tree) {
    // Если одно из деревьев не существует
    if (!left_tree || !right_tree) {
	// То мы смотрим, какое существует и ставим его на место x
	if (left_tree) x = left_tree;
	else x = right_tree;
	return;
    }
    
    // Смотрим корень какого дерева приоритетней. Он и будет корнем общего дерева
    if (tree[left_tree].prior > tree[right_tree].prior) { 
	// Левое поддерево left_tree останентся тем же, а вот правое
	// будет представлять объединение вершин правого поддерева left_tree
	// и самого right_tree
	merge(tree[left_tree].rs, tree[left_tree].rs, right_tree);
	x = left_tree;
    } else {
	// Симметричный случай
	
	merge(tree[right_tree].ls, left_tree, tree[right_tree].ls);
	x = right_tree;
    }
}

// Процедура вставки вершины в дерево с корнем в x
// new_item - уже номер сформированной вершины
void insert(int& x, int new_item) {
    // Если дерево пустое
    if (!x) {
	// Делаем новую вершину корнем дерева
	x = new_item;
	return;
    }
    // Если в это место уже можно вставить вершину
    if (tree[new_item].prior > tree[x].prior) {
	// Тогда мы просто разделем текущее поддерево на два по ключу нашего нового элемента
	// Результат процедуры (два дерева) будут сыновьями новой вершины
	// Себя опять сделаем корнем поддерева
	split(x, tree[new_item].key, tree[new_item].ls, tree[new_item].rs);
	x = new_item;
    } else {
	// Если вставлять ещё рано, смотрим в каком поддереве должна быть наша вершина
	if (tree[new_item].key < tree[x].key) insert(tree[x].ls, new_item);
	else insert(tree[x].rs, new_item);
    }
}

// Процедура, которая вставляет число x
// Т.е она должна формировать вершинку и передавать её другому insert
// По-хорошему тут должна быть гарантия, что все приоритеты разные
// Но rand() работает вроде прилично
void insert(int x) {
    tree[++kv] = (cell) {x, rand(), 0, 0};
    insert(root, kv);
}

// Удаление вершины с заданным ключом
void erase(int& x, int key) {
    // Если ничего не нашли, возвращаемся ни с чем
    if (!x) return;
    // Если нашли нужную вершину, просто объединяем два её поддерева-сына
    // И затираем результатом текущую вершину
    if (tree[x].key == key) merge(x, tree[x].ls, tree[x].rs);
    else {
	// Иначе смотрим, в каком поддереве жертва
	if (key < tree[x].key) erase(tree[x].ls, key);
	else erase(tree[x].rs, key);
    }
}

vector<int> b;
// Обход дерева (для теста)
void print(int x) {
    if (!x) return;
    print( tree[x].ls );
    b.push_back(tree[x].key);
    print( tree[x].rs );
}

int n;

// Проверяет, правильно ли сортится последовательность (для теста)
bool check(int n, int cur_rand) {
    vector<int> a(n),c;
    for (int i=0;i<n;i++) a[i] = i;
    c = a;
    
    root = kv = 0; memset(tree,0,sizeof(tree));
    b.clear();
    
    srand(cur_rand);
    random_shuffle(c.begin(),c.end());
    for (int i=0;i<n;i++) insert(c[i]);
    
    print(root);
    
    bool ans = (a == b);
    if (ans) printf("%d : OK\n",cur_rand);
    else printf("%d: WA\n",cur_rand);
    return ans;
}

int main() {
    cin >> n;
    int lim = 1 << 12;
    for (int i=0;i<lim;i++) 
	if (!check(n,i)) break;
    
    return 0;
}