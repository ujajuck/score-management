#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <process.h>
#include <ctype.h>
#include <string.h>
#include<windows.h>

struct SCORE
{
	char classname[30]; //�����
	int hakjum, season;  //������ 3������� , ���� �б� 
	char pyung[3]; //a+
	double classscore; // a+�� ���� 4.3���� ���
	char major[6];//�������� ��������

}sugang[60];

void change(struct SCORE *, int i);
void average(struct SCORE *, int cnt);
void compare(struct SCORE *, int cnt);
void comp(struct SCORE *, int cnt);
void main()
{	
	int i=0,j,cnt=0,num=0,k,trush0;
	char put[10],pass[10],ans;
	FILE *fp, *fp1;
main:;
	system("cls");
	printf("\n  �� `�Ϻ��� ���л�Ȱ'�� ���� �������� ���α׷� ^-^ ��\n\n");
	printf("  ������������������������������������\n");
	printf("  ��                                ��\n");
	printf("  ��      �� �� �� ��               ��\n");
	printf("  ��      �� ��й�ȣ ����          ��\n");
	printf("  ��      �� ��й�ȣ �ʱ⼳��	    ��\n");
	printf("  ��        (ó�� �湮�� �ʼ�)      ��\n");
	printf("  ��                                ��\n");
	printf("  ������������������������������������\n\n");
	printf("  �� ���Ͻô� ��ȣ�� �����ϼ��� : ");
	scanf("%d",&k);

	switch(k)
	{
		case 1:
		{
			fp=fopen("password.txt","r");
			fscanf(fp,"%s",pass);
			system("cls");
			printf("�ءء� �� �� �� ȣ �� �� �ءء�\n\n");
			printf(" �� ��й�ȣ�� �Է��ϼ���(��, 3ȸ�̻� Ʋ���� ���α׷��� ����˴ϴ�)\n");
			j=0;
no:;
			printf("  �� ");
			scanf("%s",&put);
			fflush(stdin);
			
			for(i=0;i<10;i++)
			{
				if(pass[i]==put[i]);
				else 
				{
					j++;
					goto no_0;
				}
			}
			fclose(fp);
			system("cls");
			printf("\n               �١ڡ١ڡ١ڡ١�Welcom!!!�١ڡ١ڡ١ڡ١�               \n\n\n");
			goto start;		
no_0:;
			printf("\n ����й�ȣ�� %dȸ �߸� �Է��ϼ̽��ϴ�.��\n",j);
			if(j==3)
			{
				printf("\n\n ���й�ȣ�� �����ϼ̳���? �� �����غ�����Ф� \n   ���α׷��� ����˴ϴ�.\n\n");
				goto out;
			}
			printf(" ����й�ȣ�� �ٽ� Ȯ���ϼ���         ��\n\n");
			goto no;
		}
	
		case 2:
		{
			fp=fopen("password.txt","r");
			fflush(stdin);
			system("cls");
			printf("�ءء� �� �� �� ȣ �� �� �ءء�\n");
re:;
			printf("\n  ��й�ȣ�� �����Ͻðڽ��ϱ�? (y/n) : ");
			scanf("%c",&ans);
			fflush(stdin);
			switch(tolower(ans))
			{
				case 'y':
					{				
						{
							printf("\n  �� �����й�ȣ�� �Է�: ");
							scanf("%s",&put);
							fflush(stdin);
							fscanf(fp,"%s",pass);
							for(i=0;i<10;i++)
								if(pass[i]==put[i]);
								else 
									goto no_1;

							printf("     �Է��Ͻ� ��й�ȣ�� �½��ϴ�.\n\n"); 
							printf("  �� ������ ��й�ȣ�� �Է�: ");
							scanf("%s",pass);
							fflush(stdin);
							fp1=fopen("password.txt","w");								
							fprintf(fp1,"%s",pass);
							fclose(fp1);
							printf("\n ��й�ȣ�� '%s' �� ���Ӱ� �����Ǿ����ϴ�.Ȯ���ϼ���\n",pass);
							printf(" ������ ��й�ȣ�� ��! ����Ͻñ� �ٶ��ϴ�.\n");
							printf("\n�ķα���ȭ������ ���ư��ϴ�. �ƹ� ����Ű�� �����ּ��� ");
							scanf("%d", &trush0);
							system("cls");
							fclose(fp);
							goto main ;							
						}
no_1:;
						printf(" ����й�ȣ�� �����ʽ��ϴ٦�\n");
						printf("  ���й�ȣ�� Ȯ���Ͻð� �����ϼ���.\n\n  4���� �ʱ�ȭ������ ���ư��ϴ�.");
						fclose(fp);
						Sleep(4000);
						goto main;
					}
				case 'n':
					{
						printf("\n  ��й�ȣ�� �������� �ʽ��ϴ�.\n  3���� �ʱ�ȭ������ ���ư��ϴ�.");
						Sleep(3000);				goto main;
					}				

				default :					
					{
						printf("\n �� �߸��� �Է�!\n    y, n �� �� �ٽ� �����ϼ���.\n");
						goto re;				
					}
			}
		}
			case 3:
				{		
					system("cls");
					printf("�ءء� �� �� �� �� �� ȣ �� �� �ءء�\n\n");
					if(num!=0)	//ó�� num=0���� �ΰ� ��й�ȣ ���� �ѹ��ϰ� �Ǹ� num=1�Ǿ� �����Ƿ� �̸� Ȯ���Ͽ� ���� �ʱ� ��й�ȣ ������ ����
					{
						printf("  �� ó�� �湮�� �ƴմϴ�. �ʱ� ��й�ȣ�� ������ �� �����ϴ�.\n");
						printf("     3���� �ʱ�ȭ������ ���ư��ϴ�.");
						Sleep(3000);
						goto main;
					}
					fp=fopen("password.txt","w");
					printf("�����Ͻô� ��й�ȣ�� �����մϴ�.\n\n");
					printf("  �� �� �� �� �� ��\n");
					printf(" 1. ����, ��/������ ���԰���.\n");
					printf(" 2. �ѱ�(2byte)�� �� 5���ڱ��� ����.\n");
					printf(" 3, ���� �� ������(�ҹ���)�� �� 10���ڱ��� ����.\n\n");
					printf(" �� ��й�ȣ �Է� : ");
					scanf("%s" ,pass);
					fflush(stdin);
					fprintf(fp, "%s",pass);
					fclose(fp);
					printf("\n ��й�ȣ�� '%s' �� �����Ǿ����ϴ�.\n",pass);
					printf(" ������ ��й�ȣ�� ��! ����Ͻñ� �ٶ��ϴ�.\n");
					printf("\n�ķα���ȭ������ ���ư��ϴ�. �ƹ� ����Ű�� �����ּ��� ");
					scanf("%d", &trush0);
					num++;
					goto main ;
				}
	}

start:;
	printf("�ءءػ���ϰ��� �ϴ� ��带 �������ּ��� �ءء�\n");
	printf("\n");
	printf("1) ��ǥ ���� ��� : <1> \n");
	printf("2) ���� �Է�, ������� : <2> \n");
	printf("3) �����б� ���� Ȯ��, �񱳸�� : <3> \n");
	printf("4) �������� ���� ������?? : <4> \n");
	printf("5) ���α׷� ���Ḧ ���Ͻø� 0�� �Է����ּ���.\n");
	printf("\n");
	printf(" �� ���� �Է�, ������带 �����Ͻñ� ���� ������ ��ǥ���� ���� ���ֽʽÿ�.\n");
	printf(" ���Ͻô� ��带 �Է��ϼ���<1,2,3,4,0> : ");
	scanf("%d",&num);
	fflush(stdin);

	system("cls");
	switch(num)
	{
		case 1:
			{
				int season2;
				double goalscore;
				int trush;

				FILE *goal;
				goal=fopen("��ǥ.txt","w");
				printf("�̹��б�� ���б� �Դϱ�?(20131,20132)");
				scanf("%d",&season2);

				printf("�̹��б� ���Ͻô� ��ǥ ������ �Է��ϼ��� : ");
				scanf("%lf",&goalscore);

				fprintf(goal,"%d\n",season2);
				fprintf(goal,"%.2lf\n",goalscore);
				fclose(goal);
				printf("\n");
				printf("%d�б� �� ��ǥ�� %.2lf�� �����ϼ̽��ϴ�.\n",season2, goalscore);
				printf("\n");
				printf("�ƹ� ����Ű�� �Է��Ͻø� ���ø��� ���ư��ϴ�. : ");
				scanf("%d", &trush);

				system("cls");

				goto start;
				}
		case 2:
			{
				int num2;
			
				printf("�ءء� �� �� �� ��, �� �� �� �� �ءء�\n");
				printf("\n");
				printf("�Է°����� ������ �ְ� 180������ 60������� �Է� �����մϴ�.\n");
				printf("\n");
				printf("	1) �� �� ��� : <1>\n");
				printf("	2) �� �� ��� : <2>\n");
				printf("\n");
				printf("�� � ��带 ���� �Ͻðڽ��ϱ�?<1,2> : ");
				scanf("%d", &num2);
				system("cls");

				if(num2==1)
				{
						int i=0;
						int trush2;
						char ans;
												
						FILE *input;
						input=fopen("����.txt","a");

						printf("�ءء� �� �� �� �� �� �� �ءء�\n");
						printf("\n");
						printf("�Է��Ͻ� ������ �����, ����, ����, �б�, ���� ������� �Է����ּ���.\n");
						printf("\n");
						printf("ex) C���α׷��ֽǽ�  3 A+ 20131 ����\n");
						printf("    ���ͺ�������� 3 A0 20132 ����\n");
						printf("\n");
						printf("�� �� �� �� �� ��\n");
						printf("   ������ �������� ��������, �б�� 20131 ���ڸ� �Է� \n");
						printf("   ������ ������ ¥������ �Է��ϴ� �κ��Դϴ�. \n");
						printf("   ������ �Է��Ҷ��� ��ĭ�� ����� ���ʽÿ�! \n");
						printf("     ex) ���� ��������� -> ���ͺ�������� \n");
						printf("   ������ A+,A0,A-,B+,D0,F ����� �Է��ϴ� ���Դϴ�. \n");
						printf("\n");
						while(i<60)
						{
							printf("%d��° �Է��Ͻ� ������ �����,����,����(���ĺ�),�б�,�������� ������� �Է� : \n",i+1);
							scanf("%s %d %s %d %s", sugang[i].classname, &sugang[i].hakjum, sugang[i].pyung, &sugang[i].season, sugang[i].major);
							fflush(stdin);
							change(sugang,i);
							fprintf(input,"%-20s %-5d %-5s %-5.1lf %-5d %-5s \n", sugang[i].classname, sugang[i].hakjum, sugang[i].pyung, sugang[i].classscore, sugang[i].season, sugang[i].major);
							i++;
							cnt++;

							printf("��� �Է� �Ͻðڽ��ϱ�?(y/n) : ");
							scanf("%c",&ans);
							fflush(stdin);

							if(tolower(ans)=='n')
								break;
						}
						fclose(input);

						//input=fopen("����.txt","r");

						i=0;
						system("cls");
						printf("                     �� �Էµ� ���� ���� ��   \n");
						printf("==================================================================\n");
						printf(" ����  �б�     �����           ����   ����  ����(����)  �а�����   \n");
						printf("==================================================================\n");
						while(i<cnt)
						{
							printf("  %2d  %6d   %-20s %-4d %-8s %-6.1lf %7s \n",i+1,sugang[i].season, sugang[i].classname, sugang[i].hakjum, sugang[i].pyung, sugang[i].classscore, sugang[i].major);
							i++;
						}
						average(sugang,cnt);

						cnt=0;
						printf("�ƹ� ����Ű�� �Է��Ͻø� ���ø��� ���ư��ϴ�. : ");
						scanf("%d", &trush2);
						system("cls");
						goto start;
					}
				else if(num2==2)
					{
						int i = 0;
						int cnt = 0;
						int trush3;
						int cnum;
						int j;
						FILE *open2;
						FILE *write;
						open2=fopen("����.txt","r");
						printf("�ءء� �� �� �� �� �� �� �ءء�\n");
						printf("\n");
						printf("                    �� ����� ���� ���� ��   \n");
						printf("==================================================================\n");
						printf(" ����  �б�       �����         ����  ����  ����(����)  �а�����   \n");
						printf("==================================================================\n");
						while(!feof(open2)) 
						{
							fscanf(open2,"%s %d %s %lf %d %s \n", sugang[i].classname, &sugang[i].hakjum, sugang[i].pyung, &sugang[i].classscore, &sugang[i].season, sugang[i].major);
							
							cnt++;
							i++;
						}
						i=0;
						while(i<cnt)
						{
							printf("  %2d  %6d   %-20s %-4d %-8s %-6.1lf %7s \n",i+1,sugang[i].season, sugang[i].classname, sugang[i].hakjum, sugang[i].pyung, sugang[i].classscore, sugang[i].major);
							i++;
						}

						fclose(open2);
						printf("\n");
						printf("�����ϰ��� �ϴ� ������ ������ �Է����ּ��� : ");
						scanf("%d", &cnum);

						j=cnum-1;
						printf("�����Ͻ� ������ �����, ����, ����(���ĺ�), �б�, �������� ������� �Է� : \n");
						scanf("%s %d %s %d %s", sugang[j].classname, &sugang[j].hakjum, sugang[j].pyung, &sugang[j].season, sugang[j].major);
						change(sugang,j);
						system("cls");

						printf("                    �� ������ ���� ���� ��   \n");
						printf("==================================================================\n");
						printf(" ����  �б�       �����         ����  ����  ����(����)  �а�����   \n");
						printf("==================================================================\n");
						i=0;
						while(i<cnt)
						{
							printf("  %2d  %6d   %-20s %-4d %-8s %-6.1lf %7s \n",i+1,sugang[i].season, sugang[i].classname, sugang[i].hakjum, sugang[i].pyung, sugang[i].classscore, sugang[i].major);
							i++;
						}
						
						write=fopen("����.txt", "w");
						i=0;
						while(i<cnt)
						{
							fprintf(write,"%-20s %-5d %-5s %-5.1lf %-5d %-5s \n", sugang[i].classname, sugang[i].hakjum, sugang[i].pyung, sugang[i].classscore, sugang[i].season, sugang[i].major);
							i++;
						}

						fclose(write);
						printf("\n");
						printf("�ƹ� ����Ű�� �Է��Ͻø� ���ø��� ���ư��ϴ�. : ");
						scanf("%d", &trush3);
						system("cls");
						goto start;	
				}
				
			}
		case 3:
			{
				int i=0;
				int cnt=0;
				int trush4;
				FILE *open3;
				open3=fopen("����.txt","r");

				while(!feof(open3)) 
				{
					fscanf(open3,"%s %d %s %lf %d %s \n", sugang[i].classname, &sugang[i].hakjum, sugang[i].pyung, &sugang[i].classscore, &sugang[i].season, sugang[i].major);				
					cnt++;
					i++;
				}
				fclose(open3);

				printf("�ءء� �� �� �� Ȯ ��, �� �� �� �� �ءء�\n");
				printf("\n");
				printf("==================================================================\n");
				printf(" ����  �б�       �����         ����  ����  ����(����)  �а�����   \n");
				printf("==================================================================\n");
				i=0;
				while(i<cnt)
						{
							printf("  %2d  %6d   %-20s %-4d %-8s %-6.1lf %7s \n",i+1,sugang[i].season, sugang[i].classname, sugang[i].hakjum, sugang[i].pyung, sugang[i].classscore, sugang[i].major);
							i++;
						}
				printf("==================================================================\n");				
				compare(sugang, cnt);
				comp(sugang, cnt);
				printf("\n");
				printf("�ƹ� ����Ű�� �Է��Ͻø� ���ø��� ���ư��ϴ�. : ");
				scanf("%d", &trush4);
				system("cls");
				goto start;	
				
			}
		case 4:
			{		
				int tothak=0,major=0,other=0,i=0,trush4,cnt=0,refine=0;
				FILE *open4;
				open4=fopen("����.txt","r");

				while(!feof(open4)) 
				{
					fscanf(open4,"%s %d %s %lf %d %s \n", sugang[i].classname, &sugang[i].hakjum, sugang[i].pyung, &sugang[i].classscore, &sugang[i].season, sugang[i].major);				
					cnt++;
					i++;
				}
				fclose(open4);
				for(i=0;i<cnt;i++)
				{
					tothak = tothak + sugang[i].hakjum;
					if(strcmp(sugang[i].major,"����") == 0) 
						major+=sugang[i].hakjum;
				}
				other=tothak-major-refine;
				printf("        �ءء� �� �� �� �� �� �� �� �� �� �� �ءء�\n\n");
				printf("   ======================================================\n");
				printf("  ��                       �� ������   ����  ����  ��Ÿ ��\n");
				printf("   ======================================================\n");
				printf("  ��        ��������       ��   140     88    18    34  ��\n");
				printf("   ======================================================\n");
				printf("  ��  ���ݱ��� �Էµ� ���� ��  %4d  %5d  %4d  %4d  ��\n",tothak,major,refine, other);
				printf("   ======================================================\n");
				printf("  ��   �������� ���� ����  ��  %4d  %5d  %4d  %4d  ��\n",(140-tothak),(88-major),(18-refine),(34-other));
				printf("   ======================================================\n\n");
				printf("  �ƹ� ����Ű�� �Է��Ͻø� ���ø��� ���ư��ϴ�. ");
				scanf("%d", &trush4);
				system("cls");
				goto start;	
			}
		default:
				exit(1);
			
	}
	out:;
}
void comp(struct SCORE *sugang, int cnt)
{
	int i=0;
	int j=0;
	int k=0;
	int shakki[12];
	double hakkipyung[12]={0};
	double avrpyung[12]={0};
	int hak[12]={0};
	double baekpyung[12]={0};
	char ans;
	printf("\n");
	printf("�ִ� ���Ҽ� �ִ� �б�� 12�б� �Դϴ�.\n ");
	printf("�Է��� 2013�� 1�б��� ���ڷ� 20131�� �Է����ּ���.\n ");
	for(i=0;i<12;i++)
	{
		printf("���Ͻ� �б�� �� �б� �ʴϱ�? : ");
		scanf("%d",&shakki[i]);
		fflush(stdin);
		printf("��� �Է��Ͻðڽ��ϱ�?(y/n)");
		scanf("%c",&ans);
		fflush(stdin);
		j++;
		if(ans=='n')
			break;
	}
	
	for(k=0;k<j;k++)
	{
		i=0;
		while(i<cnt)
		{
			if(sugang[i].season == shakki[k])
			{
				hakkipyung[k] = hakkipyung[k] + (sugang[i].classscore*sugang[i].hakjum);
				hak[k] = hak[k] + sugang[i].hakjum;
			}
			i++;
		}
	}

	for(i=0;i<j;i++)
	{
		avrpyung[i] = hakkipyung[i]/hak[i];
		baekpyung[i] = ((avrpyung[i]/4.3)*100)/5;
	}
	system("cls");
	
	i=0;  
	printf("          ��  �б⺰ ���� �׷��� �� \n");
	printf("\n");
	printf("   ==========================================\n");
	while(i<j)
	{
		printf("   �� %d �б� : ",shakki[i]);
		for(k=0;k<baekpyung[i];k++)
		{
			printf("*");
		}
		printf(" (%.2lf)\n", avrpyung[i]); 
		i++;
	}
	printf("   ==========================================\n");

}

void compare(struct SCORE *sugang, int cnt)
{
	int i=0;
	double average=0;
	double total=0;
	int tothak=0;
	int hakki=0;

	for(i=0;i<cnt;i++)
	{
			tothak = tothak + sugang[i].hakjum;
			total = total + (sugang[i].classscore * sugang[i].hakjum);
	}
	average = total/tothak;
	printf("���ݱ��� �Էµ� �� ���� : %d \n", tothak);
	printf("���ݱ��� �Էµ� ������ �� ��� : %.2lf \n", average);
}

void average(struct SCORE *sugang, int cnt)
{
	int i=0;
	double average = 0;
	double total = 0;
	int tothak = 0;
	double goals=0;
	int hakki=0;
	double ggg=0;
	FILE *open;
	for(i=0;i<cnt;i++)
		{
			tothak = tothak + sugang[i].hakjum;
			total = total + (sugang[i].classscore * sugang[i].hakjum);
		}
	
	average = total/tothak;
	printf("------------------------------------------------------------------\n");
	printf("�Էµ� �� ���� : %d \n", tothak);
	printf("�Էµ� ������ ��� : %.2lf \n", average);

	open=fopen("��ǥ.txt","r");
	fscanf(open, "%d \n %lf", &hakki,&ggg);
	goals = (average/ggg)*100;
	printf("%d �б� ��ǥ �޼� ���� : %.2lf %% \n", hakki , goals);
	if(goals>=100)
	{
		printf("��ǥ�� �޼� �ϼ̳׿�!!! ���ϵ帳�ϴ٢����� \n\a\a\a\a\a\a\a\a\a\a\a\a\a\a");
	}
	else if((goals>=70)&&(goals<100))
	{
		printf("���� �����ϳ׿�!!! ���ݴ� ����ϼ���!! \n");
	}
	else if(goals<70)
	{
		printf("�����ض�!! ���ž�!!! \n");
	}
	printf("\n");
}

void change(struct SCORE *sugang, int i)
{

	if((strcmp(sugang[i].pyung,"A+") == 0) || (strcmp(sugang[i].pyung,"a+") == 0))
	{ 
		sugang[i].classscore = 4.3;
	}
	else if((strcmp(sugang[i].pyung,"A0") == 0) || (strcmp(sugang[i].pyung,"a0") == 0))
	{ 
		sugang[i].classscore = 4.0;
	}
	else if((strcmp(sugang[i].pyung,"A-") == 0) || (strcmp(sugang[i].pyung,"a-") == 0))
	{ 
		sugang[i].classscore = 3.7;
	}
	else if((strcmp(sugang[i].pyung,"B+") == 0) || (strcmp(sugang[i].pyung,"b+") == 0))
	{ 
		sugang[i].classscore = 3.3;
	}
	else if((strcmp(sugang[i].pyung,"B0") == 0) || (strcmp(sugang[i].pyung,"b0") == 0))
	{ 
		sugang[i].classscore = 3.0;
	}
	else if((strcmp(sugang[i].pyung,"B-") == 0) || (strcmp(sugang[i].pyung,"b-") == 0))
	{ 
		sugang[i].classscore = 2.7;
	}
	else if((strcmp(sugang[i].pyung,"C+") == 0) || (strcmp(sugang[i].pyung,"c+") == 0))
	{ 
		sugang[i].classscore = 2.3;
	}
	else if((strcmp(sugang[i].pyung,"C0") == 0) || (strcmp(sugang[i].pyung,"c0") == 0))
	{ 
		sugang[i].classscore = 2.0;
	}
	else if((strcmp(sugang[i].pyung,"C-") == 0) || (strcmp(sugang[i].pyung,"c-") == 0))
	{ 
		sugang[i].classscore = 1.7;
	}	
	else if((strcmp(sugang[i].pyung,"D+") == 0) || (strcmp(sugang[i].pyung,"d+") == 0))
	{ 
		sugang[i].classscore = 1.3;
	}	
	else if((strcmp(sugang[i].pyung,"D0") == 0) || (strcmp(sugang[i].pyung,"d0") == 0))
	{ 
		sugang[i].classscore = 1.0;
	}
	else if((strcmp(sugang[i].pyung,"D-") == 0) || (strcmp(sugang[i].pyung,"d-") == 0))
	{ 
		sugang[i].classscore = 0.7;
	}	
	else if((strcmp(sugang[i].pyung,"F") == 0) || (strcmp(sugang[i].pyung,"f") == 0))
	{
		sugang[i].classscore = 0;
	}
}