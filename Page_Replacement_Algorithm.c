 #include<stdio.h>
 void FIFO(int prs[], int n, int frame);
 void LRU(int prs[], int n, int frame);
 int findLRU(int time[], int n);
 void LFU(int prs[], int n, int frame);
 
 void print(int [],int);
 
 void main()
 {
	 int n,i,frame,ch;
	 printf("Enter the Length of sequence : ");
	 scanf("%d",&n);
	 int prs[n];
	 printf("Enter the Sequence : ");
	 for(i=0;i<n;i++)
		 scanf("%d",&prs[i]);
	 printf("Enter the number of frame : ");
	 scanf("%d",&frame);
	 do
	 {
		 printf("\n------Page Replacement Algorithm------\n1.FIFO\t2.LRU\t3.LFU\t4.Exit\nEnter your Choice : ");
		 scanf("%d",&ch);
		 switch(ch)
		{
			 case 1:{
				 		printf("\n\n->FIFO Page Replacement Algorithm\n");
				 		FIFO(prs,n,frame); 
						printf("\n");
						break;
					}
			 case 2:{
				 		printf("\n\n->LRU Page Replacement Algorithm\n");
					 	LRU(prs,n,frame); 
				 		printf("\n");
				 		break;
					}
			 case 3:{
						printf("\n\n->LFU Page Replacement Algorithm\n");
						LFU(prs,n,frame); 
						printf("\n");
				 		break;
					}
			 case 4: break;
			 default: printf("\nInvalid Option!!!\n"); break;
		}
		 
	}while(ch!=4);
 }
 
 void FIFO(int prs[], int n, int frame)
	 {
		 int pagefault = 0, hit=0,k=0,i,j,s,flag=0;
		 int temp[frame];
		 printf("\nValues\t");
		 for(i=1;i<=frame;i++)
			 printf("Frame%d\t",i);
		 printf("\n");
		 for(i= 0; i< frame; i++)
		 {
			 temp[i] = -1;
		 }
		 
		 for(i= 0; i< n; i++)
		 {
			 s = 0;
			 printf("\n%d=>\t",prs[i]);
			 for(j = 0; j < frame; j++)
			 {
				 if(temp[j]==prs[i])
					 s = 1;
			 }
			 if(s == 0)
			 {
				 temp[k] = prs[i];
				 k = (k+1)%frame;
				 pagefault++;
				 for(j = 0; j < frame; j++)
				 {
					 if(temp[j]!=-1)
						 printf("%d\t",temp[j]);
				 }
				 
			 }
			 else
				 printf("\tHit!!!"); 
		 } 
		 printf("\nTotal Page Faults: %d\n", pagefault);
 }
 
//LRU Starts
 void LRU(int pg[], int n, int f)
 {
	 
	 int frames[f], counter = 0, time[10], flag1, flag2, i, j, pos, pagefault = 0;
	 printf("\nValues\t");
	 for(i=1;i<=f;i++)
		 printf("Frame%d\t",i);
	 printf("\n");
	 for(i = 0; i < f; i++)
	 {
		 frames[i] = -1;
	 }
	 
	 for(i = 0; i < n; i++)
	 {
		 flag1 = flag2 = 0;
		 printf("%d =>\t",pg[i]);
		 for(j = 0; j < f; j++)
		 {
			 if(frames[j] == pg[i])
			 {
				 counter++;
				 time[j] = counter;
				 flag1 = flag2 = 1;
				 printf("\tHit!!!\n");
				 break;
			 }
		 }
		 
		 if(flag1 == 0)
		 {
			 for(j = 0; j < f; j++ )
			 {
				 if(frames[j] == -1)
				 {
					 counter++;
					 pagefault++;
					 frames[j] = pg[i];
					 time[j] = counter;
					 flag2 = 1;
					 print(frames,f);
					 break;
				 }
			 }    
		 }
		 
		 if(flag2 == 0)
		 {
			 pos = findLRU(time, f);
			 counter++;
			 pagefault++;
			 frames[pos] = pg[i];
			 time[pos] = counter;
			 print(frames,f);
			 
		 }
		 
		 
	 }
	 
	 printf("\n\nTotal Page Fault = %d\n", pagefault);
 }
 
 int findLRU(int time[], int n)
 {
	 int i, minimum = time[0], pos = 0;
	 
	 for(i = 1; i < n; i++)
	 {
		 if(time[i] < minimum)
		 {
			 minimum = time[i];
			 pos = i;
		 }
	 }
	 
	 return pos;
 }
 
//LFU
 void LFU(int pr[], int n, int f)
 {
	 int pagefault = 0, i,j,freq[n],minimum,index,flag=0,frames[n],pos=0;
	 printf("\nValues\t");
	 for(i=1;i<=f;i++)
		 printf("Frame%d\t",i);
	 printf("\n");
	 for(i=0;i<n;i++)
		 frames[i]=-1;
	 for(i=0;i<n;i++)
	 {
		//printf("\n");
		 printf("%d =>\t",pr[i]);
		 flag=0;
		 for(j=0;j<n;j++)
		 {
			 if(pr[i]==frames[j])
			 {
				 flag = 1;
				 freq[j]++;
				 printf("\t Hit!!!\n");
				 break;
			 }
		 }
		 if(flag==0 && pagefault<f)
		 {
			 frames[pos]=pr[i];
			 freq[pos]=1;
			 pos = (pos+1)%f;
			 pagefault++;
			 print(frames,f);
		 }
		 else if(flag==0)
		 {
			 index = 0;
			 minimum = freq[0];
			 for(j=1;j<f;j++)
			 {
				 if(freq[j]<minimum)
				 {
					 index=j;
					 minimum = freq[j];
				 }	
			 }
			 frames[index]=pr[i];
			 freq[index]=1;
			 pagefault++;
			 print(frames,f);
		 }
	 }
	 printf("Total Page Faults : %d\n",pagefault);
 }
 
 void print(int frames[], int f)
 {
	 int j;
	 for(j=0;j<f;j++)
	 {	
		 if(frames[j]!=-1)
			 printf("%d\t",frames[j]);
		 else
			 printf("\t");
	 }
	 printf("\n");
 }
 
