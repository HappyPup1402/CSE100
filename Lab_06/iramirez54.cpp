#include <iostream>
#include <list>
using namespace std;

class HashTable{
    private:   
        list<int> *hashTable;
    public:
        HashTable(int size){
            hashTable = NULL;
            hashTable = new list<int>[size];
        };

        ~HashTable(){
            delete [] hashTable;
        }


        void insert(int key, int size){
            hashTable[key%size].push_front(key);
        }
        
        bool deleteKey(int key,int size){
            list<int> l = hashTable[key%size];
            list<int>::iterator it;
            if(l.empty()){
                return false;
            }
            else{
                for(it = l.begin(); it != l.end(); it++){
                    if(*it==key){
                        l.erase(it);
                        hashTable[key%size]=l;
                        return true;
                    }
                }
                return false;
            }
        }

        void search(int key, int size){
            list<int> l = hashTable[key%size];

            list<int>::iterator it;
            int index=0;
            if(l.empty()){
                cout<<key<<":NOT_FOUND;"<<endl;
            }
            else{
                for(it = l.begin(); it != l.end(); it++){
                    if(*it==key){
                        cout<<key<<":FOUND_AT"<<(key%size)<<","<<index<< ";"<<endl;
                        return;
                    }
                    index++;
                }
                cout<<key<<":NOT_FOUND;"<<endl;   
            }
        }

        void output(int size){
            list<int> l;
            list<int>::iterator it;
            for(int i = 0; i < size; i++){
                l = hashTable[i];

                if(l.empty()){
                    cout<<i<<":;"<<endl;
                }
                else{
                    cout<<i<<":";
                    for (it = l.begin(); it != l.end(); it++){
                        cout<< *it<<"->";
                    }
                    cout<<";"<<endl;   
                }   
            }
        }
};

int main(){
    int size;
    int key;
    cin>>size;
    char letter;

    HashTable table(size);
    
    cin>>letter;
    while(letter!='e'){
        if(letter=='i'){
            cin>>key;
            table.insert(key,size);
        }
        else if(letter=='d'){
            cin>>key;
            if(table.deleteKey(key,size)){
                cout<<key<<":DELETED;"<<endl;
            }
            else{
                cout<<key<<":DELETE_FAILED;"<<endl;
            }
        }
        else if(letter=='s'){
            cin>>key;
            table.search(key,size);
        }
        else if(letter=='o'){
            table.output(size);
        }
        cin>>letter;
    }
    return 0;
}

//collaborator mario barrera