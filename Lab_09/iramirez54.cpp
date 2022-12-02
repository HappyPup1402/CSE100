#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct nodes{
    char node;
    int frequency;
    nodes* left;
    nodes* right;
    public:
        nodes(){
            node = ' ';
            frequency = 0;
        }
        nodes(char name, int frequency){
            this->node = name;
            this->frequency = frequency;
        }
};

struct compare{
    bool operator()(nodes* left, nodes* right){
        return (left->frequency > right->frequency);
    }
};

void print(nodes* temp, string s, char chars[], string output[]){
	if(temp == NULL){
		return;
	}
	else if(temp->node == '\n'){
        print(temp->left, s + "0", chars, output);
        print(temp->right, s + "1", chars, output);
    }
    else{
		for(int i = 0; i < 6; i++){
            if (temp->node == chars[i]){
                output[i] = s;
            }
        }
    }
}

void Huffman(int frequency[], char chars[], string output[]){
    nodes* x;
    nodes* y;
    nodes* z;
    priority_queue <nodes*, vector <nodes*>, compare> queue;
    
	for(int i = 0; i < 6; i++){
        nodes* temp = new nodes(chars[i], frequency[i]);
        queue.push(temp);
    }
    
    while(queue.size() > 1){
        x = queue.top();
        queue.pop();
        y = queue.top();
        queue.pop();
        z = new nodes('\n', x->frequency + y->frequency);
        z->left = x;
        z->right = y;
        queue.push(z);
    }
    
    string s = "";
    print(queue.top(), s, chars, output);
}

int main(){
    int frequency[6];
    string output[6];
    char chars[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	
	for(int i = 0; i < 6; i++){
        cin >> frequency[i];
    }
    
    Huffman(frequency, chars, output);
    
    for(int i = 0; i < 6; i++){
        cout << chars[i] << ":" << output[i] << endl;
    }
    return 0;
}