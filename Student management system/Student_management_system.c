#include<stdio.h>//��׼�������ͷ�ļ�
#include<string.h>//strcmp��������ͷ�ļ�
#include<stdlib.h>//FILE����ͷ�ļ�

#define PATH "information.txt"//�궨��	ѧ����Ϣ�洢Ŀ¼

char information[1024][20];//�������п�ʼ��txt�ĵ���ȡ����ѧ����Ϣ����洢��������飬����������ɾ�Ĳ�����Ķ��������ά����

void delay(unsigned int z);
void Connection_Library();//�������ݿ�
void Menu();//�˵�
void Preservation();//�浵

FILE *fp;//��ȡtxt��д��txt��ָ��
char chaxun[1][20];//��ѯʱ��������
char shanchu[1];//ɾ��ʱ��������
int i,j;//ѭ������
int num=0;//¼��ѧ����Ϣʱ�Ż�ı�Ĭ��Ϊ0��Ҳ���൱�ڡ�¼�롱��ѧ������
int Number_of_Student;//����һ��ȫ�ֱ�����¼�ж��ٸ�ѧ��
int NUM;//��ȡʱ�������ַ�������ת��Ϊѧ���������ñ�������ȡһ��'\0'�ַ����Լ���ѧ��������ʽ��Number_of_Student = (NUM-1)/8
int k;//keyѡ�����


	//��1��\t�Ƕ����൱��tab
	//��2��\n�ǻ����൱��enter
	//��3��exit(0)�ǽ���������������
	//��4��system("cls")���������
	

void main()
{
	printf("�������ݿ��У����Ժ󡤡���\n");
	delay(1553600);
	Connection_Library();//�������ݿ�
	delay(1553600);
	system("cls");//����
	Menu();//���ò˵�

	while(1)
	{
		printf("\n������ѡ���ܵ����:");
		scanf("%d",&k);
		switch(k)
		{
			case 0://�˳�����
					exit(0);
			case 1://¼��
			{
				printf("��������Ҫ¼���ѧ������:");
				scanf("%d",&num);
				printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\t\n");
				for(i=(Number_of_Student*8);i<((num*8)+(Number_of_Student*8));i++)
				{
					scanf("%s",&information[i]);
				}
				Number_of_Student = ((num*8)+(NUM-1))/8;
				Preservation();

			}
			break;
			case 2://��ѯ
			{
				//������ѧ����Ϣ����Ҳ����informationȫ������һ��˴�������ѧ�Ž��в�ѯ����ô����������ʱ��ѧ���ɼ�����ѧ����������
				//Ҳ���ǿ��������Ĵ�ʱ��i�ǲ�����ѧ�ŵ����д�����
				//����������һ��������ڲ��ṹ
				//��0��ѧ�ţ�1��������2�����ģ�3����ѧ��4��Ӣ�5������6����ѧ��7������
				//ǰ���ǵ�һ��ͬѧ����Ϣ��Ȼ�������ڶ���ͬѧ����Ϣ
				//��8��ѧ�ţ�9��������10�����ģ�11����ѧ��12��Ӣ�13������14����ѧ��15������
			    //�Դ����ƾͻᷢ�֣�ѧ��ѧ�ŵ�λ����ȡ����8����0��������Ҳ������������ɼ���ѧ�ŵĹؼ���
				//�����������Ҳ�ͺ�ѧ�ŵĲ�ѯ������࣬����λ��8ȡ�඼��1
				printf("����������ѯѧ��ѧ�Ż�����:");
				scanf("%s",&chaxun[0]);
					for(i=0;i<1024;i++)	
					{
						if((strcmp(chaxun[0],information[i])==0)&&(i%8)==0)
						{
							printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\t\n");
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",information[i],information[i+1],information[i+2],information[i+3],information[i+4],information[i+5],information[i+6],information[i+7]);
							break;
						}
									
					}
					if(i<1024)
						break;

					for(i=0;i<1024;i++)
					{
						if(strcmp(chaxun[0],information[i])==0&&((i%8)==1))
						{
							printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\t\n");
							printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",information[i-1],information[i],information[i+1],information[i+2],information[i+3],information[i+4],information[i+5],information[i+6],information[i+7]);
							break;
						}
					}
					if(i<1024)				
						break;
					if(i==1024)
					{				
						printf("��ѯ�޹�!!!\n");
						delay(3000000);
						system("cls");
						Menu();
						break;
					}
							
			}
			break;
			case 3://�޸�
			{
				printf("\n");
				printf("------�ɼ��޸Ľ���------\n");
				printf("������Ҫ�޸ĵĳɼ�ͬѧ��������ѧ��:");
				scanf("%s",&chaxun[0]);
				for(i=0;i<1024;i++)//��ѧ�Ų�ѯ�����޸�
				{
					if((strcmp(chaxun[0],information[i])==0)&&(i%8)==0)
					{
						printf("��ǰ�����ɼ�:\n");
						printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\t\n");
						printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",information[i],information[i+1],information[i+2],information[i+3],information[i+4],information[j+5],information[i+6],information[i+7]);
						printf("����������ɼ�:\n");
						printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\t\n");
						for(i,j=0;j<8;j++)
						{
							scanf("%s",&information[i+j]);
						}
						Preservation();
						break;
					}				
				}
				if(i<1024&&(i!=0))
				{				
					break;
				}
				
				for(i=0;i<1024;i++)//��������ѯ�����޸�
				{
					if(strcmp(chaxun[0],information[i])==0&&((i%8)==1))
					{
						printf("��ǰ�����ɼ�:\n");
						printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\t\n");
						printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",information[i-1],information[i],information[i+1],information[i+2],information[i+3],information[i+4],information[i+5],information[i+6],information[i+7]);
						printf("����������ɼ�:\n");
						printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\t\n");
						for(i,j=0;j<8;j++)
						{
							scanf("%s",&information[i+j-1]);
						}
					//	for(i;i<9;i++)
					//	{
					////		scanf("%s",&information[i-1]);//�޸ĵ���˼�������¸�����ԭ����ѧ����Ϣ��ֵ����ԭ��Ϣ����
					//	}
						Preservation();
						break;
					}
				}
				if(i<1024&&(i!=0))
					break;
				if(i==1024)
				{				
					printf("��ѯ�޹�!!!\n");
					delay(3000000);
					system("cls");
					Menu();
					break;
				}
				
			}
			case 4://��ӡALL
			{
				printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\t\n");
				for(i=1;i<=Number_of_Student*8;i++)
				{
					printf("%s\t",information[i-1]);
					if(i%8==0)
					printf("\n");
				}
			}
			break;
			case 5://ɾ��ָ��ͬѧ�ɼ���Ϣ
			{
				printf("------�ɼ�ɾ������------\n");
				printf("��������Ҫɾ��ѧ����Ϣ��ѧ�Ż�����:");
				scanf("%s",&chaxun[0]);
				for(i=0;i<1024;i++)//��ѧ�Ų�ѯ����ɾ��
				{
					if((strcmp(chaxun[0],information[i])==0)&&(i%8)==0)
					{
						printf("��ǰ�����ɼ�:\n");
						printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\t\n");
						printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",information[i],information[i+1],information[i+2],information[i+3],information[i+4],information[j+5],information[i+6],information[i+7]);
						//������ɾ������
						printf("��ʾ:ȷ��Ҫɾ�������ɼ���(Y or N)\n");
						scanf("%s",&shanchu[0]);
						if(shanchu[0]=='Y')
						{
							for(i;i<Number_of_Student*8;i++)
							{
								for(j=0;j<20;j++)//��ѭ��20�ΰѵڶ�ά���鶼����λ
								{
										information[i][j]=information[i+8][j];//�˴���ɾ��������ָ����ɾ����ѧ����Ϣ���ǣ�Ҳ�ͱ������������
										//������information[i+8][j]����Ϊ��ʱ��i�Ǳ�ɾ��ѧ������Ӧ��ѧ�ţ����������е�ֵ�ǰ�i+8���Ƹ�i
								}
							
							}
							Number_of_Student = Number_of_Student-1;
							Preservation();
							printf("ɾ���ɹ�!!!\n");
							delay(3000000);
							break;
						}
						else
							break;

					}				
				}
				if(i<1024)
				{				
					break;
				}
				
				for(i=0;i<1024;i++)//��������ѯ����ɾ��
				{
					if(strcmp(chaxun[0],information[i])==0&&((i%8)==1))
					{
						printf("��ǰ�����ɼ�:\n");
						printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ\t����\t���ۺ�\t�ܷ�\t\n");
						printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",information[i-1],information[i],information[i+1],information[i+2],information[i+3],information[i+4],information[i+5],information[i+6],information[i+7]);
						//������ɾ������-----�����i�������Ա��ں�߽���ɾ������
						printf("��ʾ:ȷ��Ҫɾ�������ɼ���(Y or N)\n");
						scanf("%s",&shanchu[0]);
						if(shanchu[0]=='Y')
						{
							for(i;i<Number_of_Student*8;i++)
							{
								for(j=0;j<20;j++)
								{
										information[i-1][j]=information[i+7][j];//�˴���ɾ��������ָ����ɾ����ѧ����Ϣ���ǣ�Ҳ�ͱ������������
										//������information[i+7][j]����Ϊ��ʱ��i�Ǳ�ɾ��ѧ������Ӧ�����������������е�ֵ�ǰ�i+7���Ƹ�i-1
								}
							
							}
							Number_of_Student = Number_of_Student-1;
							Preservation();
							printf("ɾ���ɹ�!!!\n");
							delay(3000000);
							break;
						}
						else
							break;


						
					}
				}
				if(i<1024)//�����ϱ��Ƿ��Ѿ����ɾ����ɾ����i<1024���ʱ����case				
					break;
				if(i==1024)//��i=1024ʱ��û�в��ҵ���ѧ�������������������ѯδ��
				{				
					printf("��ѯ�޹�!!!\n");
					delay(3000000);
					system("cls");
					Menu();
					break;
				}

			}

			case 6://����
			{
				system("cls");
				//----�����Ѿ�����Ϊ�˼�ֱ�����ȫ�������������������ѡ����----//
				Menu();
			}
			break;
		}



	}
								

}


void delay(unsigned int z)
{
    unsigned int x,y;
    for(x=z;x>0;x--)
    for(y=110;y>0;y--);
}

void Connection_Library()//����Ƿ���ļ������������ı����ȡ������Ϣ��������information[]
{


	fp = fopen("information.txt","r");
	if (fp == NULL)
		{
			printf("����ʧ��\n");
		}
	else
		{
		NUM=0;
		while(!feof(fp))
				{
					fscanf(fp,"%s",information[NUM]);
					NUM++;
				}
		printf("���ӳɹ�\n");
		Number_of_Student = (NUM-1)/8;
		}
}

void Menu()//---����ѡ����
{
	printf("-------�˵�-------\n\n");
	printf("(1) ¼��ɼ�\n");
	printf("(2) ��ѯ�ɼ�\n");
	printf("(3) �޸���Ϣ\n");
	printf("(4) ��ӡȫ���ɼ�\n");
	printf("(5) ɾ���ɼ�\n");
	printf("(6) �����Ļ\n");
	printf("(0) �˳�����\n");
	printf("\n");
	printf("�����ڹ��ܽ�������(0)���˳�ϵͳ �������ݽ��޷�����\n");
	printf("\n");
	printf("���ݿ������ڹ���-%d-��ͬѧ��Ϣ\n",Number_of_Student);
}

void Preservation()
{
	printf("���ڴ浵���Ժ󡤡���\n");
	//------�浵ѧ����Ϣ------//
	fp=fopen("information.txt","w");
	for(i=0;i<Number_of_Student*8;i++)
		fprintf(fp,"%s ",information[i]);//������a������д���ļ����Կո����
	printf("\n");
	delay(3000000);
	printf("�浵���\n");
	delay(3000000);
}

//--------------Copy BaiYuQing Stdio--------------//
//-------------------2020-12-11-------------------//
