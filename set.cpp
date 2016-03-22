/* File Name  : set.cpp
 * Description: demo for STL's container set
 *              set      -- ����������Ų��ظ�Ԫ�ص�����
 *              multiset -- ����������ſ��ظ�Ԫ�ص�����
 * Reference  : �����÷���ο�: 
 *              http://www.cplusplus.com/reference/set/set/
 *              http://www.cplusplus.com/reference/set/multiset/
 * Author     :
 * Data       : 2016/03/22
 */

#include <set>          //set
#include <iostream>
#include <string>
#include <algorithm>    //for_each

using namespace std;

/*
 * �Զ�����������
 */
struct entry
{
    char    key;
    string  value;

    entry(void){}
    entry(char _key) : key(_key){}
    entry(char _key, string _value) : key(_key), value(_value){}

    bool operator==(const entry& _entry) const
    {
        return (this->key == _entry.key);
    }
};


struct EntryLess {
    bool operator() (const entry & lh, const entry & rh) const
    {
        return lh.key < rh.key;
    }
};

struct EntryGreater {
    bool operator() (const entry & lh, const entry & rh) const
    {
        return lh.key > rh.key;
    }
};

void PrintEntry(const entry& _entry)
{
    cout << "entry< " << _entry.key << ", " 
        << _entry.value << ">" << endl;
}

/*
 * Demo for set insert and delete
 */
void InsertAndDelete(void)
{
    set<entry, EntryLess> entrySet;

    entrySet.insert(entry('0', "value0"));
    entrySet.insert(entry('1', "value1"));
    entrySet.insert(entry('2', "value2"));
    entrySet.insert(entry('3', "value3"));


    //��������ɾ��ָ��Ԫ��
    entrySet.erase(entrySet.begin()); //ɾ����1��Ԫ��
    cout << "\nEntry set after delete:\n";
    for_each(entrySet.begin(), entrySet.end(), PrintEntry);

    //��valueɾ��ָ��Ԫ��
    entrySet.erase(entry(2)); //ɾ��key=='2'��Ԫ��
    cout << "\nEntry set after delete:\n";
    for_each(entrySet.begin(), entrySet.end(), PrintEntry);
}

/*
 * Demo for set traverse
 */
void Traversal(void)
{
    set<entry, EntryLess> entrySet;

    //����ڵ�
    entrySet.insert(entry('1', "value1"));
    entrySet.insert(entry('2', "value2"));
    entrySet.insert(entry('3', "value3"));

    //����һ: ����for_each, ��PrintEntry������[begin, end)��ÿ��Ԫ��
    cout << "\nTraversal set by for_earch:\n";
    for_each(entrySet.begin(), entrySet.end(), PrintEntry);

    //�����������õ���������
    cout << "\nTraversal set by iterator:\n";
    set<entry, EntryLess>::iterator it = entrySet.begin();
    for (; it != entrySet.end(); ++it)
    {
        cout << "entry<" << it->key << ", " << it->value << ">\n"; 
    }
}

/*
 * Demo for set search
 */
void Search(void)
{
    set<entry, EntryLess> entrySet;

    //����ڵ�
    entrySet.insert(entry('1', "value1"));
    entrySet.insert(entry('2', "value2"));
    entrySet.insert(entry('3', "value3"));

    const entry destEntry = entry('2');

    //����һ����������
    cout << "\nFind set entry by iterator:\n";
    set<entry, EntryLess>::iterator it = entrySet.begin();
    for (; it != entrySet.end(); ++it)
    {
        if (it->key == destEntry.key)
        {
            cout << "Find entry<" << it->key << ", " << it->value << ">\n"; 
            break;
        }        
    }

    //��������ͨ��find����
    cout << "\nFind set entry by function 'find':\n";
    it = entrySet.find(destEntry);
    if (it != entrySet.end())
    {
        cout << "Find entry<" << it->key << ", " << it->value << ">\n"; 
    }
}

/*
 * Demo for ascending set
 */
void AsendSort(void)
{
    set<entry, EntryLess> entrySet;

    //��1-4-3-2�������set
    entrySet.insert(entry('1', "value1"));
    entrySet.insert(entry('4', "value4"));
    entrySet.insert(entry('3', "value3"));
    entrySet.insert(entry('2', "value2"));

    //����
    cout << "\nAscending set:\n";
    for_each(entrySet.begin(), entrySet.end(), PrintEntry);
}

/*
 * Demo for descending set
 */
void DesendSort(void)
{
    set<entry, EntryGreater> entrySet;

    //��1-4-3-2�������set
    entrySet.insert(entry('1', "value1"));
    entrySet.insert(entry('4', "value4"));
    entrySet.insert(entry('3', "value3"));
    entrySet.insert(entry('2', "value2"));

    //����
    cout << "\nDescending set:\n";
    for_each(entrySet.begin(), entrySet.end(), PrintEntry);
}

int main(int argc, char **argv)
{
    InsertAndDelete();

    Traversal();

    Search();

    AsendSort();

    DesendSort();

    return 0;
}
