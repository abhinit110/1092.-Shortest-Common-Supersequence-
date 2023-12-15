class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        int pos1=0,pos2=0;
        int dp[n+1][m+1];
        //return length(text1,text2,n,m);
        for(int i=0;i<n+1;i++)
        dp[i][0]=0;
        for(int i=0;i<m+1;i++)
        dp[0][i]=0;
        for(int i=1;i<n+1;i++)
        for(int j=1;j<m+1;j++)
        {
            if(text1[i-1]==text2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
	
        string w="";
        while(n>0 && m>0)
			{
        if (text1[n-1]==text2[m-1] ) {
            w = text1[n - 1]+w;
			n-=1;
			m-=1;
        } else if (dp[n][m] == dp[n - 1][m])
            n-=1;
        else
		    m-=1;
			}
            cout<<w<<endl;
        int l=w.length();
        int i=0;
        string s=text1.length()>text2.length()?text1:text2;
        if(s==text2)
        {
            text2=text1;
            text1=s;
        }
        string res="";
		while(i<l)
        {
            string w1="";
            for(int j=pos1;j<text2.length();j++)
            {
               if(text2[j]==w[i])
               {
                   pos1=j+1;
                   break;
               }
               else
               {
                   w1+=text2[j];
               }
            }
            for(int j=pos2;j<text1.length();j++)
            {
                if(text1[j]==w[i])
               {
                   pos2=j+1;
                   
                   res+=w1;
                   res+=text1[j];
                   break;
               }
               else
               {
                   res+=text1[j];
               }
            }
            i++;
        }
        for(int j=pos2;j<text1.length();j++)
            {
                res+=text1[j];
            }
        for(int j=pos1;j<text2.length();j++)
            {
                res+=text2[j];
            }
	    return res;
    }
};
