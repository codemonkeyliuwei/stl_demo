/* File Name  : map.cpp
 * Description: demo for STL's container map
 *              map -- 按key顺序保存<key, value>键值对的容器
 * Reference  : http://www.cplusplus.com/reference/map/map/
 * Author     :
 * Data       : 2016/03/22
 */

#include <map>          //map
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

void PrintEntry(pair<int, entry> _pair)
{
    cout << "entry< " << _pair.second.key << ", " 
        << _pair.second.value << ">" << endl;
}

/*
 * Demo for map insert and delete
 */
void InsertAndDelete(void)
{
    map<int, entry> entrymap;

    //头部插入
    entrymap[1] = (entry(1, "value1"));
    entrymap[2] = (entry(2, "value2"));
    entrymap[3] = (entry(3, "value3"));
    cout << "\nEntry map after push:\n";
    for_each(entrymap.begin(), entrymap.end(), PrintEntry);

    //删除--按迭代器, 删除第一个节点
    entrymap.erase(entrymap.begin());

    //删除--按key删除指定节点, 删除key=2的entry
    entrymap.erase(2);
    cout << "\nEntry map after delete:\n";
    for_each(entrymap.begin(), entrymap.end(), PrintEntry);
}

/*
 * Demo for map traverse
 */
void Traversal(void)
{
    map<int, entry> entrymap;

    //头部插入
    entrymap[1] = (entry(1, "value1"));
    entrymap[2] = (entry(2, "value2"));
    entrymap[3] = (entry(3, "value3"));

    //方法一: 利用for_each, 将PrintEntry作用于[begin, end)的每个元素
    cout << "\nTraversal map by for_earch:\n";
    for_each(entrymap.begin(), entrymap.end(), PrintEntry);

    //方法二：利用迭代器遍历
    cout << "\nTraversal map by iterator:\n";
    map<int, entry>::iterator it = entrymap.begin();
    for (; it != entrymap.end(); ++it)
    {
        cout << "entry<" << it->first << ", " << it->second.value << ">\n"; 
    }
}

/*
 * Demo for map search
 */
void Search(void)
{
    map<int, entry> entrymap;

    //插入节点
    entrymap[1] = (entry(1, "value1"));
    entrymap[2] = (entry(2, "value2"));
    entrymap[3] = (entry(3, "value3"));

    const entry destEntry = entry(2);

    //方法一：遍历查找
    cout << "\nFind map entry by iterator:\n";
    map<int, entry>::iterator it = entrymap.begin();
    for (; it != entrymap.end(); ++it)
    {
        if (it->first == destEntry.key)
        {
            cout << "Find entry<" << it->first << ", " << it->second.value << ">\n"; 
            break;
        }        
    }

    //方法二：通过map的find查找
    cout << "\nFind map entry by function 'find':\n";
    it = entrymap.find(2);
    if (it != entrymap.end())
    {
        cout << "Find entry<" << it->first << ", " << it->second.value << ">\n"; 
    }
}

/*
 * Constructing ascending map
 */
void AscendMap(void)
{
    map<int, entry> entrymap;

    //key按1-4-3-2顺序保存pair<key, value>, 默认按key升序排列
    entrymap[1] = (entry(1, "value1"));
    entrymap[4] = (entry(4, "value4"));
    entrymap[3] = (entry(3, "value3"));
    entrymap[2] = (entry(2, "value2"));

    cout << "\nAscending map:\n";
    for_each(entrymap.begin(), entrymap.end(), PrintEntry);
}

/*
 * 自定义key比较结构
 */
struct keyGreater 
{
    bool operator() (const char& lhs, const char& rhs) const
    {return lhs>rhs;}
};

/*
 * Constructing descending map
 */
void DescendMap(void)
{
    map<char, entry, keyGreater> entrymap;

    //key按1-4-3-2顺序保存pair<key, value>, 默认按key升序排列
    entrymap['1'] = (entry(1, "value1"));
    entrymap['4'] = (entry(4, "value4"));
    entrymap['3'] = (entry(3, "value3"));
    entrymap['2'] = (entry(2, "value2"));

    cout << "\nDescending map:\n";
    for_each(entrymap.begin(), entrymap.end(), PrintEntry);
}

int main(int argc, char **argv)
{
    InsertAndDelete();

    Traversal();

    Search();

    AscendMap();

    DescendMap();

    return 0;
}
