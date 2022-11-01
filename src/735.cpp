// id:373924558
// runtime:8 ms
// memory:16.9 MB
// title:Asteroid Collision
// translatedTitle:行星碰撞
// questionId:735
// time:2022-10-17 20:05:35

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