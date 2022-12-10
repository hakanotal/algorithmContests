// g++ -std=c++11 pro.cpp -o pro && ./pro < in.txt > out.txt
#include <bits/stdc++.h>
#define M 1e9 + 7 // for modulo

using namespace std;

class File
{
public:
    string name;
    int size = 0;

    File(string name, int size)
    {
        this->name = name;
        this->size = size;
    }
};

class Folder
{
public:
    string name;
    int size = 0;
    Folder *parentFolder;
    vector<Folder *> subfolders;
    vector<File *> files;

    Folder(string name)
    {
        this->name = name;
    }

    int calc_size()
    {
        for (auto sub : subfolders)
            this->size += sub->calc_size();

        for (auto f : files)
            this->size += f->size;

        return this->size;
    }

    void print()
    {
        for (auto sub : subfolders)
        {
            cout << sub->name << " - " << sub->size << endl;
            sub->print();
        }

        for (auto f : files)
            cout << f->name << " - " << f->size << endl;
    }

    int search()
    {
        int totalSize = 0;
        for (auto sub : this->subfolders)
        {
            if (sub->size <= 100000)
                totalSize += sub->size;

            totalSize += sub->search();
        }
        return totalSize;
    }

    int find(int target, int smallest)
    {
        for (auto sub : this->subfolders)
        {
            if (sub->size >= target && sub->size < smallest)
                smallest = sub->size;

            smallest = sub->find(target, smallest);
        }
        return smallest;
    }
};

int main()
{
    // Read faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Folder start = Folder("/");
    Folder *current = &start;

    // Input
    string s;
    while (getline(cin, s))
    {
        // cout << "Current dir: " << current->name << "\n";
        if (s.find("$ cd") != string::npos)
        {
            string _, target;
            stringstream ss(s);
            ss >> _ >> _ >> target;

            if (target == "..")
            {
                current = current->parentFolder;
            }
            else if (target != "/")
            {
                for (int i = 0; i < current->subfolders.size(); i++)
                {
                    if (current->subfolders[i]->name == target)
                    {
                        current = current->subfolders[i];
                    }
                }
            }
        }
        else if (s.find("$ ls") != string::npos)
        {
            continue;
        }
        else if (s.find("dir") != string::npos)
        {
            string _, dir;
            stringstream ss(s);
            ss >> _ >> dir;

            Folder *newFolder = new Folder(dir);
            // cout << "New folder:" << newFolder->name << endl;
            newFolder->parentFolder = current;
            current->subfolders.push_back(newFolder);
        }
        else
        {
            string file;
            int size;
            stringstream ss(s);
            ss >> size >> file;

            File *newFile = new File(file, size);
            // cout << "New file:" << newFile->name << endl;
            current->files.push_back(newFile);
        }
    }

    int totalSize = start.calc_size();
    cout << "/ - " << totalSize << endl;
    start.print();
    // cout << "Search Result: " << start.search() << endl;

    int empty = 70000000 - totalSize;
    int required = 30000000 - empty;
    cout << "Required: " << required << endl;
    cout << "Find Smallest Enough: " << start.find(required, 70000000) << endl;

    return 0;
}