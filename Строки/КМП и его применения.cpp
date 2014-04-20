


inline void kmp(vector <int> &p)
{
    for(i=1;i<size;++i)
    {
        j=p[i-1];
        while(j>0 && s[i] != s[j])
            j=p[j-1];
        if(s[i] == s[j])
            ++j;
        p[i]=j;
        //if(p[i]>max)      для нахождения всех подстрок
        //  max=p[i];
    }
}

void keepfit_str(vector <int &p) //сжатие строки
{
    kmp(p);
    int k=size-p[size-1];
    if(k != size && size % k == 0)
        cout<<s.substr(p[size-1]);
    else
        cout<<"Wrong Answer";
}

void search_in_str(vector<int> &p)//нахождение подстроки в строке
{
    s=s_pref+"$"+s_main;
    size=s.length();
    size_pref=s_pref.length();
    kmp(p);
    for(i=0;i<size;++i)
        if(p[i] == size_pref)
            coout<<i-2*size_pref;//2*size_pref заранее рассчитать
}










