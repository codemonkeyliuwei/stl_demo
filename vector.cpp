/* File Name  : vecotr.cpp
 * Description: demo for STL's container vector
 * Reference  : �����÷���ο�: 
 *              http://www.cplusplus.com/reference/vector/vector/
 *              http://www.cplusplus.com/reference/algorithm/sort/
 * Author     :
 * Data       : 2016/03/19
 */

#include <vector>       //vector
#include <iostream>
#include <string>
#include <algorithm>    //for_each

using namespace std;

/*
 * �Զ�����������
 */
struct entry
{
    int     key;
    string  value;

    entry(void){}
    entry(int _key) : key(_key){}
    entry(int _key, string _value) : key(_key), value(_value){}

    bool operator==(const entry& _entry) const
    {
        return (this->key == _entry.key);
    }
};

void PrintEntry(const entry& _entry)
{
    cout << "entry< " << _entry.key << ", " 
        << _entry.value << ">" << endl;
}

/*
 * Demo for vector insert and delete
 */
void InsertAndDelete(void)
{
    vector<entry> entryVec(2);  //��ʼ��2��Ԫ�ص�����

    //����һ�������鷽ʽ��ֵ
    entryVec[0] = entry(0, "value0");
    entryVec[1] = entry(1, "value1");

    //��������ͨ��push_back��β������
    entryVec.push_back(entry(2, "value2"));
    entryVec.push_back(entry(3, "value3"));
    cout << "\nEntry vector after push:\n";
    for_each(entryVec.begin(), entryVec.end(), PrintEntry);

    //ɾ��ָ����n��Ԫ��
    entryVec.erase(entryVec.begin()+1); //ɾ����3��Ԫ��
    cout << "\nEntry vector after delete:\n";
    for_each(entryVec.begin(), entryVec.end(), PrintEntry);
}

/*
 * Demo for vector traverse
 */
void Traversal(void)
{
    vector<entry> entryVec;

    //����ڵ�
    entryVec.push_back(entry(1, "value1"));
    entryVec.push_back(entry(2, "value2"));
    entryVec.push_back(entry(3, "value3"));

    //����һ: ����for_each, ��PrintEntry������[begin, end)��ÿ��Ԫ��
    cout << "\nTraversal vector by for_earch:\n";
    for_each(entryVec.begin(), entryVec.end(), PrintEntry);

    //�����������õ���������
    cout << "\nTraversal vector by iterator:\n";
    vector<entry>::iterator it = entryVec.begin();
    for (; it != entryVec.end(); ++it)
    {
        cout << "entry<" << it->key << ", " << it->value << ">\n"; 
    }
}

/*
 * Demo for vector search
 */
void Search(void)
{
    vector<entry> entryVec;

    //����ڵ�
    entryVec.push_back(entry(1, "value1"));
    entryVec.push_back(entry(2, "value2"));
    entryVec.push_back(entry(3, "value3"));

    const entry destEntry = entry(2);

    //����һ����������
    cout << "\nFind vector entry by iterator:\n";
    vector<entry>::iterator it = entryVec.begin();
    for (; it != entryVec.end(); ++it)
    {
        if (it->key == destEntry.key)
        {
            cout << "Find entry<" << it->key << ", " << it->value << ">\n"; 
            break;
        }        
    }

    //��������ͨ��find����
    cout << "\nFind vector entry by function 'find':\n";
    it = find(entryVec.begin(), entryVec.end(), destEntry);
    if (it != entryVec.end())
    {
        cout << "Find entry<" << it->key << ", " << it->value << ">\n"; 
    }
}

bool EntryGreater(const entry & lh, const entry & rh)
{
    return lh.key > rh.key;
}

bool EntryLess(const entry & lh, const entry & rh)
{
    return lh.key < rh.key;
}

/*
 * Demo for vector sorting
 */
void Sort(void)
{
    vector<entry> entryVec;

    //��1-4-3-2�������vector
    entryVec.push_back(entry(1, "value1"));
    entryVec.push_back(entry(4, "value4"));
    entryVec.push_back(entry(3, "value3"));
    entryVec.push_back(entry(2, "value2"));

    const entry destEntry = entry(2);

    /***vectorû��sort����, ��ʹ��algorithm�е�sort�㷨***/
    
    //����
    cout << "\nSort descending:\n";
    sort(entryVec.begin(), entryVec.end(), EntryGreater);
    for_each(entryVec.begin(), entryVec.end(), PrintEntry);

    //����
    cout << "\nSort ascending:\n";
    sort(entryVec.begin(), entryVec.end(), EntryLess);
    for_each(entryVec.begin(), entryVec.end(), PrintEntry);
}

int main(int argc, char **argv)
{
    InsertAndDelete();

    Traversal();

    Search();

    Sort();

    return 0;
}
