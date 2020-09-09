/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {        
        set<pair<int, int>> obs;
        for(int i=0;i<obstacles.size();++i) {
            pair<int,int> ob(obstacles[i][0], obstacles[i][1]);
            obs.insert(ob);
        }
        pair<int, int> curPos(0,0);
        int dis=0, dir(0);//North
        int dirX[] = {0,1,0,-1}, dirY[] = {1,0,-1,0};//trick
        for(int i=0;i<commands.size();++i) {
            if(commands[i]==-1) { dir=(dir+1)%4; }
            else if(commands[i]==-2) { dir=(dir+3)%4; }
            else {
                for(int j=1;j<=commands[i];++j) {
                    pair<int, int> nextPos(curPos.first+dirX[dir], curPos.second+dirY[dir]);
                    if(obs.find(nextPos)!=obs.end()){ 
                        break; 
                    } else {
                        curPos=nextPos;
                        int curDis=curPos.first*curPos.first + curPos.second*curPos.second;
                        dis=max(dis, curDis);
                    }
                }
            }
        }
        return dis;
    }
};
// @lc code=end

