#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#define N_MAX 11
using namespace std;

// Show function修好了,flag很好用,記得都是設-1
// 然後我建議你開始想怎麼弄迴圈
// 記得要考慮如果大盤子壓在小盤子上的問題,可以透過排序知道
// 所以可以建立一個Check function 去測說是不是有換柱換錯問題
// 還有考慮什麼情況下才是完成(全部的值都在C,而且是由小排到大)
// by BC

void Beginning(int);
void Show(void);
void Move(void);
int Check();
void Show_answer();
void hanoi(int n,char A, char B, char C);
int Convert(char from, char to);

int N;
int A[N_MAX]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	B[N_MAX]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	C[N_MAX]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; //-1 for Flags to recongnize the code
int disk;
char from, to;

int error=0,success=0;

int main()
{
	char opt='\0';
	do{
		cout << "\n" << endl;
		cout << "****************************     ▆   " << endl;
		cout << "********** 河內塔 **********    ▆▆  " << endl;
		cout << "****************************   ▆▆▆ " << endl<<endl;

//	char opt = 'Y';
//	while (opt == 'Y' ||opt =='y')
//	{
//	重玩遊戲的部分之後再來

	
			cout << "請輸入想玩的盤子數量(上限為10): ";
			cin >> N ;
			cout << endl;
			Beginning(N);
			while(!success)
		{
				Move();
				Show();
				Check();
		}
			cout<< endl<< "你贏ㄌ，讚讚。" << endl<< "\n想要再玩一次嗎？\n";
			cout<< "再玩一次(Y/N),想看詳解請按任意鍵"<<endl;
			
				
				cin >> opt;
				opt = toupper(opt);
		/*
	if (贏了)
	{
		cout << "你贏ㄌ，讚讚。" << "\n想要再玩一次嗎？\n";
		cout << "(Y/N): ";
		cin >> opt;
	}

	if (opt == 'N'||opt=='n')
	{
	cout << "\n你的選擇4正確的，這遊戲真的很浪費生命。\n祝你擁有美好的一天，ㄅㄅ。\n\n";
	}
	*/}while(opt == 'Y');
	if(opt != 'N' && opt != 'Y')
	{
		Show_answer();
	}

system("pause");
return 0;

}

void Beginning(int N)
{
	cout << "----------- TOWER OF HANOI -----------" << endl;
	cout << "[A]: ";
	
	for (int i=0; i < N;i++)
	{
		if((N-i) != 0) A[i]=N-i;
			cout << " " << A[i] << " ";
		
	}
	cout << endl << "[B]: " << endl;
	cout << "[C]: " << endl;
	cout << "----------- TOWER OF HANOI -----------" << endl;
}


void Show(void)
{
	cout << "----------- TOWER OF HANOI -----------" << endl;
	int i=0;
	cout << "[A]: ";
	while(A[i] != -1) 
	{
		cout<< A[i] << " ";
		i++;
	}
	
	i=0;
	cout<<endl << "[B]: ";
	while(B[i] != -1) 
	{
		cout<< B[i] << " ";
		i++;
	}
	cout << endl;

	i=0;
	cout << "[C]: ";
	while(C[i] != -1) 
	{
		cout<< C[i] << " ";
		i++;
	}
	cout << endl;

	cout << "----------- TOWER OF HANOI -----------" << endl;
}


void Move(void)
{
	
		cout << "要移的桿子: ";
		char towerori;
	
		cin >> towerori;
		towerori = toupper(towerori); //轉成大寫 by BC
		while (towerori != 'A' && towerori != 'B' && towerori != 'C')  //如果不是定義的桿子 by BC
		{
			cout << "沒有這個桿子ㄛ，請再輸入一次。\n";
			cout << "要移的桿子: ";
			cin >> towerori;
			towerori = toupper(towerori);//轉成大寫 by BC
		}

			cout << "要放的桿桿: ";
			char towerget;
			cin >> towerget;

			towerget = toupper(towerget);//將輸入值轉成大寫 by BC
	
			while (towerget != 'A' && towerget != 'B' && towerget != 'C')  //如果user輸入的 不是定義的桿子 by BC
		{
				cout << "沒有這個桿子ㄛ，請再輸入一次。\n";
				cout << "要移的桿子: ";
				cin >> towerget;
				towerget = toupper(towerget);//將輸入值轉成大寫 by BC
		}

			int disk;
			disk = Convert(towerori,towerget);
			Check();
			if(error==1)
			{
				disk = Convert(towerget,towerori); //因為大盤子放在小盤子上,轉回來放
				cout<< "不符合河內塔規則,重新輸入一次ㄅ"<<endl;
				error = 0;
			}
			if(disk != -1)
			cout << "\n盤子" <<disk << "由桿桿" << towerori << "移動到了桿桿" << towerget << "上\n" << endl;
			
}



/*

main裡面有hanoi(N)這樣子的function
應該是解答
int hanoi(int)
{
if (N=1)
return A到C;
else
return N-2到C, N-1到B, N-2到B, N到C, N-2到A, N-1到C, N-2到C
}

*/
int Convert(char from, char to)
{
	int i=0; //用來指出array中-1的位置
	int disk=0;
	switch(from)
	{
		case 'A':
			i=0;
			while(A[i] != -1) i++;
			disk = A[i-1];
			A[i-1] = -1;
			break;
		case 'B':
			i=0;
			while(B[i] != -1) i++;
			disk = B[i-1];
			B[i-1] = -1;
			break;
		case 'C':
			i=0;
			while(C[i]!=-1) i++;
			disk = C[i-1];
			C[i-1] = -1;
			break;
	}

	switch (to)
	{
	case 'A':
		i=0;
		while(A[i]!=-1) i++;
		A[i] = disk;
		break;
	case 'B':
		i=0;
		while(B[i]!=-1) i++;
		B[i] = disk;
		break;
	case 'C':
		i=0;
		while(C[i]!=-1) i++;
		C[i] = disk;
		break;
	default:
		break;
	}

	return disk; //記得回傳已經移動的盤子
}

int Check()
{
	int i=0;
	//	check function:
	while(A[i] != -1)
	{
		if(A[i] < A[i+1]) //測試是否由大到小排序 
			{
				error=1;
				return 0;
		}
		i++;
	}
	i=0; //initialize
	while(B[i] != -1)
	{
		if(B[i] < B[i+1]) 
			{
				error=1;
				return 0;
		}
		i++;
	}
	i=0;//initialize
	
	while(C[i] != -1)
	{
		if(C[i] < C[i+1]) 
			{
				error=1;
				return 0;
		}
				i++;
	}
	//	win function:
	i=0;//initialize
	while(C[i] != -1)
	{
		if( (C[i]>C[i+1])) i++;
	}
	if( i==N ) success=1;
	i=0;
}
void Show_answer()
{
	int n=N;
    char A,B,C;
    hanoi(n,A,B,C);
}
void hanoi(int n,char A, char B, char C)
{
    if(n==1) 
        cout << "Move sheet from " << A << " to " << C << endl; 
    else
    {
        hanoi(n-1,A,C,B);
        hanoi(1,A,B,C);  
        hanoi(n-1,B,A,C);  
    }
}

