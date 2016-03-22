/* File Name  : map.cpp
 * Description: demo for STL's container map
 *              map -- ��key˳�򱣴�<key, value>��ֵ�Ե�����
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

    //ͷ������
    entrymap[1] = (entry(1, "value1"));
    entrymap[2] = (entry(2, "value2"));
    entrymap[3] = (entry(3, "value3"));
    cout << "\nEntry map after push:\n";
    for_each(entrymap.begin(), entrymap.end(), PrintEntry);

    //ɾ��--��������, ɾ����һ���ڵ�
    entrymap.erase(entrymap.begin());

    //ɾ��--��keyɾ��ָ���ڵ�, ɾ��key=2��entry
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

    //ͷ������
    entrymap[1] = (entry(1, "value1"));
    entrymap[2] = (entry(2, "value2"));
    entrymap[3] = (entry(3, "value3"));

    //����һ: ����for_each, ��PrintEntry������[begin, end)��ÿ��Ԫ��
    cout << "\nTraversal map by for_earch:\n";
    for_each(entrymap.begin(), entrymap.end(), PrintEntry);

    //�����������õ���������
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

    //����ڵ�
    entrymap[1] = (entry(1, "value1"));
    entrymap[2] = (entry(2, "value2"));
    entrymap[3] = (entry(3, "value3"));

    const entry destEntry = entry(2);

    //����һ����������
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

    //��������ͨ��map��find����
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

    //key��1-4-3-2˳�򱣴�pair<key, value>, Ĭ�ϰ�key��������
    entrymap[1] = (entry(1, "value1"));
    entrymap[4] = (entry(4, "value4"));
    entrymap[3] = (entry(3, "value3"));
    entrymap[2] = (entry(2, "value2"));

    cout << "\nAscending map:\n";
    for_each(entrymap.begin(), entrymap.end(), PrintEntry);
}

/*
 * �Զ���key�ȽϽṹ
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

    //key��1-4-3-2˳�򱣴�pair<key, value>, Ĭ�ϰ�key��������
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
