#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#define N_MAX 11
using namespace std;

// Show function�צn�F,flag�ܦn��,�O�o���O�]-1
// �M��ګ�ĳ�A�}�l�Q���˰j��
// �O�o�n�Ҽ{�p�G�j�L�l���b�p�L�l�W�����D,�i�H�z�L�ƧǪ��D
// �ҥH�i�H�إߤ@��Check function �h�����O���O�����W�������D
// �٦��Ҽ{���򱡪p�U�~�O����(�������ȳ��bC,�ӥB�O�Ѥp�ƨ�j)
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
		cout << "****************************     �g   " << endl;
		cout << "********** �e���� **********    �g�g  " << endl;
		cout << "****************************   �g�g�g " << endl<<endl;

//	char opt = 'Y';
//	while (opt == 'Y' ||opt =='y')
//	{
//	�����C������������A��

	
			cout << "�п�J�Q�����L�l�ƶq(�W����10): ";
			cin >> N ;
			cout << endl;
			Beginning(N);
			while(!success)
		{
				Move();
				Show();
				Check();
		}
			cout<< endl<< "�AĹ�{�A�g�g�C" << endl<< "\n�Q�n�A���@���ܡH\n";
			cout<< "�A���@��(Y/N),�Q�ݸԸѽЫ����N��"<<endl;
			
				
				cin >> opt;
				opt = toupper(opt);
		/*
	if (Ĺ�F)
	{
		cout << "�AĹ�{�A�g�g�C" << "\n�Q�n�A���@���ܡH\n";
		cout << "(Y/N): ";
		cin >> opt;
	}

	if (opt == 'N'||opt=='n')
	{
	cout << "\n�A�����4���T���A�o�C���u���ܮ��O�ͩR�C\n���A�֦����n���@�ѡA�t�t�C\n\n";
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
	
		cout << "�n������l: ";
		char towerori;
	
		cin >> towerori;
		towerori = toupper(towerori); //�ন�j�g by BC
		while (towerori != 'A' && towerori != 'B' && towerori != 'C')  //�p�G���O�w�q����l by BC
		{
			cout << "�S���o�ӱ�l���A�ЦA��J�@���C\n";
			cout << "�n������l: ";
			cin >> towerori;
			towerori = toupper(towerori);//�ন�j�g by BC
		}

			cout << "�n�񪺱��: ";
			char towerget;
			cin >> towerget;

			towerget = toupper(towerget);//�N��J���ন�j�g by BC
	
			while (towerget != 'A' && towerget != 'B' && towerget != 'C')  //�p�Guser��J�� ���O�w�q����l by BC
		{
				cout << "�S���o�ӱ�l���A�ЦA��J�@���C\n";
				cout << "�n������l: ";
				cin >> towerget;
				towerget = toupper(towerget);//�N��J���ন�j�g by BC
		}

			int disk;
			disk = Convert(towerori,towerget);
			Check();
			if(error==1)
			{
				disk = Convert(towerget,towerori); //�]���j�L�l��b�p�L�l�W,��^�ө�
				cout<< "���ŦX�e����W�h,���s��J�@���t"<<endl;
				error = 0;
			}
			if(disk != -1)
			cout << "\n�L�l" <<disk << "�ѱ��" << towerori << "���ʨ�F���" << towerget << "�W\n" << endl;
			
}



/*

main�̭���hanoi(N)�o�ˤl��function
���ӬO�ѵ�
int hanoi(int)
{
if (N=1)
return A��C;
else
return N-2��C, N-1��B, N-2��B, N��C, N-2��A, N-1��C, N-2��C
}

*/
int Convert(char from, char to)
{
	int i=0; //�Ψӫ��Xarray��-1����m
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

	return disk; //�O�o�^�Ǥw�g���ʪ��L�l
}

int Check()
{
	int i=0;
	//	check function:
	while(A[i] != -1)
	{
		if(A[i] < A[i+1]) //���լO�_�Ѥj��p�Ƨ� 
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

