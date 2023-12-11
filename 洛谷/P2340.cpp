#include<bits/stdc++.h>
#include<windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
int main()
{
	/*
	左键是否按下:if(KEY_DOWN(MOUSE_MOVED))
	右键是否按下:if(KEY_DOWN(MOUSE_EVENT))
	中键是否按下:if(KEY_DOWN(MOUSE_WHEELED))
	清屏:system("cls");
	判断某键是否被按下:if(KEY_DOWN('1')),if(KEY_DOWN('A'))
	*/
	int nowl=0,nowr=0,k=0,nowall=0,nkl=0,nkr=0,lpl,rpl;
	printf("按1连点左键，按2停止\n按3连点右键，按4停止\n按5按住左键，按6停止\n按7按住右键，按8停止\n按0暂停全部，按9开始\n");
	while(1){
		if(KEY_DOWN('9')){nowall=1;printf("全部操作已解锁\n");}
		while(nowall==1){
			if(KEY_DOWN('1')){nowl=1;printf("输入左键连点频率（单位:秒/次）\n");scanf("%d",&lpl);printf("左键连点已开始\n");Sleep(100);}
			if(KEY_DOWN('3')){nowr=1;printf("输入右键连点频率（单位:秒/次）\n");scanf("%d",&rpl);printf("右键连点已开始\n");Sleep(100);}
			if(KEY_DOWN('2')){nowl=0;printf("左键连点已停止\n");Sleep(100);}
			if(KEY_DOWN('4')){nowr=0;printf("右键连点已停止\n");Sleep(100);}
			if(KEY_DOWN('5')){nkl=1;printf("左键长按已开始\n");Sleep(100);}
			if(KEY_DOWN('6')){nkl=2;printf("左键长按已停止\n");Sleep(100);}
			if(KEY_DOWN('7')){nkr=1;printf("右键长按已开始\n");Sleep(100);}
			if(KEY_DOWN('8')){nkr=2;printf("右键长按已停止\n");Sleep(100);}
			if(KEY_DOWN('0')){nowall=0,nowl=0,nowr=0,nkl=0,nkr=0;printf("全部操作已停止\n");break;}
			if(nowl==1){
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				Sleep(lpl/10000);
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			}
			if(nowr==1){
				mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
				Sleep(rpl/10000);
				mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
			}
			if(nkl==1){
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				nkl=0; 
			}
			else if(nkl==2){
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
				nkl=0;
			}
			if(nkr==1){
				mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
				nkr=0;
			}
			else if(nkr==2){
				mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
				nkr=0;
			}
			Sleep(1);
		}
	}
	return 0;
}