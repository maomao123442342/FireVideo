#ifndef _FIREVIDEO_H_
#define _FIREVIDEO_H_

#include <QtGui>
#include <QtWidgets/qwidget.h>
#include <qwidgetresizehandler_p.h>
#include <qsize.h>
#include <qlabel.h>
//#include <qframe.h> 
#include <qevent.h>
#include <qpainter.h>
#include <qmediaplayer.h>
#include <QMediaPlaylist>
#include <MyVideoWidget.h> 
#include <QTimer>   //定时器
#include <qtextcodec.h>
#include "NoFocusDelegate.h"
#include "FireSlider.h"
#include "FireButton.h"
class FireVideo :public QWidget
{
	Q_OBJECT
	friend class FullScreenWidget;
public:
	explicit FireVideo(QWidget *parent = 0);
	~FireVideo();
	private slots :
	//buttons click slots
	void BtnOpenFile_Click();
	void BtnPlay_Click();
	void BtnPause_Click();
	void BtnCease_Click();
	void BtnNext_Click();
	void BtnLast_Click();
	void BtnVoice_Click();
	void BtnFullScreen_Click();
	void BtnExitFullScreen_Click();
	void BtnHideAll_Click();
	void BtnDeleteCur_Click();//删除目录列表中选中的视频
	void BtnDeleteAll_Click();//删除列表中所有的视频
	void BtnPlayCur_Click();//播放目录列表中选中的视频
	void BtnNextPlay_Click();//将目录列表中选中的视频设为下一个待播放的视频
	void BtnRestore_Click();//还原默认窗口
	void Updata_PlaySlider_Duration(qint64 duration);
	void Updata_PlaySlider_Position(qint64 pos);
	void MTimeSlot();
	int Get_Video_Position();
	void Set_Video_Volume(int vol);
	//状态更新槽函数
	void PlayStateChange(QMediaPlayer::State state);
	void playlistTable_DoubleClicked(QTableWidgetItem* item);
	void Fire_Media_Changed(const QMediaContent &);
	void videoWidget_ContextMenu(const QPoint& pos);
	void playlistTable_ContextMenu(const QPoint& pos);
	void playlistTable_Drafting(QTableWidgetItem *currentItem);
private:
	void FireVideo_Init_UI();
	void FireVideo_Init_Player();
	void FireVideo_Init_Table();
	void FireVideo_Init_InterfaceLevel();
	void FireVideo_Init_Connect();
	void Fire_Add_VideoList(QString& file);
	void Fire_Write_VideoList(); //将视频文件写入文件中
	void Fire_Read_VideoList(); //程序运行时读取上次运次存储视频，并初始化播放列表
	QString CalVideoPlayTime(); //计算视频文件需要播放的总时长
	QString CalVideoCurPlayTime(); //计算视频当前播放时间
	void Fire_ListTable_color(); //配置列表表格颜色方案
	//Event
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent* event);
	//void enterEvent(QEvent *event); //鼠标进入事件,进入按键位置,提示功能
	//void mousePressEvent(QMouseEvent* event); 
	void wheelEvent(QWheelEvent*event); //鼠标滚轮
	void contextMenuEvent(QContextMenuEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);//拖拽事件
	void dropEvent(QDropEvent *event);//释放添加事件
private:
	//buttons
	FireButton* BtnMinimize;
	FireButton* BtnExit;
	FireButton* BtnOpenFile;
	FireButton* BtnPlay;
	FireButton* BtnPause;
	FireButton* BtnCease;
	FireButton* BtnNext;
	FireButton* BtnLast;
	FireButton* BtnVoice;
	FireButton* BtnFullScreen;
	FireButton* BtnHideAllKeys;//隐藏所有按键
	//屏幕labels
	QLabel* VideoInfoLable; //显示正在播放视频文件信息
	QLabel* VolValue;      //音量大小
	QLabel* PlaySchedule; //实时播放进度时长
	QLabel* PlaySumSchedule;//视频总时长
	QLabel* SystemTime;   //显示当前系统时间
	//按键提示labels
	QLabel* HintLabel_Mini;
	QLabel* HintLabel_Exit;
	QLabel* HintLabel_OpenFile;
	QLabel* HintLabel_Pause;
	QLabel* HintLabel_Play;
	QLabel* HintLabel_Next;
	QLabel* HintLabel_Stop;
	QLabel* HintLabel_Voice;
	//list
	QTableWidget* playlistTable; //视频列表
	QStringList VideoListFlies; //存储视频文件绝对路径
	QStringList VideoListName;  //仅存储列表文件的视频名称
	QStringList VideolistTime; //存储列表文件的播放时长
	//meuns
	QMenu* VideoWidgetMenu;  //正常尺寸右击菜单
	QMenu* FullScreen_VideoWidgetMenu; //全屏右击菜单
	QMenu* Item_VideoListMenu; //选中视频时右击菜单
	QMenu* VideoListMenu;  //未选中视频右击菜单
	//QActions
	QAction* Play;
	QAction* Pause;
	QAction* Stop;
	QAction* NextVideo;
	QAction* LastVideo;
	QAction* HideAll; //隐藏所有窗口，只显示视频窗口
	QAction* Restore; //还原窗口
	QAction* FullScreen;
	QAction* Exit_FullScreen;
	QAction* AddVideo;
	QAction* DeleteCur;
	QAction* DeleteAll;
	QAction* PlayCur;
	QAction* NextPlay; //当前视频结束，直接播放该视频
	//time
	QTimer* timer; //定时器
	//Slider
	FireSlider* playSlider;//播放进度条
	QSlider* volSlider;
	//视频播放器
	QMediaPlayer* player;
	QMediaPlaylist* VideoList;
	//视频窗口
	MyVideoWidget* VideoWidget;
	int PlayingPosition;
	int CurrentIndex;
};


#endif


