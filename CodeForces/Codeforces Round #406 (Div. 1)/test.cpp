#ifndef __MP3_H__
#define __MP3_H__

/*
    播放指定路径的音乐
*/
void madplay(const char *path);

/*
    暂停播放音乐
*/
void madplay_stop();

/*
    接着播放之前暂停的音乐
*/
void madplay_continue();

/*
    关闭播放器
*/
void madplay_close();

#endif /* __MP3_H__ */