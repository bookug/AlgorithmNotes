void kmpAll(char s[], char t[], int next[], int flag[])  
{  
    int j=0, sLen=strlen(s), tLen=strlen(t);  
    while(i<sLen)  
    {  
        if(j==-1 || s[i]==t[j]){i++; j++;}  
        else j=next[j];  
        if(j==tLen) {flag[i-tLen]=true; j=next[j];}
	}  
}  

void scan(char s[], int flag[])
{
	int invalid = 0, k = 0, i = 0;
	while(i < sLen)
	{
		if(flag[i])
		{
			invalid = tLen;
		}
		if(invalid == 0) s[k++] = s[i];
		else invalid--;
		i++;
	}
	s[k] = '\0';
}

for (index=0;index<len-1;index++)  
{  
	int *next=new int[len-index+1]; //compute 1 more element
	getNext(str+index,next);//start from str+index
	nextMax = max(next);  //find the maximum value of this next array
	if(nextMax>max)  
	{  
		max=nextMax;  
		maxIndex=index;  
	}  
}  

