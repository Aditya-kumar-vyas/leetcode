class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {

         vector<pair<int,int>>v ;
          int n=pos.size() ;
         for(int  i=0;i<n;i++) {
             
             v.push_back({pos[i],i}) ;
         }
        
        sort(v.begin(),v.end()) ;
        
         stack<int>st ;
         
         
         for(int i=0;i<n;i++) {
              int ind=v[i].second ;
               char dir=d[ind] ;
               
               if(dir=='L') 
               {
                  
                    if(st.empty()) {
                       continue ;  
                    }
                   else {
                       
                        if(d[st.top()]=='R' && h[st.top()] ==h[ind]) // when same health
                        {
                             h[st.top()]=0 ;
                             st.pop() ;
                             h[ind]=0 ;
                           
                        }
                       else{ 
                       
                        while(!st.empty() && d[st.top()]=='R' && h[st.top()] < h[ind] )
                        {
                             h[st.top()]=0 ;
                            st.pop();
                            h[ind]--;
                        }
                       
                        if(!st.empty() &&  d[st.top()]=='R' && h[st.top()] > h[ind]) {
                            h[st.top()]--; 
                            h[ind]=0 ;
                        }
                      
                          else  if(!st.empty() &&  d[st.top()]=='R' && h[st.top()] == h[ind]) {
                            h[st.top()]=0; 
                            h[ind]=0 ;
                                st.pop();
                        }
                       else{
                           st.push(ind) ;
                       }
                       }
                        
                   }
               } 
     
             else{
                 st.push(ind) ;     
             }
         }
        
         vector<int>ans;
        
         for(int x:h) {
             if(x >0) ans.push_back(x) ; 
         }
        
         return ans;
         
    }
};