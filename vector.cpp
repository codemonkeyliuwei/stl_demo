/* File Name  : vecotr.cpp
 * Description: demo for STL's container vector
 * Reference  : 更多用法请参考: 
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
 * Demo for vector insert and delete
 */
void InsertAndDelete(void)
{
    vector<entry> entryVec(2);  //初始化2个元素的数组

    //方法一：按数组方式赋值
    entryVec[0] = entry(0, "value0");
    entryVec[1] = entry(1, "value1");

    //方法二：通过push_back在尾部插入
    entryVec.push_back(entry(2, "value2"));
    entryVec.push_back(entry(3, "value3"));
    cout << "\nEntry vector after push:\n";
    for_each(entryVec.begin(), entryVec.end(), PrintEntry);

    //删除指定第n个元素
    entryVec.erase(entryVec.begin()+1); //删除第3个元素
    cout << "\nEntry vector after delete:\n";
    for_each(entryVec.begin(), entryVec.end(), PrintEntry);
}

/*
 * Demo for vector traverse
 */
void Traversal(void)
{
    vector<entry> entryVec;

    //插入节点
    entryVec.push_back(entry(1, "value1"));
    entryVec.push_back(entry(2, "value2"));
    entryVec.push_back(entry(3, "value3"));

    //方法一: 利用for_each, 将PrintEntry作用于[begin, end)的每个元素
    cout << "\nTraversal vector by for_earch:\n";
    for_each(entryVec.begin(), entryVec.end(), PrintEntry);

    //方法二：利用迭代器遍历
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

    //插入节点
    entryVec.push_back(entry(1, "value1"));
    entryVec.push_back(entry(2, "value2"));
    entryVec.push_back(entry(3, "value3"));

    const entry destEntry = entry(2);

    //方法一：遍历查找
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

    //方法二：通过find查找
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

    //按1-4-3-2乱序插入vector
    entryVec.push_back(entry(1, "value1"));
    entryVec.push_back(entry(4, "value4"));
    entryVec.push_back(entry(3, "value3"));
    entryVec.push_back(entry(2, "value2"));

    const entry destEntry = entry(2);

    /***vector没有sort方法, 需使用algorithm中的sort算法***/
    
    //降序
    cout << "\nSort descending:\n";
    sort(entryVec.begin(), entryVec.end(), EntryGreater);
    for_each(entryVec.begin(), entryVec.end(), PrintEntry);

    //升序
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
