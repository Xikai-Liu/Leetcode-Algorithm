class Solution {
public:
    int tot;
    bool v[11111];
    int next[1111111],poi[1111111],head[11111],Q[111111],ind[111111];
    void Add(int x,int y){
        tot++; poi[tot]=y; next[tot]=head[x]; head[x]=tot; 
    }
    void Bfs(int x){
        int h=0; int t=1; Q[t]=x; ind[x]--; v[x]=true;
        while (h!=t){
            h++;
            int i=head[Q[h]];
            while (i!=0){
                int y=poi[i]; ind[y]--; 
                if (ind[y]==0){t++;Q[t]=y;v[y]=true;}
                i=next[i];
            }
        }
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        tot=0; memset(v,0,sizeof(v)); memset(ind,0,sizeof(ind));
        memset(next,0,sizeof(next));memset(poi,0,sizeof(poi));memset(head,0,sizeof(head));
        for (int i=0;i<prerequisites.size();i++){
            Add(prerequisites[i].second,prerequisites[i].first);
            ind[prerequisites[i].first]++; 
        }
        for (int i=0;i<numCourses;i++)if (ind[i]==0 && v[i]==false){Bfs(i);}
        //return v[1];
        for (int i=0;i<numCourses;i++)if (v[i]==false) return false;
        return true;
    }
};