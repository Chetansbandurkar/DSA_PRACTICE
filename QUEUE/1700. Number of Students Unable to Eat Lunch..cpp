class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i=0;
        queue<int>q;
        int cntz=0,cnto=0;
        for(int i=0;i<students.size();i++) {
            q.push(students[i]);
            if(students[i]==0)cntz++;
            else cnto++;
        }
        while(i<sandwiches.size()){
            if(sandwiches[i]==q.front()){
                if(q.front()==0)cntz--;
                else cnto--;
                q.pop();
                i++;
            }
            else{
                int val=q.front();
                q.push(val);
                q.pop();
                if(sandwiches[i]==0 && cntz==0)return q.size();
                else if(sandwiches[i]==1 && cnto==0)return q.size();
            }
        }

        return 0;
    }
};