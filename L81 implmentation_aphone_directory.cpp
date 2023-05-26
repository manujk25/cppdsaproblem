//Code MANUJ KUMAR YADAV
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }
  //for insertion

    void insertUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assumption: Lowercase letters only
        int index = word[0] - 'a';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    //Print Suggestion Function ke Liye ye kaam toh krna Padega 

    void printSuggestion(TrieNode* curr,vector<string> & temp,string prefix){
         if(curr->isTerminal){
             temp.push_back(prefix);
         }
         for(char ch ='a';ch<='z';ch++){
             TrieNode* next = curr->children[ch-'a'];

             if(next != NULL){
                 prefix.push_back(ch);
                 printSuggestion(next,temp,prefix);
                 prefix.pop_back();
             }
         }
    }

    vector<vector<string>>getSuggestion(string str){
        TrieNode* prev = root;
        vector<vector<string> > output;
        string prefix = "";

        for(int i =0;i<str.size();i++){
            char lastch = str[i];

            prefix.push_back(lastch);
            //check for Lastch

            TrieNode* curr = prev->children[lastch - 'a'];


            

            //if not found 
            if(curr == NULL){
                break;
            }else{
                vector<string> temp;
                printSuggestion(curr,temp,prefix);
                output.push_back(temp);
                temp.clear();
                prev = curr;
            }
        }
        return output;

    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    // create a Trie
    Trie* t = new Trie();


    //insert All Contact In Tries
    for(int i=0;i<contactList.size();i++){
        t->insertWord(contactList[i]);
    }
    return t->getSuggestion(queryStr);
}
