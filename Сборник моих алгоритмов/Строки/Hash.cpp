//���������� ���� �� ������. ������� ��� : ����� �� ������, � ��������� � ���� (��� ����� - ��� � + 1)*p[i], ��� ������ P - ������� 53(31)

long long hash()
{
    long long res=0;
    for(i=0;i<size;++i)
        res+=(s[i]-'a'+1)*p[i];
    return res;
}
