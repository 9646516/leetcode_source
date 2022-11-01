// id:373901734
// runtime:16 ms
// memory:17 MB
// title:小行星碰撞
// translatedTitle:小行星碰撞
// questionId:1000281
// time:2022-10-17 19:00:36

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>s;
        for(int i:asteroids){
            if(i>0)s.push_back(i);
            else{
                while(!s.empty()&&s.back()>0&&s.back()<-i)s.pop_back();
                if(s.empty()||s.back()<0){
                    s.push_back(i);
                }else if(s.back()==-i)s.pop_back();
            }
        }
        return s;
    }
};