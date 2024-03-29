class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

		unordered_set<string> st;
		bool isPresent = false; //Checks if endWord is present in Dictionary

		//Insert all words from Dict in set
		for(auto x : wordList){
			if(endWord.compare(x) == 0){
				isPresent = true;
			}
			st.insert(x);
		}

		// If endWord is not present in Dict
		if(isPresent == false){
			return 0;
		}

		queue<string> q;
		q.push(beginWord);
		int depth = 0;

		while(!q.empty()){

			depth += 1;
			int lsize = q.size(); //No of elements at a level

			while(lsize--){

				string curr = q.front();
				q.pop();

				//check for all possible 1 depth words
				for(int i=0 ; i<curr.length() ; i++){ //For each index

					string temp = curr;
					for(char c='a' ; c<='z' ; c++){ //Try all possible chars

						temp[i] = c;

						// Skip the same word
						if(curr.compare(temp) == 0){
							continue;
						}
						//endWord found
						if(temp.compare(endWord) == 0){
							return depth + 1;
						}

						if(st.find(temp) != st.end()){
							q.push(temp);
							st.erase(temp);
						}
					}
				}
			}
		}
		return 0;
	}
};