#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	FILE *fp = NULL;
	pid_t pid;
	char ret[100];
	char cmd[200];
	char name_str[10];
	int name;
	FILE *fp2 =NULL;
	//fp=popen("ls","r");
	//while(fgets(ret,10240,fp)!=NULL)
	//	printf("return:%s",ret);
	while(1)
	{
		while(1)
		{
			fp = popen("ls /home/pi/Desktop/input","r");
			if(fgets(ret,99,fp)!=NULL) break;
			//while(fgets(ret,10240,fp)!=NULL)
				//printf("return : %s",ret);
		}
	
		fp = popen("ls /home/pi/Desktop/input","r");
		while(fgets(ret,99,fp)!=NULL)
		{	
			//pid = fork();
			//if(pid==0)
			//{
				strcpy(cmd,"python /usr/16011033/document_scanner/scan.py --image /home/pi/Desktop/input/");
				strcat(cmd,ret);
				system(cmd);
			//	exit(0);
			//}//scan and cropping
			//else
			//	wait(0);
			system("mv /usr/16011033/document_scanner/output_image.png /home/pi/Desktop/output/");
			system("mv /usr/16011033/document_scanner/crop_image.png /home/pi/Desktop/output/");
				
			//pid = fork();
			//if(pid==0)
			//{
				fp2 = popen("python3 /usr/16011033/mnist_model/final.py","r");
				while(fgets(name_str,9,fp2)!=NULL){}
				name_str[strlen(name_str)-1]='\0';
				//name=name_str;
				//fp2 = fopen("/usr/temp.txt","r");
				//fscanf(fp2,"%d",name);
				//exit(0);
			//}//mnist
			//else 
				//wait(0);
			
			strcpy(cmd,"cp /home/pi/Desktop/output/output_image.png /home/pi/Desktop/output/");
			strcat(cmd,name_str);
			strcat(cmd,".png");
			printf(cmd);
			printf("\n");
			system(cmd);//moving file to user's directory
			


			strcpy(cmd,"tesseract /home/pi/Desktop/output/");
			strcat(cmd,name_str);
			strcat(cmd,".png /home/pi/Desktop/output/");
			strcat(cmd,name_str);
			printf(cmd);
			printf("\n");
			system(cmd);

			strcpy(cmd,"rm /home/pi/Desktop/input/");
			strcat(cmd,ret);
			system(cmd);
		}
	}
	return 0;
}
