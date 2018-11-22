#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <process.h>
#include <ctype.h>
#include <string.h>
#include<windows.h>

struct SCORE
{
	char classname[30]; //과목명
	int hakjum, season;  //학점은 3학점등등 , 시즌 학기 
	char pyung[3]; //a+
	double classscore; // a+에 대한 4.3점수 등등
	char major[6];//전공인지 교양인지

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
	printf("\n  ◐ `완벽한 대학생활'을 위한 학점관리 프로그램 ^-^ ◑\n\n");
	printf("  ┏━━━━━━━━━━━━━━━━┓\n");
	printf("  ┃                                ┃\n");
	printf("  ┃      ① 로 그 인               ┃\n");
	printf("  ┃      ② 비밀번호 변경          ┃\n");
	printf("  ┃      ③ 비밀번호 초기설정	    ┃\n");
	printf("  ┃        (처음 방문시 필수)      ┃\n");
	printf("  ┃                                ┃\n");
	printf("  ┗━━━━━━━━━━━━━━━━┛\n\n");
	printf("  ▶ 원하시는 번호를 선택하세요 : ");
	scanf("%d",&k);

	switch(k)
	{
		case 1:
		{
			fp=fopen("password.txt","r");
			fscanf(fp,"%s",pass);
			system("cls");
			printf("※※※ 비 밀 번 호 입 력 ※※※\n\n");
			printf(" ▶ 비밀번호를 입력하세요(단, 3회이상 틀릴시 프로그램이 종료됩니다)\n");
			j=0;
no:;
			printf("  ☞ ");
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
			printf("\n               ☆★☆★☆★☆★Welcom!!!☆★☆★☆★☆★               \n\n\n");
			goto start;		
no_0:;
			printf("\n │비밀번호를 %d회 잘못 입력하셨습니다.│\n",j);
			if(j==3)
			{
				printf("\n\n √비밀번호를 깜빡하셨나요? 잘 생각해보세요ㅠㅠ \n   프로그램이 종료됩니다.\n\n");
				goto out;
			}
			printf(" │비밀번호를 다시 확인하세요         │\n\n");
			goto no;
		}
	
		case 2:
		{
			fp=fopen("password.txt","r");
			fflush(stdin);
			system("cls");
			printf("※※※ 비 밀 번 호 변 경 ※※※\n");
re:;
			printf("\n  비밀번호를 변경하시겠습니까? (y/n) : ");
			scanf("%c",&ans);
			fflush(stdin);
			switch(tolower(ans))
			{
				case 'y':
					{				
						{
							printf("\n  ▶ 현재비밀번호를 입력: ");
							scanf("%s",&put);
							fflush(stdin);
							fscanf(fp,"%s",pass);
							for(i=0;i<10;i++)
								if(pass[i]==put[i]);
								else 
									goto no_1;

							printf("     입력하신 비밀번호가 맞습니다.\n\n"); 
							printf("  ▶ 변경할 비밀번호를 입력: ");
							scanf("%s",pass);
							fflush(stdin);
							fp1=fopen("password.txt","w");								
							fprintf(fp1,"%s",pass);
							fclose(fp1);
							printf("\n 비밀번호가 '%s' 로 새롭게 설정되었습니다.확인하세요\n",pass);
							printf(" 설정한 비밀번호를 꼭! 기억하시기 바랍니다.\n");
							printf("\n∞로그인화면으로 돌아갑니다. 아무 숫자키를 눌러주세요 ");
							scanf("%d", &trush0);
							system("cls");
							fclose(fp);
							goto main ;							
						}
no_1:;
						printf(" │비밀번호가 맞지않습니다│\n");
						printf("  √비밀번호를 확인하시고 변경하세요.\n\n  4초후 초기화면으로 돌아갑니다.");
						fclose(fp);
						Sleep(4000);
						goto main;
					}
				case 'n':
					{
						printf("\n  비밀번호를 변경하지 않습니다.\n  3초후 초기화면으로 돌아갑니다.");
						Sleep(3000);				goto main;
					}				

				default :					
					{
						printf("\n ⇒ 잘못된 입력!\n    y, n 둘 중 다시 선택하세요.\n");
						goto re;				
					}
			}
		}
			case 3:
				{		
					system("cls");
					printf("※※※ 초 기 비 밀 번 호 설 정 ※※※\n\n");
					if(num!=0)	//처음 num=0으로 두고 비밀번호 설정 한번하게 되면 num=1되어 있으므로 이를 확인하여 재차 초기 비밀번호 설정을 막음
					{
						printf("  ▶ 처음 방문이 아닙니다. 초기 비밀번호를 설정할 수 없습니다.\n");
						printf("     3초후 초기화면으로 돌아갑니다.");
						Sleep(3000);
						goto main;
					}
					fp=fopen("password.txt","w");
					printf("＊원하시는 비밀번호를 설정합니다.\n\n");
					printf("  ★ 주 의 사 항 ★\n");
					printf(" 1. 숫자, 한/영문자 포함가능.\n");
					printf(" 2. 한글(2byte)는 총 5글자까지 가능.\n");
					printf(" 3, 숫자 및 영문자(소문자)는 총 10글자까지 가능.\n\n");
					printf(" ☞ 비밀번호 입력 : ");
					scanf("%s" ,pass);
					fflush(stdin);
					fprintf(fp, "%s",pass);
					fclose(fp);
					printf("\n 비밀번호가 '%s' 로 설정되었습니다.\n",pass);
					printf(" 설정한 비밀번호를 꼭! 기억하시기 바랍니다.\n");
					printf("\n∞로그인화면으로 돌아갑니다. 아무 숫자키를 눌러주세요 ");
					scanf("%d", &trush0);
					num++;
					goto main ;
				}
	}

start:;
	printf("※※※사용하고자 하는 모드를 선택해주세요 ※※※\n");
	printf("\n");
	printf("1) 목표 설정 모드 : <1> \n");
	printf("2) 성적 입력, 수정모드 : <2> \n");
	printf("3) 지난학기 성적 확인, 비교모드 : <3> \n");
	printf("4) 졸업까지 남은 학점은?? : <4> \n");
	printf("5) 프로그램 종료를 원하시면 0을 입력해주세요.\n");
	printf("\n");
	printf(" → 성적 입력, 수정모드를 실행하시기 전에 무조건 목표설정 먼저 해주십시오.\n");
	printf(" 원하시는 모드를 입력하세요<1,2,3,4,0> : ");
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
				goal=fopen("목표.txt","w");
				printf("이번학기는 몇학기 입니까?(20131,20132)");
				scanf("%d",&season2);

				printf("이번학기 원하시는 목표 평점을 입력하세요 : ");
				scanf("%lf",&goalscore);

				fprintf(goal,"%d\n",season2);
				fprintf(goal,"%.2lf\n",goalscore);
				fclose(goal);
				printf("\n");
				printf("%d학기 의 목표를 %.2lf로 설정하셨습니다.\n",season2, goalscore);
				printf("\n");
				printf("아무 숫자키를 입력하시면 선택모드로 돌아갑니다. : ");
				scanf("%d", &trush);

				system("cls");

				goto start;
				}
		case 2:
			{
				int num2;
			
				printf("※※※ 성 적 입 력, 수 정 모 드 ※※※\n");
				printf("\n");
				printf("입력가능한 성적은 최고 180점으로 60과목까지 입력 가능합니다.\n");
				printf("\n");
				printf("	1) 입 력 모드 : <1>\n");
				printf("	2) 수 정 모드 : <2>\n");
				printf("\n");
				printf("■ 어떤 모드를 선택 하시겠습니까?<1,2> : ");
				scanf("%d", &num2);
				system("cls");

				if(num2==1)
				{
						int i=0;
						int trush2;
						char ans;
												
						FILE *input;
						input=fopen("성적.txt","a");

						printf("※※※ 성 적 입 력 모 드 ※※※\n");
						printf("\n");
						printf("입력하실 성적의 과목명, 학점, 평점, 학기, 전공 순서대로 입력해주세요.\n");
						printf("\n");
						printf("ex) C프로그래밍실습  3 A+ 20131 전공\n");
						printf("    논리와비판적사고 3 A0 20132 교양\n");
						printf("\n");
						printf("★ 주 의 사 항 ★\n");
						printf("   전공은 전공인지 교양인지, 학기는 20131 숫자만 입력 \n");
						printf("   학점은 몇학점 짜리인지 입력하는 부분입니다. \n");
						printf("   과목을 입력할때는 빈칸을 띄우지 마십시오! \n");
						printf("     ex) 논리와 비판적사고 -> 논리와비판적사고 \n");
						printf("   평점은 A+,A0,A-,B+,D0,F 등등을 입력하는 란입니다. \n");
						printf("\n");
						while(i<60)
						{
							printf("%d번째 입력하실 성적의 과목명,학점,평점(알파벳),학기,전공유무 순서대로 입력 : \n",i+1);
							scanf("%s %d %s %d %s", sugang[i].classname, &sugang[i].hakjum, sugang[i].pyung, &sugang[i].season, sugang[i].major);
							fflush(stdin);
							change(sugang,i);
							fprintf(input,"%-20s %-5d %-5s %-5.1lf %-5d %-5s \n", sugang[i].classname, sugang[i].hakjum, sugang[i].pyung, sugang[i].classscore, sugang[i].season, sugang[i].major);
							i++;
							cnt++;

							printf("계속 입력 하시겠습니까?(y/n) : ");
							scanf("%c",&ans);
							fflush(stdin);

							if(tolower(ans)=='n')
								break;
						}
						fclose(input);

						//input=fopen("성적.txt","r");

						i=0;
						system("cls");
						printf("                     ▶ 입력된 과목별 성적 ◀   \n");
						printf("==================================================================\n");
						printf(" 순번  학기     과목명           학점   평점  평점(숫자)  학과구분   \n");
						printf("==================================================================\n");
						while(i<cnt)
						{
							printf("  %2d  %6d   %-20s %-4d %-8s %-6.1lf %7s \n",i+1,sugang[i].season, sugang[i].classname, sugang[i].hakjum, sugang[i].pyung, sugang[i].classscore, sugang[i].major);
							i++;
						}
						average(sugang,cnt);

						cnt=0;
						printf("아무 숫자키를 입력하시면 선택모드로 돌아갑니다. : ");
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
						open2=fopen("성적.txt","r");
						printf("※※※ 성 적 수 정 모 드 ※※※\n");
						printf("\n");
						printf("                    ▶ 저장된 과목별 성적 ◀   \n");
						printf("==================================================================\n");
						printf(" 순번  학기       과목명         학점  평점  평점(숫자)  학과구분   \n");
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
						printf("수정하고자 하는 과목의 순번을 입력해주세요 : ");
						scanf("%d", &cnum);

						j=cnum-1;
						printf("수정하실 성적의 과목명, 학점, 평점(알파벳), 학기, 전공유무 순서대로 입력 : \n");
						scanf("%s %d %s %d %s", sugang[j].classname, &sugang[j].hakjum, sugang[j].pyung, &sugang[j].season, sugang[j].major);
						change(sugang,j);
						system("cls");

						printf("                    ▶ 수정된 과목별 성적 ◀   \n");
						printf("==================================================================\n");
						printf(" 순번  학기       과목명         학점  평점  평점(숫자)  학과구분   \n");
						printf("==================================================================\n");
						i=0;
						while(i<cnt)
						{
							printf("  %2d  %6d   %-20s %-4d %-8s %-6.1lf %7s \n",i+1,sugang[i].season, sugang[i].classname, sugang[i].hakjum, sugang[i].pyung, sugang[i].classscore, sugang[i].major);
							i++;
						}
						
						write=fopen("성적.txt", "w");
						i=0;
						while(i<cnt)
						{
							fprintf(write,"%-20s %-5d %-5s %-5.1lf %-5d %-5s \n", sugang[i].classname, sugang[i].hakjum, sugang[i].pyung, sugang[i].classscore, sugang[i].season, sugang[i].major);
							i++;
						}

						fclose(write);
						printf("\n");
						printf("아무 숫자키를 입력하시면 선택모드로 돌아갑니다. : ");
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
				open3=fopen("성적.txt","r");

				while(!feof(open3)) 
				{
					fscanf(open3,"%s %d %s %lf %d %s \n", sugang[i].classname, &sugang[i].hakjum, sugang[i].pyung, &sugang[i].classscore, &sugang[i].season, sugang[i].major);				
					cnt++;
					i++;
				}
				fclose(open3);

				printf("※※※ 총 성 적 확 인, 비 교 모 드 ※※※\n");
				printf("\n");
				printf("==================================================================\n");
				printf(" 순번  학기       과목명         학점  평점  평점(숫자)  학과구분   \n");
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
				printf("아무 숫자키를 입력하시면 선택모드로 돌아갑니다. : ");
				scanf("%d", &trush4);
				system("cls");
				goto start;	
				
			}
		case 4:
			{		
				int tothak=0,major=0,other=0,i=0,trush4,cnt=0,refine=0;
				FILE *open4;
				open4=fopen("성적.txt","r");

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
					if(strcmp(sugang[i].major,"전공") == 0) 
						major+=sugang[i].hakjum;
				}
				other=tothak-major-refine;
				printf("        ※※※ 졸 업 까 지 남 은 학 점 계 산 ※※※\n\n");
				printf("   ======================================================\n");
				printf("  ∥                       ∥ 총학점   전공  교양  기타 ∥\n");
				printf("   ======================================================\n");
				printf("  ∥        졸업학점       ∥   140     88    18    34  ∥\n");
				printf("   ======================================================\n");
				printf("  ∥  지금까지 입력된 학점 ∥  %4d  %5d  %4d  %4d  ∥\n",tothak,major,refine, other);
				printf("   ======================================================\n");
				printf("  ∥   졸업까지 남은 학점  ∥  %4d  %5d  %4d  %4d  ∥\n",(140-tothak),(88-major),(18-refine),(34-other));
				printf("   ======================================================\n\n");
				printf("  아무 숫자키를 입력하시면 선택모드로 돌아갑니다. ");
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
	printf("최대 비교할수 있는 학기는 12학기 입니다.\n ");
	printf("입력은 2013년 1학기라면 숫자로 20131를 입력해주세요.\n ");
	for(i=0;i<12;i++)
	{
		printf("비교하실 학기는 몇 학기 십니까? : ");
		scanf("%d",&shakki[i]);
		fflush(stdin);
		printf("계속 입력하시겠습니까?(y/n)");
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
	printf("          ※  학기별 성적 그래프 ※ \n");
	printf("\n");
	printf("   ==========================================\n");
	while(i<j)
	{
		printf("   ★ %d 학기 : ",shakki[i]);
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
	printf("지금까지 입력된 총 학점 : %d \n", tothak);
	printf("지금까지 입력된 성적의 총 평균 : %.2lf \n", average);
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
	printf("입력된 총 학점 : %d \n", tothak);
	printf("입력된 성적의 평균 : %.2lf \n", average);

	open=fopen("목표.txt","r");
	fscanf(open, "%d \n %lf", &hakki,&ggg);
	goals = (average/ggg)*100;
	printf("%d 학기 목표 달성 지수 : %.2lf %% \n", hakki , goals);
	if(goals>=100)
	{
		printf("목표를 달성 하셨네요!!! 축하드립니다♥♥♥ \n\a\a\a\a\a\a\a\a\a\a\a\a\a\a");
	}
	else if((goals>=70)&&(goals<100))
	{
		printf("조금 부족하네요!!! 조금더 노력하세요!! \n");
	}
	else if(goals<70)
	{
		printf("공부해라!! 병신아!!! \n");
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