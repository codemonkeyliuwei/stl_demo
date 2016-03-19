/* File Name  : list.cpp
 * Description: demo for STL's container list
 * Reference  : http://www.cplusplus.com/reference/list/list/
 * Author     :
 * Data       : 2016/03/19
 */

#include <list>         //list
#include <iostream>
#include <string>
#include <algorithm>    //for_each

using namespace std;

/*
 * 自定义数据类型
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
 * Demo for list insert and delete
 */
void InsertAndDelete(void)
{
    list<entry> entryList;

    //头部插入
    entryList.push_front(entry(1, "value1"));

    //尾部插入
    entryList.push_back(entry(2, "value2"));
    entryList.push_back(entry(3, "value3"));
    cout << "\nEntry list after push:\n";
    for_each(entryList.begin(), entryList.end(), PrintEntry);

    //删除--按迭代器, 删除第一个节点
    entryList.erase(entryList.begin());

    //删除--按entry的值删除指定节点, 删除key=2的entry
    entryList.remove(entry(2));
    cout << "\nEntry list after delete:\n";
    for_each(entryList.begin(), entryList.end(), PrintEntry);
}

/*
 * Demo for list traverse
 */
void Traversal(void)
{
    list<entry> entryList;

    //插入节点
    entryList.push_back(entry(1, "value1"));
    entryList.push_back(entry(2, "value2"));
    entryList.push_back(entry(3, "value3"));

    //方法一: 利用for_each, 将PrintEntry作用于[begin, end)的每个元素
    cout << "\nTraversal list by for_earch:\n";
    for_each(entryList.begin(), entryList.end(), PrintEntry);

    //方法二：利用迭代器遍历
    cout << "\nTraversal list by iterator:\n";
    list<entry>::iterator it = entryList.begin();
    for (; it != entryList.end(); ++it)
    {
        cout << "entry<" << it->key << ", " << it->value << ">\n"; 
    }
}

/*
 * Demo for list search
 */
void Search(void)
{
    list<entry> entryList;

    //插入节点
    entryList.push_back(entry(1, "value1"));
    entryList.push_back(entry(2, "value2"));
    entryList.push_back(entry(3, "value3"));

    const entry destEntry = entry(2);

    //方法一：遍历查找
    cout << "\nFind list entry by iterator:\n";
    list<entry>::iterator it = entryList.begin();
    for (; it != entryList.end(); ++it)
    {
        if (it->key == destEntry.key)
        {
            cout << "Find entry<" << it->key << ", " << it->value << ">\n"; 
            break;
        }        
    }

    //方法二：通过find查找
    cout << "\nFind list entry by function 'find':\n";
    it = find(entryList.begin(), entryList.end(), destEntry);
    if (it != entryList.end())
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
 * Demo for list sorting
 */
void Sort(void)
{
    list<entry> entryList;

    //按1-4-3-2乱序插入list
    entryList.push_back(entry(1, "value1"));
    entryList.push_back(entry(4, "value4"));
    entryList.push_back(entry(3, "value3"));
    entryList.push_back(entry(2, "value2"));

    const entry destEntry = entry(2);

    //降序
    cout << "\nSort descending:\n";
    entryList.sort(EntryGreater);
    for_each(entryList.begin(), entryList.end(), PrintEntry);

    //升序
    cout << "\nSort ascending:\n";
    entryList.sort(EntryLess);
    for_each(entryList.begin(), entryList.end(), PrintEntry);
}

int main(int argc, char **argv)
{
    InsertAndDelete();

    Traversal();

    Search();

    Sort();

    return 0;
}